/* 2351131 ��04 Τ��ó */
#include <iostream>
#include <cmath>
using namespace std;

void situation3(double a, double b) /*�б�ʽΪ0����������β�ȥ��*/
{
	double x1;
	x1 = (-b) / 2 / a;

	if (fabs(x1) < 1e-6)
		x1 = 0;

	cout << "���������ʵ����" << endl;
	cout << "x1=x2=" << x1 << endl;

}