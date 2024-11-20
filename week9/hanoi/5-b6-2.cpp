/*2351131 ��04 Τ��ó*/
#include <iostream>
#include <iomanip>
using namespace std;

int jishu = 1;/*����*/
int top[3] = { 0 };//һά����
int zhu[3][10] = { 0 };//Բ�̶�ά����
/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�����������hanoi�ж���һ����̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */

void chushihua(int n, char src)//��������г�ʼ��
{
    int i;//�������
    if (src == 'A') {
        top[0] = n;
        for (i = 0; i <= top[0] && n > 0; i++) {

            zhu[0][i] = n;

            n--;
        }
    }

    if (src == 'B') {
        top[1] = n;
        for (i = 0; i <= top[1] && n > 0; i++) {

            zhu[1][i] = n;

            n--;
        }
    }
    if (src == 'C') {
        top[2] = n;
        for (i = 0; i <= top[2] && n > 0; i++) {

            zhu[2][i] = n;

            n--;
        }
    }

    //��ʼ��ӡ
    cout << "A:";

    for (i = 0; i < 10; i++) {
        if (zhu[0][i]) {
            cout << " " << zhu[0][i] ;
        }
        else {
            cout << "  ";
        }
    }

    cout<<"B:";

    for (i = 0; i < 10; i++) {
        if (zhu[1][i])
            cout << " " << zhu[1][i] ;
        else
            cout << "  ";
    }

    cout<<"C:";

    for (i = 0; i < 10; i++) {
        if (zhu[2][i])
            cout << " " << zhu[2][i] ;
        else
            cout << "  ";
    }
    cout << endl;
}

void crosswiseprint(int n, char src, char dst)  //�����ӡ����
{
    int i;//����ѭ����ӡ��Ҫ�ı���

    //��ջ����ջ
    //��Ϊ�����n�����ջԪ����ȣ����ԾͲ����ⶨ�����cunfang
    if (src == 'A') {
        zhu[0][--top[0]] = 0;//��ջ����0
        if (dst == 'B') {
            zhu[1][top[1]++] = n;
        }
        else if (dst == 'C') {
            zhu[2][top[2]++] = n;
        }
    }
    if (src == 'B') {
        zhu[1][--top[1]] = 0;
        if (dst == 'A') {
            zhu[0][top[0]++] = n;
        }
        else if (dst == 'C') {
            zhu[2][top[2]++] = n;
        }
    }
    if (src == 'C') {
        zhu[2][--top[2]] = 0;
        if (dst == 'A') {
            zhu[0][top[0]++] = n;
        }
        else if (dst == 'B') {
            zhu[1][top[1]++] = n;
        }
    }


    //�����Ǵ�ӡ����
    cout << "A:";

    for (i = 0; i < 10; i++) {
        if (zhu[0][i]) {
            cout << " " << zhu[0][i] ;
        }
        else {
            cout << "  ";
        }
    }

    cout << "B:";

    for (i = 0; i < 10; i++) {
        if (zhu[1][i])
            cout << " " << zhu[1][i] ;
        else
            cout << "  ";
    }

    cout << "C:";

    for (i = 0; i < 10; i++) {
        if (zhu[2][i])
            cout << " " << zhu[2][i] ;
        else
            cout << "  ";
    }
    cout << endl;
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
               3��������һ����̬�ֲ�����
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {/*�������*/
        cout <<"��" << setw(4) << jishu <<" ��" << "(" << setw(2) << n << "):" << " " << src << "-->" << dst << " ";
        crosswiseprint(n, src, dst);
        jishu++;
        /*��ʽ*/
    }

    else {/*��ʼ�ݹ�*/
        hanoi(n - 1, src, dst, tmp);
        cout << "��" << setw(4) << jishu << " ��" << "(" << setw(2) << n << "):" << " " << src << "-->" << dst << " ";
        crosswiseprint(n, src, dst);
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
    int ceng;/*����*/
    char qishi, mubiao;/*����������*/
    while (1) {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> ceng;   //����ceng�ķ�ʽ������ cin>>int�ͱ���
        if (cin.fail()) {
            cin.clear();
            cin.ignore(114514, '\n');
            continue;
        }
        if (ceng >= 0 && ceng <= 10) {
            ;
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
        cin.ignore(114514, '\n');
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
            cout << "Ŀ����(" << mubiao << ")��������ʼ��(" << qishi << ")��ͬ" << endl;

            continue;
        }


        if (mubiao == 'B' || mubiao == 'A' || mubiao == 'C') {
            break;
        }
        cin.ignore(114514, '\n');
    }

    char zhongjian;
    zhongjian = 'A' + 'B' + 'C' - qishi - mubiao;/*�������м����ͱȽϼ�*/

    cout << "��ʼ:                " ;

    chushihua(ceng, qishi);
    hanoi(ceng, qishi, zhongjian, mubiao);

    return 0;
}