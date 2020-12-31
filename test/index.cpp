#include <iostream>
using namespace std;



class CDataBuff {
public:
	CDataBuff() {
		std::cout << "CDataBuf::CDataBuff" << std::endl;
		m_pBuf = nullptr;
		m_nSize = 0;
	}
	CDataBuff(char* pData, size_t nSize) {
		std::cout << "CDataBuf::CDataBuff(char* pData, size_t nSIze)" << std::endl;
		m_pBuf = (char*)malloc(nSize);
		memcpy(m_pBuf, pData, nSize);
		m_nSize = nSize;
	}
	CDataBuff(size_t nSize) {
		m_nSize = nSize;
	}
	~CDataBuff() {
		if (m_pBuf != nullptr) {
			cout << "CDataBuf::~CDataBuf" << endl;
			free(m_pBuf);
			m_pBuf = nullptr;
			m_nSize = 0;
		}
	}

	void SetData(char* pData, size_t nSize) {

		memcpy(m_pBuf, pData, nSize);
		m_nSize = nSize;
	}


private:
	char* m_pBuf;
	size_t m_nSize;
};


int main(int argc, char* argv[]) {


	char ary[] = { "hello" };

	CDataBuff buf(ary, sizeof(ary));

	CDataBuff buf1{ ary, sizeof(ary) };

}