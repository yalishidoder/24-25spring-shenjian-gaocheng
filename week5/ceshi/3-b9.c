/* 2351131 ��04 Τ��ó */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int a, b;
    for (a = 1; a <= 9; a++){
        for (b = 1; b <= a; b++){
            if (a * b<10)/*ʹ��ʽͳһ*/
                printf("%dx%d=%-d   ", b, a, a * b);
            else
                printf("%dx%d=%-d  ", b, a, a * b);
        }
        printf("\n");
    }
    printf("\n");/*������ĩβ�Ļ���*/
    return 0;
}