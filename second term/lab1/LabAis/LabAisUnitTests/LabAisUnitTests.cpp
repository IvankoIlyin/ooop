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
			vector<vector<Rationalnumber>> NewMatrix;
			vector<vector<Rationalnumber>> InversMatrix;
			NewMatrix = generateMatrix(2, 1, 5, 1, 5);
			InversMatrix = inversionGaus(NewMatrix);
			Rationalnumber D = Determinant(InversMatrix, InversMatrix.size());
			Assert::IsTrue(D.m!=0);

		}

		TEST_METHOD(TestMethod2)
		{
			vector<vector<Rationalnumber>> NewMatrix;
			vector<vector<Rationalnumber>> InversMatrix;
			NewMatrix = generateMatrix(2, -1, 6, 1, 5);
			InversMatrix = inversionGaus(NewMatrix);
			Rationalnumber D = Determinant(InversMatrix, InversMatrix.size());
			Assert::IsTrue(D.m != 0);

		}

		TEST_METHOD(TestMethod3)
		{
			vector<vector<Rationalnumber>> NewMatrix;
			vector<vector<Rationalnumber>> InversMatrix;
			NewMatrix = generateMatrix(3, 1, 5, 1, 5);
			InversMatrix = inversionGaus(NewMatrix);
			Rationalnumber D = Determinant(InversMatrix, InversMatrix.size());
			Assert::IsTrue(D.m != 0);

		}

		TEST_METHOD(TestMethod4)
		{
			vector<vector<Rationalnumber>> NewMatrix;
			vector<vector<Rationalnumber>> InversMatrix;
			NewMatrix = generateMatrix(2, -10, 5, 1, 5);
			InversMatrix = inversionGaus(NewMatrix);
			Rationalnumber D = Determinant(InversMatrix, InversMatrix.size());
			Assert::IsTrue(D.m != 0);

		}

		TEST_METHOD(TestMethod5)
		{
			vector<vector<Rationalnumber>> NewMatrix;
			vector<vector<Rationalnumber>> InversMatrix;
			NewMatrix = generateMatrix(1, 1, 5, 1, 5);
			InversMatrix = inversionGaus(NewMatrix);
			Rationalnumber D = Determinant(InversMatrix, InversMatrix.size());
			Assert::IsTrue(D.m != 0);

		}

		TEST_METHOD(TestMethod6)
		{
			vector<vector<Rationalnumber>> NewMatrix;
			vector<vector<Rationalnumber>> InversMatrix;
			NewMatrix = generateMatrix(2, -5, 5, 1, 5);
			InversMatrix = inversionGaus(NewMatrix);
			Rationalnumber D = Determinant(InversMatrix, InversMatrix.size());
			Assert::IsTrue(D.m != 0);

		}

		TEST_METHOD(TestMethod7)
		{
			vector<vector<Rationalnumber>> NewMatrix;
			vector<vector<Rationalnumber>> InversMatrix;
			NewMatrix = generateMatrix(2, 1, 7, 1, 7);
			InversMatrix = inversionGaus(NewMatrix);
			Rationalnumber D = Determinant(InversMatrix, InversMatrix.size());
			Assert::IsTrue(D.m != 0);

		}

		TEST_METHOD(TestMethod8)
		{
			vector<vector<Rationalnumber>> NewMatrix;
			vector<vector<Rationalnumber>> InversMatrix;
			NewMatrix = generateMatrix(4, 1, 5, 1, 5);
			InversMatrix = inversionGaus(NewMatrix);
			Rationalnumber D = Determinant(InversMatrix, InversMatrix.size());
			Assert::IsTrue(D.m != 0);

		}

		TEST_METHOD(TestMethod9)
		{
			vector<vector<Rationalnumber>> NewMatrix;
			vector<vector<Rationalnumber>> InversMatrix;
			NewMatrix = generateMatrix(2, -5, 5, 1, 5);
			InversMatrix = inversionGaus(NewMatrix);
			Rationalnumber D = Determinant(InversMatrix, InversMatrix.size());
			Assert::IsTrue(D.m != 0);

		}

		TEST_METHOD(TestMethod10)
		{
			vector<vector<Rationalnumber>> NewMatrix;
			vector<vector<Rationalnumber>> InversMatrix;
			NewMatrix = generateMatrix(2, 1, 5, 1, 9);
			InversMatrix = inversionGaus(NewMatrix);
			Rationalnumber D = Determinant(InversMatrix, InversMatrix.size());
			Assert::IsTrue(D.m != 0);

		}

	};
}
