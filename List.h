#include <iostream>
#include <initializer_list>
template <typename T>
class List
{
private:

	//������� ������ ������ �������� ������������ ������
	template <typename T>
	class Element
	{
	public:
		Element* pNext; //��������� �� ��������� �������. �� ���������� NULL
		Element* pPrev; //��������� �� ���������� �������. �� ���������� NULL
		T value; //������ � ��������
		Element(T value, Element* pNext = nullptr, Element* pPrev = nullptr) //������������� �������� ����� �����������
		{
			this->pNext = pNext;
			this->pPrev = pPrev;
			this->value = value;
		}
	};

	short length; //����� ������
	Element<T>* headElement; //������ ������� ������
	Element<T>* tailElement; //��������� ������� ������

public:
	List();
	List(T value);
	~List();
	T size();
	void resize(unsigned short elements);
	void resize(unsigned short elements, T value);
	void pop_back();
	void pop_front();
	bool empty();
	void push_back(T data);
	void push_front(T data);
	void assign(unsigned short n, T value);
	void insert(unsigned short pos, T value);
	T front();
	T back();
	void clear();
	void show();

	List(std::initializer_list<T> value);

};

//����������� ������ List �� ���������.
template <typename T>
List<T>::List()
{
	length = 0;
	headElement = nullptr;
	tailElement = nullptr;
}

//����������� ������ List � ����� ����������.
template <typename T>
List<T>::List(T value)
{
	length = 1;
	headElement = new Element<T>(value,nullptr, nullptr);
	tailElement = nullptr;

}

//����������� ������ List �� ������� ����������.
template <typename T>
List<T>::List(std::initializer_list<T> value)
{
	length = value.size();
	headElement = new Element<T>(*(value.begin()), nullptr, nullptr);
	Element<T>* runningElement = headElement;
	for (unsigned short step(1); step < length; step++)
	{
		runningElement->pNext = new Element<T>(*(value.begin() + step),nullptr, runningElement);
		runningElement = runningElement->pNext;
	}
	tailElement = runningElement;

}

//����� ��������� ����� ������� � ����� ������.
template<typename T>
void List<T>::push_back(T data)
{
	if (headElement == nullptr)
	{
		headElement = new Element<T>(data);
		length++;
	}
	else
	{
		Element<T>* runningElement = this->headElement;
		while (runningElement->pNext != nullptr)
		{
			runningElement = runningElement->pNext;
		}
		runningElement->pNext = new Element<T>(data);
		tailElement = runningElement->pNext;
		tailElement->pPrev = runningElement;
		length++;
	}
}

//����� ��������� ����� ������� � ������ ������.
template<typename T>
void List<T>::push_front(T data)
{
	if (headElement == nullptr)
	{
		headElement = new Element<T>(data);
		length++;
	}
	else
	{
		Element<T>* runningElement = new Element<T>(data, this->headElement);
		headElement->pPrev = runningElement;
		headElement = runningElement;
		length++;
	}
}

//����� �������� ���������� ���������� N ����������, ������� ����� �������� Value.
template<typename T>
void List<T>::assign(unsigned short n, T value)
{
	Element<T>* runningElement = tailElement;
	for (unsigned short steps(length); steps > 0; steps--)
	{
		length--;
		runningElement = tailElement->pPrev;
		delete tailElement;
		tailElement = runningElement;
	}
	headElement = nullptr;
	tailElement = nullptr;
	headElement = new Element<T>(value, nullptr, nullptr);
	runningElement = headElement;
	for (unsigned short step(0); step < n; step++)
	{
		runningElement->pNext = new Element<T>(value, nullptr, runningElement);
		runningElement = runningElement->pNext;
		tailElement = runningElement;
		length++;
	}
}

