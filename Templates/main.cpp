#include <iostream>
#include "../TemplateList/SingleList.h"

using namespace rut::miit;
int main()
{
	SingleList<int> list1;
	list1.pushBack(4);
	list1.pushBack(7);
	list1.pushFront(6);
	list1.pushBack(9);
	std::cout << list1.toString() << "\t";
	SingleList<int> list2;
	list2 = list1;

	std::cout << list2.toString();
	return 0;
}