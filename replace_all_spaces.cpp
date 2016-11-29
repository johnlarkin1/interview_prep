#include <iostream>
#include <string>
using namespace std;

string replace_all_spaces(string word) {
	int space_count=0;
	for(int i=0; i<word.length(); i++) {
		if (isspace(word[i])) {
			space_count ++;
		}
	}

	string new_word = "";
	int length_of_new_word = word.length() + 2* space_count;
	int i=0;
	while(i < length_of_new_word) {
		if (isspace(word[i])) {
			new_word += "%20";
			i++;
		}
		else {
			new_word += word[i];
			i++;
		}
	}
	return new_word;
}

int main(int argc, char* argv[]) {
	string* tests = new string[5];
	
	tests[0] = "he llo";
	tests[1] = "why     ";
	tests[2] = "hi my name is john";
	tests[3] = "normal";
	tests[4] = "good bye";

	string new_word;
	for(int i=0; i<5; i++) {
		new_word = replace_all_spaces(tests[i]);
		cout << "The old string was: " << tests[i] << " and the new string is: " << new_word << endl;
	}

	delete[] tests;
	return 0;
}
