#include "ShoppingBasketFromTextReader.h"


ShoppingBasketFromTextReader::ShoppingBasketFromTextReader(pItemsTaxReader& itemsTaxReader, std::string_view textFilePath)
	: ShoppingBasketReader{ itemsTaxReader }, _textFilePath{ textFilePath }
{
}

std::optional<ShoppingBasket> ShoppingBasketFromTextReader::readShoppingBasket() const
{

	return std::nullopt;
}

std::string ShoppingBasketFromTextReader::getShoppingBasketName() const
{
	return _textFilePath;
}
