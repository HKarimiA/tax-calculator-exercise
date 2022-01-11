#include "ShoppingBasketFromTextReader.h"
#include "LocalFileReader.h"
#include <regex>

ShoppingBasketFromTextReader::ShoppingBasketFromTextReader(pItemsTaxReader& itemsTaxReader, std::string_view textFilePath)
	: ShoppingBasketReader{ itemsTaxReader }, _textFilePath{ textFilePath }
{
}

std::optional<ShoppingBasket> ShoppingBasketFromTextReader::readShoppingBasket() const
{
	if (const auto& lines = LocalFileReader(_textFilePath).getLines())
	{
		ShoppingBasket items;
		items.reserve(lines->size());
		for (const std::string& line : *lines)
		{
			if (auto item = parseTextToItem(line))
				items.emplace_back(*item);
			else
				return std::nullopt;
		}
		return items;
	}
	return std::nullopt;
}

std::string ShoppingBasketFromTextReader::getShoppingBasketName() const
{
	return _textFilePath;
}

// text with this format: "amount" (optional: imported) "name" at "price"
// for example: "1 imported bottle of perfume at 27.99" or "1 bottle of imported perfume at 27.99" or "1 bottle of perfume at 27.99"
std::optional<Item> ShoppingBasketFromTextReader::parseTextToItem(std::string_view text) const
{
	std::string line = std::string(text);
	std::smatch match;
	static std::regex amount("^[0-9]+");
	static std::regex netPrice("([0-9]+\\.?[0-9]*|\\.[0-9]+)$");
	if (std::regex_search(line, match, amount) && match[0].length() > 0)
	{
		const int amount = std::stoi(match[0]);
		line = match.suffix();  // erase amount from text
		if (std::regex_search(line, match, netPrice) && match[0].length() > 0)
		{
			const double netPrice = std::stod(match[0]);
			line = (line[0] == ' ') ? line.substr(1, line.rfind(" at ")-1) : line.substr(0, line.rfind(" at ")-1);
			const bool imported = line.find("imported") != std::string::npos;
			const std::string name = (imported) ? line.erase(line.find("imported"), 9) : line;
			const double taxInPercent = _itemsTaxReader->evaluateTaxOfItem(name, imported);
			return Item(amount, name, imported, netPrice, taxInPercent);
		}
	}
	return std::nullopt;
}