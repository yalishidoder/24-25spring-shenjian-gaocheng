/* 2351131 信04 韦世贸 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int zeller(int y, int m, int d) {
    int c, w, year, date; 
    if (m < 3) { /*对月份的判断*/
        m += 12;
        y--;
    }
    else; 
    c = y / 100; 
    year = y - 100 * c;

    w = year + year / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1;
    while (w < 0)
        w += 7;

    date = w % 7;
  
    return date;
}

int main() {
    int nian, yue, day, right = 1, run,ret,w; 
    while (1) {
        printf("请输入年[1900-2100]、月、日：\n"); 
        ret = scanf("%d %d %d", &nian, &yue, &day);

        if (nian % 4 == 0 && nian % 100 != 0 || nian % 400 == 0)
            run = 1;
        else
            run = 0;
        /*闰年判断*/

        if (((yue % 2 && yue <= 7) || (yue >= 8 && yue % 2 == 0)) && (day > 31))
            right = 0;
        else if ((yue == 9 || yue == 6 || yue == 4 || yue == 11) && (day > 30))
            right = 0;
        else if ((yue == 2 && run) && (day > 29))
            right = 0;
        else if ((yue == 2 && !run) && (day > 28))
            right = 0;
        /*日是否正确的判断*/

        if (nian < 1900 || nian > 2100 || yue < 0 || yue > 12 || !right || ret != 3) {
            if (ret != 3) {
                printf("输入错误，请重新输入\n");
                while (getchar() != '\n') {      /*清空缓冲区*/
                    ;
                }
            }
            else if (nian < 1900 || nian > 2100)
                printf("年份不正确，请重新输入\n");
            else if (yue < 0 || yue > 12)
                printf("月份不正确，请重新输入\n");
            else if (!right) {
                printf("日不正确，请重新输入\n");
                right = 1;
            }
            
            continue;
        }

        if ((nian >= 1900 && nian <= 2100) && (yue > 0 && yue <= 12) && right) {
            break;
        }
    }/*错误处理*/

    w = zeller(nian, yue, day);/*调用函数，得到星期值*/
    printf("星期");
    switch (w)
    {
        case 0:
            printf("天\n");
            break;
        case 1:
            printf("一\n");
            break;
        case 2:
            printf("二\n");
            break;
        case 3:
            printf("三\n");
            break;
        case 4:
            printf("四\n");
            break;
        case 5:
            printf("五\n");
            break;
        case 6:
            printf("六\n");
            break;
    }
    return 0;
}
