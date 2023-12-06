#include <iostream>
#include <cmath>

int main() {
    int n, m;

    std::cout << "Введите км/дн для машины (n) и длину маршрута в км (m): ";
    std::cin >> n >> m;

    // Результат в днях округляем вверх
    int days = static_cast<int>(std::ceil(static_cast<double>(m) / n));

    std::cout << "Для проезда маршрута длиной " << m << " км машина потребуется " << days << " дней." << std::endl;

    return 0;
}
