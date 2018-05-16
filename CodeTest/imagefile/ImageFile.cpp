#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include "ImageFile.h"

using namespace std;

ImageFile::ImageFile(int type)
{
	//ȫ�����͸�ֵ
	m_Type = type;//BMP 0,Jpg 1,Png 2,Undo 3
}

ImageFile::~ImageFile()
{
}

bool ImageFile::Load(TCHAR *ImagePath, Image*loadcolorimage)
{
	switch (m_Type)
	{
	case 0:
		Load_BMP(ImagePath, loadcolorimage);
		break;
	case 1:
		LoadColor_JPG(ImagePath, loadcolorimage);
		break;
	case 2:
		LoadColor_PNG(ImagePath, loadcolorimage);
		break;
	case 3:
		MessageBoxA(NULL, "�ݲ�֧�ִ˸�ʽ�ļ��������ڴ�", "Warnning", MB_OK);
		break;
	default:
		break;
	}
	return true;
}

bool ImageFile::Save(TCHAR *ImagePath, Image*savecolorimage)
{
	switch (m_Type)
	{
	case 0:
		Save_BMP(ImagePath, savecolorimage);
		break;
	case 1:
		SaveColor_JPG(ImagePath, savecolorimage);
		break;
	case 2:
		SaveColor_PNG(ImagePath, savecolorimage);
		break;
	case 3:
		MessageBoxA(NULL, "�ݲ�֧�ִ˸�ʽ�ļ��������ڴ�", "Warnning", MB_OK);
		break;
	default:
		break;
	}
	return true;
}

bool ImageFile::GrayScale(Image*colorimage, Image*Grayimage)
{
	switch (m_Type)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		MessageBoxA(NULL, "�ݲ�֧�ִ˸�ʽ�ļ��������ڴ�", "Warnning", MB_OK);
		break;
	default:
		break;
	}
	return true;
}

bool ImageFile::Threshold(Image*Inputimage, Image*outputimage, int thresholdmin, int thresholdmax, int ThresholdType)
{
	switch (m_Type)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		MessageBoxA(NULL, "�ݲ�֧�ִ˸�ʽ�ļ��������ڴ�", "Warnning", MB_OK);
		break;
	default:
		break;
	}
	return true;
}


//BMP
bool ImageFile::Load_BMP(TCHAR *ImagePath, Image*loadcolorimage)
{
	//���ļ� rb read binary;
	FILE *rf;
	_wfopen_s(&rf,ImagePath, _T("rb"));
	if (rf == NULL) return false;
	//��ȡ�ļ�ͷ ��ȡ��Ϣͷ
	fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, rf);
	fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, rf);
	width_p = infoHeader.biWidth;
	height_p = infoHeader.biHeight;
	bitCount = infoHeader.biBitCount;
	//�жϵ�ɫ��
	if (bitCount == 8)
	{
		colorTable = new RGBQUAD[256];
		fread(&colorTable, sizeof(RGBQUAD), 256, rf);
	}
	loadcolorimage->image= new unsigned char[infoHeader.biSizeImage];
	loadcolorimage->XSize = width_p;
	loadcolorimage->YSize = height_p;
	loadcolorimage->channel = bitCount / 8;
	fread(loadcolorimage->image, 1,infoHeader.biSizeImage, rf);
	//�ر��ļ�
	fclose(rf);
	return true;
}
bool ImageFile::Save_BMP(TCHAR *ImagePath, Image*savecolorimage)
{
	//���ļ�
	FILE* wf;
	_wfopen_s(&wf, ImagePath, _T("wb"));
	if (wf == NULL) return false;
	//��ʼ���ֲ�����
	width_p = savecolorimage->XSize;
	height_p= savecolorimage->YSize;
	bitCount= savecolorimage->channel*8;
	//��� bitCount=24 ��û��color Table if bitcount is 8 ,the size of color table is 256*4,4B is the size of RGBQUAD. 
	int colorTableSize = 0;
	if (bitCount == 8)
		colorTableSize = sizeof(RGBQUAD) * 256;
	//�ļ�ͷ��С �߿ռ��С ���ݿռ��С
	int headerSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + colorTableSize;  
	int lineSize = (width_p*bitCount / 8 + 3) / 4 * 4; 
	int dataSize = lineSize*height_p; 
	//�����ļ�ͷBITMAPFILEHEADER  
	fileHeader.bfType = 0x4D42;
	fileHeader.bfSize = headerSize + dataSize;
	fileHeader.bfReserved1 = 0;
	fileHeader.bfReserved2 = 0;
	fileHeader.bfOffBits = headerSize;
	//BITMAPINFOHEADER �����ļ���Ϣͷ
	infoHeader.biSize = 40;
	infoHeader.biWidth = width_p;
	infoHeader.biHeight = height_p;
	infoHeader.biPlanes = 1;
	infoHeader.biBitCount = bitCount;
	infoHeader.biCompression = 0;
	infoHeader.biSizeImage = dataSize;
	infoHeader.biClrImportant = 0;
	infoHeader.biXPelsPerMeter = 0;
	infoHeader.biYPelsPerMeter = 0;
	//д�� �ļ�ͷ �ļ���Ϣͷ ����BMP�ļ��ܹ���д
	fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, wf);
	fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, wf);
	if (bitCount == 8)
	{
		colorTable = new RGBQUAD[256];
		fwrite(&colorTable, sizeof(RGBQUAD), 256, wf);
	}
	//д������
	fwrite(savecolorimage->image, 1, dataSize, wf); 
	//�ر��ļ�
	fclose(wf); 
	return true;
}
//JPG
bool ImageFile::LoadColor_JPG(TCHAR *ImagePath, Image*loadcolorimage)
{

	return true;
}
bool ImageFile::LoadGray_JPG(TCHAR *ImagePath, Image*loadcolorimage)
{

	return true;
}
bool ImageFile::SaveColor_JPG(TCHAR *ImagePath, Image*savecolorimage)
{

	return true;
}
bool ImageFile::SaveGray_JPG(TCHAR *ImagePath, Image*savecolorimage)
{

	return true;
}
//PNG
bool ImageFile::LoadColor_PNG(TCHAR *ImagePath, Image*loadcolorimage)
{

	return true;
}
bool ImageFile::LoadGray_PNG(TCHAR *ImagePath, Image*loadcolorimage)
{

	return true;
}
bool ImageFile::SaveColor_PNG(TCHAR *ImagePath, Image*savecolorimage)
{

	return true;
}
bool ImageFile::SaveGray_PNG(TCHAR *ImagePath, Image*savecolorimage)
{

	return true;
}

