#include <iostream>

int main() {
    int a, b, n;

    std::cout << "Введите стоимость пирожка в рублях и копейках (a b): ";
    std::cin >> a >> b;

    std::cout << "Введите количество пирожков (n): ";
    std::cin >> n;

    // Общая стоимость в копейках
    int totalCoins = (a * 100 + b) * n;

    // Рассчитываем рубли и копейки после покупки
    int amountRubles = totalCoins / 100;
    int amountCoins = totalCoins % 100;

    std::cout << "Общая стоимость: " << amountRubles << " рублей " << amountCoins << " копеек." << std::endl;

    return 0;
}
