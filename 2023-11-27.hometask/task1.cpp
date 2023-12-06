#include <iostream>
#include <string>

int countCharInString(const std::string &text, char target)
{
    int count = 0;
    for (char ch : text)
    {
        if (ch == target)
        {
            ++count;
        }
    }
    return count;
}

int main()
{
    std::string inputText;
    char targetChar;

    std::cout << "Введите текст: ";
    std::getline(std::cin, inputText);

    std::cout << "Введите символ для поиска: ";
    std::cin >> targetChar;

    int occurrences = countCharInString(inputText, targetChar);
    std::cout << "Символ '" << targetChar << "' встречается " << occurrences << " раз(a)" << std::endl;

    return 0;
}
