/* 2351131 ��04 Τ��ó */
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;
int main()
{
	int nian, yue, date,day;
	cout << "���������(2000-2030)���·�(1-12) : ";
	cin >> nian >> yue;
	while (cin.fail())  {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "����Ƿ�������������" << endl;
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> nian>> yue;
	}
	while ((nian < 2000 || nian >2030) || (yue < 1 || yue >12)) { /*����while��Ϊ��ʹ�������demo���߼�*/
		cin.clear();
		cin.ignore((nian < 2000 || nian >2030) || (yue < 1 || yue >12));
		cout << "����Ƿ�������������" << endl;
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> nian >> yue;
	}
	cout << "������" << nian << "��" << yue << "��1�յ�����(0-6��ʾ������-������) : ";
	cin >> date;
	while (cin.fail() || date < 0 || date > 6) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "����Ƿ�������������" << endl;
		cout << "������" << nian << "��" << yue << "��1�յ�����(0-6��ʾ������-������) : ";
		cin >> date;
		cout << endl;
	}
	cout << endl;
	cout << nian << "��" << yue << "�µ�����Ϊ:" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;

	if ((yue % 2 && yue <= 7) || (yue >= 8 && yue % 2 == 0)) {  /*����*/
		for (day = 1; day <= 31 + date; day++) {
			if(day > date)
				cout << setw(4) << day - date <<"    ";  /*�ո��ж�*/
			else 
				cout <<"        ";
			if (day % 7 == 0)  /*�����Ļ���˼·�Ƚϼ򵥣�Ҳ����Ҫ���¶������*/
				cout << endl;
			else;
			
		}
	}

	if (yue==9 || yue == 6 || yue == 4 ||yue==11) { /*С��*/
		for (day = 1; day <= 30 + date; day++) {
			if (day > date)
				cout << setw(4) << day - date << "    ";  
			else
				cout << "        ";
			if (day % 7 == 0)  
				cout << endl;
			else;
		}
	}

	if (yue==2) {
		if ((nian % 4 == 0 && nian % 100 != 0) || (nian % 400 == 0)) { /*����*/
			for (day = 1; day <= 29 + date; day++) {
				if (day > date)
					cout << setw(4) << day - date << "    ";
				else
					cout << "        ";
				if (day % 7 == 0)
					cout << endl;
				else;

			}
		}
		else {
			for (day = 1; day <= 28 + date; day++) {
				if (day > date)
					cout << setw(4) << day - date << "    ";
				else
					cout << "        ";
				if (day % 7 == 0)
					cout << endl;
				else;

			}
		}
	}
	cout << endl;
	return 0;
}