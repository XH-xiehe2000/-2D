#include <stdio.h>

#include <graphics.h>

#include <conio.h>
#include <GL/GLUT.h>

//�е㻭�߷�б��Ϊ0~1б��Ϊ0~1

void MidPointLine1(int x0, int y0, int x1, int y1)

{

	//��ʼһ��480*480�Ļ�ͼ��Ļ

	initgraph(480, 480);

	int a, b, delta1, delta2, d, x, y;

	a = y0 - y1;

	b = x1 - x0;

	d = 2 * a + b;

	delta1 = 2 * a;

	delta2 = 2 * (a + b);

	x = x0;

	y = y0;

	//�ڶ�Ӧ��x,y���ص���ɫ

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

		//�ڶ�Ӧ��x,y���ص���ɫ

		putpixel(x, y, GREEN);

		//���԰��������ȡ��ע�ͣ����س������߹��̡�

		//	system("pause");



	}

	//Ϊ���ܹ�������ͼЧ�� ����getch() �����ֱ�ӹرջ�ͼ��Ļ

	getch();

	closegraph();

}

//б��>1

void MidPointLine2(int x0, int y0, int x1, int y1)

{

	//��ʼһ��480*480�Ļ�ͼ��Ļ

	initgraph(480, 480);

	int a, b, delta1, delta2, d, x, y;

	a = y0 - y1;

	b = x1 - x0;

	d = a + 2 * b;

	delta1 = 2 * (a + b);

	delta2 = 2 * b;

	x = x0;

	y = y0;

	//�ڶ�Ӧ��x,y���ص���ɫ

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

		//�ڶ�Ӧ��x,y���ص���ɫ

		putpixel(x, y, GREEN);

		//���԰��������ȡ��ע�ͣ����س������߹��̡�

		//	system("pause");



	}

	//Ϊ���ܹ�������ͼЧ�� ����getch() �����ֱ�ӹرջ�ͼ��Ļ

	getch();

	closegraph();

}

//б��Ϊ-1~0

void MidPointLine3(int x0, int y0, int x1, int y1)

{

	//��ʼһ��480*480�Ļ�ͼ��Ļ

	initgraph(480, 480);

	int a, b, delta1, delta2, d, x, y;

	a = y0 - y1;

	b = x1 - x0;

	d = 2 * a - b;

	delta1 = 2 * a - 2 * b;

	delta2 = 2 * a;

	x = x0;

	y = y0;

	//�ڶ�Ӧ��x,y���ص���ɫ

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

		//�ڶ�Ӧ��x,y���ص���ɫ

		putpixel(x, y, GREEN);

		//���԰��������ȡ��ע�ͣ����س������߹��̡�

		//	system("pause");



	}

	//Ϊ���ܹ�������ͼЧ�� ����getch() �����ֱ�ӹرջ�ͼ��Ļ

	getch();

	closegraph();

}



//б��<-1

void MidPointLine4(int x0, int y0, int x1, int y1)

{

	//��ʼһ��480*480�Ļ�ͼ��Ļ

	initgraph(480, 480);

	int a, b, delta1, delta2, d, x, y;

	a = y0 - y1;

	b = x1 - x0;

	d = a - 2 * b;

	delta1 = -2 * b;

	delta2 = 2 * (a - b);

	x = x0;

	y = y0;

	//�ڶ�Ӧ��x,y���ص���ɫ

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

		//�ڶ�Ӧ��x,y���ص���ɫ

		putpixel(x, y, GREEN);

		//���԰��������ȡ��ע�ͣ����س������߹��̡�

		//	system("pause");

	}

	//Ϊ���ܹ�������ͼЧ�� ����getch() �����ֱ�ӹرջ�ͼ��Ļ

	getch();

	closegraph();

}

int main()

{

	int x1, y1, x2, y2;

	printf("��������ʼ�㣬�յ����꣨�ÿո�������س���������");

	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

	//����б�ʷ�Χ�ж϶�Ӧ����

	float k = (float)(y2 - y1) / (float)(x2 - x1);



	if (k >= 0 && k <= 1)

		MidPointLine1(x1, y1, x2, y2);//б��Ϊ0~1 ��������0 0 320 100

	else if (k > 1)

		MidPointLine2(x1, y1, x2, y2);//б��Ϊ>1  ��������0 0 100 320

	else if (k >= -1 && k <= 0)

		MidPointLine3(x1, y1, x2, y2);//б��Ϊ-1~0 ��������0 100 200 0

	else

		MidPointLine4(x1, y1, x2, y2);//б��Ϊ<-1 ��������0 200 100 0



}
