#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 7.01.it/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestCalcFunction)
		{
			const int rowCount = 2;
			const int colCount = 2;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++) {
				a[i] = new int[colCount];
			}

			

			int S, k;
			Calc(a, rowCount, colCount, S, k);

			
			Assert::AreEqual(0, S);
			Assert::AreEqual(0, k);

			
			for (int i = 0; i < rowCount; i++) {
				delete[] a[i];
			}
			delete[] a;
		}
	};
}