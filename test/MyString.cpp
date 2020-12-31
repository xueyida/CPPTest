#include "myString.h"

CMyString::CMyString()
{
	m_pBuff = nullptr;
	m_nBuffSize = 0;
	m_nStringLen = 0;
}


CMyString::CMyString(const char* str)
{
	m_nStringLen = strlen(str);
	m

}

CMyString::~CMyString()
{
}

size_t CMyString::GetLen()
{
	return size_t();
}

const char* CMyString::GetStr()
{
	return nullptr;
}
