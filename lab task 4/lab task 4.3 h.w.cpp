//Task - 03:
//Create A class called Invoice that a hardware store might use to represent an invoice for an item sold at the
//store. An Invoice should include four pieces of information as instance variables - a part number (type String), a
//part description (type String), a quantity of the item being purchased (type int) and a price per item (double).
//Your class should have a constructor that initialize the four instance variables. In addition, provide a method
//named getInvoiceAmount that calculates the invoice amount (i.e., multiples the quantity by the price per item),
//then returns the amount as a double value. If the quantity is not positive, it should be set to 0. If the price per
//item is not positive, it should be set to 0.0.

#include <iostream>
#include <string>

class Invoice {
private:
    std::string partNumber;
    std::string partDescription;
    int quantity;
    double pricePerItem;

public:
    
    Invoice(std::string pNumber, std::string pDescription, int qty, double price) 
        : partNumber(pNumber), partDescription(pDescription), quantity(qty > 0 ? qty : 0), pricePerItem(price > 0 ? price : 0.0) {}

    std::string getPartNumber() const {
        return partNumber;
    }

    std::string getPartDescription() const {
        return partDescription;
    }

    int getQuantity() const {
        return quantity;
    }

    double getPricePerItem() const {
        return pricePerItem;
    }

    double getInvoiceAmount() const {
        return quantity * pricePerItem;
    }
};

int main() {
    Invoice item("1234", "Hammer", 5, 10.50);
    
    std::cout << "Part Number: " << item.getPartNumber() << "\n";
    std::cout << "Description: " << item.getPartDescription() << "\n";
    std::cout << "Quantity: " << item.getQuantity() << "\n";
    std::cout << "Price per item: " << item.getPricePerItem() << "\n";
    std::cout << "Total Invoice Amount: " << item.getInvoiceAmount() << "\n";
    
    return 0;
};

