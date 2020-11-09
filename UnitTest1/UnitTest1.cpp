#include "pch.h"
#include "CppUnitTest.h"
#include "../лаба1_аистд/List.h"
#include "../лаба1_аистд/List.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		List a;
		TEST_METHOD(push_back)
		{
			a.push_back(10);
			a.push_back(2);
			Assert::AreEqual(a.at(0), 10);
			Assert::AreEqual(a.at(1),2);
		}
		TEST_METHOD(push_front)
		{
			a.push_front(11);
			a.push_front(12);
			a.push_front(13);
			Assert::AreEqual(a.at(0), 13);
			Assert::AreEqual(a.at(1), 12);
			Assert::AreEqual(a.at(2), 11);
		}
		TEST_METHOD(pop_back)
		{
			a.push_back(10);
			a.pop_back();
			Assert::AreNotEqual(a.at(0), 10);
		}
		TEST_METHOD(pop_front)
		{

			a.push_back(10);
			a.push_back(2);
			a.pop_front();
			Assert::AreEqual(a.at(0), 2);
		}
		TEST_METHOD(insert)
		{
			a.push_back(1);
			a.push_back(2);
			a.push_back(17);
			a.push_back(20);
			a.insert(180, 2);
			Assert::AreEqual(a.at(1), 2);
			Assert::AreEqual(a.at(2), 180);
			Assert::AreEqual(a.at(3), 17);
			Assert::AreEqual(a.at(4), 20);
		}
		TEST_METHOD(at)
		{
			a.push_back(130);
			a.push_back(-16);
			Assert::AreEqual(a.at(0), 130);
			Assert::AreEqual(a.at(1), -16);
		}
		TEST_METHOD(remove)
		{

			a.push_back(1);
			a.push_back(2);
			a.push_back(17);
			Assert::AreEqual(a.at(1), 2);
			a.remove(1);
			Assert::AreEqual(a.at(1), 17);
			Assert::AreEqual((int)a.get_size(), 2);
		}
		TEST_METHOD(clear)
		{
			a.push_back(1);
			a.push_back(2);
			a.push_back(17);
			Assert::AreEqual((int)a.get_size(), 3);
			a.clear();
			Assert::AreEqual((int)a.get_size(), 0);
		}
		TEST_METHOD(set)
		{
			a.push_back(20);
			Assert::AreEqual(a.at(0), 20);
			a.set(0, 120);
			Assert::AreEqual(a.at(0), 120);
		}
		TEST_METHOD(isEmpty)
		{
			a.push_back(1);
			a.push_back(2);
			a.push_back(17);
			Assert::AreEqual(a.isEmpty(), false);
			a.clear();
			Assert::AreEqual(a.isEmpty(), true);
		}
		List a2;
		TEST_METHOD(findfirst)
		{
			for (int i = 0; i < 10; i++)
			{
				a.push_back(i * 10);
				if (i >= 5)
				{
					a2.push_back(i * 10);
				}
			}
			
			Assert::AreEqual((int)a.find_first(&a2), 5);
		}
	};
}
