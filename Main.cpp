#include <iostream>
#include "List.h"

template <typename T>
void DoubleMin(List<T> list)
{
	if (!list.empty)
	{
		
	}
	else
	{
		std::cout << "List is empty!\a\n";
	}
}

int main()
{
	List<int> object({ 1,5,5,5,5,5,2 });
	/*object.push_back(15);
	object.push_back(10);
	object.push_front(3);
	object.push_back(13);
	object.push_back(11);
	object.push_front(2);
	object.show();
	std::cout << "\n" << object.size() << "\n";
	object.push_back(1);
	object.push_back(4);
	object.push_front(8);*/
	object.assign(5, 1);
	//object.show();
	std::cout << "\n";
	//object.insert(0, 5);
	object.show();
	std::cout << "\n";
	system("pause");
}