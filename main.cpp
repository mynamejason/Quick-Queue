#include "QuickQueue.hpp"
#include <iostream>

using namespace std;

int main(){

	QuickQueue<int> myQQ;

	myQQ.add(10);
	myQQ.add(20);
	myQQ.add(30);
	myQQ.add(40);
	myQQ.add(50);
	myQQ.add(60);
	myQQ.add(70);
	myQQ.add(80);
	myQQ.add(90);
	myQQ.add(100);
	myQQ.add(110);
	// myQQ.pop();
	// myQQ.add(40);
	// myQQ.add(50);

	return 0;
}