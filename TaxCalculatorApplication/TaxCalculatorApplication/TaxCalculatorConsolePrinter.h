#pragma once
#include "TaxCalculatorPrinter.h"

// NOTE: This class prints receipts and errors to console
class TaxCalculatorConsolePrinter : public TaxCalculatorPrinter
{
public:
	void printReceipt(const ShoppingBasket& shoppingBasket) const override;
	void printError(std::string_view error) const override;
};