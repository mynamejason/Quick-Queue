#ifndef QuickQueue_hpp
#define QuickQueue_hpp

#include <vector>
#include <iostream>

template<typename T>

class QuickQueue{
public:
	QuickQueue();
	~QuickQueue();

	T& head();
	T& tail();

	void pop(); //remove first element
	void add(const T& input);
	void reallocateQueue();

	void info();

	std::vector<T> myVector_;

	typename std::vector<T>::iterator first;
	typename std::vector<T>::iterator last;
	int itemCount;

private:

};

#include "QuickQueue.cpp"
#endif