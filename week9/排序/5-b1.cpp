/*2351131 信04 韦世贸*/
#include <iostream>
using namespace std;

int main()
{
	int shu[20] = { 0 };//数组
	int i, j, t;//数组需要的变量
	int count = 0;
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	for (i = 0; i < 20; ++i) {
		cin >> shu[i];
		if (!shu[0]) {
			cout << "无有效输入" << endl;
			return 0;
		}
	    if (!shu[i] && i>0) {
			break;
		}
		count++;
	}
	cin.ignore(114514, '\n');

	cout << "原数组为：" << endl;

	for (i = 0; i < count; i++) {
		cout << shu[i] << " ";
	}
	cout << endl;

	cout << "请输入要插入的正整数" << endl;
 	cin >> shu[count];

	for (i = 0; i < count+1; i++) {//冒泡排序
		for (j = 0; j < count + 2 - (i + 1); j++) {
			if (shu[j] > shu[j + 1]) {
				t = shu[j];
				shu[j] = shu[j + 1];
				shu[j + 1] = t;
			}
		}
	}

	cout << "插入后的数组为：" << endl;
	for (i = 0; i < count + 2; i++) {
		if(shu[i])
			cout << shu[i] << " ";
	}
	cout << endl;
	return 0;
}