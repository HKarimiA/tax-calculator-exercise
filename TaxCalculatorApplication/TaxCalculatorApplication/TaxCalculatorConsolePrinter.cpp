#include "TaxCalculatorConsolePrinter.h"
#include <iostream>
#include <string>

using std::cout, std::endl;

void TaxCalculatorConsolePrinter::printReceipt(const ShoppingBasket& shoppingBasket) const
{
	double salesTaxes = 0;
	double total = 0;
	for (const Item& item : shoppingBasket)
	{
		cout << item.amount() << (item.imported() ? " imported " : " ") << item.name() << ": " << item.amount() * item.grossPrice() << endl;
		salesTaxes += item.amount() * (item.grossPrice() - item.netPrice());
		total += item.amount() * item.grossPrice();
	}
	cout << "Sales Taxes: " << salesTaxes << "\nTotal: " << total << endl << endl;
}

void TaxCalculatorConsolePrinter::printError(std::string_view error) const
{
	std::cerr << error << endl << endl;
}