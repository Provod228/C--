#pragma once  // Добавляем защиту от повторного включения
#include "Product.h"  // Оставляем только необходимый заголовочный файл

class ProductInfo {
protected:
	Product product;
	double price;
	int quantity;
public:
	ProductInfo();
	ProductInfo(int quantity, double price, std::string title_product);
	std::string getTitle() const;
	double getPrice() const;
	int getQuantity() const;
	
	// Добавляем оператор сравнения
	bool operator<(const ProductInfo& other) const;
};