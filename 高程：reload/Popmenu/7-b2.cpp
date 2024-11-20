/* 学号 班级 姓名*/

/* 1、按需加入头文件
   2、不允许定义全局变量，包括静态全局，但不限制const及define
   3、允许定义需要的结构体、函数等，但仅限本源程序文件使用 */

#include "cmd_console_tools.h"
#include "7-b2.h"
#include <iostream>
#include <conio.h>
#include <cstring>
#include <iomanip>
using namespace std;

/* 例：声明仅本源程序文件需要的结构体，不要放到.h中
       仅为示例，不需要可删除 */
struct origin {                    //存放菜单的初始值
		//菜单宽度，不含左右边框（+4是显示的实际列数），必须是偶数
	const int high = 10;		//菜单高度，不含上下边框（+2是显示的实际行数），
};

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：定义仅本源程序文件需要的函数，设置为static即可
***************************************************************************/
static void check(int &title,int &menu, int &right)          //确保标题长度和菜单长度都为偶数
{
	if (title % 2)
		title++;

	if (menu <= title)
		menu = title;

	if ((menu - title) % 4)
		right = 1;
	else
		right = 0;
}

static void framework(const struct PopMenu* original_para, int max_sel, int right,int title)
{
	int i, j, k;
	cct_gotoxy((*original_para).start_x, (*original_para).start_y);

	cout << "╔";
	for (i = 0; i < ((*original_para).width- title)/4; i++)
		cout << "═";
	cout << (*original_para).title;
	cout << setw(title - strlen((*original_para).title)) << " ";
	for (i = 0; i < ((*original_para).width - title) / 4 + right; i++)
		cout << "═";
	cout << "╗";

	for (j = 0; j = max_sel; j++) {
		cout << "║";
	}
	for (i = 0; i < ((*original_para).width); i++)
		cout << "═";
}

static int fun(origin initial, const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
	int sel = 1, y = (*original_para).start_y + 1, MAX_Y = (*original_para).start_y +
		(initial.high < (*original_para).high ? initial.high : (*original_para).high), keyboard;

	while (1) {
		keyboard = _getch();
		if (keyboard == 27 || keyboard == '\r')
			break;
		else if (keyboard == 224) {
			int move = _getch();
			switch (move)
			{
				case 72:     //上箭头
					if (--y < (*original_para).start_y + 1)
						y = (*original_para).start_y + 1;
					if (--sel < 1)
						sel = 1;
					
					break;
				case 80:   //下箭头
					if (++y > MAX_Y)
						y = MAX_Y;
					if (++sel > 10)
						sel = 10;
					
					break;
				default:
					break;
			}
			if (y == (*original_para).start_y + 1 && sel > 1)
				;
			else if(y== (*original_para).start_y+ (*original_para).high && sel > (*original_para).high)
				;
		}
	}//仅为示例，不需要可删除
	if (keyboard == 27)
		return -1;
	else if (keyboard == '\r')
		return sel;
	else
		return 0;
}

/***************************************************************************
  函数名称：
  功    能：供测试用例调用的函数，函数声明在头文件中
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int pop_menu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
	struct origin initial;

	return fun(initial, menu,  original_para); //按需返回
}
