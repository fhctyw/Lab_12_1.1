#include "pch.h"
#include "CppUnitTest.h"
#include "Number.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Number n;
			n.Init(1445.0, -95);
			Assert::IsTrue(n.getSecond() == 0);
		}
	};
}
