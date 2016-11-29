#include <iostream>
#include <map>

using namespace std;


class mmap : public map<string, map<string, string> >
{
public:
    map<string, string>& operator [] (const string& arg)
    {
        if (this->find(arg) == this->end()) {
            map::operator[] (arg) = map<string, string>();
        }
        return map::operator[](arg);
    }

};

int main()
{
    mmap obj = mmap();
    obj["string1"] ["string2"] = "Some value!";
    
    cout << &obj["string1"] << endl;
    cout << obj["string7"]["string2"] << endl;


	map<int, int> mymap;
	cout << mymap[1] << endl;
}
