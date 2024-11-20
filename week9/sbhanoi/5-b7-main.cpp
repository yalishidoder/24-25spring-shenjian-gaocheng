/*2351131 ��04 Τ��ó*/
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include "5-b7.h"
using namespace std;

const int A = 17;
const int B = 27;
const int C = 37;
const int bu = 20;    //����һЩ�����ƶ�����λ��

static int xianshi;//������ʾ��������
static int speed;//�ƶ��ٶ�
int jishu = 1; /*ȫ�ֱ�������*/
int azhu[10] = { 0 }, bzhu[10] = { 0 }, czhu[10] = { 0 };//��¼Բ�̺ͱ�ŵ�����
int atop, btop, ctop;//����ջ��ָ��


void chushihua(int n, char src)//��������г�ʼ��
{
    int i;//�������
    int line = 7; //���庺ŵ�����ϲ�߶�
    if (src == 'A') {
        atop = n;
        for (i = 0; i <= atop && n > 0; i++) {

            azhu[i] = n;

            n--;
        }
    }

    if (src == 'B') {
        btop = n;
        for (i = 0; i <= btop && n > 0; i++) {

            bzhu[i] = n;

            n--;
        }
    }
    if (src == 'C') {
        ctop = n;
        for (i = 0; i <= ctop && n > 0; i++) {

            czhu[i] = n;

            n--;
        }
    }


    //��ʼ��ӡ
    if (xianshi) {
        cct_gotoxy(bu, 20);
        cout << "��ʼ:                 ";
        cout << "A:";

        for (i = 0; i < 10; i++) {
            if (azhu[i]) {
                cout << " " <<azhu[i];
            }
            else {
                cout << "  ";
            }
        }

        cout << "B:";

        for (i = 0; i < 10; i++) {
            if (bzhu[i])
                cout << " " <<bzhu[i];
            else
                cout << "  ";
        }

        cout << "C:";

        for (i = 0; i < 10; i++) {
            if (czhu[i])
                cout << " " <<czhu[i];
            else
                cout << "  ";
        }

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

    for (i = 9; i >= 0; i--) {
        cct_gotoxy(A, line);
        if (azhu[i]) {
            cout << azhu[i];
        }
        else {
            cout << "  ";
        }

        cct_gotoxy(B, line);
        if (bzhu[i]) {
            cout << bzhu[i];
        }
        else {
            cout << "  ";
        }

        cct_gotoxy(C, line);
        if (czhu[i]) {
            cout << czhu[i];
        }
        else {
            cout << "  ";
        }
        cout << endl;
        line++;
    }

    cct_gotoxy(15, 17);
    cout << "=========================" << endl;
    cct_gotoxy(15, 18);
    cout << "  A         B         C" << endl;
    
    if (src == 'A') {
        cct_gotoxy(A + 1, 17 - atop);
    }
    else if (src == 'B')
        cct_gotoxy(B + 1, 17 - btop);
    else if (src == 'C')
        cct_gotoxy(C + 1, 17 - ctop);

    if (speed == 0) {  //�ƶ���ʱ
        while (_getch() != '\r');
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
void crosswiseprint(int n, char src, char dst)  //�����ӡ���������
{
    int i;//����ѭ����ӡ��Ҫ�ı���
    int line = 7; //���庺ŵ�����ϲ�߶�
    //��ջ����ջ
    //��Ϊ�����n�����ջԪ����ȣ����ԾͲ����ⶨ�����cunfang
    if (src == 'A') {
        
        if (dst == 'B') {
            bzhu[btop++] = azhu[--atop];
        }
        else if (dst == 'C') {
            czhu[ctop++] = azhu[--atop];
        }
    }
    if (src == 'B') {
        bzhu[--btop] = 0;
        if (dst == 'A') {
            azhu[atop++] = n;
        }
        else if (dst == 'C') {
            czhu[ctop++] = n;
        }
    }
    if (src == 'C') {
        czhu[--ctop] = 0;
        if (dst == 'A') {
            azhu[atop++] = n;
        }
        else if (dst == 'B') {
            bzhu[btop++] = n;
        }
    }


    //�����Ǵ�ӡ����

    for (i = 9; i >= 0; i--) {
        cct_gotoxy(A, line);
        if (i>atop -1) {       //����д������һ�ָ���
            cout << "  " ;
        }
        else {
            cout << azhu[i];
        }

        cct_gotoxy(B, line);
        if (bzhu[i]) {
            cout << bzhu[i] ;
        }
        else {
            cout << "  ";
        }

        cct_gotoxy(C, line);
        if (czhu[i]) {
            cout << czhu[i] ;
        }
        else {
            cout << "  ";
        }
        cout << endl;
        line++;
    }

    cct_gotoxy(15, 17);
    cout << "=========================" << endl;
    cct_gotoxy(15, 18);
    cout << "  A         B         C" << endl;


    if (dst == 'A') {
        cct_gotoxy(A+1, 17-atop);
    }
    else if(dst == 'B')
        cct_gotoxy(B+1, 17 - btop);
    else if(dst == 'C')
        cct_gotoxy(C+1, 17 - ctop);

    if (speed == 0) {  //�ƶ���ʱ
        while (_getch() != '\r');
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

    if (xianshi) {  //��ʾ�ڲ�����
        cct_gotoxy(bu+22, 20);
        cout << "A:";

        for (i = 0; i < 10; i++) {
            if (i<atop) {  //����д������һ�ָ���
                cout << " " << azhu[i];
            }
            else {
                cout << "  ";
            }
        }

        cout << "B:";

        for (i = 0; i < 10; i++) {
            if (bzhu[i])
                cout << " " << bzhu[i];
            else
                cout << "  ";
        }

        cout << "C:";

        for (i = 0; i < 10; i++) {
            if (czhu[i])
                cout << " " << czhu[i];
            else
                cout << "  ";
        }

        if (speed == 0) {  //�ƶ���ʱ
            while (_getch() != '\r');
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
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
  ���������int n������
            char src����ʼ��
            char tmp���м���
            char dst��Ŀ����
  �� �� ֵ��
  ˵    ����1�����������βΡ��������;���׼��
            2������������������κ���ʽ��ѭ��
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {/*�������*/
        cct_gotoxy(bu, 20);
        cout << "��" << setw(4) << jishu << " ��(" << n << "#: " << src << "-->" << dst << ") ";
        crosswiseprint(n, src, dst);
        jishu++;
        /*��ʽ*/
    }
    else {/*��ʼ�ݹ�*/
        hanoi(n - 1, src, dst, tmp);
        cct_gotoxy(bu, 20);
        cout << "��" << setw(4) << jishu << " ��(" << n << "#: " << src << "-->" << dst << ") ";
        crosswiseprint(n, src, dst);
        jishu++;
        hanoi(n - 1, tmp, src, dst);
    }
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
    int ceng;/*����*/
    char qishi, mubiao;/*����������*/
    while (1) {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> ceng;   //����ceng�ķ�ʽ������ cin>>int�ͱ���
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
        cout << "��������ʼ��(A-C)" << endl;
        cin >> qishi;   //����qishi�ķ�ʽΪ�ַ�

        if (cin.fail()) {
            cin.clear();
            cin.ignore(114514, '\n');
            continue;
        }

        if (qishi == 'a' || qishi == 'b' || qishi == 'c') {/*��дת��*/
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
        cout << "������Ŀ����(A-C)" << endl;
        cin >> mubiao;  //����mubiao�ķ�ʽΪ�ַ�
        if (cin.fail()) {
            cin.clear();
            cin.ignore(114514, '\n');
            continue;
        }

        if (mubiao == 'a' || mubiao == 'c' || mubiao == 'b') {
            mubiao -= 32;  /*���ﲻ���˳�ѭ������Ϊ���滹��һ���������*/

        }

        if (mubiao == qishi) { /*�����ظ������*/
            cout << "Ŀ����(" << mubiao << ")��������ʼ��(" << qishi << ")��ͬ" << endl;

            continue;
        }


        if (mubiao == 'B' || mubiao == 'A' || mubiao == 'C') {
            break;
        }
        cin.ignore(114514, '\n');
    }

    char zhongjian;
    zhongjian = 'A' + 'B' + 'C' - qishi - mubiao;/*�������м����ͱȽϼ�*/

    while (1) {
        cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
        cin >> speed;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(114514, '\n');
            continue;
        }
        if (speed >= 0 && speed<= 5) {
            break;
        }
    }

    while (1) {
        cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
        cin >> xianshi;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(114514, '\n');
            continue;
        }
        if (xianshi >= 0 && xianshi <= 1) {
            break;
        }
    }

    cct_cls();

    cout << "�� " << qishi << " �ƶ��� " << mubiao << "���� " << ceng << " �㣬��ʱ����Ϊ " << speed << "��";
    
    if (!xianshi)
        cout << "��";

    cout << "��ʾ�ڲ�����ֵ" << endl;

    chushihua(ceng, qishi);
    hanoi(ceng, qishi, zhongjian, mubiao);

    cct_gotoxy(45, 30);
	system("pause"); //���������ʾ��ͣ��ע�⣺ֻ�ʺ����ض��������ر������ĳ���Ӵ˾���÷�Ϊ0��
	return 0;
}