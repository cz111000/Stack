#include "Stack.h"

template<class T>
Stack<T>::Stack()
{
	list = new LinkedList<T>();
}

template<class T>
Stack<T>::~Stack()
{
	delete list;
}

template<class T>
void Stack<T>::push(T &object)
{
	list->addFirst(*new T(object));
}

template<class T>
T Stack<T>::pop()
{
	T temp = list->getFirst();
	list->removeFirst();
	return temp;
}

template<class T>
bool Stack<T>::isEmpty()
{
	return list->size() == 0;
}

template<class T>
int Stack<T>::size()
{
	return list->size();
}