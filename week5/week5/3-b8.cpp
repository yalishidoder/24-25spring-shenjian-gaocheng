/* 2351131 ��04 Τ��ó */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int x;
	double b = 0, c = 1, t = 1;/*b����������c�ǽ׳˵�ÿһ�tΪչ��ÿһ���ֵ*/
	cout << "������x��ֵ[-10 ~ +65]" << endl;
	cin >> x;

	while (!(x>=-10&&x<=65))
	{
		cout << "����Ƿ�������������" << endl;
		cout << "������x��ֵ[-10 ~ +65]" << endl;
		cin >> x;
	}

	while (fabs(t) > 1e-6)
	{
		for (c = 1; fabs(t) > 1e-6; ++c) /*��c����һ��ѭ�����Ͳ���Ҫ���ⶨ��������н׳˼���*/
		{
			b = b + t;
			t = double( t * x / c);
		}
	}

	cout <<  setprecision(10) << "e^" << x << "=" << b << endl;

	return 0;
}