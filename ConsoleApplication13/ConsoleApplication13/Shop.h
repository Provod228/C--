#pragma once
#include "ProductInfo.h"
#include <vector>

class Shop {
protected:
	static int nextId;
	int id;
	std::vector<ProductInfo> products;
	std::string title;
public:
	Shop();
	Shop(std::vector<ProductInfo> products, std::string title);	
	int getId();
	std::vector<ProductInfo> getProducts();
	ProductInfo getProduct(std::string product_title);
	std::string getTitle();
	void delProductInfo(std::string title_shop);
	void addProductInfo(ProductInfo product);
};