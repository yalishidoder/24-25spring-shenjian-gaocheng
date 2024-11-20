/*2351131 信04 韦世贸*/
#include <iostream>
#include <conio.h>
#include "cmd_console_tools.h"
#include "magic_ball.h"
using namespace std;

/***************************************************************************
  函数名称：print_array
  功    能：打印数组
  输入参数：game_area,judge数组，行列
  返 回 值：
  说    明：
***************************************************************************/
void print_array(char game_area[][col_max + 2], int row, int col, char judgement[][col_max + 2])
{
	char colp = 0;
	int i, j;

	cout << "  |";

	for (colp = col_start; colp < col_start + col; colp++) {
		cout << "  " << colp;
	}
	cout << endl;
	cout << "--+";

	for (colp = col_start; colp < col_start + col; colp++) {
		cout << "---";
	}
	cout << endl;

	for (i = 2; i <= row + 1; i++) {
		cout << char(row_start + i - 1) << " |";
		for (j = 2; j <= col + 1; j++) {
			cout << "  ";
			if (judgement[i][j] == '1')
				change_color();
			cout << game_area[i][j];
			turn_back_color();
		}
		cout << endl;
	}
	cout << endl;
}

/***************************************************************************
  函数名称：search_row
  功    能：寻找每一行消除提示项
  输入参数：两个数组，行列
  返 回 值：
  说    明：
***************************************************************************/
int search_row(char game_area[][col_max + 2], int row, int col, char(&judgement)[row_max + 2][col_max + 2])
{
	int i, j, num = 0;

	for (i = 2; i <= row + 1; i++) {                //行判断
		for (j = 2; j <= col + 1; j++) {
			if (game_area[i][j] == game_area[i][j + 2]) {    //相隔一个，有两个值相等
				if (game_area[i][j] == game_area[i - 1][j + 1]) {
					judgement[i - 1][j + 1] = '1';
					judgement[i][j + 1] = '1';
					num++;
				}
				else if (game_area[i][j] == game_area[i + 1][j + 1]) {
					judgement[i + 1][j + 1] = '1';
					judgement[i][j + 1] = '1';
					num++;
				}
			}
			else if (game_area[i][j] == game_area[i][j + 1]) { //相连的两个相等值(左)
				if (game_area[i][j] == game_area[i][j - 2]) {
					judgement[i][j - 2] = '1';
					judgement[i][j - 1] = '1';
					num++;
				}
				else if (game_area[i][j] == game_area[i - 1][j - 1]){
					judgement[i - 1][j - 1] = '1';
					judgement[i][j - 1] = '1';
					num++;
				}
				else if (game_area[i][j] == game_area[i + 1][j - 1]){
					judgement[i + 1][j - 1] = '1';
					judgement[i][j - 1] = '1';
					num++;
				}
			}
			else if (game_area[i][j] == game_area[i][j - 1]) {  //相连的两个相等值(右)
				if (game_area[i][j] == game_area[i][j + 2]) {
					judgement[i][j + 2] = '1';
					judgement[i][j + 1] = '1';
					num++;
				}
				else if (game_area[i][j] == game_area[i - 1][j + 1]){
					judgement[i - 1][j + 1] = '1';
					judgement[i][j + 1] = '1';
					num++;
				}
				else if (game_area[i][j] == game_area[i + 1][j + 1]){
					judgement[i + 1][j + 1] = '1';
					judgement[i][j + 1] = '1';
					num++;
				}
			}
		}
	}
	return num;
}

