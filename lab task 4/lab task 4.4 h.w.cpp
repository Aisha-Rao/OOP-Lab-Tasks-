//Task - 04:
//A book shop maintains the inventory of books that are being sold at the shop. The list includes details such as
//author, title, price, publisher and stock position. Whenever a customer wants a book, the sales person inputs the
//title and author and the system searches the list and displays whether it is available or not. If it is not, an
//aplapropriate message is displayed. If it is, then the system displays the book details and requests for the number
//of copies required. If the requested copies are available, the total cost of the requested copies is displayed;
//otherwise “Required copies not in stock” is displayed. Design a system using a class called books with suitable
//member functions and constructors.

#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string publisher;
    double price;
    int stock;

public:
    
    Book(std::string t, std::string a, std::string p, double pr, int s)
        : title(t), author(a), publisher(p), price(pr), stock(s) {}

    void checkAvailability(std::string t, std::string a, int copies) {
        if (title == t && author == a) {
            std::cout << "Book Found!\n";
            std::cout << "Title: " << title << "\nAuthor: " << author << "\nPublisher: " << publisher << "\nPrice: " << price << "\nStock: " << stock << "\n";
            if (copies <= stock) {
                std::cout << "Total Cost: " << copies * price << "\n";
                stock -= copies;
            } else {
                std::cout << "Required copies not in stock.\n";
            }
        } else {
            std::cout << "Book not available.\n";
        }
    }
};

int main() {
    Book book1("C++ Programming", "Bjarne Stroustrup", "Pearson", 45.99, 10);
    
    std::string title, author;
    int copies;
    
    std::cout << "Enter book title: ";
    std::getline(std::cin, title);
    std::cout << "Enter author: ";
    std::getline(std::cin, author);
    std::cout << "Enter number of copies required: ";
    std::cin >> copies;
    
    book1.checkAvailability(title, author, copies);
    
    return 0;
}
