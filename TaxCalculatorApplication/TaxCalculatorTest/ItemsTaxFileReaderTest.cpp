#include "CppUnitTest.h"
#include "../TaxCalculatorApplication/ItemsTaxFileReader.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TaxCalculatorTest
{
	TEST_CLASS(ItemsTaxFileReaderTest)
	{
	public:
		TEST_METHOD(EvaluateTaxOfItem)
		{
			ItemsTaxFileReader r1(std::vector<std::string>{"../TaxCalculatorApplication/book.res", "../TaxCalculatorApplication/food.res", "../TaxCalculatorApplication/medical.res"});
			Assert::AreEqual(r1.evaluateTaxOfItem("unknown",true),15.0);
			Assert::AreEqual(r1.evaluateTaxOfItem("unknown", false), 10.0);
			Assert::AreEqual(r1.evaluateTaxOfItem("book", true), 5.0);
			Assert::AreEqual(r1.evaluateTaxOfItem("chocolate bar", false), 0.0);
			Assert::AreEqual(r1.evaluateTaxOfItem("packet of headache pills", true), 5.0);
			Assert::AreEqual(r1.evaluateTaxOfItem("packet of headache pills", false), 0.0);
		}
	};
}
