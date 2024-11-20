/*2351131 信04 韦世贸*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int shudu[9][9];//矩阵
	int crosswiseright, verticalright , gongright ;//三个判断条件
	int cross1, vertical1 ,gong1 ;//小的判断条件
	int i, j, k, l, m;//循环变量
	int gong[9] = { 0 }; //存放每个小九宫格中的数

	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			while (1) {    //输入处理
				cin >> shudu[i][j];
				//循环输入矩阵
				if (cin.fail()) {
					cin.clear();
					cin.ignore(114514, '\n');
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
					continue;
				}
				if (!shudu[i][j] || shudu[i][j] > 9) {
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
					continue;
				}
				else
					break;
			}
		}
	}
	
			
	//横向判断
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (shudu[i][j] != -1) {
				for (k = j + 1; k < 9; k++) {
					if (shudu[i][j] == shudu[i][k]) {
						cross1 = 0;
						crosswiseright = 0;
					}
					else
						cross1 = 1;
				}
			}
		}
		
	}
	if (cross1)
		crosswiseright = 1;

	for (i = 0; i < 9; i++) {  //垂直判断
		for (j = 0; j < 9; j++) {
			if (shudu[j][i] != -1) {
				for (k = j + 1; k < 9; k++) {
					if (shudu[j][i] == shudu[k][i]) {
						vertical1 = 0;
						verticalright = 0;
					}
					else
						vertical1 = 1;
				}
			}
		}


	}
	if (vertical1)
		verticalright = 1;

	for (i = 0; i < 9; i++) {
		k = 0;
		for (j = 0; j < 9; j++) {
			gong[k] = shudu[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3]; 
			//将九宫格中数的比对转换成一个一维数组的元素比对
			k++;
		}

		for (l = 0; l < 9; l++) {
			for (m = l + 1; m < 9; m++) {
				if (gong[l] == gong[m])
					gong1 = 0;
				else
					gong1 = 1;
			}
		}
	}

	if (gong1)
		gongright = 1;

	if (crosswiseright && verticalright && gongright)  //同时满足三个条件才是数独的解
		cout << "是数独的解" << endl;
	else
		cout << "不是数独的解" << endl;
}
