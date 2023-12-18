#include <iostream>
#include <cmath>
#include <stdexcept>

class Circle
{
private:
    double radius;

public:
    Circle(double r)
    {
        if (r < 0)
        {
            throw std::invalid_argument("Радиус не может быть отрицательным");
        }
        radius = r;
    }

    double getRadius() const
    {
        return radius;
    }

    double getArea() const
    {
        return M_PI * radius * radius;
    }
};

int main()
{
    try
    {
        double radius;
        std::cout << "Введите радиус круга: ";
        std::cin >> radius;

        Circle circle(radius);
        std::cout << "Площадь круга с радиусом " << circle.getRadius() << " равна " << circle.getArea() << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
