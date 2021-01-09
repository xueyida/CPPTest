#include <iostream>
using namespace std;


class CA {
public:
	void FooA() {
		cout << "CA::Foo" << endl;
	}

	int a = 2;

private:
	
};


class CD {
public:
	void FooD() {
		cout << "CD::FooD" << endl;
	}


	int a = 2;

private:

};



class CB : virtual public CA {
public:
	 void FooB() {
		cout << "CB::Foo" << endl;
	}
	
	int b = 5;
};


int main(int argc, char* argv[]) {
	CB* p = new CB;

	return 0;

}