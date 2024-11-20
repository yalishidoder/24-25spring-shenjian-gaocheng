/* 2351131 信04 韦世贸 */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */

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
       
        cout << setw(2)<< n << "#" << " " << src << "-->" << dst << endl;/*格式*/
    }
    else {/*开始递归*/
        hanoi(n - 1, src, dst, tmp);
        cout << setw(2) << n << "#" << " " << src << "-->" << dst << endl;
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
        cout << "请输入汉诺塔的层数(1-16)" << endl;
        cin >> ceng;   //读入ceng的方式必须是 cin>>int型变量
        if (cin.fail()) {
            cin.clear();
            cin.ignore(114514, '\n');
            continue;
        }
        if (ceng >= 0 && ceng <= 16) {;
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
            cout << "目标柱(" << mubiao << ")不能与起始柱(" << qishi <<")相同"<< endl;
            
            continue;
        }


        if ( mubiao == 'B' || mubiao == 'A' || mubiao == 'C') {
            break;
        }

    }

    char zhongjian;
    zhongjian = 65 + 66 + 67 - qishi - mubiao;/*这样求中间柱就比较简单*/

    cout << "移动步骤为:" << endl;

    hanoi(ceng, qishi, zhongjian, mubiao);
    
    return 0;
}