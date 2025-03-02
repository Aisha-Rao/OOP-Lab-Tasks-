#include <iostream>
#include <memory>
#include <unordered_map>

class Book {
private:
    std::string title;
    std::string isbn;

public:
    Book(std::string title, std::string isbn) : title(title), isbn(isbn) {
        std::cout << "Book '" << title << "' (ISBN: " << isbn << ") created." << std::endl;
    }
    ~Book() {
        std::cout << "Book '" << title << "' (ISBN: " << isbn << ") destroyed." << std::endl;
    }
    
    std::string getTitle() const { return title; }
    std::string getISBN() const { return isbn; }
};

class Catalog {
private:
    std::unordered_map<std::string, Book*> bookIndex;

public:
    void addBook(Book* book) {
        bookIndex[book->getISBN()] = book;
        std::cout << "Book '" << book->getTitle() << "' added to catalog." << std::endl;
    }
    
    Book* findBook(std::string isbn) {
        if (bookIndex.find(isbn) != bookIndex.end()) {
            return bookIndex[isbn];
        }
        return nullptr;
    }
};

class Library {
private:
    Catalog catalog; 
    std::string name;
    std::unordered_map<std::string, std::shared_ptr<Book>> books; 

public:
    Library(std::string name) : name(name) {
        std::cout << "Library '" << name << "' created." << std::endl;
    }
    
    void addBook(std::shared_ptr<Book> book) {
        books[book->getISBN()] = book;
        catalog.addBook(book.get());
        std::cout << "Book '" << book->getTitle() << "' added to library '" << name << "'." << std::endl;
    }
    
    void findBookInCatalog(std::string isbn) {
        Book* book = catalog.findBook(isbn);
        if (book) {
            std::cout << "Book found in catalog: '" << book->getTitle() << "' (ISBN: " << book->getISBN() << ")." << std::endl;
        } else {
            std::cout << "Book with ISBN " << isbn << " not found in catalog." << std::endl;
        }
    }
};

int main() {
    std::cout << "--- Library System Demonstration ---" << std::endl;
    Library myLibrary("City Library");
    
    auto book1 = std::make_shared<Book>("C++ Programming", "12345");
    auto book2 = std::make_shared<Book>("Data Structures", "67890");
    
    myLibrary.addBook(book1);
    myLibrary.addBook(book2);
    
    myLibrary.findBookInCatalog("12345");
    myLibrary.findBookInCatalog("11111");
    
    return 0;
}
