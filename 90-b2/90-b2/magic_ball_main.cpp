/*2351131 ��04 Τ��ó*/
#include <iostream>
#include <conio.h>
#include "cmd_console_tools.h"
#include "magic_ball.h"
using namespace std;

int main()
{
	while (1) {
		cct_cls();
		/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
		cct_setconsoleborder(120, 30, 120, 9000);
		cct_setfontsize("������", 16);
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
