#include "ProductInfo.h"
#include "Product.h"
#include <iostream>


ProductInfo::ProductInfo() : quantity(0), price(0), product(Product()) {}

ProductInfo::ProductInfo(int quantity, double price, Product product) 
	: quantity(quantity), price(price), product(product) {}

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

