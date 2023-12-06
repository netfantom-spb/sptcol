#include <iostream>
#include <cctype> // isdigit
#include <string>

int countDigits(const std::string &str)
{
    int count = 0;
    for (char ch : str)
    {
        if (std::isdigit(ch))
        {
            ++count;
        }
    }
    return count;
}

int main()
{
    std::string inputString;
    std::cout << "Введите строку: ";
    std::getline(std::cin, inputString);

    int result = countDigits(inputString);
    std::cout << "Цифр в строке: " << result << std::endl;

    return 0;
}
