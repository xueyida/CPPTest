#include <iostream>
using namespace std;



class CFoo
{
public:
	CFoo() {
		cout << "CFoo::CFoo" << endl;
	}
	~CFoo() {
		cout << "CFoo::~CFoo" << endl;
	}
};

class CPtr {
public:
	CPtr(CFoo* p) :m_p(p) {}
	~CPtr()
	{
		if (m_p != nullptr) {
			delete m_p;
			m_p = nullptr;
		}
	}

	CFoo* m_p;

};

int main(int argc, char* argv[]) {
	
	
	 

	return 0;

}