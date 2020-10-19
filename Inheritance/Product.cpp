#include "Classes.h"

Product::Product() {}

Product::Product(std::string productName, double productTotalBeforeTax, double productTax) {
	_strProductName = productName;
	_dProductTax = productTax;
	_dProductTotal = productTotalBeforeTax + productTax;
}