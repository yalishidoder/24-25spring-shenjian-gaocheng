/*2351131 ��04 Τ��ó*/
#include <iostream>
using namespace std;

int main()
{
	int shu[20] = { 0 };//����
	int i, j, t;//������Ҫ�ı���
	int count = 0;
	cout << "��������������������������20������0������������" << endl;
	for (i = 0; i < 20; ++i) {
		cin >> shu[i];
		if (!shu[0]) {
			cout << "����Ч����" << endl;
			return 0;
		}
	    if (!shu[i] && i>0) {
			break;
		}
		count++;
	}
	cin.ignore(114514, '\n');

	cout << "ԭ����Ϊ��" << endl;

	for (i = 0; i < count; i++) {
		cout << shu[i] << " ";
	}
	cout << endl;

	cout << "������Ҫ�����������" << endl;
 	cin >> shu[count];

	for (i = 0; i < count+1; i++) {//ð������
		for (j = 0; j < count + 2 - (i + 1); j++) {
			if (shu[j] > shu[j + 1]) {
				t = shu[j];
				shu[j] = shu[j + 1];
				shu[j + 1] = t;
			}
		}
	}

	cout << "����������Ϊ��" << endl;
	for (i = 0; i < count + 2; i++) {
		if(shu[i])
			cout << shu[i] << " ";
	}
	cout << endl;
	return 0;
}