#pragma once  // Добавляем защиту от повторного включения
#include <string>  // Меняем iostream на string, так как нам нужны только строки

class Product {
protected:
	static int nextId;
	int id;
	std::string title;
public:
	Product();

	Product(std::string title);
	
	std::string getTitle();
	int getId();
	
	bool operator<(const Product& other);
};
