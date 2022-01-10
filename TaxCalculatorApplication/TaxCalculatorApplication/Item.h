#pragma once
#include <string_view>

class Item
{
public:
	Item(int amount, std::string_view name, bool imported, double netPrice, double taxInPercent);
	int amount() const;
	std::string name() const;
	bool imported() const;
	double netPrice() const;
	double grossPrice() const;

private:
	double roundUp(double number) const;

	int _amount;
	std::string _name;
	bool _imported;
	double _netPrice;
	double _taxInPercent;
};