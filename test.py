
from Solver import Solver
from AstarSolver import AstarSolver
import gen
import random
import numpy as np

def test():
    for s in range(2, 10):
        for i in range(100):
            mat = gen.gen_target(s)
            gen.shuffle(mat, i)
            solver = Solver(mat, AstarSolver)
            print(np.array(mat))
            print('expected actions:', i)
            print('target state')
            print(np.array(solver.target()))
            ans = solver.solve(Solver.Euristics.Type.EUCLEDUAN,
                               Solver.Euristics.Scheduler.RANDOM)
            print(solver.metrics())
            print(ans)

            print()
            print()


if __name__ == '__main__':
    random.seed(1)
    test()
