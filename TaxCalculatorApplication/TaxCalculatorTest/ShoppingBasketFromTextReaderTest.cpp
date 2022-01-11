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

		TEST_METHOD(EvaluateTaxOfItem)
		{

		}
	};
}