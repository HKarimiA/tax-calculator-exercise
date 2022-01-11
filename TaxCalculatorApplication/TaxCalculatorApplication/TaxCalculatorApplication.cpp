#include "TaxCalculatorApplication.h"

TaxCalculatorApplication::TaxCalculatorApplication(unique_ptr<ShoppingBasketReader>&reader, unique_ptr<TaxCalculatorPrinter>&printer)
	: _reader{ std::move(reader) }, _printer{ std::move(printer) }
{
}

void TaxCalculatorApplication::run() const
{

}