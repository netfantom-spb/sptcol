#include <iostream>

class Rectangle
{
private:
    double length;
    double width;

public:
    // Конструктор по умолчанию
    Rectangle() : length(0.0), width(0.0) {}

    // Параметрический конструктор
    Rectangle(double length, double width) : length(length), width(width) {}

    // Методы доступа (геттеры и сеттеры)
    double getLength() const
    {
        return length;
    }

    void setLength(double length)
    {
        this->length = length;
    }

    double getWidth() const
    {
        return width;
    }

    void setWidth(double width)
    {
        this->width = width;
    }

    // Вычисление периметра
    double getPerimeter() const
    {
        return 2 * (length + width);
    }

    // Вычисление площади
    double getArea() const
    {
        return length * width;
    }
};

int main()
{
    Rectangle rect1;
    rect1.setLength(5.0);
    rect1.setWidth(3.0);
    std::cout << "Прямоугольник 1: Длина = " << rect1.getLength() << ", Ширина = " << rect1.getWidth() << ", Периметр = " << rect1.getPerimeter() << ", Площадь = " << rect1.getArea() << std::endl;

    Rectangle rect2(7.0, 4.0);
    std::cout << "Прямоугольник 2: Длина = " << rect2.getLength() << ", Ширина = " << rect2.getWidth() << ", Периметр = " << rect2.getPerimeter() << ", Площадь = " << rect2.getArea() << std::endl;

    return 0;
}
