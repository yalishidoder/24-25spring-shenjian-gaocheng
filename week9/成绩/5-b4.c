/* 2351131 ��04 Τ��ó */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int chengji[1000] = { 0 };
	int i, j, t, count1, count = 0;//��������ͼ�������
	printf("������ɼ������1000������������������\n");
	for (i = 0; i < 1000; ++i) {
		scanf("%d", &chengji[i]);
		if (chengji[0] < 0 ) {
			printf("����Ч����\n");
			return 0;
		}

		if (chengji[i]<0 && i > 0) {
			break;
		}
		count++;
	}
	while (getchar() != '\n');

	printf("���������Ϊ:\n");

	for (i = 0; i < count && chengji[i] <= 100; i++) {
		printf("%d ", chengji[i]);
		if ((i+1) % 10 == 0  )
			printf("\n");
	}

	printf("\n");

	printf("�����������Ķ�Ӧ��ϵΪ:\n");
	
	for (i = 0; i < count; i++) {//ð������
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