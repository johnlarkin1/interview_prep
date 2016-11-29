#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Dog {

	public:
		Dog(const string& name="default dog", const int& age=1):
		  dog_name(name),
		  dog_age(age)
	 	  {};

		
		~Dog() {
			cout << "bye dogeeee" << endl;
		};

		inline string get_name() {return this->dog_name;}
		inline int get_age() {return this->dog_age;}

	private: 
		
		string dog_name;
		int dog_age;

};

int main(int argc, char* argv[]) {

	Dog* poodle = new Dog("poodle", 14);
	Dog* basic_dog = new Dog();
	cout << "My dog's breed is: " << poodle->get_name() << endl;

	delete poodle;

	cout << "*************" << endl;

	cout << "Basic dog breed is: " << basic_dog->get_name() << endl;
	delete basic_dog;

	cout << "*************" << endl;

	int a, b;
	a = 6; b = 2;
	swap(a,b);
	cout << "The value of a was 6 and now is: " << a << endl;

	
	
	return 0;
}
