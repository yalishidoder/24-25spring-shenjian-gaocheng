/* 2351131 信04 韦世贸 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> //取系统时间

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int a, b, c, situation = 0;/*定义三个三位数以及情况数*/
	int a1, a2, a3, b1, b2, b3, c1, c2, c3;/*定义三位数的每一位*/
	for (a = 123; a <= 999 && a <= 598; a++) {
		for (b = 512; b <= 999; b++) {
			for (c = 712; c <= 999; c++) {
				a1 = a / 100 % 10;/*计算三个三位数的每一位*/
				a2 = a / 10 % 10;
				a3 = a % 10;

				b1 = b / 100 % 10;
				b2 = b / 10 % 10;
				b3 = b % 10;

				c1 = c / 100 % 10;
				c2 = c / 10 % 10;
				c3 = c % 10;
				if ((a1 != a2 && a1 != a3 && a2 != a3) && (b1 != b2 && b1 != b3 && b2 != b3) &&  /*表示三个三位数之间的关系*/
					(c1 != c2 && c1 != c3 && c2 != c3) && (a1 != b1 && a1 != b2 && a1 != b3) && /*以及三个三位数每位数不相等*/
					(a1 != c1 && a1 != c2 && a1 != c3) && (c1 != b1 && c1 != b2 && c1 != b3) && /*但判断条件过于繁琐*/
					(a2 != b1 && a2 != b2 && a2 != b3) && (a2 != c1 && a2 != c2 && a2 != c3) &&
					(c2 != b1 && c2 != b2 && c2 != b3) && (a3 != b1 && a3 != b2 && a3 != b3) &&
					(a3 != c1 && a3 != c2 && a3 != c3) && (c3 != b1 && c3 != b2 && c3 != b3) &&
					(a + b + c == 1953) && (a != b) && (b != c)) {
					if (a < b && b < c) {
						if ((a1 != 0 && a2 != 0 && a3 != 0) && (b1 != 0 && b2 != 0 && b3 != 0) && (c1 != 0 && c2 != 0 && c3 != 0)) {
							situation++;
							if (situation < 10) /*调整格式*/
								printf("No.  %d : %d+%d+%d=1953\n", situation, a, b, c);
							else if (situation >= 10 && situation < 100)
								printf("No. %d : %d+%d+%d=1953\n", situation, a, b, c);
							else if (situation >= 100)
								printf("No.%d : %d+%d+%d=1953\n", situation, a, b, c);
						}
					}
				}
			}
		}
	} printf("total=%d\n", situation);

	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	printf("计数器频率 : %lldHz\n", tick.QuadPart);
	printf("计数器计数 : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;/*c程序快于cpp*/
}