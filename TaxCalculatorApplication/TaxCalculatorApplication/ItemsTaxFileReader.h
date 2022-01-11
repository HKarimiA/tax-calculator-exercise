#pragma once
#include "ItemsTaxReader.h"
#include <vector>

class ItemsTaxFileReader : public ItemsTaxReader
{
public:
	ItemsTaxFileReader();
	ItemsTaxFileReader(const std::vector<std::string>& itemsTaxFilePaths, double basicRateInPercent = 10.0, double importedRateInPercent = 5.0);
	double evaluateTaxOfItem(std::string_view itemName, bool imported) const override;

private:
	bool isTaxExempt(std::string_view itemName) const;

	const std::vector<std::string> _itemsTaxFilePaths;
};

