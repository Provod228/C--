#include "Product.h"


int Product::nextId = 1;

Product::Product() : id(nextId++), title("") {}

Product::Product(std::string title) : id(nextId++), title(title) {}

std::string Product::getTitle()
{
	return title;
}

int Product::getId()
{
	return id;
}
