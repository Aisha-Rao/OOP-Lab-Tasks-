#include <iostream>
#include <string>

class Books {
protected:
    std::string genre;

public:
    Books(const std::string& genre) : genre(genre) {}

    virtual void displayDetails() const = 0;

    virtual ~Books() {}
};

class Novel : public Books {
private:
    std::string title;
    std::string author;

public:
    Novel(const std::string& title, const std::string& author)
        : Books("Novel"), title(title), author(author) {}

    void displayDetails() const override {
        std::cout << "Genre: " << genre << "\nTitle: " << title << "\nAuthor: " << author << std::endl;
    }
};

class Mystery : public Books {
private:
    std::string title;
    std::string author;

public:
    Mystery(const std::string& title, const std::string& author)
        : Books("Mystery"), title(title), author(author) {}

    void displayDetails() const override {
        std::cout << "Genre: " << genre << "\nTitle: " << title << "\nAuthor: " << author << std::endl;
    }
};

int main() {
    Novel novel("To Kill a Mockingbird", "Harper Lee");
    Mystery mystery("The Da Vinci Code", "Dan Brown");

    Books* book1 = &novel;
    Books* book2 = &mystery;

    book1->displayDetails();
    std::cout << std::endl;
    book2->displayDetails();

    return 0;
}

