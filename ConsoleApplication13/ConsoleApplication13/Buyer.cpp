#include "Buyer.h"

int Buyer::nextId = 1;

Buyer::Buyer() 
	: id(nextId++), name(""), money(0), list_of_products({}) {}

Buyer::Buyer(std::map<Product, int> list_of_products, double money, std::string name) 
	: id(nextId++), name(name), money(money), list_of_products(list_of_products) {}

int Buyer::getId()
{
	return id;
}

std::string Buyer::getName()
{
	return name;
}

std::map<Product, int> Buyer::getProductsList()
{
	return list_of_products;
}

double Buyer::getMoney()
{
	return money;
}

void Buyer::byProduct(std::string title_products, ShopManager& shop_manager)
{
	for (const auto& product : list_of_products) {
		Product prod = product.first;
		if (prod.getTitle() == title_products) {
			auto product_min_prices = shop_manager.getProductMinPrice(title_products);
			std::cout << product_min_prices.first.getPrice() << product_min_prices.second << std::endl;
			std::cout << product_min_prices.first.getPrice() << product_min_prices.second << std::endl;
			auto it = product_min_prices;
			if (it.first.getTitle() == title_products) {
				double total_cost = it.first.getPrice() * product.second;
				if (money >= total_cost) {
					money -= total_cost;
					return;
				}
				else {
					std::cout << "Денег слишком мало" << std::endl;
					return;
				}
			}
			return;
		}
	}
	std::cout << "Этот продукт отсутствует в списке" << std::endl;
}
