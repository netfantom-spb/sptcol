#include <iostream>
#include <string>

class Car
{
private:
    std::string brand;
    std::string model;
    int year;
    std::string color;

public:
    // Конструктор по умолчанию с инициализацией полей
    Car() : brand("Unknown"), model("Unknown"), year(0), color("Unknown") {}

    // Параметрический конструктор
    Car(const std::string &brand, const std::string &model, int year, const std::string &color)
        : brand(brand), model(model), year(year), color(color) {}

    // Методы доступа (геттеры и сеттеры)
    std::string getBrand() const
    {
        return brand;
    }

    void setBrand(const std::string &brand)
    {
        this->brand = brand;
    }

    std::string getModel() const
    {
        return model;
    }

    void setModel(const std::string &model)
    {
        this->model = model;
    }

    int getYear() const
    {
        return year;
    }

    void setYear(int year)
    {
        this->year = year;
    }

    std::string getColor() const
    {
        return color;
    }

    void setColor(const std::string &color)
    {
        this->color = color;
    }
};

int main()
{
    Car car1;
    std::cout << "Машина 1: " << car1.getBrand() << " " << car1.getModel() << ", " << car1.getYear() << ", цвет: " << car1.getColor() << std::endl;

    Car car2("BMW", "X5", 2023, "черный");
    std::cout << "Машина 2: " << car2.getBrand() << " " << car2.getModel() << ", " << car2.getYear() << ", цвет: " << car2.getColor() << std::endl;

    return 0;
}
