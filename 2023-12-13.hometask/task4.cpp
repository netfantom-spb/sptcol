#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>

int readInt()
{
    int num;
    std::string line;

    std::cout << "Введите целое число: ";
    std::getline(std::cin, line); // Считываем всю строку, а не только целое число в начале

    std::istringstream stream(line);
    if (!(stream >> num) || !stream.eof())
    {
        throw std::invalid_argument("Некорректный ввод.");
    }

    return num;
}

int main()
{
    try
    {
        int number = readInt();
        std::cout << "Вы ввели число: " << number << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
