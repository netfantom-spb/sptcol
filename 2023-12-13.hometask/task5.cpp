#include <iostream>
#include <cmath>
#include <stdexcept>

double calculateSquareRoot(double num)
{
    if (num < 0)
    {
        throw std::out_of_range("Квадратный корень из отрицательного числа - это уже высшая математика");
    }

    return sqrt(num);
}

int main()
{
    try
    {
        double number;
        std::cout << "Введите число для вычисления квадратного корня: ";
        std::cin >> number;

        double result = calculateSquareRoot(number);
        std::cout << "Квадратный корень числа " << number << " равен " << result << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
