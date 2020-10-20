#include "Classes.h"

void ProductManager::AddProduct(Product product) {
	auto position = std::find_if(_vecProducts.begin(), _vecProducts.end(), [&product](Product& obj) { return obj.GetProductName() == product.GetProductName(); });

	if (position == _vecProducts.end()) {
		_vecProducts.push_back(product);
	}
	else {
		throw std::exception("Cannot add as a product with this name already exists.");
	}

}

void ProductManager::DeleteProduct(std::string productName) {
	auto position = std::find_if(_vecProducts.begin(), _vecProducts.end(), [&productName](Product& obj) { return obj.GetProductName() == productName; });

	if (position != _vecProducts.end()) {
		_vecProducts.erase(position);
		return;
	}

	throw std::exception("No product deleted, not found.");
}

Product ProductManager::GetProduct(std::string productName) {
	for (auto& _prod : _vecProducts)
	{
		if (_prod.GetProductName() == productName) {
			return _prod;
		}
	}

	return Product();
}

std::vector<Product> ProductManager::GetAllProducts() {
	return _vecProducts;
}

void ProductManager::BuyProduct(Product product) {
	_vecBasket.push_back(product);
}

double ProductManager::GetBasketTotal() {
	double dTotal = 0;

	for (auto& product : _vecBasket)
	{
		dTotal += product.GetProductTotal();
	}

	return dTotal;
}

double ProductManager::GetBasketTax() {
	double dTotal = 0;

	for (auto& product : _vecBasket)
	{
		dTotal += product.GetProductTax();
	}

	return dTotal;
}

std::vector<Product> ProductManager::GetBasketItems() {
	return _vecBasket;
}