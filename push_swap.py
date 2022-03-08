# -*- coding: utf-8 -*-
# @Author: tlucanti
# @Date:   2022-03-07 16:25:48
# @Last Modified by:   tlucanti
# @Last Modified time: 2022-03-07 22:10:02

import sys
import numpy as np


def inp():
    return list(map(int, input().split()))


def presort(ar, wind):
    ar = ar.copy()
    sec = []
    moves = []
    while len(ar) != 0:
        if ar[0] <= wind:
            sec.insert(0, ar[0])
            del ar[0]
            wind += 1
            moves.append('pb')
        else:
            ar.append(ar[0])
            del ar[0]
            moves.append('ra')
    return moves, sec


def sort(ar):
    ar = ar.copy()
    srt = sorted(ar)[::-1]
    moves = []
    cnt = 0
    i = 0
    while True:
        if srt == ar:
            break
        elif ar[0] == srt[-1] and ar[1] == srt[0]:
            ar.append(ar[0])
            del ar[0]
            moves.append('rb')
            break
        # print(cnt, ar)
        # i += 1
        # if i == 500:
        #     break
        if ar[0] < ar[1]:
            ar[0], ar[1] = ar[1], ar[0]
            moves.append('sb')
            if cnt > 0:
                cnt -= 1
                ar.insert(0, ar[-1])
                del ar[-1]
                moves.append('rrb')
        else:
            ar.append(ar[0])
            del ar[0]
            cnt += 1
            moves.append('rb')
    # print(*ar)
    return moves, ar


def transform(array):
    table = {num: index for index, num in enumerate(sorted(array))}
    perm = [table[num] for num in array]
    return perm


def main(ar):
    ar = transform(list(map(int, ar)))
    wind = min(max(len(ar) // 10, 1), 10)
    stage1, ar = presort(ar, 10)
    stage2, ar = presort(ar, 5)
    stage3, ar = presort(ar, 0)
    # stage3, ar = sort(ar)
    ans = stage1 + stage2 + stage3 + ['pa'] * len(ar)
    print(*ans, sep='\n')


if __name__ == '__main__':
    main(sys.argv[1:])
