#include <iostream>
#include <climits>

int main() {
    const int size = 6; 
    int arr[size];
  
    std::cout << "Введите " << size << " элементов массива:\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    int minIndex = 0, maxIndex = 0;
    
    // поиск mix и max
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }

    // меняем местами
    std::swap(arr[minIndex], arr[maxIndex]);


    std::cout << "Новый массив:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
