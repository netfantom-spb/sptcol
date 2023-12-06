#include <iostream>
#include <string>

int countSubstr(const std::string &str, const std::string &substr)
{
    if (substr.length() == 0)
    {
        return 0; // Если подстрока пустая, возвращаем 0 вхождений
    }

    int count = 0;
    size_t pos = 0;
    while ((pos = str.find(substr, pos)) != std::string::npos)
    {
        ++count;
        pos += substr.length();
    }
    return count;
}

int main()
{
    std::string inputString;
    std::cout << "Введите строку: ";
    std::getline(std::cin, inputString);

    std::string substring = "aba";
    int result = countSubstr(inputString, substring);

    std::cout << "Количество вхождений 'aba': " << result << std::endl;

    return 0;
}
