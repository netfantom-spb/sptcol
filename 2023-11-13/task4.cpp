#include <iostream>
#include <array>

int main() {
    std::cout << std::endl << "Task 4" << std::endl;

    std::array<std::string, 4> seasons = {"Зима", "Весна", "Лето", "Осень"};

    int month;
    std::cout << "Введите номер месяца (от 1 до 12): ";
    std::cin >> month;

    if (month >= 1 && month <= 12) {
        int seasonIndex = (month % 12) / 3; // Ответ на вопрос - индекс месяца в масиве
        std::cout << "Пора года: " << seasons[seasonIndex] << std::endl;
    } else {
        std::cout << "Некорректный номер месяца." << std::endl;
    }

    return 0;
}
