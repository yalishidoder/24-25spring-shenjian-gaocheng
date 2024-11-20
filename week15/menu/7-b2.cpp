/* 2351131 Τ��ó ��04 */
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include "cmd_console_tools.h"
#include "7-b2.h"         
 

                                            //δ������й���
using namespace std;
/* 1���������ͷ�ļ�
   2����������ȫ�ֱ�����������̬ȫ�֣���������const��define
   3����������Ҫ�Ľṹ�塢�����ȣ������ޱ�Դ�����ļ�ʹ�� */
const int MAX_ITEM = 10;
/* ������������Դ�����ļ���Ҫ�Ľṹ�壬��Ҫ�ŵ�.h��
       ��Ϊʾ��������Ҫ��ɾ�� */
/*struct xxx
{
    ;
}*/

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����������Դ�����ļ���Ҫ�ĺ���������Ϊstatic����
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
            return (choose + 1); //ѡ��˵�������
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
    //��Ϊʾ��������Ҫ��ɾ��
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��������������õĺ���������������ͷ�ļ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int pop_menu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
    int i, x, y;

    cct_gotoxy((*original_para).start_x, (*original_para).start_y);
    cct_setcolor((*original_para).bg_color, (*original_para).fg_color);

    cout << "�X";
    
    for (int i = 0; i < ((*original_para).width - 10) / 4; i++)
        cout << "�T";
    cout << (*original_para).title << " ";
    
    for (int i = 0; i < ((*original_para).width - 10) / 4 + 1 ; i++)
        cout << "�T";
    cout << "�[" << endl;
   
    cct_gotoxy((*original_para).start_x, (*original_para).start_y + 1);
    cct_getxy(x, y);
    cout << "�U" ;
    cct_setcolor((*original_para).fg_color, (*original_para).bg_color);
    cout << menu[0] << setw((*original_para).width - strlen(menu[0])) << " ";
    cct_setcolor((*original_para).bg_color, (*original_para).fg_color);
    cct_gotoxy(x + (*original_para).width + 2, y);
    cout << "�U" << endl;

    for (i = 1; i < ((*original_para).high < MAX_ITEM ? (*original_para).high : MAX_ITEM); i++) {
        cct_gotoxy((*original_para).start_x, (*original_para).start_y + i + 1);
        cct_getxy(x, y);
        cout << "�U" << menu[i] << setw((*original_para).width - strlen(menu[i])) << " ";
        cout << "�U" << endl;
    }

    cct_gotoxy((*original_para).start_x, (*original_para).start_y + i + 1);
    cout << "�^";
    for (int i = 0; i < ((*original_para).width)/2  ; i++)
        cout << "�T";
    cout << "�a" << endl;
    cct_setcolor();

    return fun(menu, original_para); 
        
	 //���践��
}
