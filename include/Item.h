#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    Item(const std::string& name, int id, double price, int quantity);

    // Getters
    std::string getName() const;
    int getId() const;
    double getPrice() const;
    int getQuantity() const;

    // Setters
    void setName(const std::string& name);
    void setPrice(double price);
    void setQuantity(int quantity);

private:
    std::string name_;
    int id_;
    double price_;
    int quantity_;
};

#endif // ITEM_H
