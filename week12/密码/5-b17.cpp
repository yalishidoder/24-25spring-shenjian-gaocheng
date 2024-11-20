/*2351131 信04 韦世贸*/
#include <iostream>
#include <cstdio>
#include <ctime>
#include <string>

using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?";
const int _max = 10;  //密码的数量
const int other_max = 15;
const int choice = 4;

void output(int len, char password[])  //输出密码
{
	int i;
	for (i = 0; i < len; i++) { 
		cout << password[i];
	}
	cout << endl;
}

void set_password(int len, int num[],int input_len)
{
	int i,x,j,k,l;
	char y;
	char password[16] = { 0 };
	int select = 0;

	srand((unsigned int)(time(0))); //生成种子

	for (k = 1; k <= _max; k++) {   //循环10次
		for (i = 0; i < len;) {
			for (j = 0; j < num[0];) {  //大写字母
				x = rand() % (len);
				if (password[x] == 0) {
					y = rand() % ('Z' - 'A' + 1) + 'A';
					password[x] = y;
					j++;
				}
			}
			i += num[0];

			for (j = 0; j < num[1];) {  //小写字母
				x = rand() % (len);
				if (password[x] == 0) {
					y = rand() % ('z' - 'a' + 1) + 'a';
					password[x] = y;
					j++;
				}
			}
			i += num[1];

			for (j = 0; j < num[2];) {  //数字
				x = rand() % (len);
				if (password[x] == 0) {
					y = rand() % ('9' - '0' + 1) + '0';
					password[x] = y;
					j++;
				}
			}
			i += num[2];

			for (j = 0; j < num[3];) {  //其他字符
				x = rand() % (len);
				if (password[x] == 0) {
					y = rand() % (other_max);
					password[x] = other[y];
					j++;
				}
			}
			i += num[3];

			if (i < len) {   //当长度不足时，随机补足
				for (; i < len; ) {
					x = rand() % (len);
					if (password[x] == 0) {
						select = rand() % (choice)+1;
						switch (select) {
							case 1:
								y = rand() % ('Z' - 'A' + 1) + 'A';
								password[x] = y;
								break;
							case 2:
								y = rand() % ('z' - 'a' + 1) + 'a';
								password[x] = y;
								break;
							case 3:
								y = rand() % ('9' - '0' + 1) + '0';
								password[x] = y;
								break;
							case 4:
								y = rand() % (other_max);
								password[x] = other[y];
								break;
						}
						i++;
					}
				}
			}
		}
		output(len, password);

		for (l = 0; l < len; l++)   //让密码数组归0
			password[l] = 0;
	}

}

void input() 
{
	int length = 0;
	int num[4] = { 0 };
	int i;
	int input_len = 0;

	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	cin >> length;
	if (cin.fail()) {
		cout << "输入非法" << endl;
		return;
	}
	else if (length < 12 || length>16) {
		cout << "密码长度[" << length << "]不正确" << endl;
		return;
	}
	for (i = 0; i < 4; i++) {
		cin >> num[i];
		if (cin.fail()) {
			cout << "输入非法" << endl;
			return;
		}
	}

	if (num[0] < 2 || num[0] > length) {
		cout << "大写字母个数[" << num[0] << "]不正确" << endl;
		return;
	}
	if (num[1] < 2 || num[1] > length) {
		cout << "小写字母个数[" << num[1] << "]不正确" << endl;
		return;
	}
	if (num[2] < 2 || num[2] > length) {
		cout << "数字个数[" << num[2] << "]不正确" << endl;
		return;
	}
	if (num[3] < 2 || num[3] > length) {
		cout << "其他符号个数[" << num[3] << "]不正确" << endl;
		return;
	}

	for (i = 0; i < 4; i++) {
		input_len += num[i];   //计算各个字符的长度总和
	}
	if (input_len > length) {
		cout << "所有字符类型之和[" << num[0] << "+" << num[1] << "+" << num[2] << "+" << num[3] << "]大于总密码长度[" << length << "]" << endl;
		return;
	}

	cout << length << " " << num[0] << " " << num[1] << " " << num[2] << " " << num[3] << endl;
	set_password(length, num, input_len);

}

int main()
{
	input();
	return 0;
}