#include "Stack.cpp"
#include <iostream>

using namespace std;

class A
{
private:
	int a;
public:
	A(int a = 3):a(a) {}
	~A() {}
	friend ostream& operator<<(ostream& out,A& a);
};

ostream& operator<<(ostream& out,A& a)
{
	out << a.a;
	return out;
}

int main(int argc,char* argv[])
{
	Stack<A> s;
	cout << s.size() << endl;
	s.push(*new A(1));
	s.push(*new A(2));
	s.push(*new A(3));
	cout << s.size() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	system("pause");
	return 0;
}