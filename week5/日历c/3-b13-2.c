/* 2351131 ��04 Τ��ó */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int nian, yue, date, day, ret1, ret2;
	printf("���������(2000-2030)���·�(1-12) : ");
	ret1 = scanf("%d %d", &nian, &yue);
	while (ret1 != 2) {       /*�ж����������ֻ����ַ�*/
		while (getchar() != '\n') {/*������ջ�����*/
		}
		printf("����Ƿ�������������\n");
		printf("���������(2000-2030)���·�(1-12) : ");
		ret1 = scanf("%d %d", &nian, &yue);

	}

	while ((nian < 2000 || nian > 2030) || (yue < 1 || yue > 12)) {
			printf("����Ƿ�������������\n");
			printf("���������(2000-2030)���·�(1-12) : ");
			ret1 = scanf("%d %d", &nian, &yue);
	}

	printf("������%d��%d��1�յ�����(0-6��ʾ������-������) : ", nian, yue);
	ret2 = scanf("%d", &date);

	while (ret2 != 1 || date < 0 || date > 6) {
		while (getchar() != '\n') {
		}
		printf("����Ƿ�������������\n");
		printf("������%d��%d��1�յ�����(0-6��ʾ������-������) : ", nian, yue);
		ret2 = scanf("%d", &date);
	}
	printf("\n");
	printf("%d��%d�µ�����Ϊ:\n", nian, yue);
	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");

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