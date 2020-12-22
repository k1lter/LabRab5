#include <iostream>
#include <string>
#include "List.h"

template <typename T>
void DoubleMin(List<T>* object)
{
	T min = T();
	std::string check = typeid(T).name();
	{
		if (check == "char")
		{
			min = CHAR_MAX;
		}
		else if (check == "short")
		{
			min = SHRT_MAX;
		}
		else if (check == "int")
		{
			min = INT_MAX;
		}
		else if (check == "long")
		{
			min = LONG_MAX;
		}
		else if (check == "float")
		{
			min = FLT_MAX;
		}
		else if (check == "double")
		{
			min = DBL_MAX;
		}
		else
		{
			std::cout << "Error! Wrong type!\n\a";
		}
	}
	unsigned short minPos = 1;
	if (object->size() > 1)
	{
		for (int i(0); i < object->size(); i++)
		{
			if (object->front() < min)
			{
				min = object->front();
				minPos = i;
			}
			object->push_back(object->front());
			object->pop_front();
		}
		double* save = new double[minPos];
		for (int i(0); i < minPos; i++)
		{
			save[i] = object->front();
			object->pop_front();
		}
		object->begin()->value *= 2;
		for (int i(minPos - 1); i >= 0; i--)
		{
			object->push_front(save[i]);
		}
	}
	else
	{
		object->begin()->value *= 2;
	}
}

int main()
{
	setlocale(LC_ALL, "russian");
	List<int> object({ 3, 2, 3 });
	object.insert(2, 5);
	std::cout << "До обработки:\n";
	object.show();
	DoubleMin(&object);
	std::cout << "После обработки:\n";
	object.show();
	system("pause");
}