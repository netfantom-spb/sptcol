#include <iostream>
#include <cmath>

bool isPrime(int number)
{
    std::cout << std::endl
              << "Task 4" << std::endl;
              
    if (number <= 1)
    {
        return false; // Число 0 и 1 не являются простыми
    }

    if (number == 2)
    {
        return true; // Число 2 - простое
    }

    if (number % 2 == 0)
    {
        return false; // Четные числа больше 2 не являются простыми
    }

    for (int i = 3; i <= sqrt(number); i += 2)
    { // ограничиваем перебор до корня числа
        if (number % i == 0)
        {
            return false; // Если число делится без остатка, оно не является простым
        }
    }

    return true; // Если число не делится без остатка на другие числа, оно простое
}

int main()
{
    int number;

    std::cout << "Введите число: ";
    std::cin >> number;

    if (isPrime(number))
    {
        std::cout << "Да, число является простым." << std::endl;
    }
    else
    {
        std::cout << "Нет, число не является простым." << std::endl;
    }

    return 0;
}
