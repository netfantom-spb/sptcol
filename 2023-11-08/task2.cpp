#include <iostream>

int main() {
    int n;

    std::cout << "Введите количество минут: ";

    // Проверка на корректность ввода
    if (!(std::cin >> n)) {
        std::cerr << "Ошибка: введено не целое число." << std::endl;
        return 1; // Возвращаем код ошибки
    }

    // Рассчитываем количество часов и минут
    int hours = (n / 60) % 24;
    int minutes = n % 60;

    std::cout << "На электронных часах будет показываться: " << hours << ":" << minutes << std::endl;

    return 0;
}
