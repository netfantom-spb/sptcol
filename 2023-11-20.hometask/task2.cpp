#include <iostream>
#include <vector>

int countUnique(const std::vector<int> &arr)
{
    if (arr.empty())
    {
        return 0;
    }

    int uniqueCount = 1; // Первый элемент всегда уникален

    for (size_t i = 1; i < arr.size(); ++i)
    {
        if (arr[i] != arr[i - 1])
        {
            ++uniqueCount;
        }
    }

    return uniqueCount;
}

int main()
{
    std::vector<int> numbers = {1, 1, 2, 2, 2, 3, 4, 4, 5, 5, 5, 9};

    int uniqueCount = countUnique(numbers);
    std::cout << "Количество различных элементов: " << uniqueCount << std::endl;

    return 0;
}
