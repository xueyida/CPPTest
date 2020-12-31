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

	// 拷贝构造的代码
	CDataBuff(CDataBuff & obj) {
		m_pBuf = new char[obj.m_nSize];
		memcpy(m_pBuf, obj.m_pBuf, obj.m_nSize);
		m_nSize = obj.m_nSize;
		cout << "CDataBuff & obj" << endl;
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

	const char* GetData() {
		return m_pBuf;
	}

private:
	char* m_pBuf;
	size_t m_nSize;
};

void Foo(CDataBuff buf){
	cout << buf.GetData() << endl;
}

int main(int argc, char* argv[]) {
	CDataBuff buf0((char*)"hello", 6);
	Foo(buf0);
	return 0;
}
