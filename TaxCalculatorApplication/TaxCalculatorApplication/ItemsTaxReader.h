#pragma once
#include <string_view>

// NOTE: Interface for evaluating tax of items
class ItemsTaxReader
{
public:
	ItemsTaxReader(double basicRateInPercent = 10.0, double importedRateInPercent = 5.0);
	virtual ~ItemsTaxReader() = default;
	virtual double evaluateTaxOfItem(std::string_view itemName, bool imported) const = 0;

protected:
	const double _basicRateInPercent;
	const double _importedRateInPercent;
};