#include <iostream>
using namespace std;

int flip_num(int num) {
	// Just going ot use mod and division
	int reverse = 0;
	while( num != 0 ) {
		reverse = reverse*10; // select the right spot for the calc number to go 
		reverse += num % 10; // so this is essentially pulling off the one's place
		num /= 10; // get rid of that place then with floor division
	}

	return reverse;
}

int main(int argc, char* argv[]) {

	int test_cases[5];
	int ans;

	for(int i=0; i<5; i++) {
		test_cases[i] = 10000 + i;
	}

	for(int i=0; i<5; i++) {
		ans = flip_num(test_cases[i]);
		cout << "This is the num: " << test_cases[i] << " and this is the flipped num: " << ans << endl;
	}
	
	return 0;	
}
