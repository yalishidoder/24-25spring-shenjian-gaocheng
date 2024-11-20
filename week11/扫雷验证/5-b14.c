/* 2351131 –≈04 Œ§ ¿√≥ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() 
{
	const int MAX_X = 10, MAX_Y = 26;
	char boom[10][26] = { 0 };
	char nine[3][3] = { 0 };
	int jishu;
	int i, j;
	
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 26; j++) {
			scanf("%c", &boom[i][j]);
		}
		
	}
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 26; j++) {
			if (boom[i][j] == '*')
				jishu++;
		}

	}
	if (jishu != 50)
		printf("¥ÌŒÛ1\n");
}