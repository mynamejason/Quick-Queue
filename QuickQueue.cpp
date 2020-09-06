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
	if(itemCount == 0) {
		myVector_.resize(10);
		first = myVector_.begin();
		last = myVector_.begin();
		*first = input;
	}
	else if(itemCount == myVector_.size()) {
		myVector_.resize(myVector_.size() * 2);
		first = myVector_.begin();
		last = first + itemCount;
		*last = input;
	} else{
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