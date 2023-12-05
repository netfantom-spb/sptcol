#include <iostream>
#include <string>

void cleanXBeforeABC(std::string &str)
{
    size_t pos = 0;
    while ((pos = str.find("xabc", pos)) != std::string::npos)
    {
        str.erase(pos, 1); // Удаляем 'x' из строки
        pos += 3;          // Переходим к следующему блоку 'abc'
    }
}

int main()
{
    std::string inputString;
    std::cout << "Введите строку: ";
    std::getline(std::cin, inputString);

    cleanXBeforeABC(inputString);

    std::cout << "Результат: " << inputString << std::endl;

    return 0;
}
