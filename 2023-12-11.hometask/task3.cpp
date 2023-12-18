#include <iostream>
#include <string>

class Medicine
{
protected:
    std::string name;

public:
    Medicine(const std::string &name) : name(name) {}

    virtual void apply() const = 0;
};

class Antibiotic : public Medicine
{
public:
    Antibiotic(const std::string &name) : Medicine(name) {}

    void apply() const override
    {
        std::cout << "Принимаем антибиотик:" << name << std::endl;
    }
};

class Analgesic : public Medicine
{
public:
    Analgesic(const std::string &name) : Medicine(name) {}

    void apply() const override
    {
        std::cout << "Принимаем анальгетик:" << name << std::endl;
    }
};

int main()
{
    Antibiotic antibiotic("Аугментин");
    antibiotic.apply();

    Analgesic analgesic("Нурофен");
    analgesic.apply();

    return 0;
}
