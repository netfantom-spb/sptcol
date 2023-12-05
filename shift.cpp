#include <iostream>

const int MAX_SIZE = 100;

void insertElement(int arr[], int& size, int k, int C) {
    if (size >= MAX_SIZE) {
        std::cout << "Превышен максимальный размер массива!" << std::endl;
        return;
    }

    // Сдвигаем элементы массива вправо, начиная с конца до индекса k
    for (int i = size; i > k; --i) {
        arr[i] = arr[i - 1];
    }

    // Вставляем элемент C на позицию k
    arr[k] = C;
    ++size; // Увеличиваем размер массива
}

int main() {
    int numbers[MAX_SIZE] = {1, 2, 3, 4, 5};
    int size = 5; 
    int k = 2; 
    int C = 10;

    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    insertElement(numbers, size, k, C);

    std::cout << "Результат С=" << C << ",k=" << k << ": ";
    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
