/*2351131 信04 韦世贸*/
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;
/* ----------------------------------------------------------------------------------

     本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

static int speed;//移动速度
static int jishu = 0;/*计数*/
static int top[3] = { 0 };//一维数组
static int zhu[3][10] = { 0 };//圆盘二维数组
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
     函数名称：chushihua
     功    能：在特定选项初始化数组和盘子
     输入参数：
     返 回 值：
     说    明：
***************************************************************************/
void chushihua(int n, char src,int choice)//对数组进行初始化
{
    int i;//数组变量
    if (src == 'A') {
        top[0] = n;
        for (i = 0; i <= top[0] && n > 0; i++) {

            zhu[0][i] = n;

            n--;
        }
    }

    if (src == 'B') {
        top[1] = n;
        for (i = 0; i <= top[1] && n > 0; i++) {

            zhu[1][i] = n;

            n--;
        }
    }
    if (src == 'C') {
        top[2] = n;
        for (i = 0; i <= top[2] && n > 0; i++) {

            zhu[2][i] = n;

            n--;
        }
    }

    //初始打印  
    if (choice == '4' || choice == '8' || choice == '9') {
        if (choice == '4')
            cct_gotoxy(STEPX, STEPY);
        else if (choice == '8' || choice == '9')
            cct_gotoxy(STEPX, STEPY8);
        cout << "初始:                 ";

        cout << "A:";

        for (i = 0; i < 10; i++) {
            if (zhu[0][i]) {
                cout << " " << zhu[0][i];
            }
            else {
                cout << "  ";
            }
        }

        cout << "B:";

        for (i = 0; i < 10; i++) {
            if (zhu[1][i])
                cout << " " << zhu[1][i];
            else
                cout << "  ";
        }

        cout << "C:";

        for (i = 0; i < 10; i++) {
            if (zhu[2][i])
                cout << " " << zhu[2][i];
            else
                cout << "  ";
        }

        if (choice != '9')
            delay(speed);

        for (i = 9; i >= 0; i--) {
            if (choice == '4')
                cct_gotoxy(A, Y - i + 9);
            else if (choice == '8' || choice == '9')
                cct_gotoxy(A, Y8 - i + 9);

            if (zhu[0][i]) {
                cout << zhu[0][i];
            }
            else {
                cout << "  ";
            }

            if (choice == '4')
                cct_gotoxy(B, Y - i + 9);
            else if (choice == '8' || choice == '9')
                cct_gotoxy(B, Y8 - i + 9);
            if (zhu[1][i]) {
                cout << zhu[1][i];
            }
            else {
                cout << "  ";
            }

            if (choice == '4')
                cct_gotoxy(C, Y - i + 9);
            else if (choice == '8' || choice == '9')
                cct_gotoxy(C, Y8 - i + 9);
            if (zhu[2][i]) {
                cout << zhu[2][i];
            }
            else {
                cout << "  ";
            }
            cout << endl;
        }
        if (choice == '4') {
            cct_gotoxy(15, Y + 10);
            cout << "=========================" << endl;
            cct_gotoxy(15, Y + 11);
            cout << "  A         B         C" << endl;
        }
        else if (choice == '8' || choice == '9') {
            cct_gotoxy(15, Y8 + 10);
            cout << "=========================" << endl;
            cct_gotoxy(15, Y8 + 11);
            cout << "  A         B         C" << endl;
        }

        if (src == 'A') {
            if (choice == '4')
                cct_gotoxy(A + 1, Y + 10 - top[0]);
            else if (choice == '8' || choice == '9')
                cct_gotoxy(A + 1, Y8 + 10 - top[0]);
        }
        else if (src == 'B'){
            if (choice == '4')
                cct_gotoxy(B + 1, Y + 10 - top[1]);
            else if (choice == '8' || choice == '9')
                cct_gotoxy(B + 1, Y8 + 10 - top[1]);
        }
        else if (src == 'C'){
            if (choice == '4')
                cct_gotoxy(C + 1, Y + 10 - top[2]);
            else if (choice == '8' || choice == '9')
                cct_gotoxy(C + 1, Y8 + 10 - top[2]);
        }
        if (choice != '9')
            delay(speed);
    }
}

