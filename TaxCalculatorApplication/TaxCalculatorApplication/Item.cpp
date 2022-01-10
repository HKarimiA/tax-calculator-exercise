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
	return 0.0;
}

double Item::roundUp(double number) const
{
	return 0.0;
}