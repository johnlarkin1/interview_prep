#include <iostream>
#include <algorithm>
#include <utility> 
#include <vector>
using namespace std;

vector< pair<int,int> > find_two_sum_naive(int array[], int n, int k) {
	vector< pair<int,int> > solution_vec;
	for(int i=0; i < n; i++) {
		for(int j=i; j < n; j++) {
			if (array[i] + array[j] == k) {
				pair<int,int> my_pair(array[i],array[j]);
				solution_vec.push_back(my_pair); 
			}
		}
	}
	return solution_vec;
}

vector< pair<int,int> > find_two_sum_sort(int array[], int n, int k) {

	vector< pair<int,int> > solution_vec;
	sort(array,array+n);
	//for(int i=0; i<n; i++) { cout << array[i] << " ";}
	for(int i = 0; i < n; i++) {
		int value = array[i];
		bool comp_found = binary_search(array,array+n,k-value);	
		if (comp_found) {
			pair<int,int> mypair(value,k-value);
			pair<int,int> mypair_flip(k-value,value);
			if (find(solution_vec.begin(), solution_vec.end(), mypair_flip) == solution_vec.end()) {
				solution_vec.push_back(mypair);
			}
		}
	}
	return solution_vec;	
}


/* TODO: FINISH THIS PART USING A HAS TABLE */
vector< pair<int,int> > find_two_sum_hash(int array[], int n, int k) {

	vector< pair<int,int> > solution_vec;
	return solution_vec;
}

int main(int argc, char* argv[]) {

	int k = 8; int SIZE = 7;
	
	int test_array[7] = {7,2,4,3,6,5,1};

	vector< pair<int,int> > solution = find_two_sum_naive(test_array, SIZE, k); 
	cout << endl << "The solution for k = " << k << " is: " << endl;
	
	cout << "*********************" << endl;
	for(int i=0; i< solution.size(); i++) {
		pair<int,int> my_pair = solution[i];		
		cout << "( " << my_pair.first << ", " << my_pair.second << " )" << endl; 
	}	
	cout << "*********************" << endl;

	vector< pair<int,int> > solution_two = find_two_sum_sort(test_array, SIZE, k);
	for(int i=0; i< solution_two.size(); i++) {
		pair<int,int> my_pair = solution_two[i];		
		cout << "( " << my_pair.first << ", " << my_pair.second << " )" << endl; 
	}	

	vector< pair<int,int> > solution_three = find_two_sum_hash(test_array, SIZE, k);
	return 0;
}



