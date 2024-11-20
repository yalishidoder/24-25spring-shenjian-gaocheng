/*2351131 信04 韦世贸*/
#include <iostream>
#include <conio.h>
#include <iomanip>
#include "cmd_console_tools.h"
#include "magic_ball.h"
using namespace std;
/***************************************************************************
  函数名称：draw_new_ball
  功    能：画出新的球
  输入参数：
  返 回 值：
  说    明：
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
					cout << "〇";
				else
					cout << "◎";
				delay(5);
			}
		}
	}
}
/***************************************************************************
  函数名称：draw_drop
  功    能：画出下落动画
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void draw_drop(char(&game_area)[row_max + 2][col_max + 2], int row, int col, char(&judgement)[row_max + 2][col_max + 2], int zero_num)
{
	cct_gotoxy(2+4 * (col - 2), 2 + 2 * (row - 2) + 2 * zero_num);
	cct_setcolor(game_area[row][col] - '0', COLOR_BLACK);
	cout << "〇";
	delay(4);
	cct_showch(2 + 4 * (col - 2), 2 + 2 * (row - 2) , ' ', COLOR_HWHITE, COLOR_BLACK, 2);
}
/***************************************************************************
  函数名称：boom
  功    能：画出球爆炸时的动画
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void boom(char(&game_area)[row_max + 2][col_max + 2], int row, int col, char(&judgement)[row_max + 2][col_max + 2], int &score,int mode)
{
	int i, j;
	for (i = 2; i <= row + 1; i++) {
		for (j = 2; j <= col + 1; j++) {
			if (judgement[i][j] == '1') {
				cct_gotoxy(2 + 4 * (j - 2), 2 + 2 * (i - 2));
				cct_setcolor(game_area[i][j] - '0', COLOR_BLACK);
				cout << "¤";
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
  函数名称：draw_which_ball
  功    能：根据不同参数画出不同状态下的球
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void draw_which_ball(int& change1, int& change2, char select, char(&judgement)[row_max + 2][col_max + 2], int u, int v)
{
	if (judgement[u][v] == '1') {
		cout << "●";
		change1++;
	}
	else
		cout << "〇";
	change2 += 4;
}
/***************************************************************************
  函数名称：upper
  功    能：画上层框架
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void upper(int row, int col, char choice)
{
	int i;
	cout << endl;
	cout << "╔";

	if (choice == '4' || choice == '6') {
		for (i = 1; i < col; i++) {
			cout << "═";
			delay(5);
		}
	}
	else {
		for (i = 1; i < col; i++) {
			cout << "═╦";
			if (choice <= '5')
				delay(5);
		}
	}
	cout << "═╗";
	cout << endl;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void middle(int row, int col, int& x, int& y, char choice)
{
	int i, j;
	if (choice == '5' || choice == '7' || choice == '8' || choice == '9') {
		for (i = 1; i < row; i++) {
			cct_getxy(x, y);
			for (j = 0; j < col; j++) {
				cout << "║  ";
			}
			cout << "║" << endl;
			if (choice <= '5')
				delay(5);
			cout << "╠";
			for (j = 1; j < col; j++) {
				cout << "═╬";
			}
			cout << "═╣" << endl;
		}
		for (j = 0; j < col; j++) {
			cout << "║  ";
		}
		cout << "║" << endl;
		if (choice <= '5')
			delay(5);
	}
	else {
		for (i = 0; i < row; i++) {
			cout << "║";
			cct_getxy(x, y);
			cct_gotoxy(x + 2 * col, y);
			cout << "║" << endl;
			delay(5);
		}
	}
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void lower(int row, int col, char choice)
{
	int i;
	cout << "╚";
	if (choice == '4' || choice == '6') {
		for (i = 0; i < col; i++) {
			cout << "═";
			delay(5);
		}
	}
	else {
		for (i = 1; i < col; i++) {
			cout << "═╩";
			if (choice <= '5')
				delay(5);
		}
		cout << "═";
	}
	cout << "╝" << endl;
}
/***************************************************************************
  函数名称：framework
  功    能：画框架
  输入参数：
  返 回 值：
  说    明：
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
  函数名称：draw
  功    能：根据参数画出初始状态
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void draw(char(&game_area)[row_max + 2][col_max + 2], int row, int col, char choice, char(&judgement)[row_max + 2][col_max + 2])
{
	if (choice < '6') {
		cout << "按回车键显示图形...";
		wait_for_enter();
	}

	int i, j, screen = 0, jump = 0, cross = 0, remove = 0, a = 0, b = 0;
	cct_cls();

	if (choice == '4' || choice == '6')
		screen = row + 6;
	else if (choice == '5' || choice == '7' || choice == '8' || choice == '9')
		screen = 2 * row + 5;

	cct_setconsoleborder(40, screen, 50, 4);
	cct_setfontsize("新宋体", 50);

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
	cout << "屏幕：" << screen << "行" << "40列";
	if (!remove && choice > '5')
		cout << "(未找到初始可消除项)" << endl;
	cout << endl;
	if(choice=='4' || choice == '6')
		cct_gotoxy(0, b + i - row);
	else
		cct_gotoxy(0, b + 4);
}