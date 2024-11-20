/* 学号 姓名 班级 */
#include <iostream>
using namespace std;

const int col = 28;
const int row = 12;
const int m_num = 50;

int main()
{
	int r_num = 0, right = 1;
	char r_landmines[row][col] = { 0 };
	char cin_landmines[row][col] = { 0 };
	int i, j, k, l;

	for (i = 1; i < row - 1; i++) {
		for (j = 1; j < col - 1; j++) {
			cin >> cin_landmines[i][j];

			if (cin_landmines[i][j] != '*' && (cin_landmines[i][j] > '9' || cin_landmines[i][j] < '0')) {
				cin.clear();
				cin.ignore(114514, '\n');
				continue;
			}

			if (cin_landmines[i][j] == '*') {
				r_landmines[i][j] = '*';
				r_num++;
			}
		}
	}

	for (i = 1; i < row - 1; i++) {
		for (j = 1; j < col - 1; j++) {
			if (r_landmines[i][j] != '*') {
				for (k = i - 1; k <= i + 1; k++) {
					for (l = j - 1; l <= j + 1; l++) {
						if (r_landmines[k][l] == '*')
							r_landmines[i][j]++;
					}
				}
			}
		}
	}

	for (i = 1; i < row - 1; i++) {
		for (j = 1; j < col - 1; j++) {
			if (r_landmines[i][j] != cin_landmines[i][j]) {
				right--;
				break;
			}
		}
	}

	if (r_num != m_num)
		cout << "错误1" << endl;
	else if (right != 1)
		cout << "错误2" << endl;
	else
		cout << "正确" << endl;
}