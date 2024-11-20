/* 2351131 韦世贸 信04 */
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include "cmd_console_tools.h"
#include "7-b2.h"         
 

                                            //未完成所有功能
using namespace std;
/* 1、按需加入头文件
   2、不允许定义全局变量，包括静态全局，但不限制const及define
   3、允许定义需要的结构体、函数等，但仅限本源程序文件使用 */
const int MAX_ITEM = 10;
/* 例：声明仅本源程序文件需要的结构体，不要放到.h中
       仅为示例，不需要可删除 */
/*struct xxx
{
    ;
}*/

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：定义仅本源程序文件需要的函数，设置为static即可
***************************************************************************/
static int fun(const char menu[][MAX_ITEM_LEN],const struct PopMenu* original_para)
{
    const int top = (*original_para).start_y + 1;
    const int bottom = (*original_para).start_y + ((*original_para).high < MAX_ITEM ? (*original_para).high : MAX_ITEM);
    int x, y, i = 0, j = 0, k = 0;
    cct_gotoxy((*original_para).start_x + 2, (*original_para).start_y + 1);
    cct_getxy(x, y);

    int choose = y - top;

    while (1) {
        cct_setcolor((*original_para).fg_color, (*original_para).bg_color);
        int moveKey;
        int temp = _getch();

        if (temp == 27)
            return 0;
        else if (temp == '\r')
            return (choose + 1); //选择菜单的项数
        else if (temp == 224) {
            moveKey = _getch();
            if (moveKey == 72 && y != top) {
                y--;
                cct_gotoxy(x, y);
                choose = y - top;
                cout << menu[choose ] << setw((*original_para).width - strlen(menu[choose ]) ) << " ";
                cct_setcolor();
                cct_gotoxy(x, y + 1);
                cout << menu[choose + 1] << setw((*original_para).width - strlen(menu[choose + 1])) << " ";
            }
            else if (moveKey == 80) {
                if (y != bottom) {
                    y++;
                    cct_gotoxy(x, y);
                    choose = y - top;
                    cout << menu[choose ] << setw((*original_para).width - strlen(menu[choose ])) << " ";
                    cct_setcolor((*original_para).bg_color, (*original_para).fg_color);
                    cct_gotoxy(x, y - 1);
                    cout << menu[choose - 1] << setw((*original_para).width - strlen(menu[choose - 1])) << " ";
                }
                else if (y == bottom && (*original_para).high < MAX_ITEM && (choose + 1 != 10)) {
                    cct_gotoxy(x, y);
                    cout << menu[++choose];
                    if ((*original_para).width - strlen(menu[choose]) > 0) {
                        cout << setw((*original_para).width - strlen(menu[choose])) << " ";
                    }
                    cct_setcolor((*original_para).bg_color, (*original_para).fg_color);
                    for (i = (*original_para).high - MAX_ITEM + 1; i < 0; i++) {
                        cct_gotoxy(x, y + i);
                        cout << menu[choose + i] << setw((*original_para).width - strlen(menu[choose + i])) << " ";
                    }
                }

            }
        }
    }
 

    return 0;
    //仅为示例，不需要可删除
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
    int i, x, y;

    cct_gotoxy((*original_para).start_x, (*original_para).start_y);
    cct_setcolor((*original_para).bg_color, (*original_para).fg_color);

    cout << "╔";
    
    for (int i = 0; i < ((*original_para).width - 10) / 4; i++)
        cout << "═";
    cout << (*original_para).title << " ";
    
    for (int i = 0; i < ((*original_para).width - 10) / 4 + 1 ; i++)
        cout << "═";
    cout << "╗" << endl;
   
    cct_gotoxy((*original_para).start_x, (*original_para).start_y + 1);
    cct_getxy(x, y);
    cout << "║" ;
    cct_setcolor((*original_para).fg_color, (*original_para).bg_color);
    cout << menu[0] << setw((*original_para).width - strlen(menu[0])) << " ";
    cct_setcolor((*original_para).bg_color, (*original_para).fg_color);
    cct_gotoxy(x + (*original_para).width + 2, y);
    cout << "║" << endl;

    for (i = 1; i < ((*original_para).high < MAX_ITEM ? (*original_para).high : MAX_ITEM); i++) {
        cct_gotoxy((*original_para).start_x, (*original_para).start_y + i + 1);
        cct_getxy(x, y);
        cout << "║" << menu[i] << setw((*original_para).width - strlen(menu[i])) << " ";
        cout << "║" << endl;
    }

    cct_gotoxy((*original_para).start_x, (*original_para).start_y + i + 1);
    cout << "╚";
    for (int i = 0; i < ((*original_para).width)/2  ; i++)
        cout << "═";
    cout << "╝" << endl;
    cct_setcolor();

    return fun(menu, original_para); 
        
	 //按需返回
}
