/*2351131 信04 韦世贸*/
#pragma once

//base.cpp中的const常量
const char row_start = 'A';
const char col_start = '1';
const int row_max = 9;
const int col_max = 9;

//graph.cpp中的const常量
const int group_max = 81;
const int member = 2;
//menu.cpp中的函数声明
char magic_ball_menu();

//base.cpp中的函数声明
void magic_ball_cin(char choice);
int search_row(char game_area[][col_max + 2], int row, int col, char(&judgement)[row_max + 2][col_max + 2]);
int search_col(char game_area[][col_max + 2], int row, int col, char(&judgement)[row_max + 2][col_max + 2]);
void fill(char(&game_area)[row_max + 2][col_max + 2], int row, int col, char judgement[][col_max + 2]);
void turn_to_zero(char(&game_area)[row_max + 2][col_max + 2], int row, int col, char(&judgement)[row_max + 2][col_max + 2]);
void drop(char(&game_area)[row_max + 2][col_max + 2], int row, int col, char(&judgement)[row_max + 2][col_max + 2], char choice);
int find(char game_area[][col_max + 2], int row, int col, char(&judgement)[row_max + 2][col_max + 2]);
void game_play(int row, int col, char choice, char(&game_area)[row_max + 2][col_max + 2], char(&judgement)[row_max + 2][col_max + 2]);

//graph.cpp中的函数声明
void draw(char(&game_area)[row_max + 2][col_max + 2], int row, int col, char choice, char(&judgement)[row_max + 2][col_max + 2]);
void draw_drop(char(&game_area)[row_max + 2][col_max + 2], int row, int col, char(&judgement)[row_max + 2][col_max + 2], int zero_num);
void boom(char(&game_area)[row_max + 2][col_max + 2], int row, int col, char(&judgement)[row_max + 2][col_max + 2], int& score, int mode);
void draw_new_ball(char(&game_area)[row_max + 2][col_max + 2], int row, int col, char(&judgement)[row_max + 2][col_max + 2], int mode);

//tool.cpp中的函数声明
void end();
void wait_for_enter();
void magic_ball_cout(int row, int mode);
void change_color();
void turn_back_color();
void format(char(&array)[11][11]);
void delay(int speed);
void mouse(char(&game_area)[row_max + 2][col_max + 2], int row, int col, char(&judgement)[row_max + 2][col_max + 2], char choice, int& num1, int& num2);
int boundary(char(&game_area)[row_max + 2][col_max + 2], int row, int col, int my_x, int my_y, int which_mode, char(&judgement)[row_max + 2][col_max + 2], int& num1, int& num2);
void change(char(&game_area)[row_max + 2][col_max + 2], int row, int col, int my_x, int my_y, char(&judgement)[row_max + 2][col_max + 2], int& num1, int& num2);
void legality(char(&game_area)[row_max + 2][col_max + 2], int row, int col, int my_x, int my_y, char(&judgement)[row_max + 2][col_max + 2]);