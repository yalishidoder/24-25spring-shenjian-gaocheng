/*2351131 信04 韦世贸*/
#pragma once

/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */

   //定义一些光标会移动到的位置
const int A = 17;  //三个柱的横坐标
const int B = 27;
const int C = 37;
const int STEPX = 20;
const int STEPY = 20;
const int STEPY8 = STEPY + 15;
const int Y = A - 10;
const int Y8 = Y + 15;
const int towerA = 1;
const int towerB = 33;
const int towerC = 65;
const int towerAplacex = towerA + 11;
const int towerBplacex = towerB + 11;
const int towerCplacex = towerC + 11;
const int towerbase = Y + 10;
const int towertoptop = Y - 3;

//图形化字符
const char ch = ' ';

   /* hanoi_menu.cpp下的函数声明 */

  /*  hanoi_menu() 即菜单函数   */
int hanoi_menu();

  /*hanoi_multiple_solutions.cpp下的函数声明*/

void hanoi_multiple_solutions(int choice);