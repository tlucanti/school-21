# -*- coding: utf-8 -*-
# @Author: tlucanti
# @Date:   2022-03-13 22:21:40
# @Last Modified by:   tlucanti
# @Last Modified time: 2022-03-13 22:25:39

import checker
import push_swap
import sys


def main(array):
	moves, srt = push_swap.quick_sort(array)
	checker.check(array, moves)


if __name__ == '__main__':
	main(list(map(int, sys.argv[1:])))
