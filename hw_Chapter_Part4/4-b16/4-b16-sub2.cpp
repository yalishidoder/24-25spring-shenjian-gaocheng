/* 2351131 ��04 Τ��ó */
#include <iostream>
#include <cmath>
using namespace std;

void situation2(double delta, double a, double b)
{
	double x1, x2;
	double zuo = -b / 2 / a;
	double you = delta / 2 / a;

	if (fabs(zuo) < 1e-6)
		zuo = 0;
	if (fabs(you) < 1e-6)
		you = 0;

	x1 = zuo + you;
	x2 = zuo - you;

	if (fabs(x1) < 1e-6)
		x1 = 0;
	if (fabs(x2) < 1e-6)
		x2 = 0;

	cout << "����������ʵ����" << endl;
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
}