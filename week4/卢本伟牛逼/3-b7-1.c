/* 2351131 信04 韦世贸 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    double a; 
    int b, c, d, e, f, g, h, i, j, k, l; 
    printf("请输入找零值：\n"); 
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
    printf("共%d张找零，具体如下：\n", b); 

    if (c > 0) 
        printf("50元 : %d张\n", c);

    if (d > 0)
        printf("20元 : %d张\n", d);

    if (e > 0)
        printf("10元 : %d张\n", e);

    if (f > 0)
        printf("5元  : %d张\n", f);

    if (g > 0)
        printf("1元  : %d张\n", g);

    if (h > 0)
        printf("5角  : %d张\n", h);

    if (i > 0)
        printf("1角  : %d张\n", i);

    if (j > 0)
        printf("5分  : %d张\n", j);

    if (k > 0)
        printf("2分  : %d张\n", k);

    if (l > 0)
        printf("1分  : %d张\n", l);

    return 0;
}