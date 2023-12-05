#include <iostream>
#include <algorithm>

int main() {
    std::cout << std::endl  << "Task 3" << std::endl;

    int number;

    std::cout << "Введите четырехзначное число: ";
    std::cin >> number;

    if (number >= 1000 && number <= 9999) {
        int digits[4];
        
        // Заполняем массив цифрами из числа
        for (int i = 3; i >= 0; --i) {
            digits[i] = number % 10;
            number /= 10;
        }

        // Находим наибольшую и наименьшую цифры
        auto maxDigit = std::max_element(std::begin(digits), std::end(digits));
        auto minDigit = std::min_element(std::begin(digits), std::end(digits));

        // Меняем местами наибольшую и наименьшую цифры
        std::swap(*maxDigit, *minDigit);

        // Формируем число из цифр и выводим результат
        int swappedNumber = digits[0] * 1000 + digits[1] * 100 + digits[2] * 10 + digits[3];
        std::cout << "Число после замены наименьшей и наибольшей цифр: " << swappedNumber << std::endl;
    } else {
        std::cout << "Число не является четырехзначным." << std::endl;
    }

    return 0;
}
