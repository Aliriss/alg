#include "acllib.h"

#include <stdio.h>
//#include<initWindow>
#include<math.h>

int Setup()

{

	https://��ʼ������λ�úʹ�С

	initWindow("�����̵ĵ��������Ǻõĳ���Գ", 0, 0, 500, 550);

	beginPaint();

	//�Ŵ�ϵ��a

	int a = 100;

	//����ֱ������ϵ��x����
	double x = -2;
	for (; x <= 2; x = x + 0.01)

	{

		//ֱ������ϵ��y����

		double y = sqrt(2 * sqrt(x*x) - x * x);

		//ֱ������ϵ��z����

		double z = asin((fabs(x) - 1)) - 3.141592 / 2;

		//ֱ������ϵ�任����Ļ����ϵ

		int real_x = (int)(x * a + 250);

		int real_y = (int)(y * a*(-1) + 150);

		int real_z = (int)(z * a * (-1) + 150);

		//���ѿ������������ϰ벿

		putPixel(real_x, real_y, RGB(255, 0, 0));

		//���ѿ������������°벿
		putPixel(real_x, real_z, RGB(0, 0, 255));
	}
	endPaint();
	return 0;
}
