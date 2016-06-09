#include "ArrayList.h"

template<class T>
ArrayList<T>::ArrayList(int n) :length(n), next(0)
{
	arr = new T[n];
}

template<class T>
ArrayList<T>::ArrayList(T arr[], int n) :length(n), next(n)
{
	this->arr = new T[n];
	for (int i = 0;i < n;i++)
		this->arr[i] = arr[i];
}

template<class T>
ArrayList<T>::ArrayList(ArrayList<T> &list) :length(list.size()), next(list.size())
{
	arr = new T[list.size()];
	for (int i = 0;i < list.size();i++)
		arr[i] = list.get(i);
}

template<class T>
ArrayList<T>::~ArrayList()
{
	delete[] arr;
}

template<class T>
void ArrayList<T>::addFirst(T& object)
{
	add(object, 1);
}

template<class T>
void ArrayList<T>::add(T& object, int n)
{
	if (n < 1 || n > next + 1)
		return;
	n--;
	if (next == length)
	{
		T* arrPlus = new T[length *= 2];
		for (int i = 0;i <= next;i++)
			*arrPlus++ = *arr++;
		arr = arrPlus;
	}
	for (int i = next++;i >= n;i--)
		arr[i + 1] = arr[i];
	arr[n] = object;
}

template<class T>
void ArrayList<T>::addLast(T& object)
{
	if (next == length)
	{
		T* arrPlus = new T[length *= 2];
		for (int i = 0;i <= next;i++)
			*arrPlus++ = *arr++;
		arr = arrPlus;
	}
	arr[next++] = object;
}

template<class T>
void ArrayList<T>::removeFirst()
{
	remove(1);
}

template<class T>
void ArrayList<T>::remove(int n)
{
	if (n < 1 || n > next)
		return;
	n--;
	for (int i = n;i < next;i++)
		arr[i] = arr[i + 1];
	next--;
}

template<class T>
void ArrayList<T>::removeLast()
{
	next--;
}

template<class T>
int ArrayList<T>::size()
{
	return next;
}

template<class T>
T ArrayList<T>::getFirst() const
{
	return get(1);
}

template<class T>
T ArrayList<T>::get(int n) const
{
	return arr[n - 1];
}

template<class T>
T ArrayList<T>::getLast() const
{
	return get(next);
}