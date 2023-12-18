#include <iostream>
#include <string>

class Transport
{
protected:
    std::string brand;
    int year;

public:
    Transport(const std::string &brand, int year) : brand(brand), year(year) {}

    virtual void move() const
    {
        std::cout << "Транспортное средство движется" << std::endl;
    }
};

class Car : public Transport
{
public:
    Car(const std::string &brand, int year) : Transport(brand, year) {}

    void move() const override
    {
        std::cout << "Еду по дороге" << std::endl;
    }
};

class Bicycle : public Transport
{
public:
    Bicycle(const std::string &brand, int year) : Transport(brand, year) {}

    void move() const override
    {
        std::cout << "Еду по велодорожке" << std::endl;
    }
};

int main()
{
    Car car("Great Wall", 2023);
    std::cout << "Машина:";
    car.move();

    Bicycle bike("Trek", 2022);
    std::cout << "Велосипед:";
    bike.move();

    return 0;
}
