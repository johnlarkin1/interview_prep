#include <iostream>
using namespace std;

/* Point of this problem is to rotate the matrix by 90 degrees */

int** rot_mat(int** matrix, int n){
	for(int level = 0; level < n/2; level ++) {
		int first = level;
		int last = n - level - 1;
		for(int i=first; i< last; i++) {
			// four person swap
			int offset = i - first;

			cout << matrix[first][i] << matrix[last-offset][first] << matrix[last][last-offset] << matrix[i][last] << endl; 	

			cout << "This is first: " << first << " and this is i: " << i << endl;

			cout << "This is last: " << last << " and this is level: " << level << endl;
			int temp = matrix[first][i];
			matrix[first][i] = matrix[last-offset][first]; // left to top 
			matrix[last-offset][first] = matrix[last][last-offset]; // top to right
			matrix[last][last-offset] = matrix[i][last]; //right to bottom
			matrix[i][last] = temp;
			
		} 
	} 

	return matrix;
}

int main(int argc, char* argv[]) {

	int n = 5;

	int** test_case = new int*[n];
	for(int i=0; i<n; i++) {
		test_case[i] = new int[n];
	}
		
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			test_case[j][i] = i+2*j;
			cout << test_case[j][i] << " "; 

		}
		cout << endl;
	}

	cout << "After the rotation, the result is..." << endl;

	int** rotated_matrix = rot_mat(test_case, n);

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout << rotated_matrix[i][j] << " "; 

		}
		cout << endl;
	}

	for(int i =0; i<3; i++) {
		delete[] test_case[i];
	}
	delete[] test_case;

	return 0;
}
