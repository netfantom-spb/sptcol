#include <iostream>
#include <string>

class Fruit
{
protected:
    std::string name;
    double price;

public:
    Fruit(const std::string &name, double price) : name(name), price(price) {}

    virtual double calculateCost(int quantity) const = 0;
};

class Apple : public Fruit
{
public:
    Apple(const std::string &name, double price) : Fruit(name, price) {}

    double calculateCost(int quantity) const override
    {
        return price * quantity;
    }
};

class Pear : public Fruit
{
public:
    Pear(const std::string &name, double price) : Fruit(name, price) {}

    double calculateCost(int quantity) const override
    {
        return price * quantity;
    }
};

int main()
{
    Apple apple("Яблоко", 2.5);
    Pear pear("Груша", 3.0);

    int quantity = 5;

    std::cout << "Стоимость " << quantity << " яблок: " << apple.calculateCost(quantity) << " рублей" << std::endl;
    std::cout << "Стоимость " << quantity << " груш: " << pear.calculateCost(quantity) << " рублей" << std::endl;

    return 0;
}
