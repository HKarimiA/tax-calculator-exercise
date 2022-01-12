#pragma once
#include "ShoppingBasketReader.h"
#include "TaxCalculatorPrinter.h"

using std::unique_ptr;

// NOTE: This class reads a shopping basket and prints receipts or errors (Manager)
class TaxCalculatorApplication
{
public:
	TaxCalculatorApplication(unique_ptr<ShoppingBasketReader>&reader, unique_ptr<TaxCalculatorPrinter>&printer);
	void run() const;

private:
	const unique_ptr<ShoppingBasketReader>_reader;
	const unique_ptr<TaxCalculatorPrinter>_printer;
};