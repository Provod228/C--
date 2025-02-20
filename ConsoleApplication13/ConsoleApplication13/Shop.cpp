#include "Shop.h"
#include <algorithm>

int Shop::nextId = 1;

Shop::Shop() : id(nextId++), title(""), products({}) {}

Shop::Shop(std::vector<ProductInfo> products, std::string title) : id(nextId++), title(title), products(products) {}
	
int Shop::getId()
{
	return id;
}

std::vector<ProductInfo> Shop::getProducts()
{
	return products;
}

ProductInfo Shop::getProduct(std::string product_title)
{
    for (int i = 0; i < products.size(); ++i) {
        if (products[i].getTitle() == product_title) {
            return products[i];
        }
    }
    return ProductInfo();
}

std::string Shop::getTitle()
{
	return title;
}

void Shop::delProductInfo(std::string product_title) {
    for (int i = 0; i < products.size(); ++i) {
        if (products[i].getTitle() == product_title) {
            products.erase(products.cbegin() + i);
            return;
        }
    }
}

void Shop::addProductInfo(ProductInfo product) {
    products.push_back(product);
}
