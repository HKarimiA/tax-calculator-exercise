// This project needs the C++17 language standard (or higher)

#include "ItemsTaxFileReader.h"
#include "ShoppingBasketFromTextReader.h"
#include "TaxCalculatorConsolePrinter.h"
#include "TaxCalculatorApplication.h"
#include <array>

using std::unique_ptr, std::make_unique;

// demo
int main()
{
	constexpr std::array<const char*, 3>inputLists{ "input1.txt", "input2.txt", "input3.txt" };
	for (const char* inputList : inputLists)
	{
		unique_ptr<ItemsTaxReader> itemsTaxFileReader = make_unique<ItemsTaxFileReader>();
		unique_ptr<ShoppingBasketReader>reader = make_unique<ShoppingBasketFromTextReader>(itemsTaxFileReader, inputList);
		unique_ptr<TaxCalculatorPrinter>printer = make_unique<TaxCalculatorConsolePrinter>();
		TaxCalculatorApplication app(reader, printer);
		app.run();
	}
	system("pause");
	return 0;
}