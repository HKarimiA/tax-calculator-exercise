#pragma once
#include "ShoppingBasketReader.h"
#include "TaxCalculatorPrinter.h"

using std::unique_ptr;

class TaxCalculatorApplication
{
public:
	TaxCalculatorApplication(unique_ptr<ShoppingBasketReader>&reader, unique_ptr<TaxCalculatorPrinter>&printer);
	void run() const;

private:
	const unique_ptr<ShoppingBasketReader>_reader;
	const unique_ptr<TaxCalculatorPrinter>_printer;
};