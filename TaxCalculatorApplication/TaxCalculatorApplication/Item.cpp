#include "Item.h"

Item::Item(int amount, std::string_view name, bool imported, double netPrice, double taxInPercent)
	: _amount{ amount }, _name{ name }, _imported{ imported }, _netPrice{ netPrice }, _taxInPercent{ taxInPercent }
{
}

int Item::amount() const
{
	return _amount;
}

std::string Item::name() const
{
	return _name;
}

bool Item::imported() const
{
	return _imported;
}

double Item::netPrice() const
{
	return _netPrice;
}

double Item::grossPrice() const
{
	return _netPrice + roundUp(_netPrice * _taxInPercent / 100);
}

// NOTE: rounded up to the nearest 0.05
double Item::roundUp(double number) const
{
	int decimal = static_cast<int>(number * 100) % 100;
	decimal += (decimal % 5 == 0) ? 0 : 5 - (decimal % 5);
	return static_cast<int>(number) + static_cast<double>(decimal) / 100;
}