/* 2351131 ��04 Τ��ó */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

const int N = 10;

void output(int grade[], char name[][9], char degree[][8])
{
	int i;
	printf("\n");
	printf("��������(ѧ�Ž���):\n");
	for (i = 0; i < N; i++) {
		if (grade[i] >= 60) {
			printf("%s ", name[i]);
			printf("%s ", degree[i]);
			printf("%d\n", grade[i]);
		}
	}
}

void sort(int grade[],char name[][9], char degree[][8])
{
	int i, j, t, k,l;
	char s1[][10] = { '0' };
	for (i = 0; i < N - 1; i++) {
		for (j = 0; j < N - (i + 1); j++) {
			for (l = 0; l < 8; l++) {
				if (degree[j][l] <= degree[j + 1][l]) {
					if (degree[j][l] < degree[j + 1][l]) {
						t = grade[j];
						grade[j] = grade[j + 1];
						grade[j + 1] = t;
						for (k = 0; k < 9; k++) {   //��Ϊstrcpy���warning,���Ծ�û����
							s1[0][k] = name[j][k];    //����ѡ����ѭ���ķ�ʽ�����ܻ�Ƚ��鷳
							name[j][k] = name[j + 1][k];
							name[j + 1][k] = s1[0][k];
						}
						for (k = 0; k < 8; k++) {
							s1[0][k] = degree[j][k];
							degree[j][k] = degree[j + 1][k];
							degree[j + 1][k] = s1[0][k];
						}
						break;
					}
				}
				else
					break;
			}
		}
	}
	output(grade, name, degree);
}

void input()
{
	int i;
	int grade[10] = { 0 };
	char name[10][9] = { 0 };
	char degree[10][8] = { 0 };

	for (i = 0; i < N; i++) {
		printf("�������%d���˵�ѧ�š��������ɼ�\n", i + 1);
		scanf("%s", degree[i]);
		scanf("%s", name[i]);
		scanf("%d", &grade[i]);
	}

	sort(grade, name, degree);
}

int main()
{
	input();
	return 0;
}