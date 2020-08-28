// ex01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>

using namespace cv;
using namespace std;

int exam2()
{
	while (1)
	{
		
	}
}
int main()
{
	Mat img = imread("../lena.png", IMREAD_COLOR );

	if (img.empty())
	{
		printf("image load error");
		return 1;
	}

	imshow("Display", img);
	waitKey(0);



	return 0;
}
