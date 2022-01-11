#include "CppUnitTest.h"
#include "../TaxCalculatorApplication/LocalFileReader.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TaxCalculatorTest
{
	TEST_CLASS(LocalFileReaderTest)
	{
	public:
		TEST_METHOD(GetLines)
		{
			LocalFileReader r1("../TaxCalculatorApplication/book.res");
			Assert::AreEqual(r1.getLines().has_value(), true);
			Assert::AreEqual(r1.getLines().value().at(0), std::string("book"));
			LocalFileReader r2("unknown.txt");
			Assert::AreEqual(r2.getLines().has_value(), false);
		}
	};
}
