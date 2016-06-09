#include "LinkedList.cpp"

template<class T>
class Stack
{
private:
	LinkedList<T>* list;
public:
	Stack();
	~Stack();
	void push(T &object);
	T pop();
	bool isEmpty();
	int size();
};