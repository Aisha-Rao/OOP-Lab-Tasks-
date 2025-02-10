//Create a class called Book to represent a book. A Book should include four pieces of information as instance
//variables-a book name, an ISBN number, an author name and a publisher. Provide methods (query method) for
//each instance variable. Inaddition, provide a method named getBookInfo that returns the description of the book
//as a String (the description should include all the information about the book). You should use this keyword in
//member methods and constructor. Write a test application named BookTest to create an array of object for 5
//elements for class Book to demonstrate the class Book&#39;s capabilities.

#include <iostream>
using namespace std;

class Book {
public:
    string bookName;
    string isbn;
    string author;
    string publisher;
    
    Book(string bookName, string isbn, string author, string publisher) {
        this->bookName = bookName;
        this->isbn = isbn;
        this->author = author;
        this->publisher = publisher;
    }
    
    string getBookName() { return this->bookName; }
    string getISBN() { return this->isbn; }
    string getAuthor() { return this->author; }
    string getPublisher() { return this->publisher; }
    
    string getBookInfo() {
        return "Book Name: " + this->bookName + ", ISBN: " + this->isbn + ", Author: " + this->author + ", Publisher: " + this->publisher;
    }
};

int main() {
    Book books[5] = {
        Book("The Great Gatsby", "978-0743273565", "F. Scott Fitzgerald", "Scribner"),
        Book("1984", "978-0451524935", "George Orwell", "Signet Classic"),
        Book("To Kill a Mockingbird", "978-0061120084", "Harper Lee", "Harper Perennial"),
        Book("Moby-Dick", "978-1503280786", "Herman Melville", "CreateSpace"),
        Book("Pride and Prejudice", "978-1503290563", "Jane Austen", "CreateSpace")
    };
    
    for (int i = 0; i < 5; i++) {
        cout << books[i].getBookInfo() << endl;
    }
    
    return 0;
}

