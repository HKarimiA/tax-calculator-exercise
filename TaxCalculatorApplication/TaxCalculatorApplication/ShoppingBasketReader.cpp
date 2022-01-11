#include "ShoppingBasketReader.h"

ShoppingBasketReader::ShoppingBasketReader(pItemsTaxReader& itemsTaxReader) : _itemsTaxReader{ std::move(itemsTaxReader) }
{
}
