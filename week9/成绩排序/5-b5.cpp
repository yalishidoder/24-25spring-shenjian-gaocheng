/*2351131 ��04 Τ��ó*/
#include <iostream>
using namespace std;
int main()
{
	int chengji[1000] = { 0 };
	int i, j, t, count1, count = 0;//��������ͼ�������
	int count2 = 1;
	cout << "������ɼ������1000������������������" << endl;
	for (i = 0; i < 1000; ++i) {
		cin >> chengji[i];
		if (chengji[0] < 0) {
			cout << "����Ч����" << endl;
			return 0;
		}

		if (chengji[i] < 0 && i > 0) {
			break;
		}
		count++;
	}
	cin.ignore(114514, '\n');

	cout << "���������Ϊ:" << endl;

	for (i = 0; i < count && chengji[i] <= 100; i++) {
		cout << chengji[i]<<" ";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}

	cout << endl;

	cout << "���������εĶ�Ӧ��ϵΪ:" << endl;

	for (i = 0; i < count; i++) {//ð������
		for (j = 0; j < count - (i + 1); j++) {
			if (chengji[j] < chengji[j + 1]) {
				t = chengji[j];
				chengji[j] = chengji[j + 1];
				chengji[j + 1] = t;
			}
		}
	}

	for (i = 0; i < count; i++) {
		count1 = count;
		count2 = 1;
		if (chengji[i] != -1) {
			for (j = i + 1; j < count; j++) {
				if (chengji[i] == chengji[j]) {
					count2++;
					chengji[j] = -1;
					count1--;
				}
				else {
					count1--;
				}
			}
			for (t = 1; t <= count2; ++t) {
				cout << chengji[i] << " " << count1 << endl;
			}
		}
	}
	return 0;
}