#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

	char potential_string[6];

	potential_string[0] = 'h';
	potential_string[1] = 'e';
	potential_string[2] = 'l';
	potential_string[3] = 'l';
	potential_string[4] = 'o';
	potential_string[5] = '\0';

	char other_string[] = "Test";

	cout << potential_string << endl;
	cout << other_string << endl;
	return 0;
}
