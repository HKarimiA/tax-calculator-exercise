#include "ShoppingBasketReader.h"

ShoppingBasketReader::ShoppingBasketReader(pItemsTaxReader& taxReader) : _itemsTaxReader{ std::move(taxReader) }
{
}
