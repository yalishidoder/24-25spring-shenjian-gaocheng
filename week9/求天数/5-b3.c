/* 2351131 ��04 Τ��ó */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int runnian(int nian) //�ж�����ĺ���
{
    int run = 0;
    if ((nian % 4 == 0 && nian % 100 != 0) || (nian % 400 == 0)) {
        run = !run;
    }
    return run;
}

int qiutianshu(int b,int ri,int run)//�������ĺ���
{
    int tianshu[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int i, day = 0;//�����������������
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
	int a, b, c, d;//�����ꡢ�¡����Լ�������������
    int run; //�ж�����ı���
	printf("�������꣬�£���\n");
	scanf("%d %d %d", &a, &b, &c);

    run = runnian(a);
    if (b <= 12 && b) {  //������
        
        if ((b % 2 && b <= 7) || (b >= 8 && b % 2 == 0)) {
            if (c > 31) {
                printf("�������-�����µĹ�ϵ�Ƿ�\n");
                return 0;
            }
         
        }
        if (b == 9 || b == 6 || b == 4 || b == 11) {
            if (c > 30) {
                printf("�������-�����µĹ�ϵ�Ƿ�\n");
                return 0;
            }
        }
        if (b == 2) {
            if (run) {
                if (c > 29) {
                    printf("�������-�����µĹ�ϵ�Ƿ�\n");
                    return 0;
                }
            }
            else {
                if (c > 28) {
                    printf("�������-�����µĹ�ϵ�Ƿ�\n");
                    return 0;
                }
            }
        }
    }
    else
    {
        printf("�������-�·ݲ���ȷ\n");
        return 0;
    }

    d = qiutianshu(b, c, run);
    printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c, a, d);

    return 0;
}