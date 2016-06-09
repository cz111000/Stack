template<class T>
class ArrayList
{
private:
	int next;
	int length;
	T* arr;
	public:
		ArrayList(int n = 10);
		ArrayList(T arr[], int n);
		ArrayList(ArrayList &list);
		virtual ~ArrayList();
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