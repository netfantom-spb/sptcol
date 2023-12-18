#include <iostream>
#include <vector>
#include <unordered_map>

void printUniqueElements(const std::vector<int> &arr)
{
    std::unordered_map<int, int> freq;

    // Подсчет частоты вхождений каждого элемента
    for (int num : arr)
    {
        freq[num]++;
    }

    // Вывод элементов, встречающихся только один раз
    for (int num : arr)
    {
        if (freq[num] == 1)
        {
            std::cout << num << " ";
            freq[num] = -1; // Помечаем элемент, чтобы не выводить его снова (если он повторится)
        }
    }
}

int main()
{
    std::vector<int> numbers = {1, 2, 3, 2, 1, 4, 5, 6, 7, 5, 0};

    std::cout << "Элементы, встречающиеся только один раз: ";
    printUniqueElements(numbers);
    std::cout << std::endl;

    return 0;
}
