
import gen
import random

class Astar():
    class NPuzzleError(RuntimeError):
        pass

    class Euristics():
        class Type():
            INCORRECT = 0x1
            MANHATTAN = 0x2
            EUCLEDUAN = 0x3

        class Scheduler():
            FIRST_FIT = 0x1
            RANDOM = 0x2
            ROUND_ROBIN = 0x3

    LEFT = 0x1
    RIGHT = 0x2
    DOWN = 0x3
    UP = 0x4

    def __init__(self, mat):
        self.iterations = 0
        self.h = len(mat)
        self.complete_mat = gen.make_matrix_goal(self.h)
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
                expected_key = self.complete_mat[y][x]
                remap_table_y[expected_key] = y
                remap_table_x[expected_key] = x
        return remap_table_y, remap_table_x

    def init_score_incorrect(self, mat):
        score_table = [[0] * self.h for _ in range(h)]
        score = 0
        for y in range(self.h):
            for x in range(self.h):
                if mat[y][x] == 0:
                    continue
                score_val = mat[y][x] != self.complete_mat[y][x]
                score_table[y][x] = score_val
                score += score_val
        return score_table, score

    def init_score_manhattan(self, mat):
        score_table = [[0] * self.h for _ in range(h)]
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
        score_table = [[0] * self.h for _ in range(h)]
        score = 0
        remap_table_y, remap_table_x = self.remap_table
        for y in range(self.h):
            for x in range(self.h):
                curr_key = mat[y][x]
                if cur_key == 0:
                    continue
                diff_y = remap_table_y[curr_key] - y
                diff_x = remap_table_x[curr_key] - x
                score_val = diff_x * diff_x + diff_y * diff_y
                score_table[y][x] = score_val
                score += score_val
        return score_table, score_val

    def score_diff_incorrect(self, x0, y0, x1, y1):
        mat[y0][x0] != self.complete_map[y1][x1]

    def score_diff_manhattan(self, x0, y0, x1, y1):
        pass

    def score_diff_eucleduan(self, x0, y0, x1, y1):
        pass

    def chose_score_first(self, arr):
        return arr[0]

    def chose_score_random(self, arr):
        return random.choice(arr)

    def schose_score_rr(self, arr):
        self.rr_counter += 1
        return arr[self.rr_counter % len(arr)]

    def solve(self, euristic_type, euristic_sceduler):
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
            self.chose_score = self.chose_score_first
        elif self.euristic_sceduler == self.Euristics.Scheduler.RANDOM:
            self.chose_score = self.chose_score_random
        elif self.euristic_sceduler == self.Euristics.Scheduler.ROUND_ROBIN:
            self.chose_score = self.chose_score_rr
        else:
            raise NPuzzleError('unknown euristic sceduler')

        x, y = self.find_start()
        self.score_table, self.score = self.init_score_table()
        if self.current == 0:
            return []
        self.dfs(x, y)
        return self.actions

    def dfs(self, x, y):

        mat = self.mat
        avaliable = []
        while self.current_score != 0:
            if x > 0:
                diff = self.score_diff(self.LEFT)
                avaliable.append((self.LEFT, diff))
            if x < self.h - 1:
                diff = self.score_diff(self.RIGHT)
                avaliable.append((self.RIGHT, diff))
            if y > 0:
                diff = self.score_diff(self.DOWN)
                avaliable.append((self.DOWN, diff))
            if y < self.h - 1:
                diff = self.score_diff(self.UP)
                avaliable.append((self.UP, diff))

            mn = min(avaliable, key=lambda x: x[1])
            avaliable = list(filter(lambda x: x[1] == mn, avaliable))
            step = self.chose_step(avaliable)
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
            self.current_score += diff


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
    mat = input_mat()
    astar = Astar(mat)
    actions = astar.solve()
    print(actions)

if __name__ == '__main__':
    main()
