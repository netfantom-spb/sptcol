#include <iostream>

int main() {
    int number;

    std::cout << "Введите четырехзначное число: ";
    std::cin >> number;

    // Разбиваем число на отдельные цифры, если разрядов меньше чем 4, то в них будут нули
    int digit1 = number / 1000;
    int digit2 = (number / 100) % 10;
    int digit3 = (number / 10) % 10;
    int digit4 = number % 10;

    // для теста
    //std::cout << digit1 << digit2 << digit3 << digit4 << std::endl;

    // Проверяем симметричность
    int result = (digit1 == digit4 && digit2 == digit3) ? 1 : 0;

    std::cout << result << std::endl;

    return 0;
}
