/* 2351131 ��04 Τ��ó */
#include <iostream>
#include <cmath>
using namespace std;

#define  N  33

void transform(char *input, unsigned int *power)
{
	unsigned int digital[1] = { 0 }, *out, *cacl;
	unsigned int power_table[N] = { 0 };
	cacl = power_table;

	out = digital;
	while (*power && *input) {  
		*cacl = 1;
		while (*power) {
			*cacl *= 2;
			*power -= 1;
		}
		*out += ((*input - '0') * *cacl);

		power++;
		input++;	
		if (*cacl == 2) {
			*cacl = 1;
			*out += ((*input - '0') * *cacl);
		}
	}
	
	cout << *out << endl;
}
int main()
{
	char str[N], *p;
	unsigned int number[N] = { 0 }, *pnum;   //��¼����Ķ�������������ݴ�
	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;
	cin >> str;
	p = str;
	pnum = number;
	*pnum = strlen(str) - 1;
	
	while (*pnum) {
		*(pnum + 1) = *pnum - 1;
		pnum++;  //�������д�Ž�����ݴ�
	}
	pnum = number;

	transform(p, pnum);

	return 0;

}