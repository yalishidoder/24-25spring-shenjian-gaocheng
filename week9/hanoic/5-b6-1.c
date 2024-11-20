/* 2351131 信04 韦世贸 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----具体要求----
   1、不允许添加其它头文件
   2、允许定义一个全局变量、不允许定义静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */

int jishu = 1; /*全局变量计数*/
int azhu[10] = { 0 }, bzhu[10] = { 0 }, czhu[10] = { 0 };//记录圆盘和编号的数组
int atop, btop, ctop;//三个栈顶指针


void chushihua(int n,char src)//对数组进行初始化
{
    int i;//数组变量
    if (src == 'A') {
        atop = n ;
        for (i = 0; i <= atop && n > 0; i++) {
            
                azhu[i] = n;
            
            n--;
        }
    }
    
    if (src == 'B') {
        btop = n ;
        for (i = 0; i <= btop && n > 0; i++) {

            bzhu[i] = n;

            n--;
        }
    }
    if (src == 'C') {
        ctop = n ;
        for (i = 0; i <= ctop && n > 0; i++) {

            czhu[i] = n;

            n--;
        }
    }
    
   //初始打印
    printf("A:");

    for (i = 0; i < 10; i++) {
        if (azhu[i]) {
            printf(" %d", azhu[i]);
        }
        else {
            printf("  ");
        }
    }

    printf("B:");

    for (i = 0; i < 10; i++) {
        if (bzhu[i])
            printf(" %d", bzhu[i]);
        else
            printf("  ");
    }

    printf("C:");

    for (i = 0; i < 10; i++) {
        if (czhu[i])
            printf(" %d", czhu[i]);
        else
            printf("  ");
    }
    printf("\n");
}
void crosswiseprint(int n,char src,char dst)  //横向打印数组
{
    int i;//数组循环打印需要的变量
   
    //出栈与入栈
    //因为这里的n与出入栈元素相等，所以就不另外定义变量cunfang
        if (src=='A') {
            azhu[--atop] = 0;//出栈后置0
            if (dst == 'B') {
                bzhu[btop++] = n;
            }
            else if (dst == 'C') {
                czhu[ctop++] = n;
            }
        }
        if(src=='B') {
            bzhu[--btop] = 0;
            if (dst == 'A') {
                azhu[atop++] = n;
            }
            else if (dst == 'C') {
                czhu[ctop++] = n;
            }
        }
        if(src=='C') {
            czhu[--ctop] = 0;
            if (dst == 'A') {
                azhu[atop++] = n;
            }
            else if (dst == 'B') {
                bzhu[btop++] = n;
            }
        }
        

    //以下是打印部分
    printf("A:");

    for (i = 0; i < 10; i++) {
        if (azhu[i]) {
            printf(" %d", azhu[i]);
        }
        else {
            printf("  ");
        }
    }

    printf("B:");

    for (i = 0; i < 10; i++) {
        if (bzhu[i])
            printf(" %d", bzhu[i]);
        else
            printf("  ");
    }

    printf("C:");

    for (i = 0; i < 10; i++) {
        if (czhu[i])
            printf(" %d", czhu[i]);
        else
            printf("  ");
    }
    printf("\n");
   
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
        printf("第%4d 步(%2d): %c-->%c ", jishu, n, src, dst);
        crosswiseprint(n, src,dst);
        jishu++;
        /*格式*/
    }
    else {/*开始递归*/
        hanoi(n - 1, src, dst, tmp);
        printf("第%4d 步(%2d): %c-->%c ", jishu, n, src, dst);
        crosswiseprint(n, src,dst);
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
    int ceng, ret1, ret2, ret3;/*层数*/
    char qishi, mubiao;/*定义三个柱*/
    while (1) {
        printf("请输入汉诺塔的层数(1-10)\n");
        ret1 = scanf("%d", &ceng);   //读入ceng的方式必须是 cin>>int型变量
        if (ret1 != 1) {
            while (getchar() != '\n')
                continue;
        }
        if (ceng >= 0 && ceng <= 10) {
            ;
            break;
        }
    }
    while (getchar() != '\n');
    while (1) {
        printf("请输入起始柱(A-C)\n");
        ret2 = scanf("%c", &qishi);  //读入qishi的方式为字符

        if (ret2 != 1) {
            while (getchar() != '\n')
                continue;
        }

        if (qishi == 'a' || qishi == 'b' || qishi == 'c') {/*大写转换*/
            qishi -= 32;
            break;
        }

        if (qishi == 'B' || qishi == 'A' || qishi == 'C') {

            break;
        }
        while (getchar() != '\n');
    }
    while (getchar() != '\n');

    while (1) {
        printf("请输入目标柱(A-C)\n");
        ret3 = scanf("%c", &mubiao);  //读入mubiao的方式为字符
        if (ret3 != 1) {
            while (getchar() != '\n')
                continue;
        }

        if (mubiao == 'a' || mubiao == 'c' || mubiao == 'b') {
            mubiao -= 32;  /*这里不能退出循环，因为后面还有一个相等特判*/

        }

        if (mubiao == qishi) { /*输入重复的情况*/
            printf("目标柱(%c)不能与起始柱(%c)相同\n", mubiao, qishi);

            continue;
        }


        if (mubiao == 'B' || mubiao == 'A' || mubiao == 'C') {
            break;
        }
        while (getchar() != '\n');
    }

    char zhongjian;
    zhongjian = 'A' + 'B' + 'C' - qishi - mubiao;/*这样求中间柱就比较简单*/

    printf("初始:                ");

    chushihua(ceng, qishi);
    hanoi(ceng, qishi, zhongjian, mubiao);

    return 0;
}