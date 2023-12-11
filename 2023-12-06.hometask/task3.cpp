#include <iostream>

class Rectangle
{
private:
    double length;
    double width;
    double perimeter;
    double area;

public:
    // Конструктор по умолчанию
    Rectangle() : length(0.0), width(0.0), perimeter(0.0), area(0.0) {}

    // Параметрический конструктор
    Rectangle(double length, double width)
        : length(length), width(width), perimeter(2 * (length + width)), area(length * width) {}

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

    double getPerimeter() const
    {
        return perimeter;
    }

    void setPerimeter(double perimeter)
    {
        this->perimeter = perimeter;
    }

    double getArea() const
    {
        return area;
    }

    void setArea(double area)
    {
        this->area = area;
    }
};

int main()
{
    Rectangle rect1;
    std::cout << "Прямоугольник 1: Длина = " << rect1.getLength() << ", Ширина = " << rect1.getWidth() << ", Периметр = " << rect1.getPerimeter() << ", Площадь = " << rect1.getArea() << std::endl;

    Rectangle rect2(5.0, 3.0);
    std::cout << "Прямоугольник 2: Длина = " << rect2.getLength() << ", Ширина = " << rect2.getWidth() << ", Периметр = " << rect2.getPerimeter() << ", Площадь = " << rect2.getArea() << std::endl;

    return 0;
}
