#include <iostream>
#include <vector>

void replacePlusWithDash(std::vector<std::string> &text)
{
    char target = '+';
    char replacement = '-';
    
    for (std::string &line : text)
    {
        size_t found = line.find(target);
        while (found != std::string::npos)
        {
            line[found] = replacement;
            found = line.find(target, found + 1);
        }
    }
}

int main()
{
    std::vector<std::string> text = {
        "Первая строка с символом +",
        "Во второй строке + в середине",
        "+Третья строка с символом в начале",
        "+И четвертая + строка+",
    };

    replacePlusWithDash(text);

    for (const std::string &line : text)
    {
        std::cout << line << std::endl;
    }

    return 0;
}
