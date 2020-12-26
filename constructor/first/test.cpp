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

		/*1. 判断指针是否为空,没有初始化，局部变量初始化ccc，为什么？
		2. 不判断内存泄漏*/

		/*if (m_pBuf != nullptr) {
			free(m_pBuf);
			m_pBuf = nullptr;
		}
		
		m_pBuf = (char*)malloc(nSize);*/

		memcpy(m_pBuf, pData, nSize);
		m_nSize = nSize;
	}

	const char* GetData() {
		return m_pBuf;
	}

private:
	char* m_pBuf;
	size_t m_nSize;
};


int main(int argc, char* argv[]) {

	
	char ary[] = { "hello" };
	
	CDataBuff buf(ary, sizeof(ary));
	
	char ary1[] = { "hello" };

	buf.SetData(ary1, sizeof(ary1));
	

}