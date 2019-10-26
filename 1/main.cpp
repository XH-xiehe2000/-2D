#include <stdio.h>

#include <graphics.h>

#include <conio.h>
#include <GL/GLUT.h>

//中点画线法斜率为0~1斜率为0~1

void MidPointLine1(int x0, int y0, int x1, int y1)

{

	//初始一个480*480的绘图屏幕

	initgraph(480, 480);

	int a, b, delta1, delta2, d, x, y;

	a = y0 - y1;

	b = x1 - x0;

	d = 2 * a + b;

	delta1 = 2 * a;

	delta2 = 2 * (a + b);

	x = x0;

	y = y0;

	//在对应的x,y像素点着色

	putpixel(x, y, GREEN);

	while (x < x1)

	{

		if (d < 0)

		{

			x++;

			y++;

			d += delta2;

		}

		else

		{

			x++;

			d += delta1;

		}

		//在对应的x,y像素点着色

		putpixel(x, y, GREEN);

		//可以把下面这句取消注释，按回车看画线过程。

		//	system("pause");



	}

	//为了能够看到绘图效果 加了getch() 否则会直接关闭绘图屏幕

	getch();

	closegraph();

}

//斜率>1

void MidPointLine2(int x0, int y0, int x1, int y1)

{

	//初始一个480*480的绘图屏幕

	initgraph(480, 480);

	int a, b, delta1, delta2, d, x, y;

	a = y0 - y1;

	b = x1 - x0;

	d = a + 2 * b;

	delta1 = 2 * (a + b);

	delta2 = 2 * b;

	x = x0;

	y = y0;

	//在对应的x,y像素点着色

	putpixel(x, y, GREEN);

	while (y < y1)

	{

		if (d < 0)

		{

			y++;

			d += delta2;

		}

		else

		{

			y++;

			x++;

			d += delta1;

		}

		//在对应的x,y像素点着色

		putpixel(x, y, GREEN);

		//可以把下面这句取消注释，按回车看画线过程。

		//	system("pause");



	}

	//为了能够看到绘图效果 加了getch() 否则会直接关闭绘图屏幕

	getch();

	closegraph();

}

//斜率为-1~0

void MidPointLine3(int x0, int y0, int x1, int y1)

{

	//初始一个480*480的绘图屏幕

	initgraph(480, 480);

	int a, b, delta1, delta2, d, x, y;

	a = y0 - y1;

	b = x1 - x0;

	d = 2 * a - b;

	delta1 = 2 * a - 2 * b;

	delta2 = 2 * a;

	x = x0;

	y = y0;

	//在对应的x,y像素点着色

	putpixel(x, y, GREEN);

	while (x < x1)

	{

		if (d < 0)

		{

			x++;

			d += delta2;

		}

		else

		{

			x++;

			y--;

			d += delta1;

		}

		//在对应的x,y像素点着色

		putpixel(x, y, GREEN);

		//可以把下面这句取消注释，按回车看画线过程。

		//	system("pause");



	}

	//为了能够看到绘图效果 加了getch() 否则会直接关闭绘图屏幕

	getch();

	closegraph();

}



//斜率<-1

void MidPointLine4(int x0, int y0, int x1, int y1)

{

	//初始一个480*480的绘图屏幕

	initgraph(480, 480);

	int a, b, delta1, delta2, d, x, y;

	a = y0 - y1;

	b = x1 - x0;

	d = a - 2 * b;

	delta1 = -2 * b;

	delta2 = 2 * (a - b);

	x = x0;

	y = y0;

	//在对应的x,y像素点着色

	putpixel(x, y, GREEN);

	while (y > y1)

	{

		if (d < 0)

		{

			x++;

			y--;

			d += delta2;

		}

		else

		{

			y--;

			d += delta1;

		}

		//在对应的x,y像素点着色

		putpixel(x, y, GREEN);

		//可以把下面这句取消注释，按回车看画线过程。

		//	system("pause");

	}

	//为了能够看到绘图效果 加了getch() 否则会直接关闭绘图屏幕

	getch();

	closegraph();

}

int main()

{

	int x1, y1, x2, y2;

	printf("请输入起始点，终点坐标（用空格隔开，回车结束）：");

	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

	//根据斜率范围判断对应函数

	float k = (float)(y2 - y1) / (float)(x2 - x1);



	if (k >= 0 && k <= 1)

		MidPointLine1(x1, y1, x2, y2);//斜率为0~1 测试数据0 0 320 100

	else if (k > 1)

		MidPointLine2(x1, y1, x2, y2);//斜率为>1  测试数据0 0 100 320

	else if (k >= -1 && k <= 0)

		MidPointLine3(x1, y1, x2, y2);//斜率为-1~0 测试数据0 100 200 0

	else

		MidPointLine4(x1, y1, x2, y2);//斜率为<-1 测试数据0 200 100 0



}
