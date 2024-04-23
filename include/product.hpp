#pragma once
#include <iostream>
#include <my_vector.hpp>

namespace product {
    class Product {
    public:
        Product(const char* name, int quantity, double price);
        Product(const Product& other);
        ~Product();

        friend std::ostream& operator<<(std::ostream& out, Product product);

        bool operator==(const Product& product);
    private:
        char* name_;
        int quantity_;
        double price_;
    }; 
}
