#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP1.4/Complex.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ComplexTests
{
    TEST_CLASS(ComplexTests)
    {
    public:

        TEST_METHOD(TestSetReal)
        {
            Complex c;

            Assert::IsTrue(c.setReal(5.5));
            Assert::AreEqual(5.5, c.getReal(), 0.0001);
        }

        TEST_METHOD(TestSetImag)
        {
            Complex c;

            Assert::IsTrue(c.setImag(-3.5));
            Assert::AreEqual(-3.5, c.getImag(), 0.0001);
        }

        TEST_METHOD(TestInit)
        {
            Complex c;

            Assert::IsTrue(c.Init(4, -7));

            Assert::AreEqual(4.0, c.getReal(), 0.0001);
            Assert::AreEqual(-7.0, c.getImag(), 0.0001);
        }

        TEST_METHOD(TestToStringPositive)
        {
            Complex c;

            c.Init(5, 3);

            Assert::AreEqual(
                string("5 + 3i"),
                c.toString()
            );
        }

        TEST_METHOD(TestToStringNegative)
        {
            Complex c;

            c.Init(5, -3);

            Assert::AreEqual(
                string("5 - 3i"),
                c.toString()
            );
        }

        TEST_METHOD(TestAddition)
        {
            Complex c1;
            Complex c2;

            c1.Init(2, 3);
            c2.Init(4, 5);

            Complex result = c1.add(c2);

            Assert::AreEqual(6.0, result.getReal(), 0.0001);
            Assert::AreEqual(8.0, result.getImag(), 0.0001);
        }

        TEST_METHOD(TestSubtraction)
        {
            Complex c1;
            Complex c2;

            c1.Init(7, 5);
            c2.Init(2, 3);

            Complex result = c1.subtract(c2);

            Assert::AreEqual(5.0, result.getReal(), 0.0001);
            Assert::AreEqual(2.0, result.getImag(), 0.0001);
        }

        TEST_METHOD(TestMultiplication)
        {
            Complex c1;
            Complex c2;

            c1.Init(2, 3);
            c2.Init(4, 5);

            Complex result = c1.multiply(c2);

            Assert::AreEqual(-7.0, result.getReal(), 0.0001);
            Assert::AreEqual(22.0, result.getImag(), 0.0001);
        }
    };
}
