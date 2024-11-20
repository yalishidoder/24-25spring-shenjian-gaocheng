/* 2351131 信04 韦世贸 */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int x;
	double b = 0, c = 1, t = 1;/*b是输出结果，c是阶乘的每一项，t为展开每一项的值*/
	cout << "请输入x的值[-10 ~ +65]" << endl;
	cin >> x;

	while (!(x>=-10&&x<=65))
	{
		cout << "输入非法，请重新输入" << endl;
		cout << "请输入x的值[-10 ~ +65]" << endl;
		cin >> x;
	}

	while (fabs(t) > 1e-6)
	{
		for (c = 1; fabs(t) > 1e-6; ++c) /*对c进行一个循环，就不需要另外定义变量进行阶乘计算*/
		{
			b = b + t;
			t = double( t * x / c);
		}
	}

	cout <<  setprecision(10) << "e^" << x << "=" << b << endl;

	return 0;
}