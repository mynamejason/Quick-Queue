#ifndef QuickQueue_hpp
#define QuickQueue_hpp

#include <vector>
#include <iostream>

template<typename T>
class QuickQueue {
public:
	QuickQueue();
	~QuickQueue();

	T& head();

	void pop();
	void add(const T& input);
	void shrink();
	void reallocateQueue();
	void rearrangeQueue();

	void info();

	int itemCount;

private:
	T& tail();
	std::vector<T> myVector_;

	typename std::vector<T>::iterator first;
	typename std::vector<T>::iterator last;
};

#include "QuickQueue.cpp"
#endif