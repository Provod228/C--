#include <iostream>
#include <vector>
#include <map>
#include "ShopManager.h"
#include "Buyer.h"

void printMenu() {
	std::cout << "\nМеню:\n";
	std::cout << "1. Создать магазин\n";
	std::cout << "2. Добавить товар в магазин\n";
	std::cout << "3. Создать покупателя\n";
	std::cout << "4. Добавить товар в список покупок\n";
	std::cout << "5. Купить товар\n";
	std::cout << "6. Найти самую низкую цену на товар\n";
	std::cout << "7. Показать баланс покупателя\n";
	std::cout << "0. Выход\n";
	std::cout << "Выберите действие: ";
}

int main() {
	setlocale(LC_ALL, "Russian");
	ShopManager shopManager;
	std::vector<Buyer> buyers;
	int choice;

	do {
		printMenu();
		std::cin >> choice;

		switch (choice) {
		case 1: {
			std::string shopName;
			std::cout << "Введите название магазина: ";
			std::cin >> shopName;
			Shop newShop(std::vector<ProductInfo>(), shopName);
			shopManager.addShop(newShop);
			std::cout << "Магазин успешно создан!\n";
			break;
		}
		case 2: {
			std::string shopName, productName;
			int quantity;
			double price;
			std::cout << "Введите название магазина: ";
			std::cin >> shopName;
			std::cout << "Введите название товара: ";
			std::cin >> productName;
			std::cout << "Введите количество: ";
			std::cin >> quantity;
			std::cout << "Введите цену: ";
			std::cin >> price;


			ProductInfo productInfo(quantity, price, productName);
			
			for (auto& shop : shopManager.getShops()) {
				if (shop.getTitle() == shopName) {
					shop.addProductInfo(productInfo);
					std::cout << "Товар успешно добавлен!\n";
					break;
				}
			}
			break;
		}
		case 3: {
			std::string buyerName;
			double money;
			std::cout << "Введите имя покупателя: ";
			std::cin >> buyerName;
			std::cout << "Введите начальный баланс: ";
			std::cin >> money;
			
			std::map<Product, int> emptyList;
			Buyer buyer(emptyList, money, buyerName);
			buyers.push_back(buyer);
			std::cout << "Покупатель успешно создан!\n";
			break;
		}
		case 4: {
			std::string buyerName, productName;
			int quantity;
			std::cout << "Введите имя покупателя: ";
			std::cin >> buyerName;
			std::cout << "Введите название товара: ";
			std::cin >> productName;
			std::cout << "Введите количество: ";
			std::cin >> quantity;

			for (Buyer& buyer : buyers) {
				if (buyer.getName() == buyerName) {
					Product product(productName);
					std::map<Product, int> products;
					products[product] = quantity;
					buyer = Buyer(products, buyer.getMoney(), buyer.getName());
					std::cout << "Товар добавлен в список покупок!\n";
					break;
				}
			}
			break;
		}
		case 5: {
			std::string buyerName, productName;
			std::cout << "Введите имя покупателя: ";
			std::cin >> buyerName;
			std::cout << "Введите название товара: ";
			std::cin >> productName;

			for (Buyer& buyer : buyers) {
				if (buyer.getName() == buyerName) {
					buyer.byProduct(productName, shopManager);
					break;
				}
			}
			break;
		}
		case 6: {
			std::string productName;
			std::cout << "Введите название товара: ";
			std::cin >> productName;
			
			auto minPrice = shopManager.getProductMinPrice(productName);
			if (!minPrice.first.getTitle().empty() and !minPrice.second.empty()) {
				ProductInfo prodInfo = minPrice.first;
				std::cout << "Самая низкая цена: " << prodInfo.getPrice() 
						<< " в магазине " << minPrice.second << std::endl;
			}
			else {
				std::cout << "Товар не найден в магазинах.\n";
			}
			break;
		}
		case 7: {
			std::string buyerName;
			std::cout << "Введите имя покупателя: ";
			std::cin >> buyerName;

			for (auto buyer : buyers) {
				if (buyer.getName() == buyerName) {
					std::cout << "Баланс: " << buyer.getMoney() << std::endl;
					break;
				}
			}
			break;
		}
		case 0:
			std::cout << "До свидания!\n";
			break;
		default:
			std::cout << "Неверный выбор. Попробуйте снова.\n";
		}
	} while (choice != 0);

	return 0;
}
