/* 2351131 信04 韦世贸 */
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
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	fgets(str, sizeof(str), stdin);

	p1 = str;   //p1指向字符串开始位置
	p2 = str;
	p2 += strlen(str);
	p2--;
	*p2 = '\0';   //处理回车

	if(strlen(str))
		p2--;  //当str不为空时，使p2指向字符串末尾

	judgment(p1, p2);

	return 0;
}