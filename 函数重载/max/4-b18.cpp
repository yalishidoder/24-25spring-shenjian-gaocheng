/* 2351131 ��04 Τ��ó */
#include <iostream>
#include <cstdio>
using namespace std;

int max(int a1,int a2) 
{
	return(a1 > a2 ? a1 : a2);
}

int max(int a1, int a2, int a3)
{
	int bridge = a1 > a2 ? a1 : a2; /*����*/
	return(bridge > a3 ? bridge : a3);
}

int max(int a1, int a2, int a3, int a4)
{
	int bridge1 = a1 > a2 ? a1 : a2;
	int bridge2 = a3 > a4 ? a3 : a4;
	return(bridge1 > bridge2 ? bridge1 : bridge2);
}

int main()
{
	int geshu;
	int a1, a2, a3 = 0, a4 = 0;/*����δ��ʼ������*/
	while (1) {
		
		cout << "���������num��num����������" << endl;
		cin >> geshu;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(114514, '\n');
			continue;
		}

		if (geshu <= 1 || geshu > 4) {
			cout << "�����������" << endl;
			return 0;
		}
		
		if (geshu == 2) {
			cin >> a1 >> a2;
			if (cin.fail() || a1 < 0 || a2 < 0) {
				cin.clear();
				cin.ignore(114514, '\n');
				continue;/*����������������*/
			}
			else
				cout << "max=" << max(a1, a2) << endl;
			break;/*�˳�ѭ�����������*/
		}

		if (geshu == 3) {
			cin >> a1 >> a2 >> a3;
			if (cin.fail() || a1 < 0 || a2 < 0 || a3 < 0) {
				cin.clear();
				cin.ignore(114514, '\n');
				continue;
			}
			else
				cout << "max=" << max(a1, a2, a3) << endl;
			break;
		}

		if (geshu == 4) {
			cin >> a1 >> a2 >> a3 >> a4;
			if (cin.fail() || a1 < 0 || a2 < 0 || a3 < 0 || a4 < 0) {
				cin.clear();
				cin.ignore(114514, '\n');
				continue;
			}
			else
				cout << "max=" << max(a1, a2, a3, a4) << endl;
			break;
		}
		
	}
	
	return 0;
}