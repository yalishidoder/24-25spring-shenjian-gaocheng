/* 2351131 信04 韦世贸 */
#include <iostream>
#include <cstdio>
using namespace std;

int min(int a1, int a2, int a3 = INT_MAX, int a4 = INT_MAX)
/*即使不输入a3,a4，默认参数也不会影响程序正确性*/
{
	int bridge1 = a1 < a2 ? a1 : a2;
	int bridge2 = a3 < a4 ? a3 : a4;
	return(bridge1 < bridge2 ? bridge1 : bridge2);
}

int main()
{
	int geshu;
	int a1, a2, a3 = 0, a4 = 0;/*避免未初始化问题*/
	while (1) {

		cout << "请输入个数num及num个正整数：" << endl;
		cin >> geshu;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(114514, '\n');
			continue;
		}

		if (geshu <= 1 || geshu > 4) {
			cout << "个数输入错误" << endl;
			return 0;
		}

		if (geshu == 2) {
			cin >> a1 >> a2;
			if (cin.fail() || a1 < 0 || a2 < 0) {
				cin.clear();
				cin.ignore(114514, '\n');
				continue;/*后续出错，重新输入*/
			}
			else
				cout << "min=" << min(a1, a2) << endl;
			break;/*退出循环，程序结束*/
		}

		if (geshu == 3) {
			cin >> a1 >> a2 >> a3;
			if (cin.fail() || a1 < 0 || a2 < 0 || a3 < 0) {
				cin.clear();
				cin.ignore(114514, '\n');
				continue;
			}
			else
				cout << "min=" << min(a1, a2, a3) << endl;
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
				cout << "min=" << min(a1, a2, a3, a4) << endl;
			break;
		}

	}

	return 0;
}