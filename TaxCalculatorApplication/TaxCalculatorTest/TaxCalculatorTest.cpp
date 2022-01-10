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
		}
	};
}
