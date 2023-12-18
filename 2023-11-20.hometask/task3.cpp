#include <iostream>
#include <unordered_map>
#include <vector>

int countPairs(const std::vector<int> &arr)
{
    std::unordered_map<int, int> freq;

    // Подсчет количества одинаковых элементов
    // при этом условие "любые два элемента, равные друг другу образуют одну пару" мы считаем
    //  что нужно посчитать все комбинации пар, например, в последовательности "1 1 1" заложено 3 пары
    for (int num : arr)
    {
        freq[num]++;
    }

    int pairCount = 0;
    for (const auto &it : freq)
    {
        int count = it.second;
        pairCount += (count * (count - 1)) / 2; // Формула для подсчета числа сочетаний C_n^2
    }

    return pairCount;
}

int main()
{
    std::vector<int> numbers = {1, 2, 3, 2, 1, 4, 1, 3, 2};

    int pairs = countPairs(numbers);
    std::cout << "Количество пар элементов: " << pairs << std::endl;

    return 0;
}
