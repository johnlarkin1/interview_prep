#include <iostream>
#include <string>
using namespace std;

/* This problem is from Cracking the Coding Interview. The directions explicitly state that the point of the algorithm is to actually compress the string. If it would not compress the string, then we can just return the original string. Therefore, let's create a little helper function to find what the actual length of the compressed string is going to be. */


int find_length_of_int(int number) {
	int len = 0;
	while(number > 0) {
		len++;
		number /= 10;
	}
	return len;
}


int find_compressed_length(const string& input) {

	if (input.length() == 0) {
		return 0;
	}
	
	int count, size;
	count = 1; size = 0;
	char starting_char = input[0];

	for (int i=1; i< input.length(); i++) {
		if (starting_char == input[i]) {
			count ++;
		} else {
			starting_char = input[i];
			count =1;
			size += 1 + find_length_of_int(count);
		}

	}
	size += 1 + find_length_of_int(count);
	return size;
}


const string compress_string(string& input) {
	int size = find_compressed_length(input);
	cout << endl;

	if (input.length() == 0) {
		return input;
	}

	if (size > input.length()) {
		return input;
	}

	char compressed_string[size+1];
	compressed_string[size] = '\0';

	char last = input[0];
	int insert_index = 1;
	compressed_string[0] = input[0];
	int count=1;	
	for (int i= 1; i< input.length(); i++) {

		if (last == input[i]) {
			count++;
		}
		else {
			last = input[i];
			string count_str = to_string(count);
			for(int j=0; j<count_str.length(); j++) {
				compressed_string[ insert_index+j ] = count_str[j];
			}
			compressed_string[insert_index+find_length_of_int(count)] = input[i];
			insert_index += 1 + find_length_of_int(count);
			count = 1;
		}
	}

	string count_str = to_string(count);
	for(int j=0; j<count_str.length(); j++) {
		compressed_string[ insert_index+j ] = count_str[j];
	}

	return compressed_string;
	
}

int main(int argc, char* argv[]) {


	string* test_cases = new string[3];

	test_cases[0] = "aaaaabbbbbc";
	test_cases[1] = "abc";
	test_cases[2] = "abbbbbcccccc";

	string answer;
	cout << endl;	
	cout << "*********************";
	for(int i=0; i<3; i++) {
	
		answer = compress_string(test_cases[i]);
		cout << "Old string: " << test_cases[i] <<  endl << "Compressed string: " << answer << endl;
		cout << "*********************";
	}
	cout << endl <<endl;
	delete[] test_cases;
	return 0;
}
