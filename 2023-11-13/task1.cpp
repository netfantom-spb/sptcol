#include <iostream>
#include <vector>

int main() {
    std::cout << std::endl << "Task 1" << std::endl;

    std::vector<int> numbers(4);

    std::cout << "Введите четыре числа через пробел: ";
    for (int i = 0; i < 4; ++i) {
        std::cin >> numbers[i];
    }

    // Находим наибольшее четное число
    int maxEven = -1; // Изначально устанавливаем значение наибольшего четного числа на -1

    for (int i = 0; i < 4; ++i) {
        if (numbers[i] % 2 == 0 && numbers[i] > maxEven) {
            maxEven = numbers[i];
        }
    }

    if (maxEven != -1) {
        std::cout << "Наибольшее четное число: " << maxEven << std::endl;
    } else {
        std::cout << "not found" << std::endl;
    }

    return 0;
}
