#include "CppUnitTest.h"
#include "../TaxCalculatorApplication/ShoppingBasketFromTextReader.h"
#include "../TaxCalculatorApplication/ItemsTaxFileReader.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TaxCalculatorTest
{
	TEST_CLASS(ShoppingBasketFromTextReaderTest)
	{
	public:
		TEST_METHOD(GetShoppingBasketName)
		{
			std::unique_ptr<ItemsTaxReader> itemsTaxFileReader = std::make_unique<ItemsTaxFileReader>();
			ShoppingBasketFromTextReader s(itemsTaxFileReader, "../TaxCalculatorApplication/input1.txt");
			Assert::AreEqual(s.getShoppingBasketName(), std::string("../TaxCalculatorApplication/input1.txt"));
		}

		TEST_METHOD(ReadShoppingBasketInput1)
		{
			ShoppingBasket items{ Item(1, "book", false, 12.49, 0.0),
								  Item(1, "music CD", false, 14.99, 10.0),
								  Item(1, "chocolate bar", false, 0.85, 0.0) };
			std::unique_ptr<ItemsTaxReader> itemsTaxFileReader = std::make_unique<ItemsTaxFileReader>(std::vector<std::string>
			{ "../TaxCalculatorApplication/book.res", "../TaxCalculatorApplication/food.res", "../TaxCalculatorApplication/medical.res" });
			ShoppingBasketFromTextReader s(itemsTaxFileReader, "../TaxCalculatorApplication/input1.txt");
			for (size_t i = 0; i < 3; ++i)
			{
				Assert::AreEqual(s.readShoppingBasket()->at(i).amount(), items[i].amount());
				Assert::AreEqual(s.readShoppingBasket()->at(i).name(), items[i].name());
				Assert::AreEqual(s.readShoppingBasket()->at(i).imported(), items[i].imported());
				Assert::AreEqual(s.readShoppingBasket()->at(i).netPrice(), items[i].netPrice());
				Assert::AreEqual(s.readShoppingBasket()->at(i).grossPrice(), items[i].grossPrice());
			}
		}

		TEST_METHOD(ReadShoppingBasketInput3)
		{
			ShoppingBasket items{ Item(1, "bottle of perfume", true, 27.99, 15.0), Item(1, "bottle of perfume", false, 18.99, 10.0),
								  Item(1, "packet of headache pills", false, 9.75, 0.0),
								  Item(1, "box of chocolates", true, 11.25, 5.0) };
			std::unique_ptr<ItemsTaxReader> itemsTaxFileReader = std::make_unique<ItemsTaxFileReader>(std::vector<std::string>
			{ "../TaxCalculatorApplication/book.res", "../TaxCalculatorApplication/food.res", "../TaxCalculatorApplication/medical.res" });
			ShoppingBasketFromTextReader s(itemsTaxFileReader, "../TaxCalculatorApplication/input3.txt");
			for (size_t i = 0; i < 4; ++i)
			{
				Assert::AreEqual(s.readShoppingBasket()->at(i).amount(), items[i].amount());
				Assert::AreEqual(s.readShoppingBasket()->at(i).name(), items[i].name());
				Assert::AreEqual(s.readShoppingBasket()->at(i).imported(), items[i].imported());
				Assert::AreEqual(s.readShoppingBasket()->at(i).netPrice(), items[i].netPrice());
				Assert::AreEqual(s.readShoppingBasket()->at(i).grossPrice(), items[i].grossPrice());
			}
		}
	};
}