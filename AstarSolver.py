
import gen
from Solver import Solver
import random

class AstarSolver:
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
    NULL = Direction(-1, '')

    def __init__(self, mat):
        self.iterations = 0
        self.h = len(mat)
        self.target = gen.gen_target(self.h)
        self.actions = []
        self.mat = mat
        self.rr_counter = -1
        self.remap_table = self.__get_remap_table()
        if self.h == 1:
            self.dfs_depth = 0
        elif self.h == 2:
            self.dfs_depth = 1
        elif self.h == 3:
            self.dfs_depth = 9
        elif self.h == 4:
            self.dfs_depth = 13
        elif self.h == 5:
            self.dfs_depth = 13
        else:
            self.dfs_depth = 13

    def __find_start(self):
        for y in range(self.h):
            for x in range(self.h):
                if self.mat[y][x] == 0:
                    return x, y
        raise Astar.NPuzzleError('board dont have empty (0) piece')

    def __get_remap_table(self):
        remap_table_x = [0] * (self.h * self.h)
        remap_table_y = [0] * (self.h * self.h)
        for y in range(self.h):
            for x in range(self.h):
                expected_key = self.target[y][x]
                remap_table_y[expected_key] = y
                remap_table_x[expected_key] = x
        return remap_table_y, remap_table_x

    def __init_score_incorrect(self, mat):
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

    def __init_score_manhattan(self, mat):
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

    def __init_score_eucleduan(self, mat):
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
                score_val = diff_x ** 2 + diff_y ** 2
                score_table[y][x] = score_val
                score += score_val
        return score_table, score

    def __score_diff_incorrect(self, x0, y0, x1, y1):
        before = self.mat[y1][x1] != self.target[y1][x1]
        after = self.mat[y1][x1] != self.target[y0][x0]

        return after - before

    def __score_diff_manhattan(self, x0, y0, x1, y1):
        remap_table_y, remap_table_x = self.remap_table
        change_key = self.mat[y1][x1]
        before_y = abs(remap_table_y[change_key] - y1)
        before_x = abs(remap_table_x[change_key] - x1)
        after_y = abs(remap_table_y[change_key] - y0)
        after_x = abs(remap_table_x[change_key] - x0)

        before = before_x + before_y
        after = after_x + after_y
        return after - before

    def __score_diff_eucleduan(self, x0, y0, x1, y1):
        remap_table_y, remap_table_x = self.remap_table
        change_key = self.mat[y1][x1]
        before_y = remap_table_y[change_key] - y1
        before_x = remap_table_x[change_key] - x1
        after_y = remap_table_y[change_key] - y0
        after_x = remap_table_x[change_key] - x0

        before = before_x ** 2 + before_y ** 2
        after = after_x ** 2 + after_y ** 2
        return after - before

    def __choice_score_first(self, arr):
        return arr[0]

    def __choice_score_random(self, arr):
        return random.choice(arr)

    def __choice_score_rr(self, arr):
        self.rr_counter += 1
        return arr[self.rr_counter % len(arr)]

    def solve(self, euristic_type, euristic_sceduler):
        self.answer_length = 0
        if not self.solvable():
            raise self.NPuzzleError('unsolvable')
        self.euristic_type = euristic_type
        self.euristic_sceduler = euristic_sceduler

        if self.euristic_type == Solver.Euristics.Type.INCORRECT:
            self._init_score_table = self.__init_score_incorrect
            self._score_diff = self.__score_diff_incorrect
        elif self.euristic_type == Solver.Euristics.Type.MANHATTAN:
            self._init_score_table = self.__init_score_manhattan
            self._score_diff = self.__score_diff_manhattan
        elif self.euristic_type == Solver.Euristics.Type.EUCLEDUAN:
            self._init_score_table = self.__init_score_eucleduan
            self._score_diff = self.__score_diff_eucleduan
        else:
            raise NPuzzleError('unknown euristic type')

        if self.euristic_sceduler == Solver.Euristics.Scheduler.FIRST_FIT:
            self._choice_score = self.__choice_score_first
        elif self.euristic_sceduler == Solver.Euristics.Scheduler.RANDOM:
            self._choice_score = self.__choice_score_random
        elif self.euristic_sceduler == Solver.Euristics.Scheduler.ROUND_ROBIN:
            self._choice_score = self.__choice_score_rr
        else:
            raise NPuzzleError('unknown euristic sceduler')

        x, y = self.__find_start()
        self.score_table, self.score = self._init_score_table(self.mat)
        if self.score == 0:
            return []
        self._dfs(x, y)
        self.answer_length = len(self.actions)
        return self.actions

    def __swap(self, x0, y0, x1, y1):
        self.mat[y0][x0], self.mat[y1][x1] = self.mat[y1][x1], self.mat[y0][x0]

    def __dfs(self, x, y, actions, depth, diff_orig):
        if depth == 0 or self.score + diff_orig == 0:
            self.acs.append((actions.copy(), diff_orig))
            return
        if x > 0 and actions[-1] != self.RIGHT:
            diff = diff_orig + self._score_diff(x, y, x - 1, y)
            actions.append(self.LEFT)
            self.__swap(x, y, x - 1, y)
            self.__dfs(x - 1, y, actions, depth - 1, diff)
            self.__swap(x, y, x - 1, y)
            actions.pop()
        if x < self.h - 1 and actions[-1] != self.LEFT:
            diff = diff_orig + self._score_diff(x, y, x + 1, y)
            actions.append(self.RIGHT)
            self.__swap(x, y, x + 1, y)
            self.__dfs(x + 1, y, actions, depth - 1, diff)
            self.__swap(x, y, x + 1, y)
            actions.pop()
        if y > 0 and actions[-1] != self.DOWN:
            diff = diff_orig + self._score_diff(x, y, x, y - 1)
            actions.append(self.UP)
            self.__swap(x, y, x, y - 1)
            self.__dfs(x, y - 1, actions, depth - 1, diff)
            self.__swap(x, y, x, y - 1)
            actions.pop()
        if y < self.h - 1 and actions[-1] != self.UP:
            diff = diff_orig + self._score_diff(x, y, x, y + 1)
            actions.append(self.DOWN)
            self.__swap(x, y, x, y + 1)
            self.__dfs(x, y + 1, actions, depth - 1, diff)
            self.__swap(x, y, x, y + 1)
            actions.pop()

    def __apply_steps(self, actions, x, y):
        mat = self.mat
        for step in actions:
            if step == self.LEFT:
                mat[y][x], mat[y][x - 1] = mat[y][x - 1], mat[y][x]
                x = x - 1
            elif step == self.RIGHT:
                mat[y][x], mat[y][x + 1] = mat[y][x + 1], mat[y][x]
                x = x + 1
            elif step == self.UP:
                mat[y][x], mat[y - 1][x] = mat[y - 1][x], mat[y][x]
                y = y - 1
            elif step == self.DOWN:
                mat[y][x], mat[y + 1][x] = mat[y + 1][x], mat[y][x]
                y = y + 1
            elif step == self.NULL:
                continue
            else:
                raise RuntimeError()
        return x, y

    def _dfs(self, x, y):
        mat = self.mat
        while self.score != 0:
            print('===== score', self.score)
            self.acs = []
            self.__dfs(x, y, [self.NULL], self.dfs_depth, 0)

            avaliable = self.acs
            mn = min(avaliable, key=lambda x: x[1])
            #print(avaliable)
            avaliable = list(filter(lambda x: x[1] == mn[1], avaliable))
            step = self._choice_score(avaliable)
            print(step)
            x, y = self.__apply_steps(step[0], x, y)
            self.actions += step[0]
            self.score += step[1]
            assert self.score >= 0
            if len(self.actions) > 5000:
                raise RuntimeError()
            print(*self.mat, sep='\n')
        print('--------------------------------------------------------------')
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

    def metrics(self):
        return Solver.Metrics(answer_length=self.answer_length)

