#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
	string str_input;

	while (true) {

		cout << "Enter a string or press 'q' to quit: ";
		cin >> str_input;

		if (str_input == "q") {break;}

		if (str_input == string(str_input.rbegin(), str_input.rend())) {
			cout << str_input << " is a palindrome." << endl;
		} else {
			cout << str_input << " is NOT a palindrome." << endl;
		}
	
	}
	
	return 0;	
}
