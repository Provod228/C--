#pragma once
#include <vector>
#include "Shop.h"
#include <map>

class ShopManager {
protected:
	std::vector<Shop> shops;
public:
	ShopManager();
	ShopManager(std::vector<Shop> shops);
	std::vector<Shop>& getShops();
	void delShop(std::string title_shop);
	void addShop(Shop shop);
	std::map<ProductInfo, std::string> getProductMinPrice(std::string title_product);
};