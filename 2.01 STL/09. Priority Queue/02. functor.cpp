#include <iostream>
#include <cstring>
using namespace std;

//functional object , also called functor
class Fun {
public:
	// void operator()(){
	//        cout<<"Having Fun";
	//    }
	void operator()(string s) {
		cout << "Having Fun with " << s;
	}
};


int main() {

	Fun f; //Constructor
	//f();
	f("C++"); //Overloaded () Operator = Function Call where f is an object



	return 0;
}
