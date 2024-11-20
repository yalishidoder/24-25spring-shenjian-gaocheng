/* 2351131 信04 韦世贸 */
#include <iostream>
#include <cmath>
using namespace std;

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