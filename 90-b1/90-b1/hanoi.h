/*2351131 ��04 Τ��ó*/
#pragma once

/* ------------------------------------------------------------------------------------------------------

     ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ------------------------------------------------------------------------------------------------------ */

   //����һЩ�����ƶ�����λ��
const int A = 17;  //�������ĺ�����
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

//ͼ�λ��ַ�
const char ch = ' ';

   /* hanoi_menu.cpp�µĺ������� */

  /*  hanoi_menu() ���˵�����   */
int hanoi_menu();

  /*hanoi_multiple_solutions.cpp�µĺ�������*/

void hanoi_multiple_solutions(int choice);