/***************************************************************************
     函数名称：print
     功    能：打印盘子和内部数组
     输入参数：
     返 回 值：
     说    明：
***************************************************************************/
void print(char src, char dst,int choice)
{
    int i;//数组循环打印需要的变量

    if (src == 'A') {
        if (dst == 'B') {
            zhu[1][top[1]++] = zhu[0][--top[0]];
        }
        else if (dst == 'C') {
            zhu[2][top[2]++] = zhu[0][--top[0]];
        }
    }
    if (src == 'B') {       
        if (dst == 'A') {
            zhu[0][top[0]++] = zhu[1][--top[1]];
        }
        else if (dst == 'C') {
            zhu[2][top[2]++] = zhu[1][--top[1]];
        }
    }
    if (src == 'C') {
        if (dst == 'A') {
            zhu[0][top[0]++] = zhu[2][--top[2]];
        }
        else if (dst == 'B') {
            zhu[1][top[1]++] = zhu[2][--top[2]];
        }
    }


    //以下是打印部分
    if (choice == '4'|| choice == '8' || choice == '9') {
        for (i = 9; i >= 0; i--) {
            if (choice == '4')
                cct_gotoxy(A, Y - i + 9);
            else if (choice == '8' || choice == '9')
                cct_gotoxy(A, Y8 - i + 9);
            if (i > top[0] - 1) {
                cout << "  ";
            }
            else {
                cout << zhu[0][i];
            }

            if (choice == '4')
                cct_gotoxy(B, Y - i + 9);
            else if (choice == '8' || choice == '9')
                cct_gotoxy(B, Y8 - i + 9);
            if (i > top[1] - 1) {
                cout << "  ";
            }
            else {
                cout  << zhu[1][i];
            }

            if (choice == '4')
                cct_gotoxy(C, Y - i + 9);
            else if (choice == '8' || choice == '9')
                cct_gotoxy(C, Y8 - i + 9);
            if (i > top[2] - 1) {
                cout << "  ";
            }
            else {
                cout << zhu[2][i];
            }
            cout << endl;
        }

        if (choice == '4') {
            cct_gotoxy(15, Y + 10);
            cout << "=========================" << endl;
            cct_gotoxy(15, Y + 11);
            cout << "  A         B         C" << endl;
        }
        else if (choice == '8' || choice == '9') {
            cct_gotoxy(15, Y8 + 10);
            cout << "=========================" << endl;
            cct_gotoxy(15, Y8 + 11);
            cout << "  A         B         C" << endl;
        }

        if (src == 'A') {
            if (choice == '4')
                cct_gotoxy(A + 1, Y + 10 - top[0]);
            else if (choice == '8' || choice == '9')
                cct_gotoxy(A + 1, Y8 + 10 - top[0]);
        }
        else if (src == 'B') {
            if (choice == '4')
                cct_gotoxy(B + 1, Y + 10 - top[1]);
            else if (choice == '8' || choice == '9')
                cct_gotoxy(B + 1, Y8 + 10 - top[1]);
        }
        else if (src == 'C') {
            if (choice == '4')
                cct_gotoxy(C + 1, Y + 10 - top[2]);
            else if (choice == '8' || choice == '9')
                cct_gotoxy(C + 1, Y8 + 10 - top[2]);
        }

        if (choice != '9')
            delay(speed);

        if (choice == '4')
            cct_gotoxy(STEPX, STEPY);
        else if (choice == '8' || choice == '9')
            cct_gotoxy(STEPX, STEPY8);
    }

    if (choice != '7') {
        if (choice == '4')
            cct_gotoxy(STEPX + 22, STEPY);
        else if (choice == '8')
            cct_gotoxy(STEPX + 22, STEPY8);
        else if (choice == '9') {
            cct_gotoxy(STEPX, STEPY8);
            cout << "第" << setw(4) << ++jishu << " 步(";
            if(src=='A')
                cout << zhu[0][top[0]];
            else if (src == 'B')
                cout << zhu[1][top[1]];
            else if (src == 'C')
                cout << zhu[2][top[2]];
            cout<< "#: " << src << "-->" << dst << ") ";
        }
        cout << "A:";

        for (i = 0; i < 10; i++) {
            if (i < top[0]) {
                cout << " " << zhu[0][i];
            }
            else {
                cout << "  ";
            }
        }

        cout << "B:";

        for (i = 0; i < 10; i++) {
            if (i < top[1])
                cout << " " << zhu[1][i];
            else
                cout << "  ";
        }

        cout << "C:";

        for (i = 0; i < 10; i++) {
            if (i < top[2])
                cout << " " << zhu[2][i];
            else
                cout << "  ";
        }
        cout << endl;
    }
}

