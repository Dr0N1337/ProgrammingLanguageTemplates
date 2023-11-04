#include "pch.h"
#include "CppUnitTest.h"
#include "../TemplateList/SingleList.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace rut::miit;
namespace SinglyLinkedListTest
{
	
	TEST_CLASS(SinglyLinkedListTest)
	{
	public:
		TEST_METHOD(PushBack_ValidData_Success)
		{
			SingleList<int> list;
			list.pushBack(1);
			list.pushBack(2);
			Assert::IsTrue(list.toString() == "1 2 ");
		}

		TEST_METHOD(PushFront_ValidData_Success)
		{
			SingleList<int> list;
			list.pushFront(1);
			list.pushFront(2);
			Assert::IsTrue(list.toString() == "2 1 ");
		}

		TEST_METHOD(GetSize_ValidData_Success)
		{
			SingleList<int> list;
			list.pushFront(1);
			list.pushFront(2);
			Assert::IsTrue(list.getSize() == 2);
		}

		TEST_METHOD(SquareBracketsOperator_ValidData_Success)
		{
			SingleList<int> list;
			list.pushFront(1);
			list.pushFront(2);
			Assert::IsTrue(list[0] == 2);
		}

		TEST_METHOD(IsCollectionClear_ValidData_Success)
		{
			SingleList<int> list;
			Assert::IsTrue(list.isEmpty());
		}


		TEST_METHOD(ComparionOperator_ValidData_Success)
		{
			SingleList<int> list1;
			list1.pushFront(1);
			list1.pushFront(2);

			SingleList<int> list2;
			list2.pushFront(1);
			list2.pushFront(2);

			Assert::IsTrue(list1 == list2);
		}

		TEST_METHOD(CopyOperator_ValidData_Succeess)
		{
			SingleList<int> list1;

			SingleList<int> list2;
			list2.pushFront(3);
			list2.pushFront(4);

			list1 = list2;
			Assert::IsTrue(list1 == list2);
		}
		TEST_METHOD(String_ValidData_Succeess)
		{
			SingleList<std::string> a1;
			std::string str1 = "qwe";
			a1.pushBack(str1);
			SingleList<std::string> a2;
			a2.pushBack(str1);
			a2 = a1;
            Assert::IsTrue(a1 == a2);
		}
	};
}