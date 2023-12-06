#include <iostream>
#include <vector>

void primeFactors(int n)
{
    std::vector<int> factors;

    while (n % 2 == 0)
    {
        factors.push_back(2);
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }

    if (n > 2)
    {
        factors.push_back(n);
    }

    if (factors.size() == 1)
    {
        std::cout << "Число " << n << " - простое и имеет только один делитель: " << n << std::endl;
    }
    else
    {
        std::cout << "Простые делители числа " << n << " в порядке неубывания: ";
        for (int factor : factors)
        {
            std::cout << factor << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int testNumber;
    std::cout << "Введите число для поиска простых делителей: ";
    std::cin >> testNumber;

    primeFactors(testNumber);

    return 0;
}
