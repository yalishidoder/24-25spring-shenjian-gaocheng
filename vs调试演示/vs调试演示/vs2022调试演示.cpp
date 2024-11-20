/*2351131 韦世贸 信04 */
#include <iostream>

using namespace std;


void swap(double& a, double& b)
{
	double t;
	t = a;
	a = b;
	b = t;
}

double gap(double *grade)  //形参
{
	static double gap;   //静态局部变量

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

	double grade_gap,*p; //自动变量/简单变量
	p = &grade_gap;

	char abc[] ="tongji",*v;
	v = abc;
	for (; *v; v++) {
		cout << *v;
	}
	cout << endl;

	swap(grade[1], grade[0]);
	grade_gap = gap(grade);  //自定义函数
	cout << *p;
	cout << sqrt(grade[1]) << endl; //系统函数

	return 0;
}