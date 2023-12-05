#include <iostream>

int main() {
    int hours1, minutes1, seconds1;
    int hours2, minutes2, seconds2;

    std::cout << "Введите часы, минуты и секунды для первого момента времени (ЧЧ ММ СС): ";
    std::cin >> hours1 >> minutes1 >> seconds1;

    std::cout << "Введите часы, минуты и секунды для второго момента времени (ЧЧ ММ СС): ";
    std::cin >> hours2 >> minutes2 >> seconds2;

    // Рассчитываем общее количество секунд для каждого момента времени
    int intBeginSeconds = hours1 * 3600 + minutes1 * 60 + seconds1;
    int intEndSeconds = hours2 * 3600 + minutes2 * 60 + seconds2;

    // Рассчитываем разницу в секундах между двумя моментами времени
    int diffSeconds = intEndSeconds - intBeginSeconds;

    std::cout << "Между моментами времени прошло " << diffSeconds << " секунд." << std::endl;

    return 0;
}
