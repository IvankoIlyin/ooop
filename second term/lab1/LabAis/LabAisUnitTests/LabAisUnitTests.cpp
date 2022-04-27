#include "pch.h"
#include "CppUnitTest.h"
#include"../LabAis/Matrix.h"
#include"../LabAis/Rationalnumber.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LabAisUnitTests
{
	TEST_CLASS(LabAisUnitTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{	
			Matrix NewMatrix;
			NewMatrix.generateMatrix(2, 1, 5, 1, 5);
			NewMatrix.inversionGaus();
			Rationalnumber D = NewMatrix.Determinant();
			Assert::IsTrue(D.m!=0);

		}

		TEST_METHOD(TestMethod2)
		{	
			Matrix NewMatrix;
			NewMatrix.generateMatrix(2, -1, 6, 1, 5);
			NewMatrix.inversionGaus();
			Rationalnumber D = NewMatrix.Determinant();
			Assert::IsTrue(D.m != 0);
		}

		TEST_METHOD(TestMethod3)
		{	
			Matrix NewMatrix;
			NewMatrix.generateMatrix(3, 1, 5, 1, 5);
			NewMatrix.inversionGaus();
			Rationalnumber D = NewMatrix.Determinant();
			Assert::IsTrue(D.m != 0);

		}

		TEST_METHOD(TestMethod4)
		{	
			Matrix NewMatrix;
			NewMatrix.generateMatrix(2, -10, 5, 1, 5);
			NewMatrix.inversionGaus();
			Rationalnumber D = NewMatrix.Determinant();
			Assert::IsTrue(D.m != 0);

		}

		TEST_METHOD(TestMethod5)
		{	
			Matrix NewMatrix;
			NewMatrix.generateMatrix(1, 1, 5, 1, 5);
			NewMatrix.inversionGaus();
			Rationalnumber D = NewMatrix.Determinant();
			Assert::IsTrue(D.m != 0);
		}

		TEST_METHOD(TestMethod6)
		{	
			Matrix NewMatrix;
			NewMatrix.generateMatrix(2, -5, 5, 1, 5);
			NewMatrix.inversionGaus();
			Rationalnumber D = NewMatrix.Determinant();
			Assert::IsTrue(D.m != 0);

		}

		TEST_METHOD(TestMethod7)
		{
			Matrix NewMatrix;
			NewMatrix.generateMatrix(2, 1, 7, 1, 7);
			NewMatrix.inversionGaus();
			Rationalnumber D = NewMatrix.Determinant();
			Assert::IsTrue(D.m != 0);

		}

		TEST_METHOD(TestMethod8)
		{	
			Matrix NewMatrix;
			NewMatrix.generateMatrix(4, 1, 5, 1, 5);
			NewMatrix.inversionGaus();
			Rationalnumber D = NewMatrix.Determinant();
			Assert::IsTrue(D.m != 0);

		}

		TEST_METHOD(TestMethod9)
		{	
			Matrix NewMatrix;
			NewMatrix.generateMatrix(2, -5, 5, 1, 5);
			NewMatrix.inversionGaus();
			Rationalnumber D = NewMatrix.Determinant();
			Assert::IsTrue(D.m != 0);

		}

		TEST_METHOD(TestMethod10)
		{	
			Matrix NewMatrix;
			NewMatrix.generateMatrix(2, 1, 5, 1, 9);
			NewMatrix.inversionGaus();
			Rationalnumber D = NewMatrix.Determinant();
			Assert::IsTrue(D.m != 0);

		}

	};
}
