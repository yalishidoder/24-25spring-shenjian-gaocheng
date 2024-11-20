/* 学号 姓名 班级 */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/

/***************************************************************************
  函数名称：letter
  功    能：用键盘字母控制移动
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void letter(char mode, int x, int y)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	bool roll;
	int loop = 1;
	if (mode == '2' || mode == '6')
		roll = 1;
	else
		roll = 0;

	while (loop) {
		char keyboard = _getch();
		char judge = 0;

		if (mode > '4' && keyboard == -32)    //左箭头不会向下移动
			judge = _getch();

		if (judge == 0) {
			switch (keyboard)
			{
				case 32:
					cout << " ";
					break;
				case 'i':
				case 'I':
					if (--y < 1)
						y = roll ? MAX_Y : 1;
					break;
				case 'k':
				case 'K':
					if (++y > MAX_Y)
						y = roll ? 1 : MAX_Y;
					break;
				case 'j':
				case 'J':
					if (--x < 1)
						x = roll ? MAX_X : 1;
					break;
				case'l':
				case'L':
					if (++x > MAX_X)
						x = roll ? 1 : MAX_X;
					break;
				case 'q':
				case 'Q':
					loop = 0;
					break;
				default:
					break;
			}
		}
		gotoxy(hout, x, y);
	}
}

/***************************************************************************
  函数名称：arrow
  功    能：用箭头控制移动
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void arrow(char mode, int x, int y)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	bool roll;
	int loop = 1;
	if (mode == '4')
		roll = 1;
	else
		roll = 0;

	while (loop) {
		int move1= _getch();

		if (move1 == 224) {
			int move2 = _getch();
			switch (move2)
			{
				case 72:     //上箭头
					if (--y < 1)
						y = roll ? MAX_Y : 1;
					break;
				case 80:   //下箭头
					if (++y > MAX_Y)
						y = roll ? 1 : MAX_Y;
					break;
				case 75:   //左箭头
					if (--x < 1)
						x = roll ? MAX_X : 1;
					break;
				case 77:   //右箭头
					if (++x > MAX_X)
						x = roll ? 1 : MAX_X;
					break;
				default:
					break;
			}
		}
		else if (move1 == 32)
			cout << " ";
		else if (move1 == 'q' || move1 == 'Q')
			loop = 0;
		gotoxy(hout, x, y);
	}
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void move_by_keyboard(char mode)
{
	int x = (MAX_X + 1) / 2;
	int y = (MAX_Y + 1) / 2;

	switch (mode)
	{
		case '1':
		case '2':
		case '5':
		case '6':
			letter(mode, x, y);
			break;
		case '3':
		case '4':
			arrow(mode, x, y);
			break;
		default:
			break;
	}
	
}

/***************************************************************************
  函数名称：menu
  功    能：输入选项，设定模式
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char menu()
{
	cout << "1.用I、J、K、L键控制上下左右(大小写均可，边界停止)" << endl;
	cout << "2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)" << endl;
	cout << "3.用箭头键控制上下左右，边界停止" << endl;
	cout << "4.用箭头键控制上下左右，边界回绕" << endl;
	cout << "5.用箭头键控制上下左右(边界停止，演示大写HPKM可移动的错误，此项不需要实现)" << endl;
	cout << "6.用箭头键控制上下左右(边界回绕，演示大写HPKM可移动的错误，此项不需要实现)" << endl;
	cout << "0.退出" << endl;
	cout << "[请选择0-6]";

	char select = _getch();

	return select;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	int loop = 1;

	while (loop) {
		char sel = menu();

		if (sel == '0')   //选择0直接退出
			break;

		/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
		srand((unsigned int)(time(0)));

		/* 此句的作用是调用系统的cls命令清屏 */
		cls(hout);

		/* 显示初始的边框及其中的随机字符 */
		init_border(hout);

		gotoxy(hout, (MAX_X + 1) / 2, (MAX_Y + 1) / 2);

		move_by_keyboard(sel);

		gotoxy(hout, 0, 23);
		cout << "游戏结束，按回车键退出.";

		//暂停(此处作业要求是只能按回车退出，目前的getchar示例，是允许按任意键+回车退出，且任意键会出现在屏幕上)
		while (_getch() != '\r')
			;

		cls(hout);
	}

	return 0;
}