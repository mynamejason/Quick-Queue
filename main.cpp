#include "QuickQueue.hpp"
#include <iostream>
#include <string>

using namespace std;

void test1() {
	QuickQueue<int> myQuickQueue;
	myQuickQueue.add(1);
	myQuickQueue.pop();
}

void test2() {
	string strings[5] = {"cat", "dog", "dragon", "tiger", "rat"};
	QuickQueue<string> myQuickQueue;
	for(int i = 0; i < 5; i++) {
		myQuickQueue.add(strings[i]);
	}

	for(int i = 0; i < 5; i++) {
		myQuickQueue.pop();
	}

	myQuickQueue.shrink();
}

void test3() {
	QuickQueue<int> myQuickQueue;
	for(int i = 0; i < 13; i++){
		myQuickQueue.add(i+1);
	}

	for(int i = 0; i < 5; i++){
		myQuickQueue.pop();
	}

	myQuickQueue.add(100);
	myQuickQueue.add(200);

	myQuickQueue.shrink();
}

int main() {
	QuickQueue<int> myQQ;
	cout << "----test 1----" << endl;
	test1();
	cout << "----test 2----" << endl;
	test2();
	cout << "----test 3----" << endl;
	test3();

	return 0;
}