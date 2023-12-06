#include <iostream>
#include <algorithm>

int sumRange(int start, int end)
{
    int sum = 0;
    for (int i = std::min(start, end); i <= std::max(start, end); ++i)
    {
        sum += i;
    }
    return sum;
}

int main()
{
    int fromInt, toInt;
    std::cout << "Введите начальное значение ";
    std::cin >> fromInt;
    std::cout << "Введите конечное значение: ";
    std::cin >> toInt;

    int result = sumRange(fromInt, toInt);
    std::cout << "Сумма чисел в диапазоне от " << fromInt << " до " << toInt << ": " << result << std::endl;

    return 0;
}
