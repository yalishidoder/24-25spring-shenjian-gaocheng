/* 2351131 ��04 Τ��ó */
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
  �������ƣ�menu
  ��    �ܣ��˵���ʾ������ѡ���ѡ��
  ���������ѡ��
  �� �� ֵ��ѡ��
  ˵    ����
***************************************************************************/
int menu()
{
	int select;
	while (1) {
		cout << "1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" << endl;
		cout << "2.��I��J��K��L��������������(��Сд���ɣ��߽����)" << endl;
		cout << "3.�ü�ͷ�������������ң��߽�ֹͣ" << endl;
		cout << "4.�ü�ͷ�������������ң��߽����" << endl;
		cout << "0.�˳�" << endl;
		cout << "[��ѡ��0-4]";
		select = _getch() - '0';/*�����Ͳ���Ҫ�ఴһ�λس�*/
		cout << select << endl;
		switch (select)
		{
			case 0:
				return 0;/*�˳�����*/
				break;
			case 1:
			case 2:
			case 3:
			case 4:
				return select;
			default:
				cls(GetStdHandle(STD_OUTPUT_HANDLE));
				continue;
		}
	}
	
}
/***************************************************************************
  �������ƣ�move_by_keyboard
  ��    �ܣ������ض��ļ����ƶ����(�ո���������ĸ)
  ���������select,����
  �� �� ֵ���˳��ж�
  ˵    ����
***************************************************************************/
int move_by_keyboard(int select, int x, int y)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	while (1) {
		if (select == 3 || select == 4) { /*��ͷ����*/
			int keyboard;
			int shuru = _getch();
			if (shuru == 224) { /*��ͷ����ǰ����*/
				keyboard = _getch();
				if (select == 3) { /*�߽�ֹͣ*/
					if (keyboard == 72 && y >= 2) /*��*/
						gotoxy(hout, x, y--);
					if (keyboard == 80 && y <= MAX_Y / 2 - 1) /*��*/
						gotoxy(hout, x, y++);
					if (keyboard == 75 && x >= 2)  /*��*/
						gotoxy(hout, x--, y);
					if (keyboard == 77 && x <= MAX_X / 2 - 1)  /*��*/
						gotoxy(hout, x++, y);
					else if (shuru == ' ')
						showch(hout, x, y, ' ');  /*�ո�ɾ���ַ�*/
				}
				else if (select == 4) { /*�߽����*/
					if (keyboard == 72 && y >= 2) { /*��*/
						--y;
						gotoxy(hout, x, y);
					}
					if (keyboard == 80 && y <= MAX_Y / 2 - 1) { /*��*/
						++y;
						gotoxy(hout, x, ++y);
					}
					if (keyboard == 75 && x >= 2) {  /*��*/
						--x;
						gotoxy(hout, x, y);
					}
					if (keyboard == 77 && x <= MAX_X / 2 - 1) {/*��*/
						++x;
						gotoxy(hout, x, y);
					}
					else if (keyboard == ' ') {
						showch(hout, x, y, ' ');/*�ո�ɾ���ַ�*/
						gotoxy(hout, x, y);
					}
				}
			}
		}
		else if (select == 1 || select == 2) {
			char keyboard;
			keyboard = _getch();
			if (select == 1) { /*�߽�ֹͣ*/
				if ((keyboard == 'i' || keyboard == 'I') && y >= 2) /*��*/
					gotoxy(hout, x, y--);
				if ((keyboard == 'k' || keyboard == 'K') && y <= MAX_Y / 2 - 1) /*��*/
					gotoxy(hout, x, y++);
				if ((keyboard == 'j' || keyboard == 'J') && x >= 2)  /*��*/
					gotoxy(hout, x--, y);
				if ((keyboard == 'l' || keyboard == 'L') && x <= MAX_X / 2 - 1)  /*��*/
					gotoxy(hout, x++, y);
				else if (keyboard == ' ') {
					showch(hout, x, y, ' ');
					gotoxy(hout, x, y);
				}
				/*�ո�ɾ���ַ�*/
			}
			else if (select == 2) { /*�߽����*/
				if ((keyboard == 'i' || keyboard == 'I')) {/*��*/
					gotoxy(hout, x, y--);
				}
				if ((keyboard == 'k' || keyboard == 'K') && y <= MAX_Y / 2 - 1) /*��*/
					gotoxy(hout, x, y++);
				if ((keyboard == 'j' || keyboard == 'J') && x >= 2)  /*��*/
					gotoxy(hout, x--, y);
				if ((keyboard == 'l' || keyboard == 'L') && x <= MAX_X / 2 - 1)  /*��*/
					gotoxy(hout, x++, y);
				else if (keyboard == ' ') {
					showch(hout, x, y, ' ');
					gotoxy(hout, x--, y);

				}
			}



		}

	}
	
}
	

/***************************************************************************
  �������ƣ�main
  ��    �ܣ�������������
  �����������
  �� �� ֵ��0
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/

int main()
{
	while (1) {
		int select = menu();
		
		if (select == 0) /*���ѡ��0��ֱ���˳�����*/
			return 0;
		const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

		/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
		srand((unsigned int)(time(0)));

		/* �˾�������ǵ���ϵͳ��cls�������� */
		cls(hout);

		/* ��ʾ��ʼ�ı߿����е�����ַ� */
		init_border(hout);

		gotoxy(hout, MAX_X / 2, MAX_Y / 2);/*�ѹ���ƶ�����������*/

		
		move_by_keyboard(select, MAX_X / 2, MAX_Y / 2);

		
	}


	//��ͣ(�˴���ҵҪ����ֻ�ܰ��س��˳���Ŀǰ��getcharʾ���������������+�س��˳�������������������Ļ��)
	int key = _getch();
	if (key == 32 ) {
		return 0;
	}
	
}