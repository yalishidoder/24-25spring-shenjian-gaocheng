/*2351131 信04 韦世贸*/
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "magic_ball.h"
using namespace std;

/***************************************************************************
  函数名称：tj_strcasecmp
  功    能：在每小题结束后检测输入的字符是否是“end”
  输入参数：
  返 回 值：0或字符ascll码差值
  说    明：
***************************************************************************/
int tj_strcasecmp(const char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char mid1, mid2;

    if (s1 != NULL && s2 != NULL) {
        for (; *s1 || *s2; s1++, s2++) {
            if (*s1 != *s2) {
                if (*s1 >= 'A' && *s1 <= 'Z')
                    mid1 = 32 + *s1;
                else
                    mid1 = *s1;
                if (*s2 >= 'A' && *s2 <= 'Z')
                    mid2 = 32 + *s2;
                else
                    mid2 = *s2;
                if (mid1 == mid2)
                    continue;
                else
                    return (mid1 - mid2);
            }
        }
    }
    else if (s1 == NULL && s2 != NULL)
        return -1;
    else if (s1 != NULL && s2 == NULL)
        return 1;
    return 0;
}

/***************************************************************************
  函数名称：wait_for_enter
  功    能：暂停程序，输入回车继续程序
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void wait_for_enter()
{
    while (_getch() != '\r')
        ;
}

/***************************************************************************
  函数名称：end
  功    能：结束每一小题
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void end() 
{
    char s1[25] = { 0 },*p;
    int x = 0, y = 0;
    cout << "本小题结束，请输入End继续...   ";
    cct_getxy(x, y);
    p = s1;

    while (1) {
        for(;*p;p++)
            *p = '0';
        cin >> s1;

        if (tj_strcasecmp(s1, "end") == 0)
            break;
        else {
            cout << "输入错误，请重新输入" << endl;
            cct_gotoxy(x, y);
            cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 25);
            cct_gotoxy(x, y);
        }
    }

}

/***************************************************************************
  函数名称：change_color
  功    能：找到可消除项后变色
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void change_color()
{
    cct_setcolor(COLOR_HYELLOW, COLOR_BLUE);
}

/***************************************************************************
  函数名称：magic_ball_cout
  功    能：负责输出一些提示
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void magic_ball_cout(int row, int mode)
{
    turn_back_color();
    int x, y;
    cct_getxy(x, y);
    if (mode <= 6) {
        cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 70);
        cct_gotoxy(x, y);
    }
    if (mode > 6) {
        cct_showch(0, 2 * (row + 1), ' ', COLOR_BLACK, COLOR_WHITE, 40);
        cct_gotoxy(0, 2 * (row + 1));
    }
    if (mode == 1) {
        cout << "按回车键进行寻找初始可消除项的操作...";
        wait_for_enter();
    }
    else if (mode == 2|| mode == 7) {
        cout << "按回车键进行数组下落除0操作..." << endl;
        wait_for_enter();
    }
    else if (mode == 3|| mode == 8) {
        cout << "按回车键进行新值填充..." << endl;
        wait_for_enter();
    }
    else if (mode == 4)
        cout << "下落除0后的数组(不同色标识)：" << endl;
    else if (mode == 5)
        cout << "新值填充后的数组(不同色标识)：" << endl;
    else if (mode == 6) {
        cout << endl;
        cout << "可选择的消除提示（不同色标识）：" << endl;
    }
    else if (mode == 9) {
        cout << "按回车键显示消除提示...";
        wait_for_enter();
    }

}
/***************************************************************************
  函数名称：turn_back_color
  功    能：颜色回退
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void turn_back_color()
{
    cct_setcolor();        //恢复颜色
}

/***************************************************************************
  函数名称：format
  功    能：将标记数组全部元素置0
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void format(char(&array)[11][11])
{
    int i, j;
    for (i = 0; i < 11; i++) {
        for (j = 0; j < 11; j++) {
            array[i][j] = '0';
        }
    }
}
/***************************************************************************
     函数名称：delay
     功    能：移动延时
     输入参数：
     返 回 值：
     说    明：
***************************************************************************/
void delay(int speed)
{
    if (speed == 0) {  //移动延时
        while (_getch() != '\r'); //按回车进行下一步
    }
    else if (speed == 1)
        Sleep(500);
    else if (speed == 2)
        Sleep(400);
    else if (speed == 3)
        Sleep(300);
    else if (speed == 4)
        Sleep(200);
    else if (speed == 5)
        Sleep(10);
}
/***************************************************************************
  函数名称：mouse
  功    能：使用鼠标
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void mouse(char(&game_area)[row_max + 2][col_max + 2], int row, int col, char(&judgement)[row_max + 2][col_max + 2], char choice,int &num1,int &num2)
{
	int X = 0, Y = 0;
    int ret1,maction1;
	int keycode1, keycode2;
    int loop1 = 1, loop2 = 0;

	cct_enable_mouse();

	cct_setcursor(CURSOR_INVISIBLE);	//关闭光标
	
	while (loop1) {
		/* 读鼠标/键盘，返回值为下述操作中的某一种, 当前鼠标位置在<X,Y>处 */
		ret1 = cct_read_keyboard_and_mouse(X, Y, maction1, keycode1, keycode2);

        if (!num1 && !num2)
            return;

		if (ret1 == CCT_MOUSE_EVENT) {
			switch (maction1) {
				case MOUSE_ONLY_MOVED:                  //鼠标移动
                    loop2 = boundary(game_area, row, col, X, Y, 1, judgement, num1, num2);
					break;
                
                case MOUSE_LEFT_BUTTON_CLICK:			//按下左键
                    loop2 = boundary(game_area, row, col, X, Y, 2, judgement, num1, num2);
                    if (choice == '8') {
                        loop2 = 0;
                        loop1 = 0;
                    }
                    break;
                case MOUSE_RIGHT_BUTTON_CLICK:			//按下右键
                    loop2 = 0;
                    loop1 = 0;
                    break;
			} //end of switch(maction)
		} //end of if (CCT_MOUSE_EVENT)
	} //end of while(1)

    cct_gotoxy(0, 2 * (row + 1));
    turn_back_color();
}
/***************************************************************************
  函数名称：boundary
  功    能：判断鼠标位置是否在合法区域内并打印合法光标位置
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int boundary(char(&game_area)[row_max + 2][col_max + 2],int row, int col,int my_x, int my_y, int which_mode, char(&judgement)[row_max + 2][col_max + 2], int& num1, int& num2)
{
    cct_gotoxy(0, 2 * (row + 1));
    turn_back_color();
    cout << "[当前光标] ";
    if ((my_x - 2) % 4 == 0 && (my_y - 2) % 2 == 0 && my_x <= 2 + 4 * (col-1) && my_y <=  2 * row) {
        switch (which_mode) {
            case 1:
                cout << char('A' + (my_y - 2) / 2 ) << "行" << 1 + (my_x - 2) / 4  << "列 ";
                return 1;
                break;
            case 2:
                cct_gotoxy(0, 2 * (row + 1));
                legality(game_area, row, col, my_x, my_y, judgement);
                num1 = search_row(game_area, row, col, judgement);
                num2 = search_col(game_area, row, col, judgement);
                game_play(row, col, '9', game_area, judgement);
                return 1;
                break;
        }

    }
    else
        cout << "位置非法";
    return 0;
}

/***************************************************************************
  函数名称：change
  功    能：判断选中的两球是否相邻，相邻则交换两个所选的彩球
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void change(char(&game_area)[row_max + 2][col_max + 2], int row, int col, int my_x, int my_y, char(&judgement)[row_max + 2][col_max + 2])
{
    int i = (my_y - 2) / 2 + 2;
    int j = (my_x - 2) / 4 + 2;
    int k, l;
    char mid = 0;

    for (k = 2; k < row + 2; k++) {
        for (l = 2; l < col + 2; l++) {
            if (judgement[k][l] == '2'&& judgement[i][j] == '1') {
                if ((k == i && l != j) || (k != i && l == j)) {  //相邻
                    mid = game_area[i][j];
                    game_area[i][j] = game_area[k][l];
                    game_area[k][l] = mid;
                    cct_gotoxy(2 + 4 * (j - 2), 2 + 2 * (i - 2));
                    cct_setcolor(game_area[i][j] - '0', COLOR_BLACK);
                    cout << "〇";
                    cct_gotoxy(2 + 4 * (l - 2), 2 + 2 * (k - 2));
                    cct_setcolor(game_area[k][l] - '0', COLOR_BLACK);
                    cout << "〇";
                }
                else {    //不相邻
                    cct_gotoxy(my_x, my_y);
                    cct_setcolor(game_area[i][j] - '0', COLOR_HWHITE);
                    cout << "◎";
                    judgement[k][l] = '1';
                    judgement[i][j] = '2';
                }
            }
        }
    }
}

/***************************************************************************
  函数名称：legality
  功    能：判断鼠标选中的位置是否为可用球
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void legality(char(&game_area)[row_max + 2][col_max + 2],  int row, int col,int my_x, int my_y, char(&judgement)[row_max + 2][col_max + 2])
{
    int i = (my_y - 2) / 2 + 2;
    int j = (my_x - 2) / 4 + 2;
    int k, l, sign_white = 0;

    for (k = 2; k < row + 2; k++) {
        for (l = 2; l < col + 2; l++) {
            if (judgement[k][l] == '2') {
                sign_white++;

            }
        }
    }

    cct_gotoxy(0, 2 * (row + 1));
    if (judgement[i][j] > '0') {        //只有提示可消除项能被标记
        cout << "当前选择";
        cct_gotoxy(my_x, my_y);
        if (judgement[i][j] == '1' && sign_white < 1) {   //设置选中状态
            cct_setcolor(game_area[i][j] - '0', COLOR_HWHITE);
            cout << "◎";
            judgement[i][j] = '2';
 
        }
        else if(judgement[i][j] == '1' && sign_white == 1)
            change(game_area, row, col, my_x, my_y, judgement);      //完整游戏可以交换
        else if (judgement[i][j] == '2') {
            cct_setcolor(game_area[i][j] - '0', COLOR_BLACK); //取消选中状态
            cout << "◎";
            judgement[i][j] = '1';
        }
        turn_back_color();
    }
    else
        cout << "不能选择";

    cct_gotoxy(10, 2 * (row + 1));
    cout<< char('A' + (my_y - 2) / 2) << "行" << 1 + (my_x - 2) / 4  << "列  ";
}
