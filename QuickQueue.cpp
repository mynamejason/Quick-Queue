#include "QuickQueue.hpp"

template<typename T>
QuickQueue<T>::QuickQueue() {
	first = myVector_.begin();
	last = myVector_.begin();
	itemCount = 0;
}

template<typename T>
QuickQueue<T>::~QuickQueue() {

}

template<typename T>
T& QuickQueue<T>::head() {
	if(myVector_.size() > 0 && !myVector_.empty()) {
		if(myVector_.size() == 1) {
			return myVector_[0];
		} else {
			return *first;
		}
	} else {
		return *first;
	}
}

template<typename T>
T& QuickQueue<T>::tail() {
	last--;
	T& result = *last;	
	last++;
	return result;
}

template<typename T>
void QuickQueue<T>::add(const T& input) {
	if(itemCount == 0) {
		myVector_.resize(10);
		first = myVector_.begin();
		last = myVector_.begin();
		*first = input;
	} else {
		if(itemCount == myVector_.size()) {
			reallocateQueue();
		} else if(last > myVector_.begin() + itemCount) {
			last = myVector_.begin();
		} else if(last == first) {
			rearrangeQueue();
		}
		*last = input;
	}
	itemCount++;
	last++;
}

template<typename T>
void QuickQueue<T>::pop() {
	if(itemCount == 0) {
		std::cout << "No elements" << std::endl;
	} else {
		first++;
		itemCount--;
	}
}

template<typename T>
void QuickQueue<T>::shrink() {
	typename std::vector<T>::iterator travelPtr = first;
	std::vector<T> tempVector(itemCount);
	int reallocatedNum = 0;
	for(auto i = myVector_.begin(); i < last; i++) {
		reallocatedNum++;
	}

	int counter = 0;
	if(itemCount == 0) {
		myVector_.clear();
		myVector_.shrink_to_fit();
	} else {
		for(int i = 0; i < tempVector.size(); i++) {
			if(reallocatedNum > 0) {
				if(itemCount == counter + reallocatedNum) {
					travelPtr = myVector_.begin();
				}
			}
			tempVector[i] = *travelPtr;
			travelPtr++;
			counter++;
		}

		myVector_ = tempVector;
		myVector_.shrink_to_fit();
		first = myVector_.begin();
		last = first + itemCount;
	}
}

template<typename T>
void QuickQueue<T>::reallocateQueue() {
	typename std::vector<T>::iterator travelPtr = first;
	std::vector<T> tempVector(myVector_.size() * 2);

	for(int i = 0; i < myVector_.size(); i++) {
		if(travelPtr == myVector_.end()) {
			travelPtr = myVector_.begin();
		}

		tempVector[i] = *travelPtr; 
		travelPtr++;
	}

	myVector_ = tempVector;
	first = myVector_.begin();
	last = first + itemCount;
}

template<typename T>
void QuickQueue<T>::rearrangeQueue() {
	typename std::vector<T>::iterator travelPtr = first;
	std::vector<T> tempVector(myVector_.size());

	for(int i = 0; i < itemCount; i++) {
		if(travelPtr == myVector_.begin() + itemCount) {
			travelPtr = myVector_.begin();
		}
		tempVector[i] = *travelPtr;
		travelPtr++;
	}

	myVector_ = tempVector;
	first = myVector_.begin();
	last = first + itemCount;
}

template<typename T>
void QuickQueue<T>::info() {
	std::cout << "---------info()----------" << std::endl;
	std::cout << "size: " << myVector_.size() << std::endl;
	std::cout << "capacity: " << myVector_.capacity() << std::endl;
	std::cout << "itemCount: " << itemCount << std::endl;
	std::cout << "head: " << head() << std::endl;
	std::cout << "tail: " << tail() << std::endl;
	std::cout << "first: " << &(*first) << std::endl;
	std::cout << "last: " << &(*last) << std::endl;
	
	for(int i = 0; i < myVector_.size(); i++) {
		std::cout << &myVector_[i] << ", " << myVector_[i] << std::endl;
	}
}