/*2351131 ��04 Τ��ó*/
#include <iostream>
#include <cstdio>
#include <ctime>
#include <string>

using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?";
const int _max = 10;  //���������
const int other_max = 15;
const int choice = 4;

void output(int len, char password[])  //�������
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

	srand((unsigned int)(time(0))); //��������

	for (k = 1; k <= _max; k++) {   //ѭ��10��
		for (i = 0; i < len;) {
			for (j = 0; j < num[0];) {  //��д��ĸ
				x = rand() % (len);
				if (password[x] == 0) {
					y = rand() % ('Z' - 'A' + 1) + 'A';
					password[x] = y;
					j++;
				}
			}
			i += num[0];

			for (j = 0; j < num[1];) {  //Сд��ĸ
				x = rand() % (len);
				if (password[x] == 0) {
					y = rand() % ('z' - 'a' + 1) + 'a';
					password[x] = y;
					j++;
				}
			}
			i += num[1];

			for (j = 0; j < num[2];) {  //����
				x = rand() % (len);
				if (password[x] == 0) {
					y = rand() % ('9' - '0' + 1) + '0';
					password[x] = y;
					j++;
				}
			}
			i += num[2];

			for (j = 0; j < num[3];) {  //�����ַ�
				x = rand() % (len);
				if (password[x] == 0) {
					y = rand() % (other_max);
					password[x] = other[y];
					j++;
				}
			}
			i += num[3];

			if (i < len) {   //�����Ȳ���ʱ���������
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

		for (l = 0; l < len; l++)   //�����������0
			password[l] = 0;
	}

}

void input() 
{
	int length = 0;
	int num[4] = { 0 };
	int i;
	int input_len = 0;

	cout << "���������볤��(12-16)�� ��д��ĸ����(��2)�� Сд��ĸ����(��2)�� ���ָ���(��2)�� �������Ÿ���(��2)" << endl;
	cin >> length;
	if (cin.fail()) {
		cout << "����Ƿ�" << endl;
		return;
	}
	else if (length < 12 || length>16) {
		cout << "���볤��[" << length << "]����ȷ" << endl;
		return;
	}
	for (i = 0; i < 4; i++) {
		cin >> num[i];
		if (cin.fail()) {
			cout << "����Ƿ�" << endl;
			return;
		}
	}

	if (num[0] < 2 || num[0] > length) {
		cout << "��д��ĸ����[" << num[0] << "]����ȷ" << endl;
		return;
	}
	if (num[1] < 2 || num[1] > length) {
		cout << "Сд��ĸ����[" << num[1] << "]����ȷ" << endl;
		return;
	}
	if (num[2] < 2 || num[2] > length) {
		cout << "���ָ���[" << num[2] << "]����ȷ" << endl;
		return;
	}
	if (num[3] < 2 || num[3] > length) {
		cout << "�������Ÿ���[" << num[3] << "]����ȷ" << endl;
		return;
	}

	for (i = 0; i < 4; i++) {
		input_len += num[i];   //��������ַ��ĳ����ܺ�
	}
	if (input_len > length) {
		cout << "�����ַ�����֮��[" << num[0] << "+" << num[1] << "+" << num[2] << "+" << num[3] << "]���������볤��[" << length << "]" << endl;
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