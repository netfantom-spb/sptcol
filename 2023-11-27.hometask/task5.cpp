#include <iostream>
#include <string>
#include <algorithm>
#include <locale>

bool isPalindrome(const std::wstring& word) {
    std::wstring reversedWord(word.rbegin(), word.rend());

    return word == reversedWord;
}

int main() {
    std::locale::global(std::locale(""));

    std::wstring inputWord;
    std::wcout << L"Введите слово: ";
    std::getline(std::wcin, inputWord);

    bool palindrome = isPalindrome(inputWord);

    if (palindrome) {
        std::wcout << L"Слово является палиндромом" << std::endl;
    } else {
        std::wcout << L"Слово НЕ является палиндромом" << std::endl;
    }

    return 0;
}
