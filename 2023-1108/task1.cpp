#include <iostream>

int main() {
    int n;

    std::cout << "Введите натуральное число: ";
    if (!(std::cin >> n)) {
        std::cerr << "Ошибка: введено не целое число." << std::endl;
        return 1; // Возвращаем код ошибки
    }

    // Находим следующее четное число
    int nextEven = n + 2 - n % 2;

    std::cout << "Следующее четное число: " << nextEven << std::endl;

    return 0;
}