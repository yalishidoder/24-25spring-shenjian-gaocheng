/* 2351131 信04 韦世贸 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int a, b, c, d;

    printf("请输入年，月，日\n");
    scanf("%d %d %d", &a, &b, &c);

    if (b <= 12) {
        if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)) {
            switch (b) {
                case 1:
                    if (c > 31) {
                        printf("输入错误-日与月的关系非法\n");
                    }
                    else
                        printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, c);
                    break;
                case 2:
                    if (c > 29) {
                        printf("输入错误-日与月的关系非法\n");
                    }
                    else {
                        d = c + 31;
                        printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
                    }
                    break;
                case 3:
                    if (c > 31) {
                        printf("输入错误-日与月的关系非法\n");
                    }
                    else {
                        d = c + 31 + 29;
                        printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
                    }
                    break;
                case 4:
                    if (c > 30) {
                        printf("输入错误-日与月的关系非法\n");
                    }
                    else {
                        d = c + 31 + 29 + 31;
                        printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
                    }
                    break;
                case 5:
                    if (c > 31) {
                        printf("输入错误-日与月的关系非法\n");
                    }
                    else {
                        d = c + 31 + 29 + 31 + 30;
                        printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
                    }
                    break;
                case 6:
                    if (c > 30) {
                        printf("输入错误-日与月的关系非法\n");
                    }
                    else {
                        d = c + 31 + 29 + 31 + 30 + 31;
                        printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
                    }
                    break;
                case 7:
                    if (c > 31) {
                        printf("输入错误-日与月的关系非法\n");
                    }
                    else {
                        d = c + 31 + 29 + 31 + 30 + 31 + 30;
                        printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
                    }
                    break;
                case 8:
                    if (c > 31) {
                        printf("输入错误-日与月的关系非法\n");
                    }
                    else {
                        d = c + 31 + 29 + 31 + 30 + 31 + 30 + 31;
                        printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
                    }
                    break;
                case 9:
                    if (c > 30) {
                        printf("输入错误-日与月的关系非法\n");
                    }
                    else {
                        d = c + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31;
                        printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
                    }
                    break;
                case 10:
                    if (c > 31) {
                        printf("输入错误-日与月的关系非法\n");
                    }
                    else {
                        d = c + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
                        printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
                    }
                    break;
                case 11:
                    if (c > 30) {
                        printf("输入错误-日与月的关系非法\n");
                    }
                    else {
                        d = c + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
                        printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
                    }
                    break;
                case 12:
                    if (c > 31) {
                        printf("输入错误-日与月的关系非法\n");
                    }
                    else {
                        d = c + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
                        printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
                    }
                    break;
            }
        }
        else {
            switch (b) {
                case 1:
                    if (c > 31) {
                        printf("输入错误-日与月的关系非法\n");
                    }
                    else
                        printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, c);
                    break;
                case 2:
                    if (c > 28) {
                        printf("输入错误-日与月的关系非法\n");
                    }
                    else {
                        d = c + 31;
                        printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
                    }
                    break;
                case 3:
                    if (c > 31) {
                        printf("输入错误-日与月的关系非法\n");
                    }
                    else {
                        d = c + 31 + 28;
                        printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
                    }
                    break;
                case 4:
                    if (c > 30) {
                        printf("输入错误-日与月的关系非法\n");
                    }
                    else {
                        d = c + 31 + 28 + 31;
                        printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
                    }
                    break;
                case 5:
                    if (c > 31) {
                        printf("输入错误-日与月的关系非法\n");
                    }
                    else {
                        d = c + 31 + 28 + 31 + 30;
                        printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
                    }
                    break;
                case 6:
                    if (c > 30) {
                        printf("输入错误-日与月的关系非法\n");
                    }
                    else {
                        d = c + 31 + 28 + 31 + 30 + 31;
                        printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
                    }
                    break;
                case 7:
                    if (c > 31) {
                        printf("输入错误-日与月的关系非法\n");
                    }
                    else {
                        d = c + 31 + 28 + 31 + 30 + 31 + 30;
                        printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
                    }
                    break;
                case 8:
                    if (c > 31) {
                        printf("输入错误-日与月的关系非法\n");
                    }
                    else {
                        d = c + 31 + 28 + 31 + 30 + 31 + 30 + 31;
                        printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
                    }
                    break;
                case 9:
                    if (c > 30) {
                        printf("输入错误-日与月的关系非法\n");
                    }
                    else {
                        d = c + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
                        printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
                    }
                    break;
                case 10:
                    if (c > 31) {
                        printf("输入错误-日与月的关系非法\n");
                    }
                    else {
                        d = c + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
                        printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
                    }
                    break;
                case 11:
                    if (c > 30) {
                        printf("输入错误-日与月的关系非法\n");
                    }
                    else {
                        d = c + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
                        printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
                    }
                    break;
                case 12:
                    if (c > 31) {
                        printf("输入错误-日与月的关系非法\n");
                    }
                    else {
                        d = c + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
                        printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
                    }
                    break;
            }
        }
    }
     else
         printf("输入错误-月份不正确\n");
    return 0;
}
