#include <iostream>
#include <string>

int main()
{
    std::string inputString;
    std::cout << "<<: ";
    std::getline(std::cin, inputString);

    if (inputString.compare(0, 3, "abc") == 0)
    {
        inputString.replace(0, 3, "www");
    }
    else
    {
        inputString += "zzz";
    }

    std::cout << ">>: " << inputString << std::endl;

    return 0;
}
