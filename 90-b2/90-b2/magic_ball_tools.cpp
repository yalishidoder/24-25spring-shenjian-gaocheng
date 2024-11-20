/*2351131 ��04 Τ��ó*/
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "magic_ball.h"
using namespace std;

/***************************************************************************
  �������ƣ�tj_strcasecmp
  ��    �ܣ���ÿС���������������ַ��Ƿ��ǡ�end��
  ���������
  �� �� ֵ��0���ַ�ascll���ֵ
  ˵    ����
***************************************************************************/
int tj_strcasecmp(const char* s1, const char* s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�wait_for_enter
  ��    �ܣ���ͣ��������س���������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void wait_for_enter()
{
    while (_getch() != '\r')
        ;
}

/***************************************************************************
  �������ƣ�end
  ��    �ܣ�����ÿһС��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void end() 
{
    char s1[25] = { 0 },*p;
    int x = 0, y = 0;
    cout << "��С�������������End����...   ";
    cct_getxy(x, y);
    p = s1;

    while (1) {
        for(;*p;p++)
            *p = '0';
        cin >> s1;

        if (tj_strcasecmp(s1, "end") == 0)
            break;
        else {
            cout << "�����������������" << endl;
            cct_gotoxy(x, y);
            cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 25);
            cct_gotoxy(x, y);
        }
    }

}

/***************************************************************************
  �������ƣ�change_color
  ��    �ܣ��ҵ�����������ɫ
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void change_color()
{
    cct_setcolor(COLOR_HYELLOW, COLOR_BLUE);
}

/***************************************************************************
  �������ƣ�magic_ball_cout
  ��    �ܣ��������һЩ��ʾ
  ���������
  �� �� ֵ��
  ˵    ����
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
        cout << "���س�������Ѱ�ҳ�ʼ��������Ĳ���...";
        wait_for_enter();
    }
    else if (mode == 2|| mode == 7) {
        cout << "���س����������������0����..." << endl;
        wait_for_enter();
    }
    else if (mode == 3|| mode == 8) {
        cout << "���س���������ֵ���..." << endl;
        wait_for_enter();
    }
    else if (mode == 4)
        cout << "�����0�������(��ͬɫ��ʶ)��" << endl;
    else if (mode == 5)
        cout << "��ֵ���������(��ͬɫ��ʶ)��" << endl;
    else if (mode == 6) {
        cout << endl;
        cout << "��ѡ���������ʾ����ͬɫ��ʶ����" << endl;
    }
    else if (mode == 9) {
        cout << "���س�����ʾ������ʾ...";
        wait_for_enter();
    }

}
/***************************************************************************
  �������ƣ�turn_back_color
  ��    �ܣ���ɫ����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void turn_back_color()
{
    cct_setcolor();        //�ָ���ɫ
}

/***************************************************************************
  �������ƣ�format
  ��    �ܣ����������ȫ��Ԫ����0
  ���������
  �� �� ֵ��
  ˵    ����
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
     �������ƣ�delay
     ��    �ܣ��ƶ���ʱ
     ���������
     �� �� ֵ��
     ˵    ����
***************************************************************************/
void delay(int speed)
{
    if (speed == 0) {  //�ƶ���ʱ
        while (_getch() != '\r'); //���س�������һ��
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
  �������ƣ�mouse
  ��    �ܣ�ʹ�����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void mouse(char(&game_area)[row_max + 2][col_max + 2], int row, int col, char(&judgement)[row_max + 2][col_max + 2], char choice,int &num1,int &num2)
{
	int X = 0, Y = 0;
    int ret1,maction1;
	int keycode1, keycode2;
    int loop1 = 1, loop2 = 0;

	cct_enable_mouse();

	cct_setcursor(CURSOR_INVISIBLE);	//�رչ��
	
	while (loop1) {
		/* �����/���̣�����ֵΪ���������е�ĳһ��, ��ǰ���λ����<X,Y>�� */
		ret1 = cct_read_keyboard_and_mouse(X, Y, maction1, keycode1, keycode2);

        if (!num1 && !num2)
            return;

		if (ret1 == CCT_MOUSE_EVENT) {
			switch (maction1) {
				case MOUSE_ONLY_MOVED:                  //����ƶ�
                    loop2 = boundary(game_area, row, col, X, Y, 1, judgement, num1, num2);
					break;
                
                case MOUSE_LEFT_BUTTON_CLICK:			//�������
                    loop2 = boundary(game_area, row, col, X, Y, 2, judgement, num1, num2);
                    if (choice == '8') {
                        loop2 = 0;
                        loop1 = 0;
                    }
                    break;
                case MOUSE_RIGHT_BUTTON_CLICK:			//�����Ҽ�
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
  �������ƣ�boundary
  ��    �ܣ��ж����λ���Ƿ��ںϷ������ڲ���ӡ�Ϸ����λ��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int boundary(char(&game_area)[row_max + 2][col_max + 2],int row, int col,int my_x, int my_y, int which_mode, char(&judgement)[row_max + 2][col_max + 2], int& num1, int& num2)
{
    cct_gotoxy(0, 2 * (row + 1));
    turn_back_color();
    cout << "[��ǰ���] ";
    if ((my_x - 2) % 4 == 0 && (my_y - 2) % 2 == 0 && my_x <= 2 + 4 * (col-1) && my_y <=  2 * row) {
        switch (which_mode) {
            case 1:
                cout << char('A' + (my_y - 2) / 2 ) << "��" << 1 + (my_x - 2) / 4  << "�� ";
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
        cout << "λ�÷Ƿ�";
    return 0;
}

/***************************************************************************
  �������ƣ�change
  ��    �ܣ��ж�ѡ�е������Ƿ����ڣ������򽻻�������ѡ�Ĳ���
  ���������
  �� �� ֵ��
  ˵    ����
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
                if ((k == i && l != j) || (k != i && l == j)) {  //����
                    mid = game_area[i][j];
                    game_area[i][j] = game_area[k][l];
                    game_area[k][l] = mid;
                    cct_gotoxy(2 + 4 * (j - 2), 2 + 2 * (i - 2));
                    cct_setcolor(game_area[i][j] - '0', COLOR_BLACK);
                    cout << "��";
                    cct_gotoxy(2 + 4 * (l - 2), 2 + 2 * (k - 2));
                    cct_setcolor(game_area[k][l] - '0', COLOR_BLACK);
                    cout << "��";
                }
                else {    //������
                    cct_gotoxy(my_x, my_y);
                    cct_setcolor(game_area[i][j] - '0', COLOR_HWHITE);
                    cout << "��";
                    judgement[k][l] = '1';
                    judgement[i][j] = '2';
                }
            }
        }
    }
}

/***************************************************************************
  �������ƣ�legality
  ��    �ܣ��ж����ѡ�е�λ���Ƿ�Ϊ������
  ���������
  �� �� ֵ��
  ˵    ����
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
    if (judgement[i][j] > '0') {        //ֻ����ʾ���������ܱ����
        cout << "��ǰѡ��";
        cct_gotoxy(my_x, my_y);
        if (judgement[i][j] == '1' && sign_white < 1) {   //����ѡ��״̬
            cct_setcolor(game_area[i][j] - '0', COLOR_HWHITE);
            cout << "��";
            judgement[i][j] = '2';
 
        }
        else if(judgement[i][j] == '1' && sign_white == 1)
            change(game_area, row, col, my_x, my_y, judgement);      //������Ϸ���Խ���
        else if (judgement[i][j] == '2') {
            cct_setcolor(game_area[i][j] - '0', COLOR_BLACK); //ȡ��ѡ��״̬
            cout << "��";
            judgement[i][j] = '1';
        }
        turn_back_color();
    }
    else
        cout << "����ѡ��";

    cct_gotoxy(10, 2 * (row + 1));
    cout<< char('A' + (my_y - 2) / 2) << "��" << 1 + (my_x - 2) / 4  << "��  ";
}
