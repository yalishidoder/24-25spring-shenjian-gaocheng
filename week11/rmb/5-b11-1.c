/* 2351131 ��04 Τ��ó */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//�ɰ���������Ҫ��ͷ�ļ�

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
char result[256];  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int daxie(int num, int flag_of_zero,int length)
{
    if (num == 0) {
        if (!flag_of_zero)
        {
            result[length] = chnstr[0];
            result[length+1]=chnstr[1];
        }
        flag_of_zero++;
    }
    else
    {
        result[length] = chnstr[2 * num];
        result[length + 1] = chnstr[2 * num + 1];
    }
    return flag_of_zero;
}
int main()
{
    /* --���������Ҫ������ --*/
    double money;
    const char use[256] = "ʰ��Ǫ��ʰ��Բ�Ƿ���";
    int shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, yuan, jiao, fen;/* ��������Ҹ�λ����ֵ */
    int flag_of_zero[4] = { 0 };
    int length = 0;
    printf("������[0-100��)֮�������:\n") ;
    scanf("%lf", &money);

    while (money < 0 || money >= 10000000000) {
        printf("������[0-100��)֮�������:\n");
        scanf("%lf", &money);
        if (money >= 0 && money < 10000000000)
            break;
    }

    shiyi = (int)(money / 1000000000) % 10;
    yi = (int)(money / 100000000) % 10;
    qianwan = (int)(money / 10000000) % 10;
    baiwan = (int)(money / 1000000) % 10;
    shiwan = (int)(money / 100000) % 10;
    wan = (int)(money / 10000) % 10;
    qian = (int)(money / 1000) % 10;
    bai = (int)(money / 100) % 10;
    shi = (int)(money / 10) % 10;
    yuan = (int)((money / 10 - (int)(money / 10)) * 10 + 0.001) % 10;
    jiao = (int)((money / 10 - (int)(money / 10)) * 100 + 0.001) % 10;
    fen = (int)((money / 10 - (int)(money / 10)) * 1000 + 0.001) % 10;

    //ʮ�ں���λ
    flag_of_zero[0] = 1;
    flag_of_zero[0] = daxie(shiyi, flag_of_zero[0],length);
    if(shiyi)
        length += 2;

    if (shiyi)
    {
        result[length] = use[0];
        result[length+1] = use[1];
        length += 2;
    }
    flag_of_zero[0] = daxie(yi, flag_of_zero[0],length);
    if (yi)
        length += 2;
    

    if (flag_of_zero[0] != 3)
    {
        result[length] = use[2];
        result[length + 1] = use[3];
        length += 2;
    }

    //��
    if (flag_of_zero[0] != 1)
        flag_of_zero[1] = 1;
    if (qianwan && (shiwan || baiwan || wan))
        flag_of_zero[1] = 0;
    flag_of_zero[1] = daxie(qianwan, flag_of_zero[1],length);
    if (qianwan || (result[length] == chnstr[0] &&
        result[length + 1] == chnstr[1]))
        length += 2;

    if (qianwan)
    {
        result[length] = use[4];
        result[length + 1] = use[5];
        length += 2;
    }

    flag_of_zero[1] = daxie(baiwan, flag_of_zero[1], length);
    if (baiwan || (result[length] == chnstr[0] &&
        result[length + 1] == chnstr[1]))
        length += 2;
    if (baiwan)
    {
        result[length] = use[6];
        result[length + 1] = use[7];
        length += 2;
    }

    flag_of_zero[1] = daxie(shiwan, flag_of_zero[1], length);
    if (shiwan || (result[length] == chnstr[0] &&
        result[length + 1] == chnstr[1]))
        length += 2;
    if (shiwan)
    {
        result[length] = use[8];
        result[length + 1] = use[9];
        length += 2;
    }

    flag_of_zero[1] = daxie(wan, 1, length);
    if(wan)
        length += 2;
    if (qianwan || shiwan || baiwan || wan){
        result[length] = use[10];
        result[length + 1] = use[11];
        length += 2;
    }

    //ǧ����λ
    if (flag_of_zero[1] > 1)
        flag_of_zero[2] = 1;
    if (qian && (shi || bai || yuan))
        flag_of_zero[2] = 0;
    flag_of_zero[2] = daxie(qian, flag_of_zero[2], length);
    if (qian || (result[length] == chnstr[0] &&
        result[length + 1] == chnstr[1]))
        length += 2;

    if (qian)
    {
        result[length] = use[4];
        result[length + 1] = use[5];
        length += 2;
    }

    flag_of_zero[2] = daxie(bai, flag_of_zero[2], length);
    if (bai || (result[length] == chnstr[0] &&
        result[length + 1] == chnstr[1]))
        length += 2;

    if (bai)
    {
        result[length] = use[6];
        result[length + 1] = use[7];
        length += 2;
    }

    flag_of_zero[2] = daxie(shi, flag_of_zero[2], length);
    if (shi || (result[length] == chnstr[0] &&
        result[length + 1] == chnstr[1]))
        length += 2;
    if (shi)
    {
        result[length] = use[8];
        result[length + 1] = use[9];
        length += 2;
    }
    if (money < 1)
        flag_of_zero[2] = daxie(yuan, flag_of_zero[2], length);
    else
        flag_of_zero[2] = daxie(yuan, 1, length);
    length += 2;
 
    if (money == 0) {
        length = 0;
        result[length] = chnstr[0];
        result[length + 1] = chnstr[1];
        length += 2;
    }
    if (yuan || (shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi))
    {
        result[length] = use[12];
        result[length + 1] = use[13];
        length += 2;
    }
    else if (yuan >= 0 && !jiao && !fen)
    {
        result[length] = use[12];
        result[length + 1] = use[13];
        length += 2;
    }
    if (!jiao && yuan >= 0 && !fen){
        flag_of_zero[3] = 1;
    }
    flag_of_zero[3] = daxie(jiao, flag_of_zero[3], length);
    if (jiao|| (result[length] == chnstr[0] &&
        result[length + 1] == chnstr[1]))
        length += 2;
    if (jiao)
    {
        result[length] = use[14];
        result[length + 1] = use[15];
        length += 2;
    }
    if (fen)
    {
        flag_of_zero[3] = daxie(fen, flag_of_zero[3], length);
        length += 2;
        result[length] = use[16];
        result[length + 1] = use[17];
        length += 2;
    }
    else
    {
        result[length] = use[18];
        result[length + 1] = use[19];
        length += 2;
    }
    
    printf("��д�����:\n");
    printf("%s\n", result);  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
    return 0;
}