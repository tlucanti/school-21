# -*- coding: utf-8 -*-
# @Author: tlucanti
# @Date:   2022-03-07 16:25:48
# @Last Modified by:   tlucanti
# @Last Modified time: 2022-03-14 00:37:06

import sys
import numpy as np


def inp():
    return list(map(int, input().split()))


def is_sorted(ar, incr):
    if incr:
        return sorted(ar) == ar
    else:
        return sorted(ar)[::-1] == ar


def transform(array):
    table = {num: index for index, num in enumerate(sorted(array))}
    perm = [table[num] for num in array]
    return perm


def get_order(a, b, c):
    return int(''.join(list(map(str, transform((a, b, c)))))) + 111


def quick_sort(ar):
    ar = [ar.copy()]
    sec = []
    moves = []
    __debug = lambda x: x# move(f'DEBUG: {x}')
    __print = lambda x: x#__debug(x)
    __move = lambda x: print(x)
    stack = 'b'
    other = 'a'

    def move(mv):
        __move(mv)
        moves.append(mv)


    def sort2(batch):
        move(f'p{stack}')
        move(f'p{stack}')
        if batch[0] > batch[1]:
            move(f's{stack}')


    def sort3(batch):
        order = get_order(*batch)
        if order == 321:
            move(f'p{stack}')
            move(f'p{stack}')
            move(f'p{stack}')
        elif order == 123:
            move(f'p{stack}')
            move(f'r{stack}')
            move(f's{other}')
            move(f'p{stack}')
            move(f'p{stack}')
            move(f'rrs{stack}')
        elif order == 132:
            move(f'p{stack}')
            move(f'r{stack}')
            move(f'p{stack}')
            move(f'p{stack}')
            move(f'rr{stack}')
        elif order == 213:
            move(f'p{stack}')
            move(f'r{stack}')
            move(f's{other}')
            move(f'p{stack}')
            move(f'rr{stack}')
            move(f'p{stack}')
        elif order == 231:
            move(f's{other}')
            move(f'p{stack}')
            move(f'p{stack}')
            move(f'p{stack}')
        elif order == 312:
            move(f'p{stack}')
            move(f's{other}')
            move(f'p{stack}')
            move(f'p{stack}')
        else:
            raise RuntimeError(f'unknown order {order}')


    def sort(batch):
        if len(batch) == 2:
            sort2(batch)
        else:
            sort3(batch)


    def __qsort_req(ar):
        left = []
        right = []
        srt = sorted(ar)
        mid = srt[len(ar) // 2]
        while len(ar) != 0:
            if ar[0] >= mid:
                move(f'p{stack}')
                if len(sec) + len(left) + len(right) != 0:
                    move(f'r{stack}')
                right.append(ar[0])
            else:
                left.insert(0, ar[0])
                move(f'p{stack}')
            del ar[0]
            __print(f'{left} : {right}')
        return [left, right]
    

    __debug('main sort')
    while True:
        done = True
        for it in ar:
            if len(it) > 3:
                done = False
                break
        if done:
            break
        for item in ar:
            if len(item) > 1:
                l, r = __qsort_req(item)
                sec.insert(0, l)
                sec.append(r)
            else:
                sec.append(item)
                move(f'p{stack}')
        __print(sec)
        ar, sec = sec, []
        stack, other = other, stack

    __debug('half swap')
    stack, other = other, stack

    __debug('    move top2 batches to second stack')
    for i in ar[-1]:
        # here we can also chose reverse or not
        move(f'rr{stack}')
        move(f'p{other}')
    sec.insert(0, ar[-1])
    del ar[-1]
    for i in ar[0]:
        move(f'p{other}')
    sec.insert(0, ar[0][::-1])
    del ar[0]
    __print(sec)
    __print(ar)

    __debug('    swap main loop')
    for i in range(len(ar) // 2):
        for i in ar[0]:
            move(f'r{stack}')
        ar.append(ar[0])
        del ar[0]
    __print(ar)

    __debug('    move last 2 batches to second stack')
    for i in ar[0]:
        move(f'p{other}')
    sec.insert(0, ar[0][::-1])
    del ar[0]
    for i in ar[-1]:
        # here we can also chose reverse or not
        move(f'rr{stack}')
        move(f'p{other}')
    sec.insert(0, ar[-1])
    del ar[-1]
    __print(ar)
    __print(sec)

    __debug('incorrect unpacking')
    stack, other = other, stack
    while len(ar) != 0:
        if min(ar[0]) < min(ar[-1]):
            batch = ar[0]
            del ar[0]
        else:
            batch = ar[-1]
            # we can rotate all at once -> this will reverse batch
            # or rotate and push by one number in batch -> it will not reverse
            #   batch
            # we can chose reverse or not depending on order of elements
            #   and use order that uses less operations in `sort3` function
            # and if batch size equals 2 we can use command `swap`, not double
            #   reverse
            for i in batch:
                move(f'rr{other}')
            del ar[-1]
        for i in batch:
            move(f'p{stack}')
        sec.insert(0, batch[::-1])
        __print(sec)
    __print(sec)

    stack, other = other, stack
    __debug('final merge')
    while len(sec) != 0:
        if max(sec[0]) > max(sec[-1]):
            batch = sec[0]
            del sec[0]
        else:
            batch = sec[-1]
            del sec[-1]
            for i in batch:
                move(f'rr{other}')
        sort(batch)
        ar = sorted(batch) + ar
        __print(ar)
    return moves, ar
    

def main(ar):
    ar = transform(list(map(int, ar)))
    ans, srt = quick_sort(ar)
    ans += ['pa'] * len(ar)


if __name__ == '__main__':
    main(sys.argv[1:])
