#include <iostream>
#include <vector>

std::vector<std::vector<int>> addMatrices(const std::vector<std::vector<int>> &matrix1, const std::vector<std::vector<int>> &matrix2)
{
    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size())
    {
        std::cerr << "Невозможно сложить матрицы разного размера" << std::endl;
        return {};
    }

    std::vector<std::vector<int>> result(matrix1.size(), std::vector<int>(matrix1[0].size(), 0));

    for (size_t i = 0; i < matrix1.size(); ++i)
    {
        for (size_t j = 0; j < matrix1[0].size(); ++j)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

void printMatrix(const std::vector<std::vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int value : row)
        {
            std::cout << value << " | ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::vector<std::vector<int>> matrix1 = {{4, 22}, {8, 3}};
    std::vector<std::vector<int>> matrix2 = {{13, 5}, {2, 0}};

    std::cout << "Исходные матрицы:\n";
    std::cout << "Матрица 1:";
    printMatrix(matrix1);
    std::cout << "Матрица 2:";
    printMatrix(matrix2);

    std::vector<std::vector<int>> result = addMatrices(matrix1, matrix2);

    if (!result.empty())
    {
        std::cout << "\n\nСумма матриц:" << std::endl;
        printMatrix(result);
    }

    return 0;
}
