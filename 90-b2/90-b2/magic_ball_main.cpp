/*2351131 信04 韦世贸*/
#include <iostream>
#include <conio.h>
#include "cmd_console_tools.h"
#include "magic_ball.h"
using namespace std;

int main()
{
	while (1) {
		cct_cls();
		/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
		cct_setconsoleborder(120, 30, 120, 9000);
		cct_setfontsize("新宋体", 16);
		char choice = magic_ball_menu();

		if (choice == '0')
			break;
		else {
			cct_cls();
			magic_ball_cin(choice);
		}
	}

	return 0;
}
