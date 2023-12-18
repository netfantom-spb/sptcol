#include <iostream>
#include <string>

class User
{
protected:
    std::string name;
    std::string email;

public:
    User(const std::string &name, const std::string &email) : name(name), email(email) {}

    virtual void login() const
    {
        std::cout << "Пользователь вошел в систему: " << name << std::endl;
    }
};

class Administrator : public User
{
public:
    Administrator(const std::string &name, const std::string &email) : User(name, email) {}

    void login() const override
    {
        User::login();
        // что-то делаем при входе администратора
    }

    void adminFunction() const
    {
        std::cout << "Выполняем функцию только для администратора" << std::endl;
    }
};

class Guest : public User
{
public:
    Guest(const std::string &name, const std::string &email) : User(name, email) {}
};

int main()
{
    Administrator admin("Admin", "admin@test.com");
    admin.login();
    admin.adminFunction();

    Guest guest("Guest", "guest@test.com");
    guest.login();

    return 0;
}
