/*2351131 信04 韦世贸*/
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include "5-b7.h"
using namespace std;

const int A = 17;
const int B = 27;
const int C = 37;
const int bu = 20;    //定义一些光标会移动到的位置

static int xianshi;//定义显示决定变量
static int speed;//移动速度
int jishu = 1; /*全局变量计数*/
int azhu[10] = { 0 }, bzhu[10] = { 0 }, czhu[10] = { 0 };//记录圆盘和编号的数组
int atop, btop, ctop;//三个栈顶指针


void chushihua(int n, char src)//对数组进行初始化
{
    int i;//数组变量
    int line = 7; //定义汉诺塔最上层高度
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


    //初始打印
    if (xianshi) {
        cct_gotoxy(bu, 20);
        cout << "初始:                 ";
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

    if (speed == 0) {  //移动延时
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
void crosswiseprint(int n, char src, char dst)  //横向打印数组和盘子
{
    int i;//数组循环打印需要的变量
    int line = 7; //定义汉诺塔最上层高度
    //出栈与入栈
    //因为这里的n与出入栈元素相等，所以就不另外定义变量cunfang
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


    //以下是打印部分

    for (i = 9; i >= 0; i--) {
        cct_gotoxy(A, line);
        if (i>atop -1) {       //两种写法，第一种更好
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

    if (speed == 0) {  //移动延时
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

    if (xianshi) {  //显示内部数组
        cct_gotoxy(bu+22, 20);
        cout << "A:";

        for (i = 0; i < 10; i++) {
            if (i<atop) {  //两种写法，第一种更好
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

        if (speed == 0) {  //移动延时
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
  函数名称：
  功    能：打印n层汉诺塔的移动顺序
  输入参数：int n：层数
            char src：起始柱
            char tmp：中间柱
            char dst：目标柱
  返 回 值：
  说    明：1、函数名、形参、返回类型均不准动
            2、本函数不允许出现任何形式的循环
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {/*特殊情况*/
        cct_gotoxy(bu, 20);
        cout << "第" << setw(4) << jishu << " 步(" << n << "#: " << src << "-->" << dst << ") ";
        crosswiseprint(n, src, dst);
        jishu++;
        /*格式*/
    }
    else {/*开始递归*/
        hanoi(n - 1, src, dst, tmp);
        cct_gotoxy(bu, 20);
        cout << "第" << setw(4) << jishu << " 步(" << n << "#: " << src << "-->" << dst << ") ";
        crosswiseprint(n, src, dst);
        jishu++;
        hanoi(n - 1, tmp, src, dst);
    }
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
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

    while (1) {
        cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
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
        cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
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

    cout << "从 " << qishi << " 移动到 " << mubiao << "，共 " << ceng << " 层，延时设置为 " << speed << "，";
    
    if (!xianshi)
        cout << "不";

    cout << "显示内部数组值" << endl;

    chushihua(ceng, qishi);
    hanoi(ceng, qishi, zhongjian, mubiao);

    cct_gotoxy(45, 30);
	system("pause"); //最后用这句表示暂停（注意：只适合于特定程序，无特别声明的程序加此句则得分为0）
	return 0;
}