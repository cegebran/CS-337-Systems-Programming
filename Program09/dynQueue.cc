// dynQueue.cc
template <class T>
dynQueue<T>::dynQueue()
{
	this->set_tail(0);
	this->set_cap(1);
	T * array;
	array = new T[1];
	this->set_array(array);
}

template <class T>
void dynQueue<T>::increaseCapacity(int prevCap)
{
	int newCapacity = prevCap * 2;
	capacity = newCapacity;
	T * newArray;
	newArray = new T[newCapacity];

	int ct = 0;
	while(ct < prevCap + 1){
		newArray[ct] = this->array[ct];
		ct++;
	}

	delete(this->array);

	this->capacity = newCapacity;
	this->array = newArray;
}

template <class T>
void dynQueue<T>::decreaseCapacity(int prevCap)
{
	int newCapacity = prevCap / 2;
	capacity = newCapacity;
	T * newArray;
	newArray = new T[newCapacity];

	int ct = 0;
	while(ct < newCapacity){
		newArray[ct] = this->array[ct];
		ct++;
	}

	delete(this->array);

	this->capacity = newCapacity;
	this->array = newArray;
}

template <class T>
void dynQueue<T>::set_tail(int newTail)
{
	this->tail = newTail;
}

template <class T>
void dynQueue<T>::set_cap(int newCap)
{
	this->capacity = newCap;
}

template <class T>
void dynQueue<T>::set_array(T* newArray)
{
	this->array = newArray;
}

template <class T>
int dynQueue<T>::get_tail() const
{
	return this->tail;
}

template <class T>
int dynQueue<T>::get_cap() const
{
	return this->capacity;
}

template <class T>
T* dynQueue<T>::get_Array() const
{
	return this->array;
}

template <class T>
bool dynQueue<T>::getFullRatio() const
{
	int tailPt = this->tail;
	int aCap = this->capacity;

	int testCap = aCap;
	if(tailPt == testCap){
		return true;
	}else{
		return false;
	}
}

template <class T>
bool dynQueue<T>::getEmptyRatio() const
{
	int tailPt = this->tail;

	if(tailPt == 0){
		return true;
	}else{
		return false;
	}
}

template <class T>
bool dynQueue<T>::getHalfFullRatio() const
{
	int tailPt = this->tail;
	int aCap = this->capacity;

	float ratio = ((float) tailPt) / ((float) aCap);

	float compValue = .500;
 
	if(ratio < compValue){
		return true;
	}else{
		return false;
	}
}
// utility

template <class T>
dynQueue<T> &dynQueue<T>::operator+= (T r)
{
	int tailVal = this->get_tail();

	T* arrayInput = this->get_Array();
	arrayInput[tailVal] = r;
	this->set_array(arrayInput);
	++tailVal;
	this->set_tail(tailVal);

	bool fullQ = this->getFullRatio();
	if(fullQ == true)
	{
		int capacity = this->get_cap();
		this->increaseCapacity(capacity);
	}
}

template <class T>
dynQueue<T> &dynQueue<T>::operator-= (const dynQueue<T> &obj)
{
	bool emptyQ = obj.getEmptyRatio();
	if(emptyQ == false){
		int cap = obj.get_cap();
		T* arrayInput = obj.get_Array();

		dynQueue<T> returnVal = obj;

		int ct = 0;
		int ctCap = cap - 1;
		while(ct < ctCap){
			arrayInput[ct] = arrayInput[ct + 1];
			ct++;
		}
		arrayInput[(cap-1)] = 0;

		this->set_array(arrayInput);
		this->set_tail((this->get_tail() - 1));
		bool retVal = this->getHalfFullRatio();
		if(retVal == true)
		{
			this->decreaseCapacity(cap);
		}
	}
}

template <class T>
ostream &operator<< (ostream &outs, const dynQueue<T> &obj)
{
	int size = obj.get_cap();
	int tail = obj.get_tail();
	T* arrayToPrint = obj.get_Array();

	outs << "Front |";

	int capCt = 0;
	int tailCt = 0;
	T print;
	while(capCt < size)
	{
		if(tailCt < tail){
			print = arrayToPrint[tailCt];
			outs << print;
			arrayToPrint[tailCt] = print;
			tailCt++;
		}else{
			outs << "-";
		}

		if(capCt + 1 < size){
			outs << "|";
		}
		capCt++;
	}

	outs << "| Back";
	return outs;
}
