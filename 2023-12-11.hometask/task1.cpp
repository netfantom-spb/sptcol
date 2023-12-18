#include <iostream>

class Shape
{
protected:
    double width;
    double height;

public:
    Shape(double width, double height) : width(width), height(height) {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
};

class Rectangle : public Shape
{
public:
    Rectangle(double width, double height) : Shape(width, height) {}

    double getArea() const override
    {
        return width * height;
    }

    double getPerimeter() const override
    {
        return 2 * (width + height);
    }
};

class Parallelogram : public Shape
{
public:
    Parallelogram(double width, double height) : Shape(width, height) {}

    double getArea() const override
    {
        return width * height;
    }

    double getPerimeter() const override
    {
        return 2 * (width + height);
    }
};

int main()
{
    Rectangle rect(5.0, 3.0);
    std::cout << "Прямоугольник: Площадь = " << rect.getArea() << ", Периметр = " << rect.getPerimeter() << std::endl;

    Parallelogram parallelogram(7.0, 4.0);
    std::cout << "Параллелограмм: Площадь = " << parallelogram.getArea() << ", Периметр = " << parallelogram.getPerimeter() << std::endl;

    return 0;
}
