//#include "List.h"
//#include <iostream>
//
//template <typename T>
////����������� ������ List.
//List<T>::List()
//{
//	length = 0;
//	headElement = nullptr;
//}
//
//template<typename T>
////����� ��������� ����� ������� � ����� ������.
//void List<T>::push_back(T data)
//{
//	if (headElement == nullptr)
//	{
//		headElement = new Element<T>(data);
//		length++;
//	}
//	else
//	{
//		Element<T>* runningElement = this->headElement;
//		while (runningElement->pNext != nullptr)
//		{
//			runningElement = runningElement->pNext;
//		}
//		Element<T>* newTailElement = new Element<T>(data, runningElement);
//		delete runningElement;
//		length++;
//	}
//}
//
//template<typename T>
////����� ��������� ����� ������� � ������ ������.
//void List<T>::push_front(T data)
//{
//	
//}
//
//template<typename T>
////����� ���������� ������ ������� � ������.
//T List<T>::front()
//{
//	return headElement->value;
//}
//
//template<typename T>
////����� ���������� ��������� ������� � ������.
//T List<T>::back()
//{
//	return tailElement->value;
//}
//
//template<typename T>
////����� ������������� ��� �������� ������. (!!!��������� �����!!!)
//void List<T>::show()
//{
//	Element<T> runningElement = this->headElement;
//	for (short i(0); i < length; i++)
//	{
//		std::cout << runningElement.value << std::endl;
//		runningElement = runningElement.pNext;
//	}
//}
//
//template <typename T>
//List<T>::~List()
//{
//
//}
//
//template <typename T>
//T List<T>::size()
//{
//	return length;
//}
//
//template<typename T>
//bool List<T>::empty()
//{
//	if (length == 0)
//		return true;
//	else
//		return false;
//}
