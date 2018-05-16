#include "stdafx.h"
#include "INIIF.h"
#include "string.h"
#include "windows.h"

//#define _UNICODE
#ifdef _MBCS
INI_Char::INI_Char(const char * FileName)
{

	strcpy_s(m_FileName, FileName);
	memset(m_Section, 0, sizeof(m_Section));
	memset(m_TempBuf, 0, sizeof(m_TempBuf));
}

INI_Char::~INI_Char()
{
}

//��������
void INI_Char::setSection(char* section)
{
	strcpy_s(m_Section, section);
}
//��ȡint
int INI_Char::read(char* key, int Default)
{
	int ret = Default;
	memset(m_TempBuf, NULL, sizeof(m_TempBuf));
	GetPrivateProfileString(m_Section, key, "?", m_TempBuf, sizeof(m_TempBuf), m_FileName);
	if (m_TempBuf[0] == '?') {
		write(key, Default);
	}
	else {
		ret = GetPrivateProfileInt(m_Section, key, Default, m_FileName);
	}
	return(ret);
}
//��ȡ long
long INI_Char::read(char* key, long Default)
{
	long ret = Default;

	memset(m_TempBuf, NULL, sizeof(m_TempBuf));
	GetPrivateProfileString(m_Section, key, "?", m_TempBuf, sizeof(m_TempBuf), m_FileName);
	if (m_TempBuf[0] == '?') {
		write(key, Default);
	}
	else {
		ret = GetPrivateProfileInt(m_Section, key, Default, m_FileName);
	}
	return	ret;
}
//��ȡ float
float INI_Char::read(char* key, float Default)
{
	float   ret = Default;
	memset(m_TempBuf, NULL, sizeof(m_TempBuf));
	GetPrivateProfileString(m_Section, key, "?", m_TempBuf, sizeof(m_TempBuf), m_FileName);
	if (m_TempBuf[0] == '?') {
		write(key, Default);
	}
	else {
		sscanf_s(m_TempBuf, "%f", &ret, sizeof(m_TempBuf));
	}
	return	ret;
}
//��ȡchar
char* INI_Char::read(char* key, char* Default)
{
	memset(m_TempBuf, NULL, sizeof(m_TempBuf));
	GetPrivateProfileString(m_Section, key, "?", m_TempBuf, sizeof(m_TempBuf), m_FileName);
	if (m_TempBuf[0] == '?') {
		write(key, Default);

		memset(m_TempBuf, NULL, sizeof(m_TempBuf));
		wsprintf(m_TempBuf, Default);
	}
	return	m_TempBuf;
}

//��ȡbool
bool INI_Char::read(char* key, bool Default)
{
	bool ret = Default;
	int nval;
	memset(m_TempBuf, NULL, sizeof(m_TempBuf));
	GetPrivateProfileString(m_Section, key, "?", m_TempBuf, sizeof(m_TempBuf), m_FileName);
	if (m_TempBuf[0] == '?') {
		write(key, Default);
	}
	else {
		nval = GetPrivateProfileInt(m_Section, key, Default, m_FileName);
		ret = (nval == 1) ? true : false;
	}
	return	ret;
}

// д��int
void INI_Char::write(char* key, int value)
{
	char msg[64];
	wsprintf(msg, "%ld", value);
	WritePrivateProfileString(m_Section, key, msg, m_FileName);
}

// д��long
void INI_Char::write(char* key, long value)
{
	char str[32];
	sprintf_s(str, sizeof(str) - 1, "%ld", value);

	WritePrivateProfileString(m_Section, key, str, m_FileName);
}

// д��float
void INI_Char::write(char* key, float value)
{
	char str[32];
	sprintf_s(str, sizeof(str) - 1, "%.3f", value);

	WritePrivateProfileString(m_Section, key, str, m_FileName);
}

// д��char
void INI_Char::write(char* key, char* value)
{
	WritePrivateProfileString(m_Section, key, value, m_FileName);
}

#elif _UNICODE
INI_Tchar::INI_Tchar(TCHAR* fileName)
{
	wcscpy_s(m_FileName, fileName);
	memset(m_Section, 0, sizeof(m_Section));
	memset(m_TempBuf, 0, sizeof(m_TempBuf));
}

