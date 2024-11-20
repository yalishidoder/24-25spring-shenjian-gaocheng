/* 2351131 ��04 Τ��ó */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2��������һ��ȫ�ֱ������������徲̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */

int jishu = 1; /*ȫ�ֱ�������*/
int azhu[10] = { 0 }, bzhu[10] = { 0 }, czhu[10] = { 0 };//��¼Բ�̺ͱ�ŵ�����
int atop, btop, ctop;//����ջ��ָ��


void chushihua(int n,char src)//��������г�ʼ��
{
    int i;//�������
    if (src == 'A') {
        atop = n ;
        for (i = 0; i <= atop && n > 0; i++) {
            
                azhu[i] = n;
            
            n--;
        }
    }
    
    if (src == 'B') {
        btop = n ;
        for (i = 0; i <= btop && n > 0; i++) {

            bzhu[i] = n;

            n--;
        }
    }
    if (src == 'C') {
        ctop = n ;
        for (i = 0; i <= ctop && n > 0; i++) {

            czhu[i] = n;

            n--;
        }
    }
    
   //��ʼ��ӡ
    printf("A:");

    for (i = 0; i < 10; i++) {
        if (azhu[i]) {
            printf(" %d", azhu[i]);
        }
        else {
            printf("  ");
        }
    }

    printf("B:");

    for (i = 0; i < 10; i++) {
        if (bzhu[i])
            printf(" %d", bzhu[i]);
        else
            printf("  ");
    }

    printf("C:");

    for (i = 0; i < 10; i++) {
        if (czhu[i])
            printf(" %d", czhu[i]);
        else
            printf("  ");
    }
    printf("\n");
}
void crosswiseprint(int n,char src,char dst)  //�����ӡ����
{
    int i;//����ѭ����ӡ��Ҫ�ı���
   
    //��ջ����ջ
    //��Ϊ�����n�����ջԪ����ȣ����ԾͲ����ⶨ�����cunfang
        if (src=='A') {
            azhu[--atop] = 0;//��ջ����0
            if (dst == 'B') {
                bzhu[btop++] = n;
            }
            else if (dst == 'C') {
                czhu[ctop++] = n;
            }
        }
        if(src=='B') {
            bzhu[--btop] = 0;
            if (dst == 'A') {
                azhu[atop++] = n;
            }
            else if (dst == 'C') {
                czhu[ctop++] = n;
            }
        }
        if(src=='C') {
            czhu[--ctop] = 0;
            if (dst == 'A') {
                azhu[atop++] = n;
            }
            else if (dst == 'B') {
                bzhu[btop++] = n;
            }
        }
        

    //�����Ǵ�ӡ����
    printf("A:");

    for (i = 0; i < 10; i++) {
        if (azhu[i]) {
            printf(" %d", azhu[i]);
        }
        else {
            printf("  ");
        }
    }

    printf("B:");

    for (i = 0; i < 10; i++) {
        if (bzhu[i])
            printf(" %d", bzhu[i]);
        else
            printf("  ");
    }

    printf("C:");

    for (i = 0; i < 10; i++) {
        if (czhu[i])
            printf(" %d", czhu[i]);
        else
            printf("  ");
    }
    printf("\n");
   
}
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
        printf("��%4d ��(%2d): %c-->%c ", jishu, n, src, dst);
        crosswiseprint(n, src,dst);
        jishu++;
        /*��ʽ*/
    }
    else {/*��ʼ�ݹ�*/
        hanoi(n - 1, src, dst, tmp);
        printf("��%4d ��(%2d): %c-->%c ", jishu, n, src, dst);
        crosswiseprint(n, src,dst);
        jishu++;
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
    int ceng, ret1, ret2, ret3;/*����*/
    char qishi, mubiao;/*����������*/
    while (1) {
        printf("�����뺺ŵ���Ĳ���(1-10)\n");
        ret1 = scanf("%d", &ceng);   //����ceng�ķ�ʽ������ cin>>int�ͱ���
        if (ret1 != 1) {
            while (getchar() != '\n')
                continue;
        }
        if (ceng >= 0 && ceng <= 10) {
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
        printf("������Ŀ����(A-C)\n");
        ret3 = scanf("%c", &mubiao);  //����mubiao�ķ�ʽΪ�ַ�
        if (ret3 != 1) {
            while (getchar() != '\n')
                continue;
        }

        if (mubiao == 'a' || mubiao == 'c' || mubiao == 'b') {
            mubiao -= 32;  /*���ﲻ���˳�ѭ������Ϊ���滹��һ���������*/

        }

        if (mubiao == qishi) { /*�����ظ������*/
            printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n", mubiao, qishi);

            continue;
        }


        if (mubiao == 'B' || mubiao == 'A' || mubiao == 'C') {
            break;
        }
        while (getchar() != '\n');
    }

    char zhongjian;
    zhongjian = 'A' + 'B' + 'C' - qishi - mubiao;/*�������м����ͱȽϼ�*/

    printf("��ʼ:                ");

    chushihua(ceng, qishi);
    hanoi(ceng, qishi, zhongjian, mubiao);

    return 0;
}