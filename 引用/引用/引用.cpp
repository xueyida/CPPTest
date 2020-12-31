#include <iostream>

class CBuff {

public:
    CBuff(const char* pBuff = nullptr, size_t nSize=0){
        m_pBuff = new char[nSize];
        m_nSize = nSize;
        memcpy(m_pBuff, pBuff, nSize);
    }
    CBuff(const CBuff& buf) {
        // 默认拷贝构造
        memcpy(this, &buf, sizeof(buf));
    }
    ~CBuff() {
        if (m_pBuff) {
            delete[] m_pBuff;
            m_pBuff = nullptr;
            m_nSize = 0;
        }
    }
private:
    char* m_pBuff;
    size_t m_nSize;
    size_t *m_pnCount;

    void Init(const char* pBuff, const size_t & nSize) {
        if (pBuff == nullptr) {
            m_pBuff = nullptr;
            m_nSize = 0;
            m_pnCount = 0;
        }
        m_pBuff = new char[nSize];
        m_pnCount = new size_t(1);
        m_nSize = nSize;
    }
};

int main()
{

    CBuff buff1("hello", 6);
    CBuff buff2(buff1);

    std::cout << "Hello World!\n";
    return 0;
}

