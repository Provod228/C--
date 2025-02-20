#pragma once  // Добавляем защиту от повторного включения
#include "Product.h"  // Оставляем только необходимый заголовочный файл

class ProductInfo {
protected:
	Product product;
	double price;
	int quantity;
public:
	ProductInfo();
	ProductInfo(int quantity, double price, Product product);
	std::string getTitle();
	double getPrice();
	int getQuantity();
	
	// Добавляем оператор сравнения
	bool operator<(const ProductInfo& other) const {
		return price < other.price;
	}
};