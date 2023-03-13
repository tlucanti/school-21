import Solver
import AstarSolver

def inp():
    return list(map(int, input().split()))

def input_mat():
    mat = []
    mat.append(inp())
    for i in range(len(mat[0]) - 1):
        mat.append(inp())
        if len(mat[-1]) != len(mat[0]):
            raise ValueError('invalid board')
    return mat

def main():
    print('>>>')
    mat = input_mat()
    astar = Solver(mat, AstarSolver)
    actions = astar.solve()
    print(astar.metrics())
    print(actions)

if __name__ == '__main__':
    main()
