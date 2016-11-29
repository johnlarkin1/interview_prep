#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

	int range = 100;
	for(int i =0; i < range; i++) {
		if(i % 15 == 0) { cout << "Fizzbuzz" << endl; }
		else if(i%5 ==0) {cout << "Fizz" << endl; }
		else if(i%3 ==0) {cout << "Buzz" << endl; }
		else { cout << i << endl; }
	}
}
