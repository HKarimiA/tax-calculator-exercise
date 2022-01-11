#include "TaxCalculatorApplication.h"

TaxCalculatorApplication::TaxCalculatorApplication(unique_ptr<ShoppingBasketReader>&reader, unique_ptr<TaxCalculatorPrinter>&printer)
	: _reader{ std::move(reader) }, _printer{ std::move(printer) }
{
}

void TaxCalculatorApplication::run() const
{
	if (auto items = _reader->readShoppingBasket())
		_printer->printReceipt(*items);
	else
		_printer->printError("The source " + _reader->getShoppingBasketName() + " is not a valid shopping basket :(");
}