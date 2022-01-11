#include "ItemsTaxFileReader.h"
#include "LocalFileReader.h"

ItemsTaxFileReader::ItemsTaxFileReader() : ItemsTaxFileReader{ std::vector<std::string>{"book.res", "food.res","medical.res"} }
{
}

ItemsTaxFileReader::ItemsTaxFileReader(const std::vector<std::string>& itemsTaxFilePaths, double basicRateInPercent, double importedRateInPercent)
	: ItemsTaxReader{ basicRateInPercent,importedRateInPercent }, _itemsTaxFilePaths{ itemsTaxFilePaths }
{
}

double ItemsTaxFileReader::evaluateTaxOfItem(std::string_view itemName, bool imported) const
{
	double tax = isTaxExempt(itemName) ? 0.0 : _basicRateInPercent;
	tax += imported ? _importedRateInPercent : 0.0;
	return tax;
}

bool ItemsTaxFileReader::isTaxExempt(std::string_view itemName) const
{
	return false;
}
