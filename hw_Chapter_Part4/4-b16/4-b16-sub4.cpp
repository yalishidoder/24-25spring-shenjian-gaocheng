/* 2351131 ��04 Τ��ó */
#include <iostream>
#include <cmath>
using namespace std;

void situation4(double delta, double a, double b)
{
	double shibu, xubu; /*ʵ���鲿�ֿ���*/
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
	cout << "i" << endl;
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