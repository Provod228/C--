#include "ProductInfo.h"
#include "Product.h"
#include <iostream>
#include <exception>


ProductInfo::ProductInfo() : quantity(0), price(0), product(Product()) {}


ProductInfo::ProductInfo(int quantity, double price, std::string title_product) {
    this->quantity = 0;
    this->price = 0;
    try {
        if (price <= 0) {
            throw std::runtime_error("error input, price not < or = 0");
        }
        this->price = price;

        if (quantity < 0) {
            throw std::runtime_error("error input, quantity not < 0");
        }
        this->quantity = quantity;

        this->product = Product(title_product);
    }
    catch (const std::runtime_error& e) {
        std::cout << "������: " << e.what() << std::endl;
    }
}


std::string ProductInfo::getTitle() const {
	return product.getTitle();
}

double ProductInfo::getPrice() const {
	return price;
}

int ProductInfo::getQuantity() const {
	return quantity;
}


bool ProductInfo::operator<(const ProductInfo& other) const {
	return price < other.price;
}

