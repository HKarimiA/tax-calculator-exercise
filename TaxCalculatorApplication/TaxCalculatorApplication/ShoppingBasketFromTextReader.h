#pragma once
#include "ShoppingBasketReader.h"

// NOTE: This class reads a shopping basket from a text file in a specific format
class ShoppingBasketFromTextReader : public ShoppingBasketReader
{
public:
	ShoppingBasketFromTextReader(pItemsTaxReader& itemsTaxReader, std::string_view textFilePath);
	std::optional<ShoppingBasket> readShoppingBasket() const override;
	std::string getShoppingBasketName() const override;

private:
	std::optional<Item>parseTextToItem(std::string_view text) const;

	const std::string _textFilePath;
};