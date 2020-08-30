#ifndef QuickQueue_hpp
#define QuickQueue_hpp

#include <vector>
#include <iostream>

template<typename T>

class QuickQueue{
public:
	T& head();
	T& tail();

	void pop(); //remove first element
	void add(const T& input);

	void info();

	std::vector<T> myVector_;

private:

};

#include "QuickQueue.cpp"
#endif