#include <iostream>

int main()
{
    std::cout << std::endl
              << "Task 5" << std::endl;

    int number, firstMax, secondMax;

    std::cout << "Введите числа (0 для завершения ввода):" << std::endl;

    std::cin >> number; // Считываем первое число
    firstMax = number;  // Первое число сразу становится наибольшим
    std::cin >> number; // Считываем второе число

    // Определяем первые два числа как наибольшие и вторые по величине
    if (number > firstMax)
    {
        secondMax = firstMax;
        firstMax = number;
    }
    else
    {
        secondMax = number;
    }

    // Считываем остальные числа и обновляем первое и второе по величине, если необходимо
    while (std::cin >> number && number != 0)
    {
        if (number > firstMax)
        {
            secondMax = firstMax;
            firstMax = number;
        }
        else if (number > secondMax)
        {
            secondMax = number;
        }
    }

    std::cout << "Второе по величине число: " << secondMax << std::endl;

    return 0;
}