INI_Tchar::~INI_Tchar()
{
}
//��������
void INI_Tchar::setSection(TCHAR* section)
{
	wcscpy_s(m_Section, section);
}
//��ȡint
int INI_Tchar::read(TCHAR* key, int Default)
{
	int ret = Default;
	memset(m_TempBuf, NULL, sizeof(m_TempBuf));
	GetPrivateProfileString(m_Section, key, (LPCTSTR)("?"), m_TempBuf, sizeof(m_TempBuf), m_FileName);
	if (m_TempBuf[0] == '?') {
		write(key, Default);
	}
	else {
		ret = GetPrivateProfileInt(m_Section, key, Default, m_FileName);
	}
	return(ret);
}

//��ȡlong
long INI_Tchar::read(TCHAR* key, long Default)
{
	long ret = Default;
	memset(m_TempBuf, NULL, sizeof(m_TempBuf));
	GetPrivateProfileString(m_Section, key, (LPCTSTR)("?"), m_TempBuf, sizeof(m_TempBuf), m_FileName);
	if (m_TempBuf[0] == '?') {
		write(key, Default);
	}
	else {
		ret = GetPrivateProfileInt(m_Section, key, Default, m_FileName);
	}
	return	ret;
}

//��ȡfloat
float INI_Tchar::read(TCHAR* key, float Default)
{
	float   ret = Default;
	memset(m_TempBuf, NULL, sizeof(m_TempBuf));
	GetPrivateProfileString(m_Section, key, (LPCTSTR)("?"), m_TempBuf, sizeof(m_TempBuf), m_FileName);
	if (m_TempBuf[0] == '?') {
		write(key, Default);
	}
	else {
		swscanf_s(m_TempBuf, (LPCTSTR)("%f"), &ret, sizeof(m_TempBuf));
	}
	return	ret;
}
//��ȡdouble
double INI_Tchar::read(TCHAR* key, double Default)
{
	double   ret = Default;

	memset(m_TempBuf, NULL, sizeof(m_TempBuf));
	GetPrivateProfileString(m_Section, key, _T("?"), m_TempBuf, sizeof(m_TempBuf), m_FileName);
	if (m_TempBuf[0] == '?') {
		write(key, Default);
	}
	else {
		swscanf_s(m_TempBuf, _T("%lf"), &ret, sizeof(m_TempBuf));
	}
	return	ret;
}

//��ȡTchar
TCHAR* INI_Tchar::read(TCHAR* key, TCHAR* Default)
{
	memset(m_TempBuf, NULL, sizeof(m_TempBuf));
	GetPrivateProfileString(m_Section, key, (LPCTSTR)("?"), m_TempBuf, sizeof(m_TempBuf), m_FileName);
	if (m_TempBuf[0] == '?') {
		write(key, Default);

		memset(m_TempBuf, NULL, sizeof(m_TempBuf));
		wsprintf(m_TempBuf, Default);
	}
	return	m_TempBuf;
}


//��ȡbool
bool INI_Tchar::read(TCHAR* key, bool Default)
{

	bool ret = Default;
	int nval;
	memset(m_TempBuf, NULL, sizeof(m_TempBuf));
	GetPrivateProfileString(m_Section, key, (LPCTSTR)("?"), m_TempBuf, sizeof(m_TempBuf), m_FileName);
	if (m_TempBuf[0] == '?') {
		write(key, Default);
	}
	else {
		nval = GetPrivateProfileInt(m_Section, key, Default, m_FileName);
		ret = (nval == 1) ? true : false;
	}
	return	ret;
	
}

//д��int
void INI_Tchar::write(TCHAR* key, int value)
{
	TCHAR msg[64];
	wsprintf(msg, _T("%d"), value);
	WritePrivateProfileString(m_Section, key, msg, m_FileName);
}

//д��long
void INI_Tchar::write(TCHAR* key, long value)
{
	TCHAR str[32];
	_stprintf_s(str, (sizeof(str) - 1) / sizeof(TCHAR), _T("%ld"), value);

	WritePrivateProfileString(m_Section, key, str, m_FileName);
}

//д��float
void INI_Tchar::write(TCHAR* key, float value)
{
	TCHAR str[32];
	_stprintf_s(str, (sizeof(str) - 1) / sizeof(TCHAR), _T("%.3f"), value);

	WritePrivateProfileString(m_Section, key, str, m_FileName);
}
//д��double
void INI_Tchar::write(TCHAR* key, double value)
{
	TCHAR str[32];
	_stprintf_s(str, (sizeof(str) - 1) / sizeof(TCHAR), _T("%.3f"), value);

	WritePrivateProfileString(m_Section, key, str, m_FileName);
}

//д��tchar
void INI_Tchar::write(TCHAR* key, TCHAR* value)
{
	WritePrivateProfileString(m_Section, key, value, m_FileName);
}

#endif // DEBUG

//���������
#if 0
2555
#endif // 0

