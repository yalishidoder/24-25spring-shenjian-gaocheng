/* 2351131 ��04 Τ��ó */
#include <iostream>
#include <cmath>
using namespace std;

void situation1();

void situation2(double delta, double a, double b);

void situation3(double a, double b);

void situation4(double delta, double a, double b);

int main()
{
	double a, b, c;
	cout << "������һԪ���η��̵�����ϵ��a,b,c:" << endl;
	cin >> a >> b >> c;
	if (fabs(a) < 1e-6)
		a = 0;
	if (fabs(b) < 1e-6)
		b = 0;
	if (fabs(c) < 1e-6)
		c = 0;

	double del = b * b - 4 * a * c;/*�б�ʽ*/

	if (fabs(del) < 1e-6)
		del = 0;

	if (a == 0)
		situation1();

	else if (del > 0) {
		double delta = sqrt(del);

		if (fabs(delta) < 1e-6)
			delta = 0;

		situation2(delta, a, b);
	}
	else if (del == 0) {
		situation3(a, b);
	}
	else {
		double delta = sqrt(-del);/*�Ӹ���*/

		if (fabs(delta) < 1e-6)
			delta = 0;

		situation4(delta, a, b);
	}
	return 0;
}