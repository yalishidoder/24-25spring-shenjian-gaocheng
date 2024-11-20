/* ѧ�� ���� �༶ */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
			char ch     ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
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

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/

/***************************************************************************
  �������ƣ�letter
  ��    �ܣ��ü�����ĸ�����ƶ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void letter(char mode, int x, int y)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	bool roll;
	int loop = 1;
	if (mode == '2' || mode == '6')
		roll = 1;
	else
		roll = 0;

	while (loop) {
		char keyboard = _getch();
		char judge = 0;

		if (mode > '4' && keyboard == -32)    //���ͷ���������ƶ�
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
  �������ƣ�arrow
  ��    �ܣ��ü�ͷ�����ƶ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void arrow(char mode, int x, int y)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

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
				case 72:     //�ϼ�ͷ
					if (--y < 1)
						y = roll ? MAX_Y : 1;
					break;
				case 80:   //�¼�ͷ
					if (++y > MAX_Y)
						y = roll ? 1 : MAX_Y;
					break;
				case 75:   //���ͷ
					if (--x < 1)
						x = roll ? MAX_X : 1;
					break;
				case 77:   //�Ҽ�ͷ
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�menu
  ��    �ܣ�����ѡ��趨ģʽ
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char menu()
{
	cout << "1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" << endl;
	cout << "2.��I��J��K��L��������������(��Сд���ɣ��߽����)" << endl;
	cout << "3.�ü�ͷ�������������ң��߽�ֹͣ" << endl;
	cout << "4.�ü�ͷ�������������ң��߽����" << endl;
	cout << "5.�ü�ͷ��������������(�߽�ֹͣ����ʾ��дHPKM���ƶ��Ĵ��󣬴����Ҫʵ��)" << endl;
	cout << "6.�ü�ͷ��������������(�߽���ƣ���ʾ��дHPKM���ƶ��Ĵ��󣬴����Ҫʵ��)" << endl;
	cout << "0.�˳�" << endl;
	cout << "[��ѡ��0-6]";

	char select = _getch();

	return select;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	int loop = 1;

	while (loop) {
		char sel = menu();

		if (sel == '0')   //ѡ��0ֱ���˳�
			break;

		/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
		srand((unsigned int)(time(0)));

		/* �˾�������ǵ���ϵͳ��cls�������� */
		cls(hout);

		/* ��ʾ��ʼ�ı߿����е�����ַ� */
		init_border(hout);

		gotoxy(hout, (MAX_X + 1) / 2, (MAX_Y + 1) / 2);

		move_by_keyboard(sel);

		gotoxy(hout, 0, 23);
		cout << "��Ϸ���������س����˳�.";

		//��ͣ(�˴���ҵҪ����ֻ�ܰ��س��˳���Ŀǰ��getcharʾ���������������+�س��˳�������������������Ļ��)
		while (_getch() != '\r')
			;

		cls(hout);
	}

	return 0;
}