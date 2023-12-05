#include <iostream>
#include <array>

// Проверка валидности месяц + день
bool isValidDate(int day, int month,int year) {
    std::cout << std::endl << "Task 4" << std::endl;
    
    // Если месяц выходит за границу 1-12 или делнь за границу 1-31 возвращаем что дата невалидная
    if (month < 1 || month > 12 || day < 1 || day > 31 || year < 0) {
        return false;
    }

    // Массив с числом дней в месяцах
    std::array<int, 12> daysCount = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    // Возвращаем True если указанный день меньше или равен количеству дней в месяце по календарю
    return daysCount[month-1] >= day;
   
}

int main() {
    std::cout << std::endl << "Task 5" << std::endl;

    int day, month, year;

    std::cout << "Введите день, месяц, год через пробел: ";
    std::cin >> day >> month >> year;

    if (isValidDate(day, month, year)) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }
    return 0;
}
