/* 2351131 信04 韦世贸 */
#include <iostream>
using namespace std;
int main()
{
    double a;
    int b, c, d, e, f, g, h, i, j, k, l;
    cout << "请输入找零值：" << endl;
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
    cout << "共" << b << "张找零，具体如下：" << endl;
    if (c > 0)
        cout << "50元 : " << c << "张" << endl;
    
    if (d > 0)
        cout << "20元 : " << d << "张" << endl;
   
    if (e > 0)
        cout << "10元 : " << e << "张" << endl;
   
    if (f > 0)
        cout << "5元  : " << f << "张" << endl;
   
    if (g > 0)
        cout << "1元  : " << g << "张" << endl;
   
    if (h > 0)
        cout << "5角  : " << h << "张" << endl;

    if (i > 0)
        cout << "1角  : " << i<< "张" << endl;

    if (j > 0)
        cout << "5分  : " << j << "张" << endl;

    if (k > 0)
        cout << "2分  : " << k << "张" << endl;

    if (l > 0)
        cout << "1分  : " << l << "张" << endl;

    return 0;
}