/***************************************************************************
     函数名称：hanoi_draw
     功    能：伪图形化画出三根圆柱
     输入参数：
     返 回 值：
     说    明：
***************************************************************************/
void hanoi_draw()
{
    cct_setcursor(CURSOR_INVISIBLE);
    int i;
   
    cct_showch(towerA, Y + 11, ch,  COLOR_HYELLOW, COLOR_WHITE, 23);
    cct_showch(towerB, Y + 11, ch,  COLOR_HYELLOW, COLOR_WHITE, 23);
    cct_showch(towerC, Y + 11, ch,  COLOR_HYELLOW, COLOR_WHITE, 23);

    for (i = 0; i < 12; i++) {
        cct_showch(towerAplacex, Y + i - 1, ch, COLOR_HYELLOW, COLOR_WHITE, 1);
        cct_showch(towerBplacex, Y + i - 1, ch, COLOR_HYELLOW, COLOR_WHITE, 1);
        cct_showch(towerCplacex, Y + i - 1, ch, COLOR_HYELLOW, COLOR_WHITE, 1);
        Sleep(100);
    }

    cct_setcolor(COLOR_BLACK, COLOR_WHITE);  //恢复到正常颜色
    cct_gotoxy(STEPX + 20, STEPY+20);
    cct_setcursor(CURSOR_VISIBLE_NORMAL);
}
/***************************************************************************
     函数名称：hanoi_draw_place
     功    能：画出柱子上的盘子
     输入参数：
     返 回 值：
     说    明：
***************************************************************************/
void hanoi_draw_place(int n,char src,int choice)
{
    cct_setcursor(CURSOR_INVISIBLE);
    int i;
    for (i = 0; i < n; i++) {
        switch (src) {
            case 'A':
                cct_showch(towerAplacex - (2 * (n - i) + 1) / 2, towerbase - i, ch, n - i, COLOR_WHITE, 2 * (n - i) + 1);
                break;

            case 'B':
                cct_showch(towerBplacex - (2 * (n - i) + 1) / 2, towerbase - i, ch, n - i, COLOR_WHITE, 2 * (n - i) + 1);
                break;

            case 'C':
                cct_showch(towerCplacex - (2 * (n - i) + 1) / 2, towerbase - i, ch, n - i, COLOR_WHITE, 2 * (n - i) + 1);
                break;
        }
        Sleep(100);
    }

    cct_setcolor(COLOR_BLACK, COLOR_WHITE);  //恢复到正常颜色
    cct_setcursor(CURSOR_VISIBLE_NORMAL);
    if (choice == '6') {
        cct_gotoxy(STEPX + 20, STEPY + 20);
    }
}
/***************************************************************************
     函数名称：hanoi_move_place
     功    能：图形化移动盘子
     输入参数：
     返 回 值：
     说    明：
***************************************************************************/
void hanoi_move_place(char src, char dst, int choice,int jishu)
{
    int x, y;
    cct_setcursor(CURSOR_INVISIBLE);

    if (choice == '7' && jishu != 1) {
        cct_gotoxy(STEPX + 20, STEPY + 20);
        return;
    }

    if (src == 'A') {
        for (y = towerbase- top[0]; y >= towertoptop; y--) {
            cct_showch(towerAplacex - (2 * zhu[0][top[0]] + 1) / 2, y, ch, zhu[0][top[0]], COLOR_WHITE, 2 * zhu[0][top[0]] + 1);

            Sleep(50);

            if (y >= towertoptop + 2) {
                cct_showch(towerAplacex - (2 * zhu[0][top[0]] + 1) / 2, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[0][top[0]] + 1) / 2);
                cct_showch(towerAplacex , y, ch, COLOR_HYELLOW, COLOR_WHITE, 1);
                cct_showch(towerAplacex + 1, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[0][top[0]] + 1) / 2);
            }
            else if(y >= towertoptop)
                cct_showch(towerAplacex - (2 * zhu[0][top[0]] + 1) / 2, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[0][top[0]] + 1));
        }
        if (dst == 'B') {
            for (x = towerAplacex; x <= towerBplacex - (2 * zhu[0][top[0]] + 1); x++) {
                cct_showch(x, y, ch, zhu[0][top[0]], COLOR_WHITE, 2 * zhu[0][top[0]] + 1);
                Sleep(50);
                if (x <= towerBplacex - (2 * zhu[0][top[0]] + 1)) {
                    cct_showch(x, y, ch, COLOR_BLACK, COLOR_WHITE, 2 * zhu[0][top[0]] + 1);
                }
            }
            for (y = towertoptop; y <= towerbase - top[1] + 1; y++) {
                cct_showch(towerBplacex - (2 * zhu[0][top[0]] + 1) / 2, y, ch, zhu[0][top[0]], COLOR_WHITE, 2 * zhu[0][top[0]] + 1);

                Sleep(50);

                if (y < towerbase - top[1] + 1 && y > towertoptop + 1) {
                    cct_showch(towerBplacex - (2 * zhu[0][top[0]] + 1) / 2, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[0][top[0]] + 1) / 2);
                    cct_showch(towerBplacex, y, ch, COLOR_HYELLOW, COLOR_WHITE, 1);
                    cct_showch(towerBplacex + 1, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[0][top[0]] + 1) / 2);
                }
                else if (y <= towertoptop + 1)
                    cct_showch(towerBplacex - (2 * zhu[0][top[0]] + 1) / 2, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[0][top[0]] + 1));
            }
            
        }
        else if (dst == 'C') {
            for (x = towerAplacex; x <= towerCplacex - (2 * zhu[0][top[0]] + 1); x++) {
                cct_showch(x, y, ch, zhu[0][top[0]], COLOR_WHITE, 2 * zhu[0][top[0]] + 1);
                Sleep(50);
                if (x <= towerCplacex - (2 * zhu[0][top[0]] + 1)) {
                    cct_showch(x, y, ch, COLOR_BLACK, COLOR_WHITE, 2 * zhu[0][top[0]] + 1);
                }
            }
            for (y = towertoptop; y <= towerbase - top[2] + 1; y++) {
                cct_showch(towerCplacex - (2 * zhu[0][top[0]] + 1) / 2, y, ch, zhu[0][top[0]], COLOR_WHITE, 2 * zhu[0][top[0]] + 1);

                Sleep(50);

                if (y < towerbase - top[2] + 1 && y > towertoptop + 1) {
                    cct_showch(towerCplacex - (2 * zhu[0][top[0]] + 1) / 2, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[0][top[0]] + 1) / 2);
                    cct_showch(towerCplacex, y, ch, COLOR_HYELLOW, COLOR_WHITE, 1);
                    cct_showch(towerCplacex + 1, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[0][top[0]] + 1) / 2);
                }
                else if (y <= towertoptop + 1)
                    cct_showch(towerCplacex - (2 * zhu[0][top[0]] + 1) / 2, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[0][top[0]] + 1));
            }
        }
    }

    if (src == 'B') {
        for (y = towerbase - top[1]; y >= towertoptop; y--) {
            cct_showch(towerBplacex - (2 * zhu[1][top[1]] + 1) / 2, y, ch, zhu[1][top[1]], COLOR_WHITE, 2 * zhu[1][top[1]] + 1);

            Sleep(50);

            if (y >= towertoptop + 2) {
                cct_showch(towerBplacex - (2 * zhu[1][top[1]] + 1) / 2, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[1][top[1]] + 1) / 2);
                cct_showch(towerBplacex, y, ch, COLOR_HYELLOW, COLOR_WHITE, 1);
                cct_showch(towerBplacex + 1, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[1][top[1]] + 1) / 2);
            }
            else if (y >= towertoptop)
                cct_showch(towerBplacex - (2 * zhu[1][top[1]] + 1) / 2, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[1][top[1]] + 1));
        }
        if (dst == 'A') {
            for (x = towerBplacex; x >= towerAplacex - (2 * zhu[1][top[1]] + 1); x--) {
                cct_showch(x, y, ch, zhu[1][top[1]], COLOR_WHITE, 2 * zhu[1][top[1]] + 1);
                Sleep(50);
                if (x >= towerAplacex - (2 * zhu[1][top[1]] + 1)) {
                    cct_showch(x, y, ch, COLOR_BLACK, COLOR_WHITE, 2 * zhu[1][top[1]] + 1);
                }
            }
            for (y = towertoptop; y <= towerbase - top[0] + 1; y++) {
                cct_showch(towerAplacex - (2 * zhu[1][top[1]] + 1) / 2, y, ch, zhu[1][top[1]], COLOR_WHITE, 2 * zhu[1][top[1]] + 1);

                Sleep(50);

                if (y < towerbase - top[0] + 1 && y > towertoptop + 1) {
                    cct_showch(towerAplacex - (2 * zhu[1][top[1]] + 1) / 2, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[1][top[1]] + 1) / 2);
                    cct_showch(towerAplacex, y, ch, COLOR_HYELLOW, COLOR_WHITE, 1);
                    cct_showch(towerAplacex + 1, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[1][top[1]] + 1) / 2);
                }
                else if (y <= towertoptop + 1)
                    cct_showch(towerAplacex - (2 * zhu[1][top[1]] + 1) / 2, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[1][top[1]] + 1));
            }
        }
        else if (dst == 'C') {
            for (x = towerBplacex; x <= towerCplacex - (2 * zhu[1][top[1]] + 1); x++) {
                cct_showch(x, y, ch, zhu[1][top[1]], COLOR_WHITE, 2 * zhu[1][top[1]] + 1);
                Sleep(50);
                if (x <= towerCplacex - (2 * zhu[1][top[1]] + 1)) {
                    cct_showch(x, y, ch, COLOR_BLACK, COLOR_WHITE, 2 * zhu[1][top[1]] + 1);
                }
            }
            for (y = towertoptop; y <= towerbase - top[2] + 1; y++) {
                cct_showch(towerCplacex - (2 * zhu[1][top[1]] + 1) / 2, y, ch, zhu[1][top[1]], COLOR_WHITE, 2 * zhu[1][top[1]] + 1);

                Sleep(50);

                if (y < towerbase - top[2] + 1 && y > towertoptop + 1) {
                    cct_showch(towerCplacex - (2 * zhu[1][top[1]] + 1) / 2, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[1][top[1]] + 1) / 2);
                    cct_showch(towerCplacex, y, ch, COLOR_HYELLOW, COLOR_WHITE, 1);
                    cct_showch(towerCplacex + 1, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[1][top[1]] + 1) / 2);
                }
                else if (y <= towertoptop + 1)
                    cct_showch(towerCplacex - (2 * zhu[1][top[1]] + 1) / 2, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[1][top[1]] + 1));
            }
        }
    }

    if (src == 'C') {
        for (y = towerbase - top[2]; y >= towertoptop; y--) {
            cct_showch(towerCplacex - (2 * zhu[2][top[2]] + 1) / 2, y, ch, zhu[2][top[2]], COLOR_WHITE, 2 * zhu[2][top[2]] + 1);

            Sleep(50);

            if (y >= towertoptop + 2) {
                cct_showch(towerCplacex - (2 * zhu[2][top[2]] + 1) / 2, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[2][top[2]] + 1) / 2);
                cct_showch(towerCplacex, y, ch, COLOR_HYELLOW, COLOR_WHITE, 1);
                cct_showch(towerCplacex + 1, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[2][top[2]] + 1) / 2);
            }
            else if (y >= towertoptop)
                cct_showch(towerCplacex - (2 * zhu[2][top[2]] + 1) / 2, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[2][top[2]] + 1));
        }
        if (dst == 'A') {
            for (x = towerCplacex; x >= towerAplacex - (2 * zhu[2][top[2]] + 1); x--) {
                cct_showch(x, y, ch, zhu[2][top[2]], COLOR_WHITE, 2 * zhu[2][top[2]] + 1);
                Sleep(50);
                if (x >= towerAplacex - (2 * zhu[2][top[2]] + 1)) {
                    cct_showch(x, y, ch, COLOR_BLACK, COLOR_WHITE, 2 * zhu[2][top[2]] + 1);
                }
            }
            for (y = towertoptop; y <= towerbase - top[0] + 1; y++) {
                cct_showch(towerAplacex - (2 * zhu[2][top[2]] + 1) / 2, y, ch, zhu[2][top[2]], COLOR_WHITE, 2 * zhu[2][top[2]] + 1);

                Sleep(50);

                if (y < towerbase - top[0] + 1 && y > towertoptop + 1) {
                    cct_showch(towerAplacex - (2 * zhu[2][top[2]] + 1) / 2, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[2][top[2]] + 1) / 2);
                    cct_showch(towerAplacex, y, ch, COLOR_HYELLOW, COLOR_WHITE, 1);
                    cct_showch(towerAplacex + 1, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[2][top[2]] + 1) / 2);
                }
                else if (y <= towertoptop + 1)
                    cct_showch(towerAplacex - (2 * zhu[2][top[2]] + 1) / 2, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[2][top[2]] + 1));
            }
        }
        else if (dst == 'B') {
            for (x = towerCplacex; x >= towerBplacex - (2 * zhu[2][top[2]] + 1); x--) {
                cct_showch(x, y, ch, zhu[2][top[2]], COLOR_WHITE, 2 * zhu[2][top[2]] + 1);
                Sleep(50);
                if (x >= towerBplacex - (2 * zhu[2][top[2]] + 1)) {
                    cct_showch(x, y, ch, COLOR_BLACK, COLOR_WHITE, 2 * zhu[2][top[2]] + 1);
                }
            }
            for (y = towertoptop; y <= towerbase - top[1] + 1; y++) {
                cct_showch(towerBplacex - (2 * zhu[2][top[2]] + 1) / 2, y, ch, zhu[2][top[2]], COLOR_WHITE, 2 * zhu[2][top[2]] + 1);

                Sleep(50);

                if (y < towerbase - top[1] + 1 && y > towertoptop + 1) {
                    cct_showch(towerBplacex - (2 * zhu[2][top[2]] + 1) / 2, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[2][top[2]] + 1) / 2);
                    cct_showch(towerBplacex, y, ch, COLOR_HYELLOW, COLOR_WHITE, 1);
                    cct_showch(towerBplacex + 1, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[2][top[2]] + 1) / 2);
                }
                else if (y <= towertoptop + 1)
                    cct_showch(towerBplacex - (2 * zhu[2][top[2]] + 1) / 2, y, ch, COLOR_BLACK, COLOR_WHITE, (2 * zhu[2][top[2]] + 1));
            }
        }
    }

    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
    cct_setcursor(CURSOR_VISIBLE_NORMAL);
}

