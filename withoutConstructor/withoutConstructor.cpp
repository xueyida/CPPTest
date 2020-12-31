#include <iostream>

class CDataBuff {
public:
    void Init() {
        m_pBuf = nullptr;
        m_nSize = 0;
    }
    void SetData(char* pData, size_t nSize) {
        if (m_pBuf !=nullptr) {
            free(m_pBuf);
            m_pBuf = nullptr;
        }
        m_pBuf = (char*)malloc(nSize);
        memcpy(m_pBuf, pData, nSize);
    }
    const char* GetData() {
        return m_pBuf;
    }
private:
    char* m_pBuf;
    rsize_t m_nSize;
};

int main()
{
    char ary[] = { "hello" };
    CDataBuff buf;
    buf.Init();
    buf.SetData(ary, sizeof(ary));
    std::cout << "Hello World!\n";
}
