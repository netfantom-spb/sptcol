#include <iostream>
#include <string>

class Book
{
private:
    std::string title;
    std::string author;
    int year;
    int pagesCount;

public:
    // Конструктор по умолчанию
    Book() : year(0), pagesCount(0), title("Новая книга"), author("неизвестный автор") {}

    // Параметрический конструктор
    Book(const std::string &title, const std::string &author, int year, int pageCount)
        : title(title), author(author), year(year), pagesCount(pageCount) {}

    // Методы доступа (геттеры и сеттеры)
    std::string getTitle() const
    {
        return title;
    }

    void setTitle(const std::string &title)
    {
        this->title = title;
    }

    std::string getAuthor() const
    {
        return author;
    }

    void setAuthor(const std::string &author)
    {
        this->author = author;
    }

    int getYear() const
    {
        return year;
    }

    void setYear(int year)
    {
        this->year = year;
    }

    int getPageCount() const
    {
        return pagesCount;
    }

    void setPageCount(int pageCount)
    {
        this->pagesCount = pageCount;
    }
};

int main()
{
    Book book1;
    std::cout << "Книга 1: " << book1.getTitle() << ", " << book1.getAuthor() << ", " << book1.getYear() << ", " << book1.getPageCount() << " страниц" << std::endl;

    Book book2("Книга обо всем на свете", "Зазнайка З.З.", 2023, 3000);
    std::cout << "Книга 2: " << book2.getTitle() << ", " << book2.getAuthor() << ", " << book2.getYear() << ", " << book2.getPageCount() << " страниц" << std::endl;

    return 0;
}
