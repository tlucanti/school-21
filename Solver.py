
import gen
import random

class Solver():
    class NPuzzleError(RuntimeError):
        pass

    class Euristics():
        class Type():
            class INCORRECT(): pass
            class MANHATTAN(): pass
            class EUCLEDUAN(): pass

        class Scheduler():
            class FIRST_FIT(): pass
            class RANDOM(): pass
            class ROUND_ROBIN(): pass

    class Metrics():
        def __init__(self, answer_length):
            self.answer_length = answer_length

        def __str__(self):
            return f'answer_length: {self.answer_length}'

    def __init__(self, mat, solver):
        self.__solver = solver(mat)

    def solvable(self):
        return self.__solver.solvable()

    def target(self):
        return self.__solver.target

    def solve(self, euristic_type, euristic_sceduler):
        return self.__solver.solve(euristic_type, euristic_sceduler)

    def metrics(self):
        return self.__solver.metrics()


