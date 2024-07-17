#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    Item(int id, const std::string& name, const std::string& description, int quantity, double unitPrice);
    // Getters
    int getId() const;
    std::string getName() const;
    std::string getDescription() const;
    int getQuantity() const;
    double getUnitPrice() const;
    // Setters
    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setQuantity(int quantity);
    void setUnitPrice(double unitPrice);

private:
    int id_;
    std::string name_;
    std::string description_;
    int quantity_;
    double unitPrice_;
};

#endif // ITEM_H
