#include "LinkedList.h"
#include <iostream>
using namespace std;

template<class T>
LinkedList<T>::LinkedList()
{
	pLast = pHead = new Node(NULL,NULL);
	length = 0;
}

template<class T>
LinkedList<T>::LinkedList(T arr[], int n)
{
	pLast = pHead = new Node(NULL, NULL);
	length = 0;
	for(int i = 0;i < n;i++)
		addLast(&arr[i]);
}

template<class T>
LinkedList<T>::LinkedList(LinkedList<T> &list)
{
	pLast = pHead = new Node(NULL, NULL);
	length = 0;
	int n = list.size();
	for(int i = 0;i < n;i++)
	{
		T* temp = new T(list.get(i + 1));
		addLast(temp);
	}
}

template<class T>
LinkedList<T>::~LinkedList()
{
	Node* temp = pHead;
	while (pHead)
	{
		temp = pHead;
		pHead = pHead->getNext();
		delete temp;
	}
}

template<class T>
void LinkedList<T>::addFirst(T& object)
{
	add(object, 1);
}

template<class T>
void LinkedList<T>::add(T& object, int n)
{
	if (n < 1 || n > length + 1)
		return;
	Node* temp = pHead;
	while (--n) { temp = temp->getNext();}
	temp->setNext(new Node(new T(object), temp->getNext()));
	temp = temp->getNext();
	length++;
	if (temp->getNext() == NULL)
		pLast = temp;
}

template<class T>
void LinkedList<T>::addLast(T& object)
{
	//add(object, length + 1);
	pLast->setNext(new Node(new T(object), pLast->getNext()));
	pLast = pLast->getNext();
	length++;
}

template<class T>
void LinkedList<T>::removeFirst()
{
	remove(1);
}

template<class T>
void LinkedList<T>::remove(int n)
{
	if (n < 1 || n > length)
		return;
	Node* temp = pHead;
	while (--n) { temp = temp->getNext(); }
	Node* pOld = temp->getNext();
	temp->setNext(temp->getNext()->getNext());
	delete pOld;
	length--;
	if (temp->getNext() == NULL)
		pLast = temp;
}

template<class T>
void LinkedList<T>::removeLast()
{
	remove(length);
}

template<class T>
int LinkedList<T>::size()
{
	return length;
}

template<class T>
T LinkedList<T>::getFirst() const
{
	return get(1);
}

template<class T>
T LinkedList<T>::get(int n) const
{
	Node* temp = pHead;
	while (n--) { temp = temp->getNext(); }
	return *(temp->get());
}

template<class T>
T LinkedList<T>::getLast() const
{
	return *(pLast->get());
}