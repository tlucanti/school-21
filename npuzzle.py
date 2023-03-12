
import gen
import random

class Astar():
    class NPuzzleError(RuntimeError):
        pass

    class Euristics():
        class Type():
            class INCORRECT(): pass
            class MANHATTAN(): pass
            class EUCLEDUAN(): pass

        class Scheduler():
            class FIRST_FIT(): pass
            class RANDOM(): pass
            class ROUND_ROBIN(): pass

    class Direction():
        def __init__(self, value, name):
            self.value = value
            self.name = name

        def __repr__(self):
            return self.name

        def __eq__(self, other):
            return self.value == other.value

        def __ne__(self, other):
            return self.value != other.value

    LEFT = Direction(0x1, 'left')
    RIGHT = Direction(0x2, 'right')
    UP = Direction(0x3, 'up')
    DOWN = Direction(0x4, 'down')

    def __gen_matrix(self):
        target = [[0] * self.h for i in range(self.h)]
        i = 0
        for y in range(self.h):
            for x in range(self.h):
                i += 1
                target[y][x] = i
        target[-1][-1] = 0
        return target

    def __init__(self, mat):
        self.iterations = 0
        self.h = len(mat)
        #self.target = gen.make_matrix_goal(self.h)
        self.target = self.__gen_matrix()
        self.actions = []
        self.mat = mat
        self.rr_counter = -1
        self.remap_table = self.__get_remap_table()

    def find_start(self):
        for y in range(self.h):
            for x in range(self.h):
                if self.mat[y][x] == 0:
                    return x, y
        raise NPuzzleError('board dont have empty (0) piece')

    def __get_remap_table(self):
        remap_table_x = [0] * (self.h * self.h)
        remap_table_y = [0] * (self.h * self.h)
        for y in range(self.h):
            for x in range(self.h):
                expected_key = self.target[y][x]
                remap_table_y[expected_key] = y
                remap_table_x[expected_key] = x
        return remap_table_y, remap_table_x

    def init_score_incorrect(self, mat):
        score_table = [[0] * self.h for _ in range(self.h)]
        score = 0
        for y in range(self.h):
            for x in range(self.h):
                if mat[y][x] == 0:
                    continue
                score_val = mat[y][x] != self.target[y][x]
                score_table[y][x] = score_val
                score += score_val
        return score_table, score

    def init_score_manhattan(self, mat):
        score_table = [[0] * self.h for _ in range(self.h)]
        score = 0
        remap_table_y, remap_table_x = self.remap_table
        for y in range(self.h):
            for x in range(self.h):
                curr_key = mat[y][x]
                if curr_key == 0:
                    continue
                diff_y = abs(remap_table_y[curr_key] - y)
                diff_x = abs(remap_table_x[curr_key] - x)
                score_val = diff_x + diff_y
                score_table[y][x] = score_val
                score += score_val
        return score_table, score

    def init_score_eucleduan(self, mat):
        score_table = [[0] * self.h for _ in range(self.h)]
        score = 0
        remap_table_y, remap_table_x = self.remap_table
        for y in range(self.h):
            for x in range(self.h):
                curr_key = mat[y][x]
                if curr_key == 0:
                    continue
                diff_y = remap_table_y[curr_key] - y
                diff_x = remap_table_x[curr_key] - x
                score_val = diff_x * diff_x + diff_y * diff_y
                score_table[y][x] = score_val
                score += score_val
        return score_table, score_val

    def score_diff_incorrect(self, x0, y0, x1, y1):
        before = self.mat[y1][x1] != self.target[y1][x1]
        after = self.mat[y1][x1] != self.target[y0][x0]

        return after - before

    def score_diff_manhattan(self, x0, y0, x1, y1):
        remap_table_y, remap_table_x = self.remap_table
        change_key = self.mat[y1][x1]
        before_y = abs(remap_table_y[change_key] - y1)
        before_x = abs(remap_table_x[change_key] - x1)
        after_y = abs(remap_table_y[change_key] - y0)
        after_x = abs(remap_table_x[change_key] - x0)

        before = before_x + before_y
        after = after_x + after_y
        return after - before

    def score_diff_eucleduan(self, x0, y0, x1, y1):
        remap_table_y, remap_table_x = self.remap_table
        change_key = self.mat[y1][x1]
        before_y = remap_table_y[change_key] - y1
        before_x = remap_table_x[change_key] - x1
        after_y = remap_table_y[change_key] - y0
        after_x = remap_table_x[change_key] - x0

        before = before_x ** 2 + before_y ** 2
        after = after_x ** 2 + after_y ** 2
        return after - before

    def choice_score_first(self, arr):
        return arr[0]

    def choice_score_random(self, arr):
        return random.choice(arr)

    def choice_score_rr(self, arr):
        self.rr_counter += 1
        return arr[self.rr_counter % len(arr)]

    def solve(self, euristic_type, euristic_sceduler):
        if not self.solvable():
            raise self.NPuzzleError('unsolvable')
        self.euristic_type = euristic_type
        self.euristic_sceduler = euristic_sceduler

        if self.euristic_type == self.Euristics.Type.INCORRECT:
            self.init_score_table = self.init_score_incorrect
            self.score_diff = self.score_diff_incorrect
        elif self.euristic_type == self.Euristics.Type.MANHATTAN:
            self.init_score_table = self.init_score_manhattan
            self.score_diff = self.score_diff_manhattan
        elif self.euristic_type == self.Euristics.Type.EUCLEDUAN:
            self.init_score_table = self.init_score_eucleduan
            self.score_diff = self.score_diff_eucleduan
        else:
            raise NPuzzleError('unknown euristic type')

        if self.euristic_sceduler == self.Euristics.Scheduler.FIRST_FIT:
            self.choice_score = self.choice_score_first
        elif self.euristic_sceduler == self.Euristics.Scheduler.RANDOM:
            self.choice_score = self.choice_score_random
        elif self.euristic_sceduler == self.Euristics.Scheduler.ROUND_ROBIN:
            self.choice_score = self.choice_score_rr
        else:
            raise NPuzzleError('unknown euristic sceduler')

        x, y = self.find_start()
        self.score_table, self.score = self.init_score_table(self.mat)
        if self.score == 0:
            return []
        self.dfs(x, y)
        return self.actions

    def dfs(self, x, y):
        mat = self.mat
        while self.score != 0:
            print(self.score)
            avaliable = []
            if x > 0:
                diff = self.score_diff(x, y, x - 1, y)
                avaliable.append((self.LEFT, diff))
            if x < self.h - 1:
                diff = self.score_diff(x, y, x + 1, y)
                avaliable.append((self.RIGHT, diff))
            if y > 0:
                diff = self.score_diff(x, y, x, y - 1)
                avaliable.append((self.DOWN, diff))
            if y < self.h - 1:
                diff = self.score_diff(x, y, x, y + 1)
                avaliable.append((self.UP, diff))

            mn = min(avaliable, key=lambda x: x[1])
            print(avaliable)
            avaliable = list(filter(lambda x: x[1] == mn[1], avaliable))
            step = self.choice_score(avaliable)
            print(step)
            if step[0] == self.LEFT:
                mat[y][x], mat[y][x - 1] = mat[y][x - 1], mat[y][x]
                x = x - 1
            elif step[0] == self.RIGHT:
                mat[y][x], mat[y][x + 1] = mat[y][x + 1], mat[y][x]
                x = x + 1
            elif step[0] == self.DOWN:
                mat[y][x], mat[y - 1][x] = mat[y - 1][x], mat[y][x]
                y = y - 1
            elif step[0] == self.UP:
                mat[y][x], mat[y + 1][x] = mat[y + 1][x], mat[y][x]
                y = y + 1
            else:
                raise RuntimeError()
            self.actions.append(step[0])
            self.score += step[1]
            if len(self.actions) > 1000:
                raise RuntimeError()
            print(*self.mat, sep='\n')
        print('------------')
        print(*self.mat, sep='\n')

    def solvable(self):
        return True
        ans = 0
        remap_table = [0] * (self.h ** 2)
        i = 0
        for y in range(self.h):
            for x in range(self.h):
                i += 1
                val = self.target[y][x] - 1
                remap_table[val] = i
        remap_table[self.target[-1][-1] - 1] = 0
        mat = []
        for y in range(self.h):
            for x in range(self.h):
                val = self.mat[y][x] - 1
                mat.append(remap_table[val])
                if remap_table[val] == 0:
                    ans += y + 1
        print(mat)
        print(remap_table)
        s = len(remap_table)
        for i in range(s):
            if mat[i] == 0:
                continue
            for j in range(i + 1, s):
                if mat[j] == 0:
                    continue
                if mat[i] > mat[j]:
                    ans += 1
        return ans % 2 == 0

def inp():
    return list(map(int, input().split()))

def input_mat():
    mat = []
    mat.append(inp())
    for i in range(len(mat[0]) - 1):
        mat.append(inp())
        if len(mat[-1]) != len(mat[0]):
            raise NPuzzleError('invalid board')
    return mat

def main():
    print('>>>')
    mat = input_mat()
    astar = Astar(mat)
    actions = astar.solve()
    print(actions)

if __name__ == '__main__':
    main()
