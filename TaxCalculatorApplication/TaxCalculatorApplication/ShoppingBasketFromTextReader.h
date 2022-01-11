#pragma once
#include "ShoppingBasketReader.h"

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