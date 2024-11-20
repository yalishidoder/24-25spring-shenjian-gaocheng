/*2351131 信04 韦世贸*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int A = 3;
const int B = 128;
int upper( char str[][128], int len[])
{
	int up = 0, j = 0, i = 0;
	for (i = 0; i < A; i++) {
		for (j = 0; j < len[i]; j++) {
			if (str[i][j] >= 'A' && str[i][j] <= 'Z')
				up++;
		}
	}
	return up;
}
int lower(char str[][128], int len[])
{
	int low = 0, j = 0, i = 0;
	for (i = 0; i < A; i++) {
		for (j = 0; j < len[i]; j++) {
			if (str[i][j] >= 'a' && str[i][j] <= 'z')
				low++;
		}
	}
	return low;
}
int sp(char str[][128], int len[])
{
	int space = 0, j = 0, i = 0;
	for (i = 0; i < A; i++) {
		for (j = 0; j < len[i]; j++) {
			if (str[i][j] == ' ')
				space++;
		}
	}
	return space;
}
int num(char str[][128], int len[])
{
	int num = 0, j = 0, i = 0;
	for (i = 0; i < A; i++) {
		for (j = 0; j < len[i]; j++) {
			if (str[i][j] >= '0' && str[i][j] <= '9')
				num++;
		}
	}
	return num;
}
int main()
{
	char  line[A][B] = { 0 };
	char c;
	int uppercase = 0, lowercase = 0, space = 0, number = 0, other = 0;
	int i, length = 0;
	int len[3] = { 0 };  //记录输入的字符串的长度
	for (i = 0; i < A; i++) {
		cout << "请输入第" << i + 1 << "行" << endl;
		while (cin.get(c) && c != '\n' && length < B - 1) {
			line[i][length++] = c;
		}
		line[i][length] = '\0'; // 添加字符串结束符
		len[i] = length;
		length = 0;
	}

	uppercase += upper(line, len);

	lowercase += lower(line, len);

	space += sp(line, len);

	number += num(line, len);
	
	for (i = 0; i < A; i++) {
		other += len[i];
	}
	other = other - uppercase - lowercase - space - number;  //不需要额外写函数记录其他字符的数量
	cout << "大写 :" << uppercase << endl;
	cout << "小写 :" << lowercase << endl;
	cout << "数字 :" << number << endl;
	cout << "空格 :" << space << endl;
	cout << "其它 :" << other << endl;
}