/***************************************************************************
     函数名称：game_set
     功    能：判断移动是否合法
     输入参数：
     返 回 值：
     说    明：
***************************************************************************/
int game_set(char src,char dst)
{
    if (src == 'A') {
        if (zhu[0][top[0]-1] == 0) {
            cout << "源柱为空！" << endl;
            
            return -1;
        }
        if (dst == 'B'&& zhu[1][top[1]] < zhu[0][top[0]] && zhu[1][top[1]]) {
            cout << "大盘压小盘，非法移动！" << endl;
            
            return -1;
        }
        else if (dst == 'C' && zhu[2][top[2]] < zhu[0][top[0]] && zhu[2][top[2]]) {
            cout << "大盘压小盘，非法移动！" << endl;
           
            return -1;
        }
    }
    if (src == 'B') {
        if (zhu[1][top[1]-1] == 0) {
            cout << "源柱为空！" << endl;
        
            return -1;
        }
        if (dst == 'A' && zhu[0][top[0]] < zhu[1][top[1]]) {
            cout << "大盘压小盘，非法移动！" << endl;
            
            return -1;
        }
        else if (dst == 'C' && zhu[2][top[2]] < zhu[1][top[1]]) {
            cout << "大盘压小盘，非法移动！" << endl;
            
            return -1;
        }
    }
    if (src == 'C') {
        if (zhu[2][top[2]-1] == 0) {
            cout << "源柱为空！" << endl;
            return -1;
        }
        if (dst == 'A' && zhu[0][top[0]] < zhu[2][top[2]]) {
            cout << "大盘压小盘，非法移动！" << endl;
            return -1;
        }
        else if (dst == 'B' && zhu[1][top[1]] < zhu[2][top[2]]) {
            cout << "大盘压小盘，非法移动！" << endl;
            return -1;
        }
    }
    return 0;
}
/***************************************************************************
     函数名称：game_play
     功    能：根据键盘写入进行盘子移动
     输入参数：
     返 回 值：
     说    明：
***************************************************************************/
void game_play(int n,char src)
{
    char start, end;
    int right, x, y, i;
    int jieshu = 0;
    cct_getxy(x, y);
    cct_gotoxy(x, y);
    
    while (1) {
        switch (src) {
            case 'A':
                if (top[0] == n) {
                    jieshu = 1;
                }
                break;

            case 'B':
                if (top[1] == n) {
                    jieshu = 1;
                }
                break;

            case 'C':
                if (top[2] == n) {
                    jieshu = 1;
                }
                break;
        }
        if (jieshu == 1)
            break;

        cin >> start;

        if (start == 'Q' || start == 'q') {
            cout << "游戏中止!!!!!" << endl;
            break;
        }

        cin >> end;
       
        if (start == 'a' || start == 'c' || start == 'b') {
            start -= 32;
        }
        if (end == 'a' || end == 'c' || end == 'b') {
            end -= 32;
        }
        if (start == end) {
            cin.clear();
            cin.ignore(114514, '\n');
            cct_showch(x, y, ch, COLOR_BLACK, COLOR_WHITE, 2);
            cct_gotoxy(x, y);
            continue;
        }

       
        if ((start == 'B' || start == 'A' || start == 'C') && (end == 'B' || end == 'A' || end == 'C')) {
            right = game_set(start, end);
            if (right != 0) {
                Sleep(100);
                cct_showch(x, y, ch, COLOR_BLACK, COLOR_WHITE, 2);
                for (i = 1; i < 10; i++) {
                    cct_showch(0, y + i, ch, COLOR_BLACK, COLOR_WHITE, 55);
                }
                cct_gotoxy(x, y);
                continue;
            }
            else {
                print(start, end, '9');
                hanoi_move_place(start, end, '9', jishu);
                Sleep(50);
                cct_showch(x, y, ch, COLOR_BLACK, COLOR_WHITE, 2);
                for (i = 1; i < 10; i++) {
                    cct_showch(0, y + i, ch, COLOR_BLACK, COLOR_WHITE, 55);
                }
                cct_gotoxy(x, y);
            }
        }
    }
    cct_gotoxy(STEPX, STEPY8 + 3);
    cout << "游戏结束!!!!!" << endl;
    
}
/***************************************************************************
     函数名称：gamestart_end
     功    能：进行游戏初始化
     输入参数：
     返 回 值：
     说    明：
***************************************************************************/
void gamestart_end(int n,char src)
{
    cct_gotoxy(STEPX, STEPY8 + 2);
    cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";
    game_play(n,src);
    
}
/***************************************************************************
     函数名称：hanoi_cout
     功    能：打印步数,缩短递归函数的行数
     输入参数：
     返 回 值：
     说    明：
***************************************************************************/
void hanoi_cout(int n, char src, char tmp, char dst, int choice)
{
    if (choice != '1') {
        if (choice == '4')
            cct_gotoxy(STEPX, STEPY);
        else if (choice == '8' || choice == '9')
            cct_gotoxy(STEPX, STEPY8);
        if (choice != '7')
            cout << "第" << setw(4) << ++jishu << " 步(" << n << "#: " << src << "-->" << dst << ") ";
        else
            ++jishu;
        if (choice == '2')
            cout << endl;
        if (choice == '3' || choice == '4' || choice == '7' || choice == '8') {
            print(src, dst, choice);
            if (choice == '7' || choice == '8')
                hanoi_move_place(src, dst, choice,jishu);
        }
    }
    else
        cout << setw(2) << n << "#" << " " << src << "-->" << dst << endl;/*格式*/
}

