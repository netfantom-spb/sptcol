#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

int main()
{
    std::vector<int> array;
    srand(time(0)); // Инициализация генератора случайных чисел

    // Заполнение массива из 11 случайных чисел в диапазоне [-1; 1] и вывод на экран
    std::cout << "Массив: ";
    for (int i = 0; i < 11; ++i)
    {
        int num = rand() % 3 - 1; // Генерация чисел [-1; 1]
        array.push_back(num);
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Подсчет количества вхождений каждого числа
    std::unordered_map<int, int> frequency;
    for (int num : array)
    {
        frequency[num]++;
    }

    // Нахождение числа, встречающегося чаще всего
    int mostCommon = 0;
    bool isAmbiguous = false;
    for (auto &pair : frequency)
    {
        if (pair.second > frequency[mostCommon])
        {
            mostCommon = pair.first;
            isAmbiguous = false;
        }
        else if (pair.second == frequency[mostCommon])
        {
            isAmbiguous = true;
        }
    }

    // Вывод результата
    if (!isAmbiguous && mostCommon != 0)
    {
        std::cout << "Число " << mostCommon << " встречается чаще всего (" << frequency[mostCommon] << " раз(a))" << std::endl;
    }
    else
    {
        std::cout << "Нет однозначно наиболее частого числа" << std::endl;
    }

    return 0;
}
