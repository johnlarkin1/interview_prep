#include <iostream>
#include <string>
using namespace std;

class basic_class_with_initialization_list {
	public: 
		basic_class_with_initialization_list(const string& name, const int& data):
		  my_name(name), 
		  my_data(data) {} // empty constructor
	

		inline const string get_name() {return this->my_name;}
	private:
		string my_name;
		int my_data;
};


int main(int argc, char* argv[]) {

	basic_class_with_initialization_list my_class("test", 4);

	cout << "This is my class name: " << my_class.get_name() << endl;
		
	return 0;
}
