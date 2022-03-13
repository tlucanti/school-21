# -*- coding: utf-8 -*-
# @Author: tlucanti
# @Date:   2022-03-07 18:04:01
# @Last Modified by:   tlucanti
# @Last Modified time: 2022-03-14 00:08:35

import sys
import numpy as np


def transform(array):
    table = {num: index for index, num in enumerate(sorted(array))}
    perm = [table[num] for num in array]
    return perm


def check(array, prog):
	s1 = transform(array)
	s2 = []
	srt = sorted(s1)
	if prog[-1] == '':
		del prog[-1]
	for i in prog:
		if i.startswith('DEBUG'):
			print()
			print(i)
			continue
		print(i)
		if i == 'sa':
			if len(s1) == 0:
				raise IndexError(f'{i}: There are no elements in stack A')
			elif len(s1) == 1:
				raise IndexError(f'{i}: There are only one element in stack A')
			s1[0], s1[1] = s1[1], s1[0]
		elif i == 'sb':
			if len(s2) == 0:
				raise IndexError(f'{i}: There are no elements in stack B')
			elif len(s2) == 1:
				raise IndexError(f'{i}: There are only one element in stack B')
			s2[0], s2[1] = s2[1], s2[0]
		elif i == 'pa':
			if len(s2) == 0:
				raise IndexError(f'{i}: There are no elements in stack B')
			s1.insert(0, s2[0])
			del s2[0]
		elif i == 'pb':
			if len(s1) == 0:
				raise IndexError(f'{i}: There are no elements in stack A')
			s2.insert(0, s1[0])
			del s1[0]
		elif i == 'ra':
			if len(s1) == 0:
				raise IndexError(f'{i}: There are no elements in stack A')
			elif len(s1) == 1:
				raise IndexError(f'{i}: There are only one element in stack A')
			s1.append(s1[0])
			del s1[0]
		elif i == 'rb':
			if len(s2) == 0:
				raise IndexError(f'{i}: There are no elements in stack B')
			elif len(s2) == 1:
				raise IndexError(f'{i}: There are only one element in stack B')
			s2.append(s2[0])
			del s2[0]
		elif i == 'rra':
			if len(s1) == 0:
				raise IndexError(f'{i}: There are no elements in stack A')
			elif len(s1) == 1:
				raise IndexError(f'{i}: There are only one element in stack A')
			s1.insert(0, s1[-1])
			del s1[-1]
		elif i == 'rrb':
			if len(s2) == 0:
				raise IndexError(f'{i}: There are no elements in stack B')
			elif len(s2) == 1:
				raise IndexError(f'{i}: There are only one element in stack B')
			s2.insert(0, s2[-1])
			del s2[-1]
		else:
			raise SyntaxError(f'command `{i}` is unknown')
		print('A :', np.array(s1))
		print('B :', np.array(s2))
		print('------------------------------- ', end='')

	if s1 != srt:
		print('KO')
		print(np.array(s1))
		print('!=')
		print(np.array(srt))
	else:
		print('OK')


def main():
	array = list(map(int, sys.argv[1:]))
	prog = sys.stdin.read().split('\n')
	check(array, prog)


if __name__ == '__main__':
	main()
