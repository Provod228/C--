#pragma once
#include "Product.h"
#include <map>
#include <iostream>
#include "ShopManager.h"


class Buyer {
protected:
	static int nextId;
	int id;
	std::string name;
	std::map<Product, int> list_of_products;
	double money;
public:
	Buyer();
	Buyer(std::map<Product, int> list_of_products, double money, std::string name);
	int getId();
	std::string getName();
	std::map<Product, int> getProductsList();
	double getMoney();
	void byProduct(std::string title_products, ShopManager& shop_manager);
};