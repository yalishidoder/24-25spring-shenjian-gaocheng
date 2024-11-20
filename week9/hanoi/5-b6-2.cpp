/*2351131 信04 韦世贸*/
#include <iostream>
#include <iomanip>
using namespace std;

int jishu = 1;/*计数*/
int top[3] = { 0 };//一维数组
int zhu[3][10] = { 0 };//圆盘二维数组
/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、仅允许hanoi中定义一个静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */

void chushihua(int n, char src)//对数组进行初始化
{
    int i;//数组变量
    if (src == 'A') {
        top[0] = n;
        for (i = 0; i <= top[0] && n > 0; i++) {

            zhu[0][i] = n;

            n--;
        }
    }

    if (src == 'B') {
        top[1] = n;
        for (i = 0; i <= top[1] && n > 0; i++) {

            zhu[1][i] = n;

            n--;
        }
    }
    if (src == 'C') {
        top[2] = n;
        for (i = 0; i <= top[2] && n > 0; i++) {

            zhu[2][i] = n;

            n--;
        }
    }

    //初始打印
    cout << "A:";

    for (i = 0; i < 10; i++) {
        if (zhu[0][i]) {
            cout << " " << zhu[0][i] ;
        }
        else {
            cout << "  ";
        }
    }

    cout<<"B:";

    for (i = 0; i < 10; i++) {
        if (zhu[1][i])
            cout << " " << zhu[1][i] ;
        else
            cout << "  ";
    }

    cout<<"C:";

    for (i = 0; i < 10; i++) {
        if (zhu[2][i])
            cout << " " << zhu[2][i] ;
        else
            cout << "  ";
    }
    cout << endl;
}

void crosswiseprint(int n, char src, char dst)  //横向打印数组
{
    int i;//数组循环打印需要的变量

    //出栈与入栈
    //因为这里的n与出入栈元素相等，所以就不另外定义变量cunfang
    if (src == 'A') {
        zhu[0][--top[0]] = 0;//出栈后置0
        if (dst == 'B') {
            zhu[1][top[1]++] = n;
        }
        else if (dst == 'C') {
            zhu[2][top[2]++] = n;
        }
    }
    if (src == 'B') {
        zhu[1][--top[1]] = 0;
        if (dst == 'A') {
            zhu[0][top[0]++] = n;
        }
        else if (dst == 'C') {
            zhu[2][top[2]++] = n;
        }
    }
    if (src == 'C') {
        zhu[2][--top[2]] = 0;
        if (dst == 'A') {
            zhu[0][top[0]++] = n;
        }
        else if (dst == 'B') {
            zhu[1][top[1]++] = n;
        }
    }


    //以下是打印部分
    cout << "A:";

    for (i = 0; i < 10; i++) {
        if (zhu[0][i]) {
            cout << " " << zhu[0][i] ;
        }
        else {
            cout << "  ";
        }
    }

    cout << "B:";

    for (i = 0; i < 10; i++) {
        if (zhu[1][i])
            cout << " " << zhu[1][i] ;
        else
            cout << "  ";
    }

    cout << "C:";

    for (i = 0; i < 10; i++) {
        if (zhu[2][i])
            cout << " " << zhu[2][i] ;
        else
            cout << "  ";
    }
    cout << endl;
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
               3、允许定义一个静态局部变量
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {/*特殊情况*/
        cout <<"第" << setw(4) << jishu <<" 步" << "(" << setw(2) << n << "):" << " " << src << "-->" << dst << " ";
        crosswiseprint(n, src, dst);
        jishu++;
        /*格式*/
    }

    else {/*开始递归*/
        hanoi(n - 1, src, dst, tmp);
        cout << "第" << setw(4) << jishu << " 步" << "(" << setw(2) << n << "):" << " " << src << "-->" << dst << " ";
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
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
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
            ;
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

    cout << "初始:                " ;

    chushihua(ceng, qishi);
    hanoi(ceng, qishi, zhongjian, mubiao);

    return 0;
}