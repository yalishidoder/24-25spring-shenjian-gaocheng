/* 2351131 ��04 Τ��ó */
#include <iostream>
#include <string>
using namespace std;

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
string result;  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int daxie(int num,  int flag_of_zero)
{
    if (num == 0) {
        if (!flag_of_zero)
        {
            result += chnstr[0];
            result += chnstr[1];
        }
        flag_of_zero++;
    }
    else
    {
        result += chnstr[2 * num];
        result += chnstr[2 * num + 1];
    }
    return flag_of_zero;
}
int main()
{
    /* --���������Ҫ������ --*/

    double money;
    int shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, yuan, jiao, fen;/* ��������Ҹ�λ����ֵ */
    int flag_of_zero[4] = { 0 };
    
    cout<<"������[0-100��)֮�������:"<<endl;
    cin >> money;

    while (money < 0 || money >= 10000000000) {
        cout<<"������[0-100��)֮�������:"<<endl;
        cin >> money;
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
    flag_of_zero[0] = daxie(shiyi, flag_of_zero[0]);

    if (shiyi)
    {
        result+= "ʰ";      
    }
    flag_of_zero[0] = daxie(yi, flag_of_zero[0]);

    if (flag_of_zero[0] != 3)
    {
        result += "��";
    }

    //��
    if (flag_of_zero[0] != 1)
        flag_of_zero[1] = 1;
    if (qianwan && (shiwan || baiwan || wan))
        flag_of_zero[1] = 0;
    flag_of_zero[1] = daxie(qianwan, flag_of_zero[1]);
    
    if (qianwan)
    {
        result += "Ǫ";
    }

    flag_of_zero[1] = daxie(baiwan, flag_of_zero[1]);
    if (baiwan)
    {
        result += "��";
    }

    flag_of_zero[1] = daxie(shiwan, flag_of_zero[1]);

    if (shiwan)
    {
        result += "ʰ";
    }

    flag_of_zero[1] = daxie(wan, 1);
    if (qianwan || shiwan || baiwan || wan)
        result += "��";

    //ǧ����λ
    if (flag_of_zero[1] > 1)
        flag_of_zero[2] = 1;
    if (qian && (shi || bai || yuan))
        flag_of_zero[2] = 0;
    flag_of_zero[2] = daxie(qian, flag_of_zero[2]);
    if (qian)
    {
        result+= "Ǫ";
    }

    flag_of_zero[2] = daxie(bai, flag_of_zero[2]);
 
    if (bai)
    {
        result += "��";
    }

    flag_of_zero[2] = daxie(shi, flag_of_zero[2]);
    if (shi)
    {
        result += "ʰ";
    }
    if(money<1)
        flag_of_zero[2] = daxie(yuan, flag_of_zero[2]);
    else
        flag_of_zero[2] = daxie(yuan, 1);
    if(money == 0){
        result += chnstr[0];
        result += chnstr[1];
    }
    if (yuan  || (shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi))
    {
        result+= "Բ";
    }
    else if(yuan >= 0 && !jiao && !fen)
        result += "Բ";
    if(!jiao && yuan>=0 && !fen)
        flag_of_zero[3] = 1;
    flag_of_zero[3] = daxie(jiao, flag_of_zero[3]);
    if (jiao)
    {
        result += "��";
    }
    if (fen)
    {
        flag_of_zero[3] = daxie(fen, flag_of_zero[3]);
        result += "��";
    }
    else
        result += "��";
    cout << "��д�����:" << endl;
    cout << result << endl;  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
    return 0;
}