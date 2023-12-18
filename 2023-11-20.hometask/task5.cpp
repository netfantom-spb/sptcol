#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

// Функция для создания массива из n случайных чисел в диапазоне [0; 5]
std::vector<int> createRandomArray(int n)
{
    std::vector<int> arr;
    for (int i = 0; i < n; ++i)
    {
        arr.push_back(rand() % 6); // Генерация чисел от 0 до 5
    }
    return arr;
}

int main()
{
    srand(time(0)); // Установка seed для генератора случайных чисел

    // Создание двух массивов из 5 случайных чисел
    std::vector<int> array1 = createRandomArray(5);
    std::vector<int> array2 = createRandomArray(5);

    // Вывод двух массивов на экран
    std::cout << "Первый массив: ";
    for (int num : array1)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Второй массив: ";
    for (int num : array2)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Вычисление среднего арифметического для каждого массива
    double sum1 = 0, sum2 = 0;
    for (int num : array1)
    {
        sum1 += num;
    }
    double avg1 = sum1 / array1.size();

    for (int num : array2)
    {
        sum2 += num;
    }
    double avg2 = sum2 / array2.size();

    // Сравнение и вывод результата
    if (avg1 > avg2)
    {
        std::cout << "Среднее арифметическое первого массива больше" << std::endl;
    }
    else if (avg2 > avg1)
    {
        std::cout << "Среднее арифметическое второго массива больше" << std::endl;
    }
    else
    {
        std::cout << "Средние арифметические значений равны" << std::endl;
    }

    return 0;
}
