#include "Product.h"


int Product::nextId = 1;

Product::Product() : id(nextId++), title("") {}

Product::Product(std::string title) : id(nextId++), title(title) {}

std::string Product::getTitle() const {
	return title;
}

int Product::getId() const {
	return id;
}


bool Product::operator<(const Product& other) const {
	return title < other.title;
}
