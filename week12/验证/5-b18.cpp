/*2351131 信04 韦世贸*/
#include <iostream>
#include <string>

using namespace std;

static const char otherchars[] = "!@#$%^&*-_=+,.?";

int upper(char str[][30], int len,int i)
{
	int up = 0, j;

	for (j = 0; j < len; j++) {
		if (str[i][j] >= 'A' && str[i][j] <= 'Z')
			up++;
	}

	return up;
}
int lower(char str[][30], int len, int i)
{
	int low = 0, j;
	
	for (j = 0; j < len; j++) {
		if (str[i][j] >= 'a' && str[i][j] <= 'z')
			low++;
	}
	
	return low;
}
int num(char str[][30], int len, int i)
{
	int num = 0, j;

	for (j = 0; j < len; j++) {
		if (str[i][j] >= '0' && str[i][j] <= '9')
			num++;
	}

	return num;
}
int oth(char str[][30], int len, int i)
{
	int other = 0;
	int j,k;
	for (j = 0; j < len; j++) {
		for (k = 0; k < 15; k++) {
			if (str[i][j] == otherchars[k])
				other++;
		}
	}

	return other;
}
void output(int right)
{
	if (right == 1)
		cout << "正确" << endl;
	else
		cout << "错误" << endl;
}
void inspection(int len,int length[],char password[][30],int right)
{
	int i;
	int mylen;
	int passwordlen;

	for (i = 0; i < 10; i++) {  //验证长度
		mylen = strlen(password[i]);
		if (mylen < len)
			right--;
	}

	for (i = 0; i < 10; i++) {
		int uppercase = 0, lowercase = 0, number = 0, other = 0;  //这样就直接归0
		uppercase = upper(password, len, i);
		if (uppercase < length[0])
			right--;

		lowercase = lower(password, len, i);
		if (lowercase < length[1])
			right--;

		number = num(password, len, i);
		if (number < length[2])
			right--;

		other = oth(password, len, i);
		if (other < length[3])
			right--;

		passwordlen = other + number + uppercase + lowercase;

		if (passwordlen != mylen)
			right--;
	}


	output(right);
}
void input()
{
	int right = 1;
	char nothing[200] = { 0 };
	int len;
	int length[4] = { 0 };
	int i,j;
	char c;
	char password[10][30] = { 0 };
	i = 0;
	while (cin.get(c) && c != '\n') {
		nothing[i] = c;
		i++;
	}

	cin >> len;
	if (cin.fail()) {
		right--;
	}
	else if (len < 12 || len>16) {
		right--;
	}
	for (i = 0; i < 4; i++) {
		cin >> length[i];
	}

	if (length[0] < 2 || length[0] > len) {
		right--;
	}
	if (length[1] < 2 || length[1] > len) {
		right--;
	}
	if (length[2] < 2 || length[2] > len) {
		right--;
	}
	if (length[3] < 2 || length[3] > len) {
		right--;
	}
	for (i = 0; i < 10; i++) {
		for (j = 0; j < len && password[i][j] != '\n'; j++) {
			cin >> password[i][j];
		}
		password[i][j] = '\0';
	}

	inspection(len, length, password,right);
}
int main()
{
	input();
	return 0;
}