// dynQueue.h
#include <iostream>

using namespace std;

// class definition
template <class T>
class dynQueue
{

	private:
		T* array;
		int tail;
		int capacity;

		void increaseCapacity(int prevCap);	// T ?
		void decreaseCapacity(int prevCap);
		void set_tail(int newTail);
		void set_cap(int newCap);
		void set_array(T* newArray);
	public:
		dynQueue();

		int get_tail() const;
		int get_cap() const;
		T* get_Array() const;
		bool getFullRatio() const;
		bool getEmptyRatio() const;
		bool getHalfFullRatio() const;

		dynQueue<T> &operator+= (T r);


		dynQueue<T> &operator-= (const dynQueue<T> &obj);

		template <class TT>
		friend ostream &operator<< (ostream &outs, const dynQueue<TT> &obj);

		//~dynQueue();
};

#include "dynQueue.cc"
