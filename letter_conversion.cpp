#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
	string word = "hello";

	for (int i =0; i<word.length(); i++) {
		cout << "This is the value: " << (int)word[i] << endl;
	}

}
