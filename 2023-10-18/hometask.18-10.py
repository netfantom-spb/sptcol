# =============Task 1======================================
class Film:
    def __init__(self, title, duration_minutes):
        self.title = title
        self.duration_minutes = duration_minutes

    def __len__(self):
        return self.duration_minutes
# =============Task 2======================================
class Vector:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):
        if isinstance(other, Vector):
            return Vector(self.x + other.x, self.y + other.y)
        else:
            raise ValueError("Нельзя сложить Vector с объектом другого типа")

    def __sub__(self, other):
        if isinstance(other, Vector):
            return Vector(self.x - other.x, self.y - other.y)
        else:
            raise ValueError("Нельзя вычесть Vector из объекта другого типа")

    def __str__(self):
        return f"({self.x}, {self.y})"


# =============Task 3======================================
class Matrix:
    def __init__(self, data):
        self.__data = data

    def __mul__(self, scalar):
        if isinstance(scalar, (int, float)):
            result_data = [[cell * scalar for cell in row] for row in self.__data]
            return Matrix(result_data)
        else:
            raise ValueError("Умножение матрицы допустимо только на число")

    def __str__(self):
        return "\n".join(["\t|\t ".join(map(str, row)) for row in self.__data])


if __name__ == "__main__":
    print(f"\n\n=============Task 1======================================")
    film = Film("Аватар", 162)
    print(f"Длительность фильма '{film.title}' в минутах: {len(film)}")

    print(f"\n\n=============Task 2======================================")
    vector1 = Vector(3, 4)
    vector2 = Vector(1, 2)

    sum_vector = vector1 + vector2
    print(f"Сумма векторов: {sum_vector}")

    diff_vector = vector1 - vector2
    print(f"Разность векторов: {diff_vector}")
        
    print(f"\n\n=============Task 3======================================")
    matrix_data = [[1, 2, 3, 10], [4, 5, 6, 20], [7, 8, 9, 30]]
    matrix = Matrix(matrix_data)

    print("Исходная матрица:")
    print(matrix)

    multiplier = 2
    result_matrix = matrix * multiplier
    print(f"\nРезультат умножения матрицы на {multiplier}:")
    print(result_matrix)
