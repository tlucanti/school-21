
import gen
import random

class Astar():
    class NPuzzleError(RuntimeError):
        pass

    class Euristics():
        INCORRECT = 0x1
        INCORRECT_RANDOM = 0x2
        INCORRECT_ROUND_ROBIN = 0x3
        MANHATTAN = 0x4
        MANHATTAN_RANDOM = 0x5
        MANHATTAN_ROUND_ROBIN = 0x6

    LEFT = 0x1
    RIGHT = 0x2
    DOWN = 0x3
    UP = 0x4

    def __init__(self, mat, score):
        self.iterations = 0
        self.h = len(mat)
        self.complete_mat = gen.make_matrix_goal(self.h)
        self.actions = []
        self.mat = mat
        for y in range(self.h):
            nxt = list(range(y * self.h + 1, (y + 1) * self.h + 1))
            self.complete_mat.append(nxt)

    def find_start(self):
        for y in range(self.h):
            for x in range(self.h):
                if self.mat[y][x] == 0:
                    return x, y
        raise NPuzzleError('board dont have empty (0) piece')

    def get_score(self, mat):
        self.iterations += 1
        score = 0
        for y in range(self.h):
            for x in range(self.h):
                score += mat[y][x] != self.complete_mat[y][x]
        return score

    def solve(self):
        x, y = self.find_start()
        if self.get_score(self.mat) == 0:
            return []
        self.dfs(x, y)
        return self.actions

    def dfs(self, x, y):

        mat = self.mat
        while True:
            if x > 0:
                mat[y][x], mat[y][x - 1] = mat[y][x - 1], mat[y][x]
                left = self.get_score(mat)
                mat[y][x], mat[y][x - 1] = mat[y][x - 1], mat[y][x]
            else:
                left  = self.h ** 2

            if x < self.h - 1:
                mat[y][x], mat[y][x + 1] = mat[y][x + 1], mat[y][x]
                right = self.get_score(mat)
                mat[y][x], mat[y][x + 1] = mat[y][x + 1], mat[y][x]
            else:
                right = self.h ** 2

            if y > 0:
                mat[y][x], mat[y - 1][x] = mat[y - 1][x], mat[y][x]
                down = self.get_score(mat)
                mat[y][x], mat[y - 1][x] = mat[y - 1][x], mat[y][x]
            else:
                down = self.h ** 2

            if y < self.h - 1:
                mat[y][x], mat[y + 1][x] = mat[y + 1][x], mat[y][x]
                up = self.get_score(mat)
                mat[y][x], mat[y + 1][x] = mat[y + 1][x], mat[y][x]
            else:
                up = self.h ** 2

            mn = min(left, right, up, down)
            if mn == left:
                self.actions.append(self.LEFT)
                mat[y][x], mat[y][x - 1] = mat[y][x - 1], mat[y][x]
                x = x - 1
            elif mn == right:
                self.actions.append(self.RIGHT)
                mat[y][x], mat[y][x + 1] = mat[y][x + 1], mat[y][x]
                x = x + 1
            elif mn == down:
                self.actions.append(self.DOWN)
                mat[y][x], mat[y - 1][x] = mat[y - 1][x], mat[y][x]
                y = y - 1
            else:
                self.actions.append(self.UP)
                mat[y][x], mat[y + 1][x] = mat[y + 1][x], mat[y][x]
                y = y + 1
            if mn == 0:
                break


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
