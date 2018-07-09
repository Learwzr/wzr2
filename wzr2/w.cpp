//////////////////////////////////////
//钟表程序
//编译环境 VC2017
//吴卓睿
//2018/7/9
//////////////////////////////////////
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include<stdio.h>
#include<cstring>

#define PI 3.1415926535
//
//name：钟表函数
//data：2018.7.9
//wzr
//
void draw(int hour, int min, int sec)
{
	double rad_hour, rad_min, rad_sec;//弧度
	int x_hour, x_min, x_sec;//横坐标
	int y_hour, y_min, y_sec;//纵坐标
	//逻辑坐标

	//计算
	rad_sec = sec * 2 * PI / 60;
	rad_min = min * 2 * PI / 60 + rad_sec / 60;
	rad_hour = hour * 2 * PI / 12 + rad_min / 60;
	
	x_sec = 320 + int(120 * sin(rad_sec));
	y_sec = 240 - int(120 * cos(rad_sec));
	x_min = 320 + int(100 * sin(rad_min));
	y_min = 240 - int(100 * cos(rad_min));
	x_hour = 320 + int(70 * sin(rad_hour));
	y_hour = 240 - int(70 * cos(rad_hour));

	// 画时针
	setlinestyle(PS_SOLID, 10, NULL);
	setlinecolor(WHITE);
	line(320, 240, x_hour, y_hour);
	// 画分针
	setlinestyle(PS_SOLID, 6, NULL);
	setlinecolor(LIGHTGRAY);
	line(320, 240, x_min, y_min);
	// 画秒针
	setlinestyle(PS_SOLID, 2, NULL);
	setlinecolor(LIGHTRED);
	line(320, 240, x_sec, y_sec);
}

//void CharToTchar (const char * _char, TCHAR * tchar)
//{
//	    int iLength;
//	
//		   iLength = MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, NULL, 0);
//	  MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, tchar, iLength);
//}

void main()
{
	initgraph(640, 480);
	setcolor(YELLOW);
	circle(320, 240, 2);
	circle(320, 240, 60);
	circle(320, 240, 160);
	SYSTEMTIME ti;
	TCHAR t[100];
	TCHAR _t[100];
	RECT r = { 260, 340, 380, 370 };
	RECT _r = { 200, 30, 450, 70 };
	rectangle(260, 340, 380, 370);
	rectangle(200, 30, 450, 70);
	setwritemode(R2_XORPEN);
	while (!_kbhit())
	{
		GetLocalTime(&ti);
		_stprintf_s(t, _T("%02d:%02d:%02d"), ti.wHour, ti.wMinute, ti.wSecond);
		_stprintf_s(_t, _T("%d年%02d月%02d日"), ti.wYear,ti.wMonth, ti.wDay);
		draw(ti.wHour, ti.wMinute, ti.wSecond);//表针
		drawtext(t, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//数字时钟
		settextstyle(30, 0, _T("宋体"));
		drawtext(_t, &_r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//年月日
		Sleep(1000);
		_stprintf_s(t,_T( "%d:%d:%d"), ti.wHour, ti.wMinute, ti.wSecond);
		draw(ti.wHour, ti.wMinute, ti.wSecond);
		_stprintf_s(_t, _T("%d年%02d月%02d日"), ti.wYear, ti.wMonth, ti.wDay);
		drawtext(t, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		drawtext(_t, &_r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//年月日
	}
	closegraph();

}