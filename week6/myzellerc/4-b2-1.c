/* 2351131 ��04 Τ��ó */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int zeller(int y, int m, int d) {
    int c, w, year, date; 
    if (m < 3) { /*���·ݵ��ж�*/
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
        printf("��������[1900-2100]���¡��գ�\n"); 
        ret = scanf("%d %d %d", &nian, &yue, &day);

        if (nian % 4 == 0 && nian % 100 != 0 || nian % 400 == 0)
            run = 1;
        else
            run = 0;
        /*�����ж�*/

        if (((yue % 2 && yue <= 7) || (yue >= 8 && yue % 2 == 0)) && (day > 31))
            right = 0;
        else if ((yue == 9 || yue == 6 || yue == 4 || yue == 11) && (day > 30))
            right = 0;
        else if ((yue == 2 && run) && (day > 29))
            right = 0;
        else if ((yue == 2 && !run) && (day > 28))
            right = 0;
        /*���Ƿ���ȷ���ж�*/

        if (nian < 1900 || nian > 2100 || yue < 0 || yue > 12 || !right || ret != 3) {
            if (ret != 3) {
                printf("�����������������\n");
                while (getchar() != '\n') {      /*��ջ�����*/
                    ;
                }
            }
            else if (nian < 1900 || nian > 2100)
                printf("��ݲ���ȷ������������\n");
            else if (yue < 0 || yue > 12)
                printf("�·ݲ���ȷ������������\n");
            else if (!right) {
                printf("�ղ���ȷ������������\n");
                right = 1;
            }
            
            continue;
        }

        if ((nian >= 1900 && nian <= 2100) && (yue > 0 && yue <= 12) && right) {
            break;
        }
    }/*������*/

    w = zeller(nian, yue, day);/*���ú������õ�����ֵ*/
    printf("����");
    switch (w)
    {
        case 0:
            printf("��\n");
            break;
        case 1:
            printf("һ\n");
            break;
        case 2:
            printf("��\n");
            break;
        case 3:
            printf("��\n");
            break;
        case 4:
            printf("��\n");
            break;
        case 5:
            printf("��\n");
            break;
        case 6:
            printf("��\n");
            break;
    }
    return 0;
}
