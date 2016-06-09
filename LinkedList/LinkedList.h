template<class T>
class LinkedList
{
private:
	class Node
	{
	private:
		T* object;
		Node* next;
	public:
		Node(T* object,Node* next):object(object),next(next){}
		~Node(){delete object;}
		T* get() { return object; }
		Node* getNext(){return next;}
		void setNext(Node* next){this->next = next;}
	};
	int length;
	Node* pHead;
	Node* pLast;
	public:
		LinkedList();
		LinkedList(T arr[], int n);
		LinkedList(LinkedList &list);
		virtual ~LinkedList();
		void addFirst(T& object);
		void add(T& object, int n);
		void addLast(T& object);
		void removeFirst();
		void remove(int n);
		void removeLast();
		int size();
		T getFirst() const;
		T get(int n) const;
		T getLast() const;
};
