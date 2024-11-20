/*2351131 ��04 Τ��ó*/
#include <iostream>
#include <conio.h>
#include <iomanip>
#include "cmd_console_tools.h"
#include "magic_ball.h"
using namespace std;
/***************************************************************************
  �������ƣ�draw_new_ball
  ��    �ܣ������µ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void draw_new_ball(char(&game_area)[row_max + 2][col_max + 2], int row, int col, char(&judgement)[row_max + 2][col_max + 2], int mode)
{
	int i, j;
	for (i = 2; i <= row + 1; i++) {
		for (j = 2; j <= col + 1; j++) {
			if (judgement[i][j] == '1') {
				cct_gotoxy(2 + 4 * (j - 2), 2 + 2 * (i - 2));
				cct_setcolor(game_area[i][j] - '0', COLOR_BLACK);
				if (mode)
					cout << "��";
				else
					cout << "��";
				delay(5);
			}
		}
	}
}
/***************************************************************************
  �������ƣ�draw_drop
  ��    �ܣ��������䶯��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void draw_drop(char(&game_area)[row_max + 2][col_max + 2], int row, int col, char(&judgement)[row_max + 2][col_max + 2], int zero_num)
{
	cct_gotoxy(2+4 * (col - 2), 2 + 2 * (row - 2) + 2 * zero_num);
	cct_setcolor(game_area[row][col] - '0', COLOR_BLACK);
	cout << "��";
	delay(4);
	cct_showch(2 + 4 * (col - 2), 2 + 2 * (row - 2) , ' ', COLOR_HWHITE, COLOR_BLACK, 2);
}
/***************************************************************************
  �������ƣ�boom
  ��    �ܣ�������ըʱ�Ķ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void boom(char(&game_area)[row_max + 2][col_max + 2], int row, int col, char(&judgement)[row_max + 2][col_max + 2], int &score,int mode)
{
	int i, j;
	for (i = 2; i <= row + 1; i++) {
		for (j = 2; j <= col + 1; j++) {
			if (judgement[i][j] == '1') {
				cct_gotoxy(2 + 4 * (j - 2), 2 + 2 * (i - 2));
				cct_setcolor(game_area[i][j] - '0', COLOR_BLACK);
				cout << "��";
				delay(4);
				cct_gotoxy(2 + 4 * (j - 2), 2 + 2 * (i - 2));
				cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
				cout << "  ";
				if (mode)
					score++;
			}
		}
	}
}
/***************************************************************************
  �������ƣ�draw_which_ball
  ��    �ܣ����ݲ�ͬ����������ͬ״̬�µ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void draw_which_ball(int& change1, int& change2, char select, char(&judgement)[row_max + 2][col_max + 2], int u, int v)
{
	if (judgement[u][v] == '1') {
		cout << "��";
		change1++;
	}
	else
		cout << "��";
	change2 += 4;
}
/***************************************************************************
  �������ƣ�upper
  ��    �ܣ����ϲ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void upper(int row, int col, char choice)
{
	int i;
	cout << endl;
	cout << "�X";

	if (choice == '4' || choice == '6') {
		for (i = 1; i < col; i++) {
			cout << "�T";
			delay(5);
		}
	}
	else {
		for (i = 1; i < col; i++) {
			cout << "�T�j";
			if (choice <= '5')
				delay(5);
		}
	}
	cout << "�T�[";
	cout << endl;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void middle(int row, int col, int& x, int& y, char choice)
{
	int i, j;
	if (choice == '5' || choice == '7' || choice == '8' || choice == '9') {
		for (i = 1; i < row; i++) {
			cct_getxy(x, y);
			for (j = 0; j < col; j++) {
				cout << "�U  ";
			}
			cout << "�U" << endl;
			if (choice <= '5')
				delay(5);
			cout << "�d";
			for (j = 1; j < col; j++) {
				cout << "�T�p";
			}
			cout << "�T�g" << endl;
		}
		for (j = 0; j < col; j++) {
			cout << "�U  ";
		}
		cout << "�U" << endl;
		if (choice <= '5')
			delay(5);
	}
	else {
		for (i = 0; i < row; i++) {
			cout << "�U";
			cct_getxy(x, y);
			cct_gotoxy(x + 2 * col, y);
			cout << "�U" << endl;
			delay(5);
		}
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void lower(int row, int col, char choice)
{
	int i;
	cout << "�^";
	if (choice == '4' || choice == '6') {
		for (i = 0; i < col; i++) {
			cout << "�T";
			delay(5);
		}
	}
	else {
		for (i = 1; i < col; i++) {
			cout << "�T�m";
			if (choice <= '5')
				delay(5);
		}
		cout << "�T";
	}
	cout << "�a" << endl;
}
/***************************************************************************
  �������ƣ�framework
  ��    �ܣ������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void framework(int row, int col, int &x, int &y, char choice)
{
	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);

	upper(row, col, choice);
	delay(5);

	middle(row, col, x, y, choice);
	delay(5);

	lower(row, col, choice);
	delay(5);
}

/***************************************************************************
  �������ƣ�draw
  ��    �ܣ����ݲ���������ʼ״̬
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void draw(char(&game_area)[row_max + 2][col_max + 2], int row, int col, char choice, char(&judgement)[row_max + 2][col_max + 2])
{
	if (choice < '6') {
		cout << "���س�����ʾͼ��...";
		wait_for_enter();
	}

	int i, j, screen = 0, jump = 0, cross = 0, remove = 0, a = 0, b = 0;
	cct_cls();

	if (choice == '4' || choice == '6')
		screen = row + 6;
	else if (choice == '5' || choice == '7' || choice == '8' || choice == '9')
		screen = 2 * row + 5;

	cct_setconsoleborder(40, screen, 50, 4);
	cct_setfontsize("������", 50);

	framework(row, col, a, b, choice);
	for (i = 2; i <= row + 1; i++) {
		cct_gotoxy(a, b + i - row - 1 + jump);
		for (j = 2; j <= col + 1; j++) {
			if (choice == '5' || choice == '7' || choice == '8' || choice == '9')
				cct_gotoxy(a + cross + 2, b + i - 2 * row + 2 + jump);
			cct_setcolor(game_area[i][j] - '0', COLOR_BLACK);
			draw_which_ball(remove, cross, choice, judgement, i, j);
			if (choice <= '5')
				delay(5);
		}
		cross = 0;
		if (choice == '5'|| choice == '7' || choice == '8' || choice == '9')
			jump ++;
		turn_back_color();
	}

	cct_gotoxy(0, 0);
	cout << "��Ļ��" << screen << "��" << "40��";
	if (!remove && choice > '5')
		cout << "(δ�ҵ���ʼ��������)" << endl;
	cout << endl;
	if(choice=='4' || choice == '6')
		cct_gotoxy(0, b + i - row);
	else
		cct_gotoxy(0, b + 4);
}