/***************************************************************************
     函数名称：hanoi
     功    能：完成基本的汉诺塔移动
     输入参数：
     返 回 值：
     说    明：
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst,int choice)
{
    if (n == 1) {/*特殊情况*/
        hanoi_cout(n, src, tmp, dst, choice);
    }

    else {/*开始递归*/
        hanoi(n - 1, src, dst, tmp, choice);
        hanoi_cout(n, src, tmp, dst, choice);
        hanoi(n - 1, tmp, src, dst, choice);
    }

}
/***************************************************************************
  函数名称：turn_to_zero
  功    能：将静态全局变量归0，保证该程序能够多次运行
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void turn_to_zero()
{
    int i, j = 0;
    jishu = 0;
    for (i = 0; i < 3; i++)
        top[i] = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 10; j++)
            zhu[i][j] = 0;
    }
}
/***************************************************************************
	 函数名称：hanoi_cin
	 功    能：根据选项调用函数,并完成1-4项功能
	 输入参数：选项
	 返 回 值：
	 说    明：
***************************************************************************/
int hanoi_cin(int choice)
{
    if (choice == '5') {
        cct_cls();
        hanoi_draw();
        return 0;
    }

    int ceng;/*层数*/
    char qishi, mubiao;/*定义三个柱*/
    while (1) {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> ceng;   //读入ceng的方式必须是 cin>>int型变量
        if (cin.fail()) {
            cin.clear();
            cin.ignore(114514, '\n');
            continue;
        }
        if (ceng >= 0 && ceng <= 10) {
            break;
        }
    }
    cin.ignore(114514, '\n');
    while (1) {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> qishi;   //读入qishi的方式为字符

        if (cin.fail()) {
            cin.clear();
            cin.ignore(114514, '\n');
            continue;
        }

        if (qishi == 'a' || qishi == 'b' || qishi == 'c') {/*大写转换*/
            qishi -= 32;
            break;
        }

        if (qishi == 'B' || qishi == 'A' || qishi == 'C') {

            break;
        }
        cin.ignore(114514, '\n');
    }
    cin.ignore(114514, '\n');

    while (1) {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> mubiao;  //读入mubiao的方式为字符
        if (cin.fail()) {
            cin.clear();
            cin.ignore(114514, '\n');
            continue;
        }

        if (mubiao == 'a' || mubiao == 'c' || mubiao == 'b') {
            mubiao -= 32;  /*这里不能退出循环，因为后面还有一个相等特判*/

        }

        if (mubiao == qishi) { /*输入重复的情况*/
            cout << "目标柱(" << mubiao << ")不能与起始柱(" << qishi << ")相同" << endl;

            continue;
        }


        if (mubiao == 'B' || mubiao == 'A' || mubiao == 'C') {
            break;
        }
        cin.ignore(114514, '\n');
    }

    char zhongjian;
    zhongjian = 'A' + 'B' + 'C' - qishi - mubiao;/*这样求中间柱就比较简单*/

    if (choice == '4'|| choice == '6' || choice == '7' || choice == '8' || choice == '9') {
        if (choice == '4' || choice == '8') {
            while (1) {
                cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)";
                cin >> speed;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(114514, '\n');
                    continue;
                }
                if (speed >= 0 && speed <= 5) {
                    break;
                }
            }
        }

        cct_cls();

        cout << "从 " << qishi << " 移动到 " << mubiao << "，共 " << ceng << " 层";

        if (choice == '4'|| choice == '8')
            cout << "，延时设置为 " << speed << endl;
        if (choice == '6') {
            hanoi_draw();
            hanoi_draw_place(ceng, qishi,choice);
            chushihua(ceng, qishi, choice);
            return 0;
        }
    }

    if (choice == '3' || choice == '4'|| choice == '7' || choice == '8'|| choice == '9')
        chushihua(ceng, qishi, choice);
    if (choice == '7' || choice == '8' || choice == '9') {
        hanoi_draw();
        hanoi_draw_place(ceng, qishi, choice);
    }

    if (choice != '9') {
        hanoi(ceng, qishi, zhongjian, mubiao, choice);
    }
    else 
        gamestart_end(ceng,mubiao);

    turn_to_zero();

    if (choice == '8' || choice == '9')
        cct_gotoxy(STEPX + 20, STEPY + 20);

    return 0 ;
}
/***************************************************************************
  函数名称：hanoi_multiple_solutions
  功    能：根据选项调用函数
  输入参数：选项
  返 回 值：
  说    明：
***************************************************************************/
void hanoi_multiple_solutions(int choice)
{
    cout << endl;
    cout << endl;
    
    hanoi_cin(choice);
}