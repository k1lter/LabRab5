#include <iostream>
#include "List.h"

void DoubleMin(List<double>* object)
{
	double min = DBL_MAX;
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
	List<double> object({ 3, 2, 3 });
	object.show();
	DoubleMin(&object);
	object.show();
	system("pause");
}