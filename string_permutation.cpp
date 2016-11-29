#include <iostream>
#include <vector>
#include <string>
using namespace std;


string insert_char(string input, int position, char ins) {
	string start = input.substr(0,position);
	string end = input.substr(position,input.length()-position);
	return start + ins + end;
}

vector<string> find_perm(string input) {
	vector<string> solution_vec;
	if (input.length() == 0) {
		solution_vec.push_back("");
		return solution_vec;
	}

	char last = input[input.length()-1];
	string remainder = input.substr(0,input.length()-1);
	vector<string> words = find_perm(remainder);

	for(int i=0; i< words.size(); i++) {
		string word = words[i];
		for(int j=0; j <= word.length(); j++) {
			string new_word = insert_char(word, j, last); 
			solution_vec.push_back(new_word);
		}
	}

	return solution_vec;
}

int main(int argc, char* argv[]) {

	string test_case = "abc";


	vector<string> solution = find_perm(test_case);
	cout << "Vector size: " << solution.size() << endl;
	
	for(int i=0; i< solution.size(); i++) {
		string word = solution[i];
		cout << "(" << word << ")" << " ";
	}
	cout << endl;
	
	string mystr = "w";
	cout << mystr.length();

}
