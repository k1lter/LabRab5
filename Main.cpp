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
	List<int> object({5,1,5});
	object.show();
	object.assign(5, 1);
	object.show();
	system("pause");
}