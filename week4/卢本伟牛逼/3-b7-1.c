/* 2351131 ��04 Τ��ó */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    double a; 
    int b, c, d, e, f, g, h, i, j, k, l; 
    printf("����������ֵ��\n"); 
    scanf("%lf", &a);  
    c = (int)(a / 50); d = (int)a % 50 / 20; 
    e = (int)a % 50 % 20 / 10; 
    f = (int)a % 50 % 20 % 10 / 5; 
    g = (int)a % 50 % 20 % 10 % 5 / 1;
    h = (int)((a - (int)a) * 10 + 0.001) / 5; 
    i = (int)((a - (int)a) * 10 + 0.001) % 5 / 1;
    j = (int)((a - (int)a) * 100 + 0.001) % 10 / 5; 
    k = (int)((a - (int)a) * 100 + 0.001) % 10 % 5 / 2;
    l = (int)((a - (int)a) * 100 + 0.001) % 10 % 5 % 2 / 1;
    b = c + d + e + f + g + h + i + j + k + l;
    printf("��%d�����㣬�������£�\n", b); 

    if (c > 0) 
        printf("50Ԫ : %d��\n", c);

    if (d > 0)
        printf("20Ԫ : %d��\n", d);

    if (e > 0)
        printf("10Ԫ : %d��\n", e);

    if (f > 0)
        printf("5Ԫ  : %d��\n", f);

    if (g > 0)
        printf("1Ԫ  : %d��\n", g);

    if (h > 0)
        printf("5��  : %d��\n", h);

    if (i > 0)
        printf("1��  : %d��\n", i);

    if (j > 0)
        printf("5��  : %d��\n", j);

    if (k > 0)
        printf("2��  : %d��\n", k);

    if (l > 0)
        printf("1��  : %d��\n", l);

    return 0;
}