/* 2351131 ��04 Τ��ó */
#include <iostream>
using namespace std;

#define  N  80	

void judgment(char *start, char* end)
{
	while (*start) {
		if (*start == *end) {
			start++;
			end--;
		}
		else {
			cout << "no" << endl;
			break;
		}

		cout << "yes" << endl;
		break;
	}

	if (*start == *end && *start == '\0')
		cout << "yes" << endl;
}

int main()
{
	char str[N], *p1,*p2;
	cout << "������һ������С��80���ַ��������Ĵ���" << endl;
	fgets(str, sizeof(str), stdin);

	p1 = str;   //p1ָ���ַ�����ʼλ��
	p2 = str;
	p2 += strlen(str);
	p2--;
	*p2 = '\0';   //����س�

	if(strlen(str))
		p2--;  //��str��Ϊ��ʱ��ʹp2ָ���ַ���ĩβ

	judgment(p1, p2);

	return 0;
}