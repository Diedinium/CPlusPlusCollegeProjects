#include "Classes.h"

void ProductManager::AddProduct(Product& product) {
	_vecProducts.push_back(product);
}

void ProductManager::DeleteProduct(std::string productName) {
	for (size_t i = 0; i < _vecProducts.size(); i++)
	{
		if (_vecProducts[i].GetProductName() == productName) {
			_vecProducts.erase(_vecProducts.begin(), _vecProducts.begin() + i);
		}
	}
}

Product* ProductManager::GetProduct(std::string productName) {
	for (auto &_prod : _vecProducts)
	{
		if (_prod.GetProductName() == productName) {
			return &_prod;
		}
	}

	return NULL;
}

std::vector<Product> ProductManager::GetAllProducts() {
	return _vecProducts;
}