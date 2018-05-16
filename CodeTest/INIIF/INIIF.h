#ifndef INIIFH
#define INIIFH
#include "windows.h"
//ini 文件 初始化读写
class INI_Char
{
public:
	INI_Char(const char * FileName);
	~INI_Char();

	//参数
	char	m_FileName[256];
	char	m_Section[256];
	char	m_TempBuf[256];
	//设置区域
	void setSection(char* section);

	//获取数值
	int		read(char* key, int		Default);
	long	read(char* key, long	Default);
	float	read(char* key, float	Default);
	char*	read(char* key, char*	Default);
	bool	read(char* key, bool	Default);

	//写入数值
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
	//参数
	TCHAR	m_FileName[_MAX_DIR];
	TCHAR	m_Section[256];
	TCHAR	m_TempBuf[256];
	//设置区域
	void setSection(TCHAR* section);
	//获取数据
	int		read(TCHAR* key, int	Default);
	long	read(TCHAR* key, long	Default);
	float	read(TCHAR* key, float	Default);
	double	read(TCHAR* key, double Default);
	TCHAR*	read(TCHAR* key, TCHAR*	Default);
	bool	read(TCHAR* key, bool	Default);
	//写入数据
	void	write(TCHAR* key, int	value);
	void	write(TCHAR* key, long	value);
	void	write(TCHAR* key, float	value);
	void    write(TCHAR* key, double value);
	void	write(TCHAR* key, TCHAR*value);
};


#endif // !INIIFH

