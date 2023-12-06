#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <random>

const std::string chars = "abcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+"; // допустимые символы для пароля
const std::string marker = "syc"; // маркер

// Генерация пароля заданной длины
std::string generatePassword(int length)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, chars.size() - 1);

    std::string password;
    for (int i = 0; i < length; ++i)
    {
        password += chars[distribution(gen)];
    }

    return marker + password;
}

// Проверка что строка состоит только из разрешенных символов
bool containsOnlyAllowedChars(const std::string &password, const std::string &allowedChars)
{
    for (char ch : password)
    {
        if (allowedChars.find(ch) == std::string::npos)
        {
            return false; // Если символ не найден в разрешенных символах, возвращаем false
        }
    }
    return true; // Если все символы из пароля найдены в разрешенных, возвращаем true
}

// Проверка что пароль сгенерирован алгоритмом
bool isPasswordGeneratedByAlgorithm(const std::string &password)
{
    return password.find(marker) == 0 && containsOnlyAllowedChars(password, chars);
}

int main()
{
    int passwordLength = 10; // Длина пароля
    std::string password = generatePassword(passwordLength);

    std::cout << "Сгенерированный пароль: " << password << std::endl;

    if (isPasswordGeneratedByAlgorithm(password))
    {
        std::cout << "Пароль сгенерирован алгоритмом" << std::endl;
    }
    else
    {
        std::cout << "Пароль НЕ сгенерирован алгоритмом" << std::endl;
    }

    // "Испортим" пароль
    std::string wrongPassord = password + "BCA";
    std::cout << """Испорченный"" пароль: " << wrongPassord << std::endl;
    if (isPasswordGeneratedByAlgorithm(wrongPassord))
    {
        std::cout << "Пароль сгенерирован алгоритмом" << std::endl;
    }
    else
    {
        std::cout << "Пароль НЕ сгенерирован алгоритмом" << std::endl;
    }

    return 0;
}
