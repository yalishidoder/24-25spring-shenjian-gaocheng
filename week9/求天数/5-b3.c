/* 2351131 信04 韦世贸 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int runnian(int nian) //判断闰年的函数
{
    int run = 0;
    if ((nian % 4 == 0 && nian % 100 != 0) || (nian % 400 == 0)) {
        run = !run;
    }
    return run;
}

int qiutianshu(int b,int ri,int run)//求天数的函数
{
    int tianshu[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int i, day = 0;//数组变量，最后的天数
    if (run) {
        tianshu[1] = 29;
    }

    for (i = 0; i < b - 1; ++i) {
        day += tianshu[i];
    }
    day += ri;
    return day;
}

int main() 
{
	int a, b, c, d;//定义年、月、日以及最后输出的天数
    int run; //判断闰年的变量
	printf("请输入年，月，日\n");
	scanf("%d %d %d", &a, &b, &c);

    run = runnian(a);
    if (b <= 12 && b) {  //错误处理
        
        if ((b % 2 && b <= 7) || (b >= 8 && b % 2 == 0)) {
            if (c > 31) {
                printf("输入错误-日与月的关系非法\n");
                return 0;
            }
         
        }
        if (b == 9 || b == 6 || b == 4 || b == 11) {
            if (c > 30) {
                printf("输入错误-日与月的关系非法\n");
                return 0;
            }
        }
        if (b == 2) {
            if (run) {
                if (c > 29) {
                    printf("输入错误-日与月的关系非法\n");
                    return 0;
                }
            }
            else {
                if (c > 28) {
                    printf("输入错误-日与月的关系非法\n");
                    return 0;
                }
            }
        }
    }
    else
    {
        printf("输入错误-月份不正确\n");
        return 0;
    }

    d = qiutianshu(b, c, run);
    printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);

    return 0;
}