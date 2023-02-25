
import npuzzle
import gen

for s in range(2, 10):
    for i in range(100):
        mat = gen.make_matrix_puzzle(s, True, i)
        print(*mat, sep='\n')
        solver = npuzzle.Astar(mat)
        ans = solver.solve()
        print('total states checked:', solver.iterations)
        print('answer length:', len(ans))
        print(ans)

        print()
        print()



