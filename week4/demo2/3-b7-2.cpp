/* 2351131 ��04 Τ��ó */
#include <iostream>
using namespace std;
int main()
{
    double a;
    int b, c, d, e, f, g, h, i, j, k, l;
    cout << "����������ֵ��" << endl;
    cin >> a;
    c = int(a / 50);
    d = int(a) % 50 / 20;
    e = int(a) % 50 % 20 / 10;
    f = int(a) % 50 % 20 % 10 / 5;
    g = int(a) % 50 % 20 % 10 % 5 / 1;
    h = int((a - int(a)) * 10 + 0.001) / 5;
    i = int((a - int(a)) * 10 + 0.001) % 5 / 1;
    j = int((a - int(a)) * 100 + 0.001) % 10 / 5;
    k = int((a - int(a)) * 100 + 0.001) % 10 % 5 / 2;
    l = int((a - int(a)) * 100 + 0.001) % 10 % 5 % 2 / 1;
    b = c + d + e + f + g + h + i + j + k + l;
    cout << "��" << b << "�����㣬�������£�" << endl;
    if (c > 0)
        cout << "50Ԫ : " << c << "��" << endl;
    
    if (d > 0)
        cout << "20Ԫ : " << d << "��" << endl;
   
    if (e > 0)
        cout << "10Ԫ : " << e << "��" << endl;
   
    if (f > 0)
        cout << "5Ԫ  : " << f << "��" << endl;
   
    if (g > 0)
        cout << "1Ԫ  : " << g << "��" << endl;
   
    if (h > 0)
        cout << "5��  : " << h << "��" << endl;

    if (i > 0)
        cout << "1��  : " << i<< "��" << endl;

    if (j > 0)
        cout << "5��  : " << j << "��" << endl;

    if (k > 0)
        cout << "2��  : " << k << "��" << endl;

    if (l > 0)
        cout << "1��  : " << l << "��" << endl;

    return 0;
}