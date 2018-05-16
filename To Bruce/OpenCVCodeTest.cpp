// OpenCVCodeTest.cpp : �������̨Ӧ�ó������ڵ㡣
//
// ��дOPENCV ���� 
#include "stdafx.h"
#include <windows.h>
#include <numeric>
#include <iostream>
#include <opencv2\core.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv2\highgui.hpp>
#define OpenCV330
#ifdef OpenCV330
#ifdef _DEBUG
#pragma comment (lib,"opencv_world330d")
#else
#pragma comment (lib,"opencv_world330")
#endif // _DEBUG
#endif 
using namespace cv;
using namespace std;

//ˮƽͶӰ
Mat Hprojection(Mat & BinInput)
{
	//������Ƕ�ֵͼ
	Mat inputtemp = BinInput.clone();
	vector<int>a;
	int temp = 0;
	for (int i = 0; i < BinInput.rows; i++)
	{
		for (int j = 0; j <BinInput.cols; j++)
		{
			if (BinInput.at<uchar>(i,j)==0)
			{
				temp += 1;
			}
		}
		a.push_back(temp);
		temp = 0;
	}
	auto colmax = max_element(a.begin(), a.end());
	Mat Hprojection(BinInput.rows, (int)((*colmax)*1.1), BinInput.type(), Scalar(0, 0, 0));
	for (int i = 0; i < BinInput.rows; i++)
	{
		for (int j = 0; j < a[i]; j++)
		{
			Hprojection.at<uchar>(i, j)= 255;
		}
	}
	return Hprojection;
}
//��ֱͶӰ
Mat Vprojection(Mat & BinInput)
{
	//������Ƕ�ֵͼ
	Mat inputtemp = BinInput.clone();
	vector<int>a;
	int temp = 0;
	for (int i = 0; i < BinInput.cols; i++)
	{
		for (int j = 0; j <BinInput.rows; j++)
		{
			if (BinInput.at<uchar>(j, i) == 0)
			{
				temp += 1;
			}
		}
		a.push_back(temp);
		temp = 0;
	}
	auto rowmax=max_element(a.begin(), a.end());
	Mat Vprojection((int)((*rowmax)*1.1), BinInput.cols, BinInput.type(), Scalar(0, 0, 0));
	for (int i = 0; i < BinInput.cols; i++)
	{
		for (int j = 0; j < a[i]; j++)
		{
			Vprojection.at<uchar>(j,i) = 255;
		}
	}
	return Vprojection;
}
//�����������
Mat SaltNoise(Mat & Input,int n)
{
	Mat noise = Input.clone();
	//�������	
	SYSTEMTIME st;
	srand((unsigned int)&st);
	for (int k = 0; k < n; k++)
	{
		//������
		int i = rand() % Input.cols;
		int j = rand() % Input.rows;
		if (Input.channels() == 1)
		{
			//�Ҷ�ͼ
			if (noise.at<uchar>(j, i) >=128)
			{
				noise.at<uchar>(j, i) = 0;
			}
			else
			{
				noise.at<uchar>(j, i) = 255;
			}
		}
		else if (Input.channels() == 3)
		{
			//��ͼ
			noise.at<Vec3b>(j, i) = 0;
			noise.at<Vec3b>(j, i) = 0;
			noise.at<Vec3b>(j, i) = 0;
		}
	}
	return noise;
}
//�Ҷ�ͼ ֱ���ֲ� ԭ��
Mat GrayHist(Mat & Input)
{
	//���ؼ��
	vector<int> a(256);
	for (int i = 0; i < Input.cols; i++)
	{
		for (int j = 0; j < Input.rows; j++)
		{
			/*if (Input.at<uchar>(j, i)==255)
			{
				continue;
			}*/
			a[Input.at<uchar>(j, i)]++;
		}
	}
	//�綨�߽�
	auto HistMax=max_element(a.begin(), a.end());
	int ysize = 256*0.9;
	//����ͼ�� ����
	Mat GrayHist(256, 256, CV_8U, Scalar(0, 0, 0));
	for (int i = 0; i < GrayHist.cols; i++)
	{
		int dis = ((ysize * a[i]) / (*HistMax));
		line(GrayHist, Point(i, 256), Point(i, 256 -dis), Scalar::all(255));
	}
	return GrayHist;
}
//opencv ���� Ϊʲôû��ͳ��255����ɫ���أ�
Mat cv1dhist(Mat&src, Mat &dst)
{
	MatND hist;
	int hsize = 256;
	float range[] = { 0.0, 255.0 };
	const float * hrange = range;
	dst=Mat(hsize, hsize, CV_8U,Scalar::all(0));
	calcHist(&src, 1, 0, Mat(), hist, 1, &hsize, &hrange);
	double minval, maxval;
	minMaxLoc(hist, &minval, &maxval, 0, 0);
	int hpt = saturate_cast<int>(0.9*hsize);
	for (int i = 0; i < hsize; i++)
	{
		float binval = hist.at<float>(i);
		int dis = saturate_cast<int>(hpt*binval / maxval);
		line(dst, Point(i, hsize), Point(i, hsize - dis), Scalar(255,255,255));

	}
	return hist;
}
//LUT �ı�ͼƬ
Mat Luttest(Mat & input)
{
	Mat Result(input.size(),CV_8U,Scalar::all(0));
	Mat lut(1, 256, CV_8U, Scalar(0, 0, 0));
	//look-up-table ���ұ� 
	for (int i = 0; i < lut.cols; i++)
	{
		//���ݶ���Ĳ�ͬ ���Խ��в�ͬ�Ĳ���
		if (i<50||i>200)
		{
			lut.at<uchar>(i) = 255;
		}
		else
		{
			lut.at<uchar>(i) = i;
		}
	}
	LUT(input, lut, Result);
	return Result;
}

int main()
{
	Mat test=imread("..\\Test.jpg",0);
	Mat H=Luttest(test);
	//Mat hist;
	//cv1dhist(test, hist);
	//threshold(test, test, 100, 255, THRESH_BINARY);
	//Mat H=Hprojection(test);
	//Mat H = Vprojection(test);
	//Mat H = SaltNoise(test, 1000);
	//Mat H = GrayHist(test);
	imshow("test", H);
	//imshow("aaa",hist);
	while ((char)waitKey(1) != 'q')
	{
	}
	//system("pause");
    return 0;
}

