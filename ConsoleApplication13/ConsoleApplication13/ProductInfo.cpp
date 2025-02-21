#include "ProductInfo.h"
#include "Product.h"
#include <iostream>


ProductInfo::ProductInfo() : quantity(0), price(0), product(Product()) {}

ProductInfo::ProductInfo(int quantity, double price, std::string title_product)
	: quantity(quantity), price(price), product(Product(title_product)) {
	
}

std::string ProductInfo::getTitle()
{
	return product.getTitle();
}

double ProductInfo::getPrice()
{
	return price;
}

int ProductInfo::getQuantity()
{
	return quantity;
}


bool ProductInfo::operator<(const ProductInfo& other) {
	return price < other.price;
}

