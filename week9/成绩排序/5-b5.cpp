/*2351131 信04 韦世贸*/
#include <iostream>
using namespace std;
int main()
{
	int chengji[1000] = { 0 };
	int i, j, t, count1, count = 0;//数组变量和计数变量
	int count2 = 1;
	cout << "请输入成绩（最多1000个），负数结束输入" << endl;
	for (i = 0; i < 1000; ++i) {
		cin >> chengji[i];
		if (chengji[0] < 0) {
			cout << "无有效输入" << endl;
			return 0;
		}

		if (chengji[i] < 0 && i > 0) {
			break;
		}
		count++;
	}
	cin.ignore(114514, '\n');

	cout << "输入的数组为:" << endl;

	for (i = 0; i < count && chengji[i] <= 100; i++) {
		cout << chengji[i]<<" ";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}

	cout << endl;

	cout << "分数与名次的对应关系为:" << endl;

	for (i = 0; i < count; i++) {//冒泡排序
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