/* 2351131 信04 韦世贸 */
#include <iostream>
#include <cmath>
using namespace std;

void situation1()
{
	cout << "不是一元二次方程" << endl;
}

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

	cout << "有两个不等实根：" << endl;
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
}

void situation3(double a, double b) /*判别式为0，所以这个形参去掉*/
{
	double x1;
	x1 = (-b) / 2 / a;

	if (fabs(x1) < 1e-6)
		x1 = 0;

	cout << "有两个相等实根：" << endl;
	cout << "x1=x2=" << x1 << endl;

}

void situation4(double delta, double a, double b)
{
	double shibu, xubu; /*实部虚部分开求*/
	shibu = -b / 2 / a;
	xubu = delta / 2 / a;

	if (fabs(shibu) < 1e-6)
		shibu = 0;
	if (fabs(xubu) < 1e-6)
		xubu = 0;

	cout << "有两个虚根：" << endl;

	/*x1*/
	cout << "x1=";
	if (shibu)   /*实部为0*/
		cout << shibu << "+";
	else;  /*不输出*/
	if (xubu == 1 || xubu == -1)  /*+-i的特殊情况*/
		cout << "";  /*不输出*/
	else
		cout << fabs(xubu);
	cout << "i" << endl;
	/*x2*/
	cout << "x2=";
	if (shibu)   /*实部为0*/
		cout << shibu;
	else;
	cout << "-";
	if (xubu == 1 || xubu == -1)  /*+-i的特殊情况*/
		cout << "";   /*不输出*/
	else
		cout << fabs(xubu);
	cout << "i" << endl;
}