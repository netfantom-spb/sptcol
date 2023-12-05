#include <iostream>

int main() {
    int lessonNumber;

    std::cout << "Введите номер урока (от 1 до 10): ";
    std::cin >> lessonNumber;

    // Рассчитываем время окончания урока
    // После каждого урока есть перемена минимум в 5 минут, а после каждого четного урока к перемене добавляем еще 10 минут
    // Перемены начинаем учитывать только начиная со второго урока
    int totalMinutes = 45 + (lessonNumber - 1) * (45 + 5) + ((lessonNumber - 1) / 2) * 10;

    // Рассчитываем часы и минуты
    int endHour = 9 + totalMinutes / 60;
    int endMinute = totalMinutes % 60;

    std::cout << "Урок номер " << lessonNumber << " заканчивается в " << endHour << ':' << endMinute << std::endl;

    return 0;
}
