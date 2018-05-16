#pragma once
#include <windows.h>



class ImageFile
{
public:
	ImageFile(int Code);
	~ImageFile();

	int m_Type;
	struct Image
	{
		unsigned char* image;
		int XSize;
		int YSize;
		int channel;
		LPRGBQUAD colorTable;
		BITMAPFILEHEADER fileHeader;
		BITMAPINFOHEADER infoHeader;
	};

	bool Load(TCHAR *ImagePath,Image*loadcolorimage);
	bool Save(TCHAR *ImagePath, Image*savecolorimage);
	bool GrayScale(Image*colorimage, Image*Grayimage);
	bool Threshold(Image*Inputimage, Image*outputimage,int thresholdmin,int thresholdmax,int ThresholdType);
protected:
	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;
private:
	//BMP
	int width_p, height_p, bitCount;
	LPRGBQUAD colorTable;
	bool Load_BMP(TCHAR *ImagePath, Image*loadcolorimage);
	bool Save_BMP(TCHAR *ImagePath, Image*savecolorimage);

	//JPG
	bool LoadColor_JPG(TCHAR *ImagePath, Image*loadcolorimage);
	bool LoadGray_JPG(TCHAR *ImagePath, Image*loadcolorimage);
	bool SaveColor_JPG(TCHAR *ImagePath, Image*savecolorimage);
	bool SaveGray_JPG(TCHAR *ImagePath, Image*savecolorimage);
	//PNG
	bool LoadColor_PNG(TCHAR *ImagePath, Image*loadcolorimage);
	bool LoadGray_PNG(TCHAR *ImagePath, Image*loadcolorimage);
	bool SaveColor_PNG(TCHAR *ImagePath, Image*savecolorimage);
	bool SaveGray_PNG(TCHAR *ImagePath, Image*savecolorimage);
};


enum
{
	IMAGE_BMP = 0,				//BMP
	IMAGE_JPG = 1,				//JPG
	IMAGE_PNG = 2,				//PNG
	UNDO	  = 3,				//UNDO
};
enum
{
	THRESHOLD_BINARY = 0,		//����ֵ��Χ�ڵ���Ϊ255 ����Ϊ0
	THRESHOLD_BINARY_INV = 1,	//����ֵ��Χ�ڵ���Ϊ0 ����Ϊ255
};
//BMPͼ���ļ����ɽ���
//------------------------------------//
//			λͼ�ļ�ͷ				  //
//------------------------------------//
//λͼ��Ϣ  |λͼ��Ϣͷ				  //				
//			|��ɫ��					  //
//------------------------------------//
//��	��	|����					  //
//------------------------------------//
/*
//λͼͷ�ļ�
#ifndef tagBITMAPFILEHEADER
typedef struct tagBITMAPFILEHEADER
{
	WORD    byType;      //˵���ļ�������
	DWORD   bfSize;      //˵���ļ��Ĵ�С�����ֽ�Ϊ��λ
	WORD    bfReserved1; //����������Ϊ0
	WORD    bfReserved2; //����������Ϊ0
	DWORD   bfOffBits; //   ˵����BITMAPFILEHEADER�ṹ
					   //��ʼ��ʵ��ͼ�����������ֽڼ���ֽ�ƫ����
}BITMAPFILEHEADER;

#endif // !tagBITMAPFILEHEADER
//λͼ��Ϣͷ
#ifndef tagBITMAPINFOHEADER
typedef struct tagBITMAPINFOHEADER
{
	DWORD   biSize;        //���ṹ��С���ֽ���
	LONG    biWidth;       //λͼ�Ŀ�ȣ���λΪ���ص�
	LONG    biHeight;      //λͼ�ĸ߶ȣ���λΪ���ص�
	WORD    biPlanes;      //Ŀ���豸λƽ��������ֵ����Ϊ1   1
	WORD    biBitCount;    //���ص�λ��(1,4,8,24)
	DWORD   biCompression; //ѹ����ʽ,0Ϊ��ѹ��
	DWORD   biSizeImage;   //ѹ��ͼ���С���ֽ���,Ϊѹ��ͼ��Ϊ0
	LONG    biXpelsPerMeter;//ˮƽ�ֱ���(���ص�ÿ��)
	LONG    biYpelsPerMeter;//��ֱ�ֱ���(���ص�ÿ��)
	DWORD   biClrUsed;      //ͼ����ʹ�õ���ɫ��
	DWORD   biClrImportant; //��Ҫɫ������0��ʾ����Ҫ
}BITMAPINFOHEADER;
#endif // !tagBITMAPINFOHEADER
//��ɫ��
#ifndef tagRGBQUAD
typedef struct tagRGBQUAD
{
	BYTE    rgbBlue;     //ָ����ɫ����
	BYTE    rgbGreen;    //ָ����ɫ����
	BYTE    rgbRed;      //ָ����ɫ����
	BYTE    rgbReserved; //����ֵ
}RGBQUAD;
#endif // !tagRGBQUAD
*/

