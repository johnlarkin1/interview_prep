#include <iostream>
#include <string>
using namespace std;

bool all_unique(string word) {
	for(int i=0; i<word.length(); i++) {
		for(int j=i+1; j<word.length(); j++) {
			if (word[i]==word[j]) {
				return false;
			}
		}		
	}
	return true;	
} 

int main(int argc, char* argv[]) {
	

	string tests[5];
	tests[0] = "animal";
	tests[1] = "dog";
	tests[2] = "cats";
	tests[3] = "person";
	tests[4] = "trees";
		

	bool result;
	for(int i=0; i<5; i++) {
		result = all_unique(tests[i]);
		if (result) {
			cout << "The word: " << tests[i] << " has all unique char" << endl;
		} else {
			cout << "The word: " << tests[i] << " does NOT have all unique char" << endl;
		}	
	}
 
	return 0;
}



