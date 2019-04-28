#include "acllib.h"

#include <stdio.h>
//#include<initWindow>
#include<math.h>

int Setup()

{

	https://初始化窗口位置和大小

	initWindow("不会编程的单身汪不是好的程序猿", 0, 0, 500, 550);

	beginPaint();

	//放大系数a

	int a = 100;

	//遍历直角坐标系中x变量
	double x = -2;
	for (; x <= 2; x = x + 0.01)

	{

		//直角坐标系中y变量

		double y = sqrt(2 * sqrt(x*x) - x * x);

		//直角坐标系中z变量

		double z = asin((fabs(x) - 1)) - 3.141592 / 2;

		//直角坐标系变换到屏幕坐标系

		int real_x = (int)(x * a + 250);

		int real_y = (int)(y * a*(-1) + 150);

		int real_z = (int)(z * a * (-1) + 150);

		//画笛卡尔心型曲线上半部

		putPixel(real_x, real_y, RGB(255, 0, 0));

		//画笛卡尔心型曲线下半部
		putPixel(real_x, real_z, RGB(0, 0, 255));
	}
	endPaint();
	return 0;
}
