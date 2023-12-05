#include <iostream>

int main()
{
    std::cout << std::endl
              << "Task 3" << std::endl;

    int number, sum = 0;

    std::cout << "Введите число: ";
    std::cin >> number;

    // перебираем исходное число по разрядам и прибавялеми к результату
    while (number > 0)
    {
        int digit = number % 10;
        sum += digit;            
        number /= 10;            
    }

    std::cout << "Сумма цифр исходного числа: " << sum << std::endl;

    return 0;
}
