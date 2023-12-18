#include <iostream>
#include <vector>

int main()
{
    int size;
    std::cout << "Введите количество элементов массива: ";
    std::cin >> size;

    try
    {
        if (size <= 0)
        {
            throw std::out_of_range("Размер массива должен быть положительным числом");
        }

        std::vector<int> arr(size);
        std::cout << "Введите значения элементов массива:\n";

        for (int i = 0; i < size; ++i)
        {
            std::cin >> arr[i];
        }

        std::cout << "Массив: ";
        for (int i = 0; i < size; ++i)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        int index;
        std::cout << "Введите индекс элемента для доступа: ";
        std::cin >> index;

        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Индекс находится за пределами массива");
        }

        std::cout << "Элемент по индексу " << index << ": " << arr[index] << std::endl;
    }
    catch (const std::out_of_range &ex)
    {
        std::cerr << "Ошибка: " << ex.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Произошла неизвестная ошибка" << std::endl;
    }

    return 0;
}
