#include <iostream>
using namespace std;


int main (int argc, char* argv[]) {

	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "This is the size of the array: " << n << endl;

	return 0;

}
