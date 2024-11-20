/* 2351131 信04 韦世贸 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int chengji[1000] = { 0 };
	int i, j, t, count1, count = 0;//数组变量和计数变量
	printf("请输入成绩（最多1000个），负数结束输入\n");
	for (i = 0; i < 1000; ++i) {
		scanf("%d", &chengji[i]);
		if (chengji[0] < 0 ) {
			printf("无有效输入\n");
			return 0;
		}

		if (chengji[i]<0 && i > 0) {
			break;
		}
		count++;
	}
	while (getchar() != '\n');

	printf("输入的数组为:\n");

	for (i = 0; i < count && chengji[i] <= 100; i++) {
		printf("%d ", chengji[i]);
		if ((i+1) % 10 == 0  )
			printf("\n");
	}

	printf("\n");

	printf("分数与人数的对应关系为:\n");
	
	for (i = 0; i < count; i++) {//冒泡排序
		for (j = 0; j < count - (i + 1); j++) {
			if (chengji[j] < chengji[j + 1]) {
				t = chengji[j];
				chengji[j] = chengji[j + 1];
				chengji[j + 1] = t;
			}
		}
	}

	for ( i = 0; i < count; i++) {
		count1 = 1;
		if (chengji[i] != -1) {
			for ( j = i + 1; j < count; j++) {
				if (chengji[i] == chengji[j]) {
					count1++;
					chengji[j] = -1;
				}
			}
			printf("%d %d\n", chengji[i], count1);

		}
	}
	return 0;
}