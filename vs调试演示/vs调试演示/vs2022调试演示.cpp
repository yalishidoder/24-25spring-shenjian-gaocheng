/*2351131 Τ��ó ��04 */
#include <iostream>

using namespace std;


void swap(double& a, double& b)
{
	double t;
	t = a;
	a = b;
	b = t;
}

double gap(double *grade)  //�β�
{
	static double gap;   //��̬�ֲ�����

	gap =  *grade;
	grade++;
	gap -= *grade;
	grade++;
	return gap;
}

int main()
{
	double grade[2] = { 0 };
	grade[0] = 5.0;
	grade[1] = 2.5;

	int num[2][1] = { 0 };
	int what[][2] = { 0 };

	double grade_gap,*p; //�Զ�����/�򵥱���
	p = &grade_gap;

	char abc[] ="tongji",*v;
	v = abc;
	for (; *v; v++) {
		cout << *v;
	}
	cout << endl;

	swap(grade[1], grade[0]);
	grade_gap = gap(grade);  //�Զ��庯��
	cout << *p;
	cout << sqrt(grade[1]) << endl; //ϵͳ����

	return 0;
}