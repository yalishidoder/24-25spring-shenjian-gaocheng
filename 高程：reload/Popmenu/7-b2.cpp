/* ѧ�� �༶ ����*/

/* 1���������ͷ�ļ�
   2����������ȫ�ֱ�����������̬ȫ�֣���������const��define
   3����������Ҫ�Ľṹ�塢�����ȣ������ޱ�Դ�����ļ�ʹ�� */

#include "cmd_console_tools.h"
#include "7-b2.h"
#include <iostream>
#include <conio.h>
#include <cstring>
#include <iomanip>
using namespace std;

/* ������������Դ�����ļ���Ҫ�Ľṹ�壬��Ҫ�ŵ�.h��
       ��Ϊʾ��������Ҫ��ɾ�� */
struct origin {                    //��Ų˵��ĳ�ʼֵ
		//�˵���ȣ��������ұ߿�+4����ʾ��ʵ����������������ż��
	const int high = 10;		//�˵��߶ȣ��������±߿�+2����ʾ��ʵ����������
};

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����������Դ�����ļ���Ҫ�ĺ���������Ϊstatic����
***************************************************************************/
static void check(int &title,int &menu, int &right)          //ȷ�����ⳤ�ȺͲ˵����ȶ�Ϊż��
{
	if (title % 2)
		title++;

	if (menu <= title)
		menu = title;

	if ((menu - title) % 4)
		right = 1;
	else
		right = 0;
}

static void framework(const struct PopMenu* original_para, int max_sel, int right,int title)
{
	int i, j, k;
	cct_gotoxy((*original_para).start_x, (*original_para).start_y);

	cout << "�X";
	for (i = 0; i < ((*original_para).width- title)/4; i++)
		cout << "�T";
	cout << (*original_para).title;
	cout << setw(title - strlen((*original_para).title)) << " ";
	for (i = 0; i < ((*original_para).width - title) / 4 + right; i++)
		cout << "�T";
	cout << "�[";

	for (j = 0; j = max_sel; j++) {
		cout << "�U";
	}
	for (i = 0; i < ((*original_para).width); i++)
		cout << "�T";
}

static int fun(origin initial, const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
	int sel = 1, y = (*original_para).start_y + 1, MAX_Y = (*original_para).start_y +
		(initial.high < (*original_para).high ? initial.high : (*original_para).high), keyboard;

	while (1) {
		keyboard = _getch();
		if (keyboard == 27 || keyboard == '\r')
			break;
		else if (keyboard == 224) {
			int move = _getch();
			switch (move)
			{
				case 72:     //�ϼ�ͷ
					if (--y < (*original_para).start_y + 1)
						y = (*original_para).start_y + 1;
					if (--sel < 1)
						sel = 1;
					
					break;
				case 80:   //�¼�ͷ
					if (++y > MAX_Y)
						y = MAX_Y;
					if (++sel > 10)
						sel = 10;
					
					break;
				default:
					break;
			}
			if (y == (*original_para).start_y + 1 && sel > 1)
				;
			else if(y== (*original_para).start_y+ (*original_para).high && sel > (*original_para).high)
				;
		}
	}//��Ϊʾ��������Ҫ��ɾ��
	if (keyboard == 27)
		return -1;
	else if (keyboard == '\r')
		return sel;
	else
		return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��������������õĺ���������������ͷ�ļ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int pop_menu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
	struct origin initial;

	return fun(initial, menu,  original_para); //���践��
}
