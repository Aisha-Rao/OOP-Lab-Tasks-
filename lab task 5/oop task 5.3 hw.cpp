#include <iostream>

struct MenuItem {
    std::string name;
    std::string type; 
    double price;
};

class CoffeeShop {
private:
    std::string name;
    MenuItem menu[10];
    std::string orders[10];
    int menuSize;
    int orderCount;

public:
    CoffeeShop(std::string shopName, MenuItem menuItems[], int size) : name(shopName), menuSize(size), orderCount(0) {
        for (int i = 0; i < size; i++) {
            menu[i] = menuItems[i];
        }
    }
    
    std::string getName() const {
        return name;
    }
    
    std::string addOrder(std::string itemName) {
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].name == itemName) {
                orders[orderCount++] = itemName;
                return "Order added: " + itemName;
            }
        }
        return "This item is currently unavailable!";
    }
    
    std::string fulfillOrder() {
        if (orderCount > 0) {
            std::string order = orders[0];
            for (int i = 0; i < orderCount - 1; i++) {
                orders[i] = orders[i + 1];
            }
            orderCount--;
            return "The " + order + " is ready!";
        }
        return "All orders have been fulfilled";
    }
    
    double dueAmount() const {
        double total = 0.0;
        for (int i = 0; i < orderCount; i++) {
            for (int j = 0; j < menuSize; j++) {
                if (menu[j].name == orders[i]) {
                    total += menu[j].price;
                }
            }
        }
        return total;
    }
    
    std::string cheapestItem() const {
        if (menuSize == 0) return "No items available";
        
        const MenuItem* cheapest = &menu[0];
        for (int i = 1; i < menuSize; i++) {
            if (menu[i].price < cheapest->price) {
                cheapest = &menu[i];
            }
        }
        return cheapest->name;
    }
    
    void drinksOnly() const {
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "drink") {
                std::cout << menu[i].name << " ";
            }
        }
        std::cout << std::endl;
    }
    
    void foodOnly() const {
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "food") {
                std::cout << menu[i].name << " ";
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    MenuItem menu[] = {
        {"Coffee", "drink", 2.5},
        {"Tea", "drink", 2.0},
        {"Sandwich", "food", 5.0},
        {"Cake", "food", 3.5}
    };
    
    CoffeeShop shop("Java Haven", menu, 4);
    
    std::cout << shop.addOrder("Coffee") << std::endl;
    std::cout << shop.addOrder("Cake") << std::endl;
    std::cout << shop.addOrder("Pasta") << std::endl;
    
    std::cout << "Total due: $" << shop.dueAmount() << std::endl;
    
    std::cout << shop.fulfillOrder() << std::endl;
    std::cout << shop.fulfillOrder() << std::endl;
    std::cout << shop.fulfillOrder() << std::endl;
    
    std::cout << "Cheapest item: " << shop.cheapestItem() << std::endl;
    
    std::cout << "Drinks available: ";
    shop.drinksOnly();
    
    std::cout << "Food available: ";
    shop.foodOnly();
    
    return 0;
}
