#include <iostream>

int main()
{
    std::cout << std::endl
              << "Task 2" << std::endl;

    int number, reversedNumber = 0;

    std::cout << "Введите число: ";
    std::cin >> number;

    // перебираем исходное число по разрядам и формируем число в обратном порядке
    while (number > 0)
    {
        int digit = number % 10;
        reversedNumber = reversedNumber * 10 + digit;
        number /= 10;
    }

    std::cout << "Число с цифрами в обратном порядке: " << reversedNumber << std::endl;

    return 0;
}