/***************************************************************************
  函数名称：search_col
  功    能：寻找列的可消除项
  输入参数：两个数组，行列
  返 回 值：
  说    明：
***************************************************************************/
int search_col(char game_area[][col_max + 2], int row, int col, char(&judgement)[row_max + 2][col_max + 2])
{
	int i, j, num = 0;
	for (i = 2; i <= row + 1; i++) {                //列判断
		for (j = 2; j <= col + 1; j++) {
			if (game_area[i][j] == game_area[i + 2][j]) {    //相隔一个，有两个值相等
				if (game_area[i][j] == game_area[i + 1][j - 1]) {
					judgement[i + 1][j - 1] = '1';
					judgement[i + 1][j] = '1';
					num++;
				}
				else if (game_area[i][j] == game_area[i + 1][j + 1]) {
					judgement[i + 1][j + 1] = '1';
					judgement[i + 1][j] = '1';
					num++;
				}
			}
			else if (game_area[i][j] == game_area[i + 1][j]) { //相连的两个相等值(上)
				if (game_area[i][j] == game_area[i - 2][j]) {
					judgement[i - 2][j] = '1';
					judgement[i - 1][j] = '1';
					num++;
				}
				else if (game_area[i][j] == game_area[i - 1][j - 1]){
					judgement[i - 1][j - 1] = '1';
					judgement[i - 1][j] = '1';
					num++;
				}
				else if (game_area[i][j] == game_area[i - 1][j + 1]){
					judgement[i - 1][j + 1] = '1';
					judgement[i - 1][j] = '1';
					num++;
				}
			}
			else if (game_area[i][j] == game_area[i - 1][j]) {  //相连的两个相等值(下)
				if (game_area[i][j] == game_area[i + 2][j]) {
					judgement[i + 2][j] = '1';
					judgement[i + 1][j] = '1';
					num++;
				}
				else if (game_area[i][j] == game_area[i + 1][j - 1]){
					judgement[i + 1][j - 1] = '1';
					judgement[i + 1][j] = '1';
					num++;
				}
				else if (game_area[i][j] == game_area[i + 1][j + 1]){
					judgement[i + 1][j + 1] = '1';
					judgement[i + 1][j] = '1';
					num++;
				}
			}
		}
	}
	return num;
}
/***************************************************************************
  函数名称：fill
  功    能：向被消除项填充随机值
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void fill(char(&game_area)[row_max + 2][col_max + 2], int row, int col, char judgement[][col_max + 2])
{
	int i, j;
	srand((unsigned int)(time(0))); //生成种子

	for (i = 2; i <= row + 1; i++) {
		for (j = 2; j <= col + 1; j++) {
			if (judgement[i][j] == '1')
				game_area[i][j] = 1 + rand() % 9 + '0';
		}
	}
}

/***************************************************************************
  函数名称：turn_to_zero
  功    能：将可消除项置0
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void turn_to_zero(char(&game_area)[row_max + 2][col_max + 2], int row, int col, char(&judgement)[row_max + 2][col_max + 2])
{
	int i, j;
	for (i = 2; i <= row + 1; i++) {
		for (j = 2; j <= col + 1; j++) {
			if (judgement[i][j] == '1')
				game_area[i][j] = '0';
		}
	}

}

/***************************************************************************
  函数名称：drop
  功    能：非0元素下落
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void drop(char(&game_area)[row_max + 2][col_max + 2], int row, int col, char(&judgement)[row_max + 2][col_max + 2],char choice)
{
	int i, j, zero_num;
	for (j = 2; j < col + 2; j++) {
		zero_num = 0;
		for (i = row + 1; i > 1; i--) {
			if (judgement[i][j] == '1') {
				zero_num++;
				judgement[i][j] = '0';
				continue;
			}
			else {
				game_area[i + zero_num][j] = game_area[i][j];
				if (choice > '6' && zero_num)
					draw_drop(game_area, i, j, judgement, zero_num);
			}
		}
		if (zero_num) {
			for (i = 2; i < 2 + zero_num; i++)
				judgement[i][j] = '1';
		}
	}
}

/***************************************************************************
  函数名称：confirm
  功    能：查看此时是否有可消除项
  输入参数：sure
  返 回 值：
  说    明：
***************************************************************************/
void confirm(int sure,char choice)
{
	if (!sure) {
		cout << "初始已无可消除项";
		if (choice == '2')
			cout << "，本小题无法测试，请再次运行";
		cout << endl;
	}
	else {
		cout << endl;
		cout << "初始可消除项（不同色标识）：" << endl;
	}
}

/***************************************************************************
  函数名称：find
  功    能：寻找可消除项
  输入参数：game_area数组，行列
  返 回 值：
  说    明：
***************************************************************************/
int find(char game_area[][col_max + 2], int row, int col, char(&judgement)[row_max + 2][col_max + 2])
{
	int i, j, sure = 0;
	 
	for (i = 2; i <= row + 1; i++) {
		for (j = 2; j <= col + 1; j++) {
			if (game_area[i][j] == game_area[i][j - 1] && game_area[i][j] == game_area[i][j + 1]) {
				judgement[i][j] = '1';
				judgement[i][j + 1] = '1';
				judgement[i][j - 1] = '1';
				sure++;
			}
		}
	}

	for (i = 2; i <= row + 1; i++) {
		for (j = 2; j <= col + 1; j++) {
			if (game_area[i][j] == game_area[i - 1][j] && game_area[i][j] == game_area[i + 1][j]) {
				judgement[i][j] = '1';
				judgement[i - 1][j] = '1';
				judgement[i + 1][j] = '1';
				sure++;
			}
		}
	}

	return sure;
}

/***************************************************************************
  函数名称：operate_array
  功    能：对数组的操作
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void operate_array(int row, int col, char choice, char(&game_area)[row_max + 2][col_max + 2], char(&judgement)[row_max + 2][col_max + 2])
{
	int sure = 0;
	magic_ball_cout(row, 1);
	sure = find(game_area, row, col, judgement);
	confirm(sure, choice);
	if (sure)
		print_array(game_area, row, col, judgement);
	switch (choice)
	{
		case '2':
		case '3':
			while (sure) {
				magic_ball_cout(row, 2);
				drop(game_area, row, col, judgement, choice);
				turn_to_zero(game_area, row, col, judgement);

				magic_ball_cout(row, 4);
				print_array(game_area, row, col, judgement);

				magic_ball_cout(row, 3);
				fill(game_area, row, col, judgement);

				magic_ball_cout(row, 5);
				print_array(game_area, row, col, judgement);
				format(judgement);

				sure = find(game_area, row, col, judgement);
				confirm(sure, '1');
				if (sure)
					print_array(game_area, row, col, judgement);
			}
			if (choice == '3') {
				magic_ball_cout(row, 6);
				search_row(game_area, row, col, judgement);
				search_col(game_area, row, col, judgement);
				print_array(game_area, row, col, judgement);
			}
			break;
		default:
			break;
	}
	end();
}
/***************************************************************************
  函数名称：operate_graphical
  功    能：对图形化进行操作
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void operate_graphical(int row, int col, char choice, char(&game_area)[row_max + 2][col_max + 2], char(&judgement)[row_max + 2][col_max + 2])
{
	int sure = 0, point = 0; //这个分数在这里用不到
	switch (choice)
	{
		case '4':
		case '5':
			draw(game_area, row, col, choice, judgement);
			break;
		case '6':
		case '7':
			sure = find(game_area, row, col, judgement);
			draw(game_area, row, col, choice, judgement);
			if (choice > '6') {
				while (sure) {
					magic_ball_cout(row, 7);
					boom(game_area, row, col, judgement, point, 0);
					drop(game_area, row, col, judgement, choice);
					magic_ball_cout(row, 8);
					turn_to_zero(game_area, row, col, judgement);
					fill(game_area, row, col, judgement);
					format(judgement);
					sure = find(game_area, row, col, judgement);
					draw(game_area, row, col, choice, judgement);
					turn_back_color();
				}

				magic_ball_cout(row, 9);
				search_row(game_area, row, col, judgement);
				search_col(game_area, row, col, judgement);
				draw_new_ball(game_area, row, col, judgement, 0);
				turn_back_color();
			}
			break;
		default:
			break;
	}
	turn_back_color();
	cct_gotoxy(0, 2 * (row + 1));
	end();
}
/***************************************************************************
  函数名称：game_play
  功    能：完成游戏操作
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void game_play(int row, int col, char choice, char(&game_area)[row_max + 2][col_max + 2], char(&judgement)[row_max + 2][col_max + 2])
{
	int sure = 0, num1 = 0, num2 = 0, point = 0; 
	
	sure = find(game_area, row, col, judgement);
	draw(game_area, row, col, choice, judgement);
	while (sure) {
		boom(game_area, row, col, judgement, point, 0);
		drop(game_area, row, col, judgement, choice);
		turn_to_zero(game_area, row, col, judgement);
		fill(game_area, row, col, judgement);
		format(judgement);
		sure = find(game_area, row, col, judgement);
		draw(game_area, row, col, choice, judgement);
		turn_back_color();
	}
	cct_gotoxy(14, 0);
	turn_back_color();
	cout << "(当前分数：" << point << "右键退出)";
	num1 = search_row(game_area, row, col, judgement);
	num2 = search_col(game_area, row, col, judgement);
	draw_new_ball(game_area, row, col, judgement, 0);
	turn_back_color();
	while (num1 || num2) {
		mouse(game_area, row, col, judgement, choice, num1, num2);
		if (choice == '8')
			break;
	}
	if (!num1 && !num2) {
		cct_gotoxy(0, 0);
		turn_back_color();
		cout << "无可消除项，游戏结束！     ";
	}
	end();
	cct_disable_mouse();	//禁用鼠标
	cct_setcursor(CURSOR_VISIBLE_NORMAL);	//打开光标

}
/***************************************************************************
  函数名称：transit
  功    能：根据选项调用函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void transit(int row, int col, char choice, char(&game_area)[row_max + 2][col_max + 2])
{
	char judgement[row_max + 2][col_max + 2] = { 0 };
	if (choice < '4')
		operate_array(row, col, choice, game_area, judgement);
	else if (choice >= '4' && choice < '8')
		operate_graphical(row, col, choice, game_area, judgement);
	else
		game_play(row, col, choice, game_area, judgement);
}

/***************************************************************************
  函数名称：initialization
  功    能：进行初始化
  输入参数：行列
  返 回 值：
  说    明：
***************************************************************************/
void initialization(int row,int col, char choice)
{
	char game_area[row_max + 2][col_max + 2] = { 0 };
	char judgement[row_max + 2][col_max + 2] = { 0 };
	int i, j;  //定义循环变量

	srand((unsigned int)(time(0))); //生成种子

	for (i = 2; i <= row + 1; i++) {
		for (j = 2; j <= col + 1; j++) {
			game_area[i][j] = 1 + rand() % 9 + '0';
		}
	}
	if (choice < '6') {
		cout << "初始数组：" << endl;
		print_array(game_area, row, col, judgement);
	}
	transit(row, col, choice, game_area);
}

/***************************************************************************
  函数名称：magic_ball_cin
  功    能：输入游戏区域的大小
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void magic_ball_cin(char choice)
{
	int row, col;

	while (1) {
		cout << "请输入行数(5-9)：" << endl;
		cin >> row;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(114514, '\n');
			continue;
		}

		if (row <= row_max && row >= 5)
			break;;
	}

	while (1) {
		cout << "请输入列数(5-9)：" << endl;
		cin >> col;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(114514, '\n');
			continue;
		}

		if (col >= 5 && col <= col_max)
			break;
	}

	cout << endl;
	initialization(row, col, choice);
}