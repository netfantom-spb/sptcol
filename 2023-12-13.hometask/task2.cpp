#include <iostream>
#include <vector>
#include <stdexcept>

class Matrix {
private:
    std::vector<std::vector<int>> data;

public:
    Matrix(std::vector<std::vector<int>> initialData) : data(initialData) {}

    int getRows() const {
        return data.size();
    }

    int getColumns() const {
        if (data.empty()) {
            return 0;
        }
        return data[0].size();
    }

    std::vector<int>& operator[](int index) {
        return data[index];
    }

    Matrix operator*(const Matrix& other) const {
        int rows1 = getRows();
        int cols1 = getColumns();
        int rows2 = other.getRows();
        int cols2 = other.getColumns();

        if (cols1 != rows2) {
            throw std::invalid_argument("Умножение невозможно: количество столбцов первой матрицы не равно количеству строк второй матрицы");
        }

        Matrix result(std::vector<std::vector<int>>(rows1, std::vector<int>(cols2, 0)));

        for (int i = 0; i < rows1; ++i) {
            for (int j = 0; j < cols2; ++j) {
                for (int k = 0; k < cols1; ++k) {
                    result[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }
};

int main() {
    Matrix matrix1({{1, 2, 4}, {3, 4, 5}, {3,5, 9}});
    Matrix matrix2({{1, 0}, {0, 1}});

    try {
        Matrix result = matrix1 * matrix2;
        std::cout << "Результат умножения матриц:" << std::endl;
        for (int i = 0; i < result.getRows(); ++i) {
            for (int j = 0; j < result.getColumns(); ++j) {
                std::cout << result[i][j] << " ";
            }
            std::cout << std::endl;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
