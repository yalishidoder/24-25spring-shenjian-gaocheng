/* 2351131 信04 韦世贸 */
#include <iostream>
using namespace std;

#define  N  10	/* 假设最多转换10个数字 */

/* 不允许再定义其它函数、全局变量 */

int main()
{
	/* 如果有不需要的变量，允许删除，但不允许添加或替换为其它类型的变量 */
	char str[256], *p;
	int  a[N] = { 0 }, *pnum, *pa;
	bool is_num;

	/* 上面的定义不准动(删除不需要的变量除外)，下面为程序的具体实现，要求不得再定义任何变量、常量、常变量 */

	cout << "请输入间隔含有若干正负数字的字符串" << endl;
	gets_s(str);
	p = str;
	pa = a;
	pnum = pa;

	
	for (; *p != '\0' && pa-a<10; p++) {
		if (*p >= '0' && *p <= '9') {
			is_num = true;
		}
		else
			is_num = false;
		
		if (is_num) {
			*pnum = *pnum * 10 + *p - '0';
		}
		if ((*(p - 1) >= '0' && *(p - 1) <= '9') && !is_num) {   //判断后一个元素是不是数字
			pnum++; //指针指向下一个元素位置
			pa++;
		}
		if (is_num && *(p + 1) == '\0')  //判断数字后的元素是否为尾0
			pa++;
		
	}

	if (pa - a == 10)
		pnum--;

	cout << "共有" << pa - a << "个整数" << endl;
	

	pa = a;

	while (pnum-pa>=0) {
		cout << *pa << " ";
		pa++;
	}

	cout << endl;
	return 0;
}
