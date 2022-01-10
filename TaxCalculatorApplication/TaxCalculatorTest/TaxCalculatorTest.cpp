#include "CppUnitTest.h"
#include "../TaxCalculatorApplication/Item.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TaxCalculatorTest
{
	TEST_CLASS(ItemTest)
	{
	public:
		
		TEST_METHOD(GrossPrice)
		{
			Item i1(1, "some item", false, 10.0, 10);
			Assert::AreEqual(i1.grossPrice(),11.0);
			Item i2(1, "box of chocolates", true, 10.0, 5);
			Assert::AreEqual(i2.grossPrice(), 10.50);
			Item i3(1, "bottle of perfume", true, 27.99, 15);
			Assert::AreEqual(i3.grossPrice(), 32.19);
			Item i4(1, "packet of headache pills", false, 9.75, 0);
			Assert::AreEqual(i4.grossPrice(), 9.75);
		}
	};
}
