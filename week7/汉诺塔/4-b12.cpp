/* 2351131 ��04 Τ��ó */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */

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
       
        cout << setw(2)<< n << "#" << " " << src << "-->" << dst << endl;/*��ʽ*/
    }
    else {/*��ʼ�ݹ�*/
        hanoi(n - 1, src, dst, tmp);
        cout << setw(2) << n << "#" << " " << src << "-->" << dst << endl;
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
    int ceng;/*����*/
    char qishi, mubiao;/*����������*/
    while (1) {
        cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
        cin >> ceng;   //����ceng�ķ�ʽ������ cin>>int�ͱ���
        if (cin.fail()) {
            cin.clear();
            cin.ignore(114514, '\n');
            continue;
        }
        if (ceng >= 0 && ceng <= 16) {;
            break;
        }
    }
    cin.ignore(114514, '\n');
    while (1) {
        cout << "��������ʼ��(A-C)" << endl;
        cin >> qishi;   //����qishi�ķ�ʽΪ�ַ�
       
        if (cin.fail()) {
            cin.clear();
            cin.ignore(114514, '\n');
            continue;
        }
        
        if (qishi == 'a' || qishi == 'b' || qishi == 'c') {/*��дת��*/
            qishi -= 32;
            break;
        }
        
        if (qishi == 'B' || qishi == 'A' || qishi == 'C') {
            
            break;
        }
        
    }
    cin.ignore(114514, '\n');
    while (1) {
        cout << "������Ŀ����(A-C)" << endl;
        cin >> mubiao;  //����mubiao�ķ�ʽΪ�ַ�
        if (cin.fail()) {
            cin.clear();
            cin.ignore(114514, '\n');
            continue;
        }

        if (mubiao == 'a' || mubiao == 'c' || mubiao == 'b') {
            mubiao -= 32;  /*���ﲻ���˳�ѭ������Ϊ���滹��һ���������*/
            
        }

        if (mubiao == qishi) { /*�����ظ������*/
            cout << "Ŀ����(" << mubiao << ")��������ʼ��(" << qishi <<")��ͬ"<< endl;
            
            continue;
        }


        if ( mubiao == 'B' || mubiao == 'A' || mubiao == 'C') {
            break;
        }

    }

    char zhongjian;
    zhongjian = 65 + 66 + 67 - qishi - mubiao;/*�������м����ͱȽϼ�*/

    cout << "�ƶ�����Ϊ:" << endl;

    hanoi(ceng, qishi, zhongjian, mubiao);
    
    return 0;
}