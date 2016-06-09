#include "ArrayList.cpp"

template<class T>
class Stack
{
private:
	ArrayList<T>* list;
public:
	Stack();
	~Stack();
	void push(T &object);
	T pop();
	bool isEmpty();
	int size();
};