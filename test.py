
import npuzzle
import gen
import random

def test():
    for s in range(2, 10):
        for i in range(10):
            mat = gen.make_matrix_puzzle(s, True, i)
            solver = npuzzle.Astar(mat)
            print(*mat, sep='\n')
            print('target state')
            print(*solver.target, sep='\n')
            ans = solver.solve(solver.Euristics.Type.EUCLEDUAN, solver.Euristics.Scheduler.RANDOM)
            print('total states checked:', solver.iterations)
            print('answer length:', len(ans))
            print(ans)

            print()
            print()


if __name__ == '__main__':
    random.seed(1)
    test()
