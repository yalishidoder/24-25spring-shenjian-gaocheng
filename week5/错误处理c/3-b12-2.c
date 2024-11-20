/* 2351131 信04 韦世贸 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ret, x;

	while (1) {
		printf("请输入x的值[0-100] : ");
		ret = scanf("%d", &x); //读入x的方式必须是scanf且格式符为%d，不准用非scanf
		while (ret!= 1){       /*判断x是数字还是字符*/
			while (getchar ()!='\n') {      /*快速清空缓冲区*/
			}
			printf("输入有错[ret=%d x=%d],请重新输入\n", ret, x);/*这样就不会多次输出错误提醒*/
			printf("请输入x的值[0-100] : ");
			ret = scanf("%d", &x);

		}
		if (ret == 1 && (x >= 0 && x <= 100)) {
			break;
		}

		printf("输入有错[ret=%d x=%d],请重新输入\n", ret, x); //确认一下，ret的值（即scanf的返回值）是什么含义？ 
	}

	printf("ret=%d x=%d\n", ret, x);

	return 0;
}