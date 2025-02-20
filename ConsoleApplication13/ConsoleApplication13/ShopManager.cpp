#include "ShopManager.h"

ShopManager::ShopManager() : shops({}) {}

ShopManager::ShopManager(std::vector<Shop> shops) : shops(shops) {}

std::vector<Shop>& ShopManager::getShops()
{
	return shops;
}

void ShopManager::delShop(std::string title_shop)
{
    for (int i = 0; i < shops.size(); ++i) {
        if (shops[i].getTitle() == title_shop) {
            shops.erase(shops.cbegin() + i);
            return;
        }
    }
}

void ShopManager::addShop(Shop shop)
{
	shops.push_back(shop);
}

std::map<ProductInfo, std::string> ShopManager::getProductMinPrice(std::string title_product)
{
    int min_price = 0;
    double price;
    ProductInfo min_price_product;
    std::string name_shop;
    std::map<ProductInfo, std::string> min_info;
    for (Shop shop : shops) {
        price = shop.getProduct(title_product).getPrice();
        if (min_price == 0) {
            min_price = price;
            min_price_product = shop.getProduct(title_product);
            name_shop = shop.getTitle();
        }
        else if (min_price > price) {
            min_price = price;
            min_price_product = shop.getProduct(title_product);
            name_shop = shop.getTitle();
        }
    }
    min_info[min_price_product] = name_shop;
    return min_info;
}
