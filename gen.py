
import random

def gen_target_default(h):
    target = [[0] * h for _ in range(h)]
    i = 0
    for y in range(h):
        for x in range(h):
            i += 1
            target[y][x] = i
    target[-1][-1] = 0
    return target

def gen_target_spiral(h):
    target = [[0] * h for _ in range(h)]
    second = True
    x = 0
    y = 0
    RIGHT = 0
    DOWN = 1
    LEFT = 2
    UP = 3
    step = h
    stepped = 1
    direction = RIGHT
    i = 0
    while i < h * h - 1:
        i += 1
        target[y][x] = i
        if direction == RIGHT:
            x += 1
        elif direction == LEFT:
            x -= 1
        elif direction == UP:
            y -= 1
        else:
            y += 1
        stepped += 1
        if stepped == step:
            direction = (direction + 1) % 4
            if second:
                second = False
                step -= 1
            else:
                second = 1
            stepped = 0
    return target

def shuffle(mat, n):
    def find_start(mat):
        for y in range(len(mat)):
            for x in range(len(mat)):
                if mat[y][x] == 0:
                    return y, x

    def swap(mat, y0, x0, y1, x1):
        mat[y0][x0], mat[y1][x1] = mat[y1][x1], mat[y0][x0]

    h = len(mat)
    y, x = find_start(mat)
    LEFT = 0
    RIGHT = 1
    UP = 2
    DOWN = 3
    for i in range(n):
        avaliable = []
        if x > 0:
            avaliable.append(LEFT)
        if x < h - 1:
            avaliable.append(RIGHT)
        if y > 0:
            avaliable.append(UP)
        if y < h - 1:
            avaliable.append(DOWN)
        step = random.choice(avaliable)
        if step == LEFT:
            swap(mat, y, x, y, x - 1)
            x = x - 1
        elif step == RIGHT:
            swap(mat, y, x, y, x + 1)
            x = x + 1
        elif step == UP:
            swap(mat, y, x, y - 1, x)
            y = y - 1
        elif step == DOWN:
            swap(mat, y, x, y + 1, x)
            y = y + 1
    return mat


def gen_target(h):
    return gen_target_default(h)


if __name__ == '__main__':
    import numpy as np
    mat = gen_target_default(5)
    shuffle(mat, 2)
    print(np.array(mat))

