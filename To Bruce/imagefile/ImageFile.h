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
	THRESHOLD_BINARY = 0,		//在阈值范围内的置为255 其余为0
	THRESHOLD_BINARY_INV = 1,	//在阈值范围内的置为0 其余为255
};
//BMP图像文件构成解析
//------------------------------------//
//			位图文件头				  //
//------------------------------------//
//位图信息  |位图信息头				  //				
//			|调色板					  //
//------------------------------------//
//像	素	|数据					  //
//------------------------------------//
/*
//位图头文件
#ifndef tagBITMAPFILEHEADER
typedef struct tagBITMAPFILEHEADER
{
	WORD    byType;      //说明文件的类型
	DWORD   bfSize;      //说明文件的大小，以字节为单位
	WORD    bfReserved1; //保留，设置为0
	WORD    bfReserved2; //保留，设置为0
	DWORD   bfOffBits; //   说明从BITMAPFILEHEADER结构
					   //开始到实际图像数据阵列字节间的字节偏移量
}BITMAPFILEHEADER;

#endif // !tagBITMAPFILEHEADER
//位图信息头
#ifndef tagBITMAPINFOHEADER
typedef struct tagBITMAPINFOHEADER
{
	DWORD   biSize;        //本结构大小的字节数
	LONG    biWidth;       //位图的宽度，单位为像素点
	LONG    biHeight;      //位图的高度，单位为像素点
	WORD    biPlanes;      //目标设备位平面数，其值设置为1   1
	WORD    biBitCount;    //像素的位数(1,4,8,24)
	DWORD   biCompression; //压缩方式,0为不压缩
	DWORD   biSizeImage;   //压缩图像大小的字节数,为压缩图像为0
	LONG    biXpelsPerMeter;//水平分辨率(像素点每米)
	LONG    biYpelsPerMeter;//垂直分辨率(像素点每米)
	DWORD   biClrUsed;      //图像中使用的颜色数
	DWORD   biClrImportant; //重要色彩数，0表示都重要
}BITMAPINFOHEADER;
#endif // !tagBITMAPINFOHEADER
//调色板
#ifndef tagRGBQUAD
typedef struct tagRGBQUAD
{
	BYTE    rgbBlue;     //指定蓝色分量
	BYTE    rgbGreen;    //指定绿色分量
	BYTE    rgbRed;      //指定红色分量
	BYTE    rgbReserved; //保留值
}RGBQUAD;
#endif // !tagRGBQUAD
*/

