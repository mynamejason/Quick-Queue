#include "QuickQueue.hpp"
#include <iostream>

using namespace std;

int main(){

	QuickQueue<int> myQQ;

	myQQ.add(10);
	myQQ.add(20);
	myQQ.add(30);
	myQQ.pop();
	myQQ.add(40);
	myQQ.add(50);
	myQQ.pop();

	return 0;
}