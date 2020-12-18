#include <iostream>
#include <initializer_list>
template <typename T>
class List
{
private:

	//Создаем шаблон класса элемента односвязного списка
	template <typename T>
	class Element
	{
	public:
		Element* pNext; //Указатель на следующий элемент. По умолчаниею NULL
		Element* pPrev; //Указатель на предыдущий элемент. По умолчаниею NULL
		T value; //Данные в элементе
		Element(T value, Element* pNext = nullptr, Element* pPrev = nullptr) //Инициализация элемента через конструктор
		{
			this->pNext = pNext;
			this->pPrev = pPrev;
			this->value = value;
		}
	};

	short length; //Длина списка
	Element<T>* headElement; //Первый элемент списка
	Element<T>* tailElement; //Последний элемент списка

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

//Конструктор класса List по умолчанию.
template <typename T>
List<T>::List()
{
	length = 0;
	headElement = nullptr;
	tailElement = nullptr;
}

//Конструктор класса List с одним агрументом.
template <typename T>
List<T>::List(T value)
{
	length = 1;
	headElement = new Element<T>(value,nullptr, nullptr);
	tailElement = nullptr;

}

//Конструктор класса List со списком аргументов.
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

//Метод добавляет новый элемент в конец списка.
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

//Метод добавляет новый элемент в начало списка.
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

//Метод заменяет содержимое контейнера N элементами, которые имеют значение Value.
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

//Метод возвращает первый элемент в списке.
template<typename T>
T List<T>::front()
{
	return headElement->value;
}

//Метод возвращает последний элемент в списке.
template<typename T>
T List<T>::back()
{
	return tailElement->value;
}

//Метод полностью очищает список.
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

//Метод демнострирует все элементы списка. (!!!ВРЕМЕННЫЙ МЕТОД!!!)
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

//Деструктор класса List
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

//Метод возвращает длину списка.
template <typename T>
T List<T>::size()
{
	return length;
}

//Метод оставляет Elements первых элементов списка. Если элементов меньше, чем Elements, то добавляются элементы со значением по умолчанию.
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

//Метод оставляет Elements первых элементов списка. Если элементов меньше, чем Elements, то добавляются элементы со значением Value.
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

//Метод удаляет последний элемент списка.
template<typename T>
void List<T>::pop_back()
{
	length--;
	Element<T>* transit = tailElement->pPrev;
	delete transit->pNext;
	tailElement = transit;
}

//Метод удаляет первый элемент списка.
template<typename T>
void List<T>::pop_front()
{
	length--;
	Element<T>* transit = headElement->pNext;
	delete transit->pPrev;
	headElement = transit;
}

//Метод возвращает ИСТИНО если список пустой, и ЛОЖНО если нет.
template<typename T>
bool List<T>::empty()
{
	if (length == 0)
		return true;
	else
		return false;
}
