#include "product.hpp"
#include <cstring>

namespace product {
    Product::Product(const char* name, int quantity, double price) {
        name_ = new char [strlen(name) + 1];
        strcpy(name_, name);
        quantity_ = quantity;
        price_ = price;
    }

    Product::Product(const Product& other) {
        name_ = new char [strlen(other.name_) + 1];
        strcpy(name_, other.name_);
        quantity_ = other.quantity_;
        price_ = other.price_;
    }

    Product::~Product() {
        delete [] name_;
    }

    std::ostream& operator<<(std::ostream& out, Product product) {
        out << product.name_ << " " << product.quantity_ << " " << product.price_;
        return out;
    }

    bool Product::operator==(const Product& product) {
        return (strcmp(product.name_, name_) == 0) && (product.quantity_ == quantity_) && (product.price_ == price_);
    }

}
