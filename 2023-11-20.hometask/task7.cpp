#include <iostream>
#include <vector>

void insertElement(std::vector<int> &array, int k, int C)
{
    array.push_back(0); // Добавляем временный элемент в конец массива
    for (int i = array.size() - 1; i > k; --i)
    {
        array[i] = array[i - 1]; // Сдвигаем элементы массива справа от k на одну позицию вправо
    }
    array[k] = C; // Вставляем новый элемент на позицию k
}

void print_array(std::vector<int> &array)
{
    for (int num : array)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> array = {1, 2, 3, 4, 5}; // Пример массива
    int k = 2;                                // Индекс, на котором нужно вставить элемент
    int C = 10;                               // Значение элемента, который нужно вставить

    std::cout << "Исходный массив: ";
    print_array(array);
    std::cout << "Вставляем значение " << C << " в позицию " << k + 1 << std::endl;

    insertElement(array, k, C);
    std::cout << "Измененный массив: ";
    print_array(array);

    return 0;
}
