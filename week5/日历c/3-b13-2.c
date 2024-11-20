/* 2351131 信04 韦世贸 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int nian, yue, date, day, ret1, ret2;
	printf("请输入年份(2000-2030)和月份(1-12) : ");
	ret1 = scanf("%d %d", &nian, &yue);
	while (ret1 != 2) {       /*判断输入是数字还是字符*/
		while (getchar() != '\n') {/*快速清空缓冲区*/
		}
		printf("输入非法，请重新输入\n");
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		ret1 = scanf("%d %d", &nian, &yue);

	}

	while ((nian < 2000 || nian > 2030) || (yue < 1 || yue > 12)) {
			printf("输入非法，请重新输入\n");
			printf("请输入年份(2000-2030)和月份(1-12) : ");
			ret1 = scanf("%d %d", &nian, &yue);
	}

	printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ", nian, yue);
	ret2 = scanf("%d", &date);

	while (ret2 != 1 || date < 0 || date > 6) {
		while (getchar() != '\n') {
		}
		printf("输入非法，请重新输入\n");
		printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ", nian, yue);
		ret2 = scanf("%d", &date);
	}
	printf("\n");
	printf("%d年%d月的月历为:\n", nian, yue);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");

	if ((yue % 2 && yue <= 7) || (yue >= 8 && yue % 2 == 0)) {
		for (day = 1; day <= 31 + date; day++) {
			if (day > date)
				printf("%4d    ", day - date);
			else
				printf("        ");
			if (day % 7 == 0)
				printf("\n");
		}
	}

	if (yue == 9 || yue == 6 || yue == 4 || yue == 11) {
		for (day = 1; day <= 30 + date; day++) {
			if (day > date)
				printf("%4d    ", day - date);
			else
				printf("        ");
			if (day % 7 == 0)
				printf("\n");
		}
	}

	if (yue == 2) {
		if ((nian % 4 == 0 && nian % 100 != 0) || (nian % 400 == 0)) {
			for (day = 1; day <= 29 + date; day++) {
				if (day > date)
					printf("%4d    ", day - date);
				else
					printf("        ");
				if (day % 7 == 0)
					printf("\n");
			}
		}
		else {
			for (day = 1; day <= 28 + date; day++) {
				if (day > date)
					printf("%4d    ", day - date);
				else
					printf("        ");
				if (day % 7 == 0)
					printf("\n");
			}
		}
	}
	printf("\n");
	return 0;
}