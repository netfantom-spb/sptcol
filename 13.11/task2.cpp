#include <iostream>

int main() {
    std::cout << std::endl  << "Task 2" << std::endl;

    int number;

    std::cout << "Введите четырехзначное число: ";
    std::cin >> number;

    if (number >= 1000 && number <= 9999) {
        // Разбиваем число на отдельные цифры
        int thousands = number / 1000;
        int hundreds = (number / 100) % 10;
        int tens = (number / 10) % 10;
        int units = number % 10;

        // Проверяем, идут ли цифры в убывающем порядке
        bool isDecreasing = (thousands > hundreds) && (hundreds > tens) && (tens > units);

        // Выводим результат
        if (isDecreasing) {
            std::cout << "Цифры идут в убывающем порядке." << std::endl;
        } else {
            std::cout << "Цифры не идут в убывающем порядке." << std::endl;
        }
    } else {
        std::cout << "Число не является четырехзначным." << std::endl;
    }

    return 0;
}
