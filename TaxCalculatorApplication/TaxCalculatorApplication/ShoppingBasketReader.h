#pragma once
#include "Item.h"
#include "ItemsTaxReader.h"
#include <vector>
#include <optional>

using ShoppingBasket = std::vector<Item>;
using pItemsTaxReader = std::unique_ptr<ItemsTaxReader>;

class ShoppingBasketReader
{
public:
	ShoppingBasketReader(pItemsTaxReader& taxReader);
	virtual ~ShoppingBasketReader() = default;
	virtual std::optional<ShoppingBasket> readShoppingBasket() const = 0;
	virtual std::string getShoppingBasketName() const = 0;

protected:
	const pItemsTaxReader _itemsTaxReader;
};