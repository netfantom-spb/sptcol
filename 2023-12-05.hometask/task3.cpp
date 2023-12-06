#include <iostream>

bool isPrime(int number)
{
    if (number <= 1)
    {
        return false; // Число 1 и меньше не являются простыми
    }
    for (int i = 2; i * i <= number; ++i)
    {
        if (number % i == 0)
        {
            return false; // Если найден делитель, число не является простым
        }
    }
    return true; // Если делителей не найдено, число простое
}

int main()
{
    int test_number;
    std::cout << "Введите число для проверки: ";
    std::cin >> test_number;

    if (isPrime(test_number))
    {
        std::cout << test_number << " - простое число" << std::endl;
    }
    else
    {
        std::cout << test_number << " - НЕ простое число" << std::endl;
    }

    return 0;
}
