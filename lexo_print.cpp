#include <iostream>
using namespace std;


void lexo_helper(int N, int k) {
	if (k>N) {return;}
	for(int i=0; i<10; i++) {
		if (k <= N) {
			cout << k << endl; 
			k*=10;
		    lexo_helper(N,k);
			k /= 10;
			k++;
			if (k%10 == 0) { return;}	
		}
	}
}


int main(int argc, char* argv[]) {
	
	int range;
	cout << "Please enter a number for the lexo sort: ";
	cin >> range;
	

	cout << "The solution is: " << endl;
	lexo_helper(range, 1);
	return 0;
}
