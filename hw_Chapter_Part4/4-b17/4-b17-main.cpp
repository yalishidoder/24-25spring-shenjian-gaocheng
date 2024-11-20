/* 2351131 信04 韦世贸 */
#include <iostream>
#include <cmath>
using namespace std;
double a, b, c;


void situation1();

void situation2();

void situation3();

void situation4();

int main()
{
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin >> a >> b >> c;
	if (fabs(a) < 1e-6)
		a = 0;
	if (fabs(b) < 1e-6)
		b = 0;
	if (fabs(c) < 1e-6)
		c = 0;

	double del;/*判别式*/
	del = b * b - 4 * a * c;

	if (fabs(del) < 1e-6)
		del = 0;

	if (a == 0)
		situation1();

	else if (del > 0) { 
		situation2();
	}
	else if (del == 0) {
		situation3();
	}
	else {
		situation4();
	}
	return 0;
}