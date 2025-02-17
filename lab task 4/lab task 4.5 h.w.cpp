/*Task - 05:
Write a class called CoffeeShop, which has three instance variables: 
Name: a string (basically, of the shop)
Menu: an array of items (of type MenuItem), with each item containing the item (name of the item), type
(whether a food or a drink) and price.
Orders: an empty array and seven methods:
addOrder: adds the name of the item to the end of the orders array if it exists on the menu. Otherwise, return
“This item is currently unavailable”
fulfillOrder: if the orders array is not empty, return “The {item} is ready” . If the orders array is empty, return
“All orders have been fulfilled”
listOrders: returns the list of orders taken, otherwise, an empty array.
dueAmount: returns the total amount due for the orders taken.
cheapestItem: returns the name of the cheapest item on the menu.
drinksOnly: returns only the item names of type drink from the menu.
foodOnly: returns only the item names of type food from the menu.*/


#include <iostream>
#include <vector>
#include <limits>

class MenuItem {
public:
    std::string name;
    std::string type;
    double price;

    MenuItem(std::string n, std::string t, double p) : name(n), type(t), price(p) {}
};

class CoffeeShop {
private:
    std::string name;
    std::vector<MenuItem> menu;
    std::vector<std::string> orders;

public:
    CoffeeShop(std::string shopName, std::vector<MenuItem> shopMenu) : name(shopName), menu(shopMenu) {}

    std::string addOrder(std::string itemName) {
        for (const auto& item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                return "Order added: " + itemName;
            }
        }
        return "This item is currently unavailable";
    }

    std::string fulfillOrder() {
        if (!orders.empty()) {
            std::string order = orders.front();
            orders.erase(orders.begin());
            return "The " + order + " is ready";
        }
        return "All orders have been fulfilled";
    }

    std::vector<std::string> listOrders() {
        return orders;
    }

    double dueAmount() {
        double total = 0;
        for (const auto& order : orders) {
            for (const auto& item : menu) {
                if (item.name == order) {
                    total += item.price;
                    break;
                }
            }
        }
        return total;
    }

    std::string cheapestItem() {
        if (menu.empty()) return "No items in menu";
        
        const MenuItem* cheapest = &menu[0];
        for (const auto& item : menu) {
            if (item.price < cheapest->price) {
                cheapest = &item;
            }
        }
        return cheapest->name;
    }

    std::vector<std::string> drinksOnly() {
        std::vector<std::string> drinks;
        for (const auto& item : menu) {
            if (item.type == "drink") {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }

    std::vector<std::string> foodOnly() {
        std::vector<std::string> food;
        for (const auto& item : menu) {
            if (item.type == "food") {
                food.push_back(item.name);
            }
        }
        return food;
    }
};

int main() {
    std::vector<MenuItem> menu = {
        {"Coffee", "drink", 2.5},
        {"Tea", "drink", 1.5},
        {"Sandwich", "food", 5.0},
        {"Cake", "food", 3.5}
    };

    CoffeeShop myShop("Java Haven", menu);
    
    std::cout << myShop.addOrder("Coffee") << "\n";
    std::cout << myShop.addOrder("Burger") << "\n";
    std::cout << "Total Due: " << myShop.dueAmount() << "\n";
    std::cout << myShop.fulfillOrder() << "\n";
    std::cout << "Cheapest Item: " << myShop.cheapestItem() << "\n";
    
    std::cout << "Drinks: ";
    for (const auto& drink : myShop.drinksOnly()) std::cout << drink << " ";
    std::cout << "\nFood: ";
    for (const auto& food : myShop.foodOnly()) std::cout << food << " ";
    std::cout << "\n";
    
    return 0;
}

