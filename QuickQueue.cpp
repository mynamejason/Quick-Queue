#include "QuickQueue.hpp"

template<typename T>
T& QuickQueue<T>::head(){
	if(myVector_.size() > 0){
		if(myVector_.size() == 1){
			return myVector_[0];
		} else{
			return myVector_[]
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
void QuickQueue<T>::add(const T& input){
	myVector_.push_back(input);
	info();
}

template<typename T>
void QuickQueue<T>::pop(){
	std::cout << "pop: " << head() << std::endl;
	for(int i = 0; i < myVector_.size(); i++){
		if(myVector_[i] == head()){
			myVector_[i] = 0;
			
		}
	}
	
	info();
}

template<typename T>
void QuickQueue<T>::info(){
	std::cout << "---------info()----------" << std::endl;
	std::cout << "size: " << myVector_.size() << std::endl;
	std::cout << "capacity: " << myVector_.capacity() << std::endl;
	std::cout << "head: " << head() << std::endl;
	std::cout << "tail: " << tail() << std::endl;
	for(int i = 0; i < myVector_.size(); i++){
		std::cout << myVector_[i] << ", " << &myVector_[i] << std::endl;
	}
}