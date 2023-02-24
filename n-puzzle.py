

class Astar():
    class NPuzzleError(RuntimeError):
        pass

    LEFT = 0
    RIGHT = 1
    DOWN = 2
    UP = 3

    def __init__(self, mat):
        self.h = len(mat)
        self.complete_mat = []
        self.actions = []
        self.mat = mat
        for y in range(self.h):
            nxt = list(range(y * self.h + 1, (y + 1) * self.h + 1))
            self.complete_mat.append(nxt)
        self.complete_mat[-1][-1] = 0

    def find_start(self):
        for y in range(self.h):
            for x in range(self.h):
                if self.mat[y][x] == 0:
                    return x, y
        raise NPuzzleError('board dont have empty (0) piece')

    def get_score(self, mat):
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
        print(x, y)
        mat = self.mat
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
            if mn != 0:
                self.dfs(x - 1, y)
        elif mn == right:
            self.actions.append(self.RIGHT)
            mat[y][x], mat[y][x + 1] = mat[y][x + 1], mat[y][x]
            if mn != 0:
                self.dfs(x + 1, y)
        elif mn == down:
            self.actions.append(self.DOWN)
            mat[y][x], mat[y - 1][x] = mat[y - 1][x], mat[y][x]
            if mn != 0:
                self.dfs(x, y - 1)
        else:
            self.actions.append(self.UP)
            mat[y][x], mat[y + 1][x] = mat[y + 1][x], mat[y][x]
            if mn != 0:
                self.dfs(x, y + 1)


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
