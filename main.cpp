#include "QuickQueue.hpp"
#include <iostream>

using namespace std;

int main(){

	QuickQueue<int> myQQ;

	for(int i = 1; i <= 10; i++){
		myQQ.add(i);
	}
	myQQ.pop();
	myQQ.pop();
	myQQ.add(11);
	myQQ.add(12);
	myQQ.add(13);
	myQQ.pop();
	myQQ.pop();
	myQQ.add(100);
	for(int i = 1; i <= 5; i++){
		myQQ.add(i*1000);
	}

	return 0;
}