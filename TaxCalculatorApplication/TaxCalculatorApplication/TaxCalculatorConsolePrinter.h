#pragma once
#include "TaxCalculatorPrinter.h"

class TaxCalculatorConsolePrinter : public TaxCalculatorPrinter
{
public:
	void printReceipt(const ShoppingBasket& shoppingBasket) const override;
	void printError(std::string_view error) const override;
};