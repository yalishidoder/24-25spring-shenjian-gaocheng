/* 2351131 ��04 Τ��ó */
#include <iostream>
#include <cmath>
using namespace std;

void situation1()
{
	cout << "����һԪ���η���" << endl;
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

	cout << "����������ʵ����" << endl;
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
}

void situation3(double a,double b) /*�б�ʽΪ0����������β�ȥ��*/
{
	double x1;
	x1 = (-b) / 2 / a;

	if (fabs(x1) < 1e-6)
		x1 = 0;

	cout << "���������ʵ����" << endl;
	cout << "x1=x2=" << x1 << endl;
	
}

void situation4(double delta, double a, double b)
{
	double shibu,xubu; /*ʵ���鲿�ֿ���*/
	shibu = -b / 2 / a;
	xubu = delta / 2 / a;

	if (fabs(shibu) < 1e-6)
		shibu = 0;
	if (fabs(xubu) < 1e-6)
		xubu = 0;

	cout << "�����������" << endl;

	/*x1*/
	cout << "x1=";
	if (shibu)   /*ʵ��Ϊ0*/
		cout << shibu << "+";
	else;  /*�����*/
	if (xubu == 1 || xubu == -1)  /*+-i���������*/
		cout << "";  /*�����*/
	else
		cout << fabs(xubu);
	cout<< "i" << endl;
	/*x2*/
	cout << "x2=";
	if (shibu)   /*ʵ��Ϊ0*/
		cout << shibu;
	else;
	cout << "-";
	if (xubu == 1 || xubu == -1)  /*+-i���������*/
		cout << "";   /*�����*/
	else
		cout << fabs(xubu);
	cout << "i" << endl;
}

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