template<typename T>
void List<T>::insert(unsigned short pos, T value)
{
	if (pos < length)
	{
		Element<T>* runningElement = headElement;
		for (unsigned short place(1); place < pos; place++)
		{
			runningElement = runningElement->pNext;
		}
		if (pos == 0)
		{
			length++;
			Element<T>* newElement = new Element<T>(value, headElement, nullptr);
			headElement->pPrev = newElement;
			headElement = newElement;

		}
		else
		{
			Element<T>* newElement = new Element<T>(value, runningElement->pNext, runningElement);
			Element<T>* transit = runningElement->pNext;
			newElement->pNext = transit;
			runningElement->pNext = newElement;
			transit->pPrev = newElement;
			length++;
		}
	}
	else
	{
		std::cout << "Error! Not enough elements.";
	}
}

//����� ���������� ������ ������� � ������.
template<typename T>
T List<T>::front()
{
	return headElement->value;
}

//����� ���������� ��������� ������� � ������.
template<typename T>
T List<T>::back()
{
	return tailElement->value;
}

//����� ��������� ������� ������.
template<typename T>
void List<T>::clear()
{
	Element<T>* runningElement = tailElement;
	for (unsigned short steps(length); steps != 0; steps--)
	{
		length = steps;
		runningElement = tailElement->pPrev;
		delete tailElement;
		tailElement = runningElement;
	}
	length--;
	headElement = nullptr;
	tailElement = nullptr;
}

//����� ������������� ��� �������� ������. (!!!��������� �����!!!)
template<typename T>
void List<T>::show()
{
	if (length != 0)
	{
		Element<T>* runningElement = this->headElement;
		for (unsigned short steps(0); steps < length; steps++)
		{
			std::cout << runningElement->value;
			runningElement = runningElement->pNext;
		}
	}
	else
	{
		std::cout << "No elements\n";
	}
	std::cout << "\n";
}

//���������� ������ List
template <typename T>
List<T>::~List()
{
	Element<T>* runningElement = tailElement;
	for (unsigned short steps(length); steps != 0; steps--)
	{
		runningElement = tailElement->pPrev;
		delete tailElement;
		tailElement = runningElement;
	}
	delete tailElement, headElement, runningElement;
}

//����� ���������� ����� ������.
template <typename T>
T List<T>::size()
{
	return length;
}

//����� ��������� Elements ������ ��������� ������. ���� ��������� ������, ��� Elements, �� ����������� �������� �� ��������� �� ���������.
template<typename T>
void List<T>::resize(unsigned short elements)
{
	if (length > elements)
	{
		Element<T>* runningElement = tailElement->pPrev;
		while (length != elements)
		{
			length--;
			delete runningElement->pNext;
			runningElement = runningElement->pPrev;
		}
		tailElement = runningElement->pNext;
	}
	else if(length < elements)
	{
		while (length != elements)
		{
			length++;
			tailElement->pNext = new Element<int>(T(), nullptr, tailElement);
			tailElement = tailElement->pNext;
		}
	}
}

//����� ��������� Elements ������ ��������� ������. ���� ��������� ������, ��� Elements, �� ����������� �������� �� ��������� Value.
template<typename T>
void List<T>::resize(unsigned short elements, T value)
{
	if (length > elements)
	{
		Element<T>* runningElement = tailElement->pPrev;
		while (length != elements)
		{
			length--;
			delete runningElement->pNext;
			runningElement = runningElement->pPrev;
		}
		tailElement = runningElement->pNext;
	}
	else if (length < elements)
	{
		while (length != elements)
		{
			length++;
			tailElement->pNext = new Element<int>(value, nullptr, tailElement);
			tailElement = tailElement->pNext;
		}
	}
}

//����� ������� ��������� ������� ������.
template<typename T>
void List<T>::pop_back()
{
	length--;
	Element<T>* transit = tailElement->pPrev;
	delete transit->pNext;
	tailElement = transit;
}

//����� ������� ������ ������� ������.
template<typename T>
void List<T>::pop_front()
{
	length--;
	Element<T>* transit = headElement->pNext;
	delete transit->pPrev;
	headElement = transit;
}

//����� ���������� ������ ���� ������ ������, � ����� ���� ���.
template<typename T>
bool List<T>::empty()
{
	if (length == 0)
		return true;
	else
		return false;
}
