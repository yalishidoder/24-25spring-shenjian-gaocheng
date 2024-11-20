/* 2351131 信04 韦世贸 */
#include <iostream>
#include <cmath>
using namespace std;

void situation3(double a, double b) /*判别式为0，所以这个形参去掉*/
{
	double x1;
	x1 = (-b) / 2 / a;

	if (fabs(x1) < 1e-6)
		x1 = 0;

	cout << "有两个相等实根：" << endl;
	cout << "x1=x2=" << x1 << endl;

}