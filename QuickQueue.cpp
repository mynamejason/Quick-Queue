#include "QuickQueue.hpp"

template<typename T>
QuickQueue<T>::QuickQueue(){
	first = myVector_.begin();
	last = myVector_.begin();
	itemCount = 0;
}

template<typename T>
QuickQueue<T>::~QuickQueue(){}

template<typename T>
T& QuickQueue<T>::head(){
	if(myVector_.size() > 0){
		if(myVector_.size() == 1){
			return myVector_[0];
		} else{
			//return myVector_[];
		}
	}
}

template<typename T>
T& QuickQueue<T>::tail(){
	if(myVector_.size() > 0){
		return myVector_[myVector_.size() - 1];
	}
}

template<typename T>
void QuickQueue<T>::add(const T& input) {
	if(itemCount == 0) { //very first add
		myVector_.resize(10);
		first = myVector_.begin();
		last = myVector_.begin();
		*first = input;
	}
	else { // second ++ add
		if(itemCount == myVector_.size()){
			// add && need to resize
			reallocateQueue();
			std::cout << "Triggered" << std::endl;
		}
		// add but there are empty whole && no need to resize
		// the (itr)last is pointing the last element of vector
//Super set of Vector
		// QuickQueue (= Vector
		// we can use Vector features
		// first, last, Head, Tail, vector.begin(), vector.begin() + itemcount
		else if(last > myVector_.begin() + itemCount) {
			last = myVector_.begin();
		}
		*last = input;
	}
	itemCount++;
	last++;
	//
	info();
}

template<typename T>
void QuickQueue<T>::pop() {
	if(itemCount == 0) {
		std::cout << "No elements" << std::endl;
	} else {
		*first = 0;
		first++;
		itemCount--;
	}
	
	info();
}

template<typename T>
void QuickQueue<T>::reallocateQueue(){
	myVector_.resize(myVector_.size() * 2);
	first = myVector_.begin();
	last = first + itemCount;
}

template<typename T>
void QuickQueue<T>::info(){
	std::cout << "---------info()----------" << std::endl;
	std::cout << "size: " << myVector_.size() << std::endl;
	std::cout << "capacity: " << myVector_.capacity() << std::endl;
	// std::cout << "head: " << head() << std::endl;
	// std::cout << "tail: " << tail() << std::endl;
	std::cout << "first: " << &(*first) << std::endl;
	std::cout << "last: " << &(*last) << std::endl;
	for(int i = 0; i < myVector_.size(); i++){
		std::cout << &myVector_[i] << ", " << myVector_[i] << std::endl;
	}
}