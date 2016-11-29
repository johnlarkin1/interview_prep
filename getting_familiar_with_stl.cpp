#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <unordered_map>
#include <map>
#include <string>
#include <utility> // for pair
#include <iostream>
using namespace std;


int main(int argc, char* argv[]) {

	/********************** MAP **********************/	
	map<int,string> my_map;
	my_map[1] = "test";
	my_map[2] = "is";
	my_map[3] = "this";
	my_map[4] = "working?";

	map<int,string>::iterator my_it;
	for(my_it = my_map.begin(); my_it != my_map.end(); my_it ++) {
		cout << my_it->first << " : " << my_it->second << endl;
	}

	for (auto const& x : my_map) {
		cout << x.first << " : " << x.second << endl;
	}
	cout << "This is the corresponding map value for 1: " << my_map[1] << endl;

	/********************** UNORDERED MAP **********************/	
	// The main difference is there is no way to iterate over the data in a sorted manor. 
	// Much closer to a hash table.
	unordered_map<char, int> my_unord_map;
	pair<char, int> my_pair('a',4);
	my_unord_map.insert(my_pair);

	my_unord_map['b'] = 6;
	cout << "This is the corresponding map value for 'a': " << my_unord_map['a'] << endl; 	
	cout << "This is the corresponding map value for 'b': " << my_unord_map['b'] << endl; 	

	
	/********************** LIST **********************/	
	return 0;
}



