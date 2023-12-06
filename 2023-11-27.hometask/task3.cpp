#include <iostream>
#include <string>

int findLastDotPosition(const std::string &text)
{
    size_t found = text.rfind('.');
    if (found != std::string::npos)
    {
        return static_cast<int>(found); // Преобразуем в int, чтобы вернуть позицию
    }
    return -1; // Если точка не найдена, возвращаем -1
}

int main()
{
    std::string inputText;

    std::cout << "Введите строку: ";
    std::getline(std::cin, inputText);

    int lastDotPosition = findLastDotPosition(inputText);
    if (lastDotPosition != -1)
    {
        std::cout << "Последняя '.' находится на позиции: " << lastDotPosition << std::endl;
    }
    else
    {
        std::cout << "'.' не найдена в тексте" << std::endl;
    }

    return 0;
}
