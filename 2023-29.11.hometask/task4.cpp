#include <iostream>
#include <cctype>
#include <string>

int sumOfDigits(const std::string &str)
{
    int sum = 0;
    for (char ch : str)
    {
        if (std::isdigit(ch))
        {
            // символы 0-9 расположены в ASCII таблице подряд
            sum += (ch - '0'); // Преобразование символа в цифру и добавление к сумме
        }
    }
    return sum;
}

int main()
{
    std::string inputText;
    std::cout << "Введите текст: ";
    std::getline(std::cin, inputText);

    int totalSum = sumOfDigits(inputText);
    std::cout << "Сумма цифр в тексте: " << totalSum << std::endl;

    return 0;
}
