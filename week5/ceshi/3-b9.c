/* 2351131 信04 韦世贸 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int a, b;
    for (a = 1; a <= 9; a++){
        for (b = 1; b <= a; b++){
            if (a * b<10)/*使格式统一*/
                printf("%dx%d=%-d   ", b, a, a * b);
            else
                printf("%dx%d=%-d  ", b, a, a * b);
        }
        printf("\n");
    }
    printf("\n");/*程序最末尾的换行*/
    return 0;
}