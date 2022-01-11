#pragma once
#include "Item.h"
#include <vector>

using ShoppingBasket = std::vector<Item>;

class TaxCalculatorPrinter
{
public:
	TaxCalculatorPrinter() = default;
	virtual ~TaxCalculatorPrinter() = default;
	virtual void printReceipt(const ShoppingBasket& shoppingBasket) const = 0;
	virtual void printError(std::string_view error) const = 0;
};