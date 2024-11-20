/*2351131 ��04 Τ��ó*/
#include <iostream>
#include <conio.h>
#include "cmd_console_tools.h"
#include "magic_ball.h"
using namespace std;

/***************************************************************************
  �������ƣ�print_array
  ��    �ܣ���ӡ����
  ���������game_area,judge���飬����
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�search_row
  ��    �ܣ�Ѱ��ÿһ��������ʾ��
  ����������������飬����
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int search_row(char game_area[][col_max + 2], int row, int col, char(&judgement)[row_max + 2][col_max + 2])
{
	int i, j, num = 0;

	for (i = 2; i <= row + 1; i++) {                //���ж�
		for (j = 2; j <= col + 1; j++) {
			if (game_area[i][j] == game_area[i][j + 2]) {    //���һ����������ֵ���
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
			else if (game_area[i][j] == game_area[i][j + 1]) { //�������������ֵ(��)
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
			else if (game_area[i][j] == game_area[i][j - 1]) {  //�������������ֵ(��)
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
  �������ƣ�search_col
  ��    �ܣ�Ѱ���еĿ�������
  ����������������飬����
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int search_col(char game_area[][col_max + 2], int row, int col, char(&judgement)[row_max + 2][col_max + 2])
{
	int i, j, num = 0;
	for (i = 2; i <= row + 1; i++) {                //���ж�
		for (j = 2; j <= col + 1; j++) {
			if (game_area[i][j] == game_area[i + 2][j]) {    //���һ����������ֵ���
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
			else if (game_area[i][j] == game_area[i + 1][j]) { //�������������ֵ(��)
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
			else if (game_area[i][j] == game_area[i - 1][j]) {  //�������������ֵ(��)
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
  �������ƣ�fill
  ��    �ܣ���������������ֵ
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void fill(char(&game_area)[row_max + 2][col_max + 2], int row, int col, char judgement[][col_max + 2])
{
	int i, j;
	srand((unsigned int)(time(0))); //��������

	for (i = 2; i <= row + 1; i++) {
		for (j = 2; j <= col + 1; j++) {
			if (judgement[i][j] == '1')
				game_area[i][j] = 1 + rand() % 9 + '0';
		}
	}
}

/***************************************************************************
  �������ƣ�turn_to_zero
  ��    �ܣ�������������0
  ���������
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�drop
  ��    �ܣ���0Ԫ������
  ���������
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�confirm
  ��    �ܣ��鿴��ʱ�Ƿ��п�������
  ���������sure
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void confirm(int sure,char choice)
{
	if (!sure) {
		cout << "��ʼ���޿�������";
		if (choice == '2')
			cout << "����С���޷����ԣ����ٴ�����";
		cout << endl;
	}
	else {
		cout << endl;
		cout << "��ʼ���������ͬɫ��ʶ����" << endl;
	}
}

/***************************************************************************
  �������ƣ�find
  ��    �ܣ�Ѱ�ҿ�������
  ���������game_area���飬����
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�operate_array
  ��    �ܣ�������Ĳ���
  ���������
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�operate_graphical
  ��    �ܣ���ͼ�λ����в���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void operate_graphical(int row, int col, char choice, char(&game_area)[row_max + 2][col_max + 2], char(&judgement)[row_max + 2][col_max + 2])
{
	int sure = 0, point = 0; //��������������ò���
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
  �������ƣ�game_play
  ��    �ܣ������Ϸ����
  ���������
  �� �� ֵ��
  ˵    ����
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
	cout << "(��ǰ������" << point << "�Ҽ��˳�)";
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
		cout << "�޿��������Ϸ������     ";
	}
	end();
	cct_disable_mouse();	//�������
	cct_setcursor(CURSOR_VISIBLE_NORMAL);	//�򿪹��

}
/***************************************************************************
  �������ƣ�transit
  ��    �ܣ�����ѡ����ú���
  ���������
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�initialization
  ��    �ܣ����г�ʼ��
  �������������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void initialization(int row,int col, char choice)
{
	char game_area[row_max + 2][col_max + 2] = { 0 };
	char judgement[row_max + 2][col_max + 2] = { 0 };
	int i, j;  //����ѭ������

	srand((unsigned int)(time(0))); //��������

	for (i = 2; i <= row + 1; i++) {
		for (j = 2; j <= col + 1; j++) {
			game_area[i][j] = 1 + rand() % 9 + '0';
		}
	}
	if (choice < '6') {
		cout << "��ʼ���飺" << endl;
		print_array(game_area, row, col, judgement);
	}
	transit(row, col, choice, game_area);
}

/***************************************************************************
  �������ƣ�magic_ball_cin
  ��    �ܣ�������Ϸ����Ĵ�С
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void magic_ball_cin(char choice)
{
	int row, col;

	while (1) {
		cout << "����������(5-9)��" << endl;
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
		cout << "����������(5-9)��" << endl;
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