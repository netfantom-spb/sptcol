#include <iostream>
#include <string>

std::string reverseString(const std::string& text) {
    std::string reversedText;
    for (int i = text.length() - 1; i >= 0; --i) {
        reversedText += text[i];
    }
    return reversedText;
}

int main() {
    std::string inputText;

    std::cout << "Введите строку: ";
    std::getline(std::cin, inputText);

    std::string reversedText = reverseString(inputText);

    std::cout << "Фокус-покус: " << reversedText << std::endl;

    return 0;
}
