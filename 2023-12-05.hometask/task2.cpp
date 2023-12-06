#include <iostream>
#include <random>

int random_int(int fromInt, int toInt)
{
    std::random_device rd;                                                                       // Инициализация генератора случайных чисел
    std::mt19937 gen(rd());                                                                      // Используем Mersenne Twister для генерации случайных чисел
    std::uniform_int_distribution<> distrib(std::min(fromInt, toInt), std::max(fromInt, toInt)); // Определяем равномерное распределение в заданном диапазоне

    return distrib(gen); // Генерируем случайное число
}

int main()
{
    int fromInt, toInt;
    std::cout << "Введите начальное значение ";
    std::cin >> fromInt;
    std::cout << "Введите конечное значение: ";
    std::cin >> toInt;

    int random_number = random_int(fromInt, toInt);
    std::cout << "Случайное число в диапазоне от " << fromInt << " до " << toInt << ": " << random_number << std::endl;

    return 0;
}
