/* 2351131 ��04 Τ��ó */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2��������һ��ȫ�ֱ������������徲̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */

int jishu = 0; /*ȫ�ֱ�������*/
   /***************************************************************************
     �������ƣ�
     ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
     ���������int n������
               char src����ʼ��
               char tmp���м���
               char dst��Ŀ����
     �� �� ֵ��
     ˵    ����1�����������βΡ��������;���׼��
               2������������������κ���ʽ��ѭ��
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {/*�������*/
        printf("%5d",++jishu);
        printf(" :%3d# %c-->%c\n", n, src, dst);
        
        /*��ʽ*/
    }
    else {/*��ʼ�ݹ�*/
        hanoi(n - 1, src, dst, tmp);
        printf("%5d", ++jishu);
        printf(" :%3d# %c-->%c\n",  n, src, dst);
    
        hanoi(n - 1, tmp, src, dst);
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
            2�������������ʱ������ʹ��ѭ��
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
    int ceng,ret1,ret2,ret3;/*����*/
    char qishi, mubiao;/*����������*/
    while (1) {
        printf("�����뺺ŵ���Ĳ���(1-16)\n") ;
        ret1=scanf("%d", &ceng);   //����ceng�ķ�ʽ������ cin>>int�ͱ���
        if (ret1 != 1) {
            while (getchar() != '\n')
            continue;
        }
        if (ceng >= 0 && ceng <= 16) {
            ;
            break;
        }
    }
    while (getchar() != '\n');
    while (1) {
        printf("��������ʼ��(A-C)\n");
        ret2 = scanf("%c", &qishi);  //����qishi�ķ�ʽΪ�ַ�

        if (ret2 != 1) { 
             while (getchar() != '\n')
            continue;
        }

        if (qishi == 'a' || qishi == 'b' || qishi == 'c') {/*��дת��*/
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
        printf ("������Ŀ����(A-C)\n");
        ret3 = scanf("%c", &mubiao);  //����mubiao�ķ�ʽΪ�ַ�
        if (ret3 != 1 ) {
             while (getchar() != '\n')
            continue;
        }

        if (mubiao == 'a' || mubiao == 'c' || mubiao == 'b') {
            mubiao -= 32;  /*���ﲻ���˳�ѭ������Ϊ���滹��һ���������*/

        }

        if (mubiao == qishi) { /*�����ظ������*/
            printf( "Ŀ����(%c)��������ʼ��(%c)��ͬ\n", mubiao, qishi);

            continue;
        }


        if (mubiao == 'B' || mubiao == 'A' || mubiao == 'C') {
            break;
        }
        while (getchar() != '\n');
    }

    char zhongjian;
    zhongjian = 'A' + 'B' + 'C' - qishi - mubiao;/*�������м����ͱȽϼ�*/

    printf( "�ƶ�����Ϊ:\n" );

    hanoi(ceng, qishi, zhongjian, mubiao);

    return 0;
}