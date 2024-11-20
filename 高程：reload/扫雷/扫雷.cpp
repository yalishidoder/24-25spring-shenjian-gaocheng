/* 学号 姓名 班级 */
#include <iostream>
using namespace std;

const int col = 28;
const int row = 12;
const int m_num = 50;

int main()
{
	srand((unsigned int)(time(0)));  //生成种子

	char landmines[row][col] = { 0 };
	int i, x, y, j, k, l;

	for (i = 0; i < m_num;) {
		x = rand() % (row - 2) + 1;
		y = rand() % (col - 2) + 1;
		if (landmines[x][y] == 0) {
			landmines[x][y] = '*';
			i++;
		}
	}

	for (i = 1; i < row - 1; i++) {
		for (j = 1; j < col - 1; j++) {
			if (landmines[i][j] != '*') {
				for (k = i - 1; k <= i + 1; k++) {
					for (l = j - 1; l <= j + 1; l++) {
						if (landmines[k][l] == '*')
							landmines[i][j]++;
					}
				}
			}
		}
	}

	for (i = 1; i < row - 1; i++) {
		for (j = 1; j < col - 1; j++) {
			if (landmines[i][j] != '*')
				cout << int(landmines[i][j]);
			else
				cout << landmines[i][j];
			cout << " ";
		}
		cout << endl;
	}
}