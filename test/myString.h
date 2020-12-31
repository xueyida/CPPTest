#pragma once
class CMyString
{
public:
	CMyString();
	CMyString(const char *str);
	
	~CMyString();

	size_t GetLen();
	const char *GetStr();


private:
	char* m_pBuff;
	size_t m_nStringLen;
	size_t m_nBuffSize;
};

