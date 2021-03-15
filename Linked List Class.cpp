#include <iostream>
#include "Linked_List.h"
#include "Node.h"
#include "Iterator.h"

int main()
{
	Linked_List<int> int_test;
	int_test.push_back(1);
	for (int i = 0; i != 6; ++i)
		int_test.push_back(i);

	//std::cout << int_test.front();
	for (auto i = int_test.begin(); i != int_test.end(); ++i)
	{
		std::cout << *i << ", ";
	}
	std::cout << std::endl;
	int_test.insert(4, 3);
	int_test.remove(2);
	Linked_List<int> int2(int_test);
	int2.remove(3);
	int2.insert(3, 4);
	for (auto i = int2.begin(); i != int2.end(); ++i)
	{
		std::cout << *i << ", ";
	}
	auto it_test = int_test.begin();
	std::cout << std::endl << *(it_test + 2) << std::endl << int_test.size() << std::endl;

}
