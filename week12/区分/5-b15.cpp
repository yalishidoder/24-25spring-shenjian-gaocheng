/*2351131 ��04 Τ��ó*/
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
	int len[3] = { 0 };  //��¼������ַ����ĳ���
	for (i = 0; i < A; i++) {
		cout << "�������" << i + 1 << "��" << endl;
		while (cin.get(c) && c != '\n' && length < B - 1) {
			line[i][length++] = c;
		}
		line[i][length] = '\0'; // ����ַ���������
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
	other = other - uppercase - lowercase - space - number;  //����Ҫ����д������¼�����ַ�������
	cout << "��д :" << uppercase << endl;
	cout << "Сд :" << lowercase << endl;
	cout << "���� :" << number << endl;
	cout << "�ո� :" << space << endl;
	cout << "���� :" << other << endl;
}