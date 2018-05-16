#ifndef INIIFH
#define INIIFH
#include "windows.h"
//ini �ļ� ��ʼ����д
class INI_Char
{
public:
	INI_Char(const char * FileName);
	~INI_Char();

	//����
	char	m_FileName[256];
	char	m_Section[256];
	char	m_TempBuf[256];
	//��������
	void setSection(char* section);

	//��ȡ��ֵ
	int		read(char* key, int		Default);
	long	read(char* key, long	Default);
	float	read(char* key, float	Default);
	char*	read(char* key, char*	Default);
	bool	read(char* key, bool	Default);

	//д����ֵ
	void	write(char* key, int	value);
	void	write(char* key, long	value);
	void	write(char* key, float	value);
	void	write(char* key, char*	value);
private:

};
class INI_Tchar
{
public:
	INI_Tchar(TCHAR* fileName);
	~INI_Tchar();
	//����
	TCHAR	m_FileName[_MAX_DIR];
	TCHAR	m_Section[256];
	TCHAR	m_TempBuf[256];
	//��������
	void setSection(TCHAR* section);
	//��ȡ����
	int		read(TCHAR* key, int	Default);
	long	read(TCHAR* key, long	Default);
	float	read(TCHAR* key, float	Default);
	double	read(TCHAR* key, double Default);
	TCHAR*	read(TCHAR* key, TCHAR*	Default);
	bool	read(TCHAR* key, bool	Default);
	//д������
	void	write(TCHAR* key, int	value);
	void	write(TCHAR* key, long	value);
	void	write(TCHAR* key, float	value);
	void    write(TCHAR* key, double value);
	void	write(TCHAR* key, TCHAR*value);
};


#endif // !INIIFH

