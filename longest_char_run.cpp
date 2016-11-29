#include <iostream>
#include <string>
using namespace std;


string longest_run(string input) {
	char runner = input[0];
	int maxRun = 1;
	int currRun = 1;
	for(int i=1; i<input.length(); i++) {
		if (input[i-1] == input[i]) {
			// we know we're running
			currRun += 1;
		} else {
			if (currRun > maxRun) {
				maxRun = currRun;
				runner = input[i-1];
			}
			currRun = 1;
		}

	}

	if (currRun > maxRun ) {
		runner = input[input.length()-1];
		maxRun = currRun;
	}

	char solution[maxRun+1];
	solution[maxRun] = '\0';

	for(int i=0; i< maxRun; i++) {
		solution[i] = runner;
	}
	
	string sol(solution);
	return sol;
}



int main(int argc, char* argv[]) {
	string test_cases[3];
	test_cases[0] = "aabbbbbcc"; // 5 b's should be returned
	test_cases[1] = "abc";
	test_cases[2] = "acccccccddddeee";
	for(int i=0; i<3; i++) {
		string solution = longest_run(test_cases[i]);
		cout << "Input: " << test_cases[i] << " and solution: " << solution << endl;
	}
	return 0;

}
