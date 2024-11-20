/* 2351131 –≈04 Œ§ ¿√≥ */
#include <iostream>
#include <string>
using namespace std;

int main()
{
	const int MAX_X = 10, MAX_Y = 26;
	char boom[MAX_X][MAX_Y] = { 0 };
	int i,j,k,l;
	int x, y, jishu = 0;
	srand((unsigned int)(time(0)));
	char nine[3][3] = {0 };
	nine[1][1] = '0';
	for (i = 0; i < 50; i++) {
		x = rand() % (MAX_X);
		y = rand() % (MAX_Y);
		if (boom[x][y] == '*') {
			i--;
			
		}
		else
			boom[x][y] = '*';
	}
	
	for (i = 0; i < MAX_X; i++) { 
		for (j = 0; j < MAX_Y; j++) {
			if(boom[i][j] != '*')
			{
				boom[i][j] = nine[1][1];
				if (i == 0 && j == 0) {
					nine[2][2] = boom[i + 1][j + 1];
					nine[2][1] = boom[i + 1][j];
					nine[1][2] = boom[i][j + 1];
				}
				else if (i == 0 && j == 25) {
					nine[2][2] = boom[i + 1][j - 1];
					nine[2][1] = boom[i + 1][j];
					nine[1][2] = boom[i][j - 1];
				}
				else if (i == 9 && j == 25) {
					nine[2][2] = boom[i - 1][j - 1];
					nine[2][1] = boom[i - 1][j];
					nine[1][2] = boom[i][j - 1];
				}
				else if (i == 9 && j == 0) {
					nine[2][2] = boom[i + 1][j - 1];
					nine[2][1] = boom[i - 1][j];
					nine[1][2] = boom[i][j + 1];
				}
				else if (i != 0 && j == 0) {
					nine[2][2] = boom[i + 1][j + 1];
					nine[1][0] = boom[i - 1][j + 1];
					nine[2][1] = boom[i - 1][j];
					nine[1][2] = boom[i][j + 1];
					nine[0][2] = boom[i + 1][j];
				}
				else if (i == 0 && j != 0) {
					nine[2][2] = boom[i][j - 1];
					nine[0][2] = boom[i + 1][j - 1];
					nine[2][1] = boom[i][j + 1];
					nine[1][2] = boom[i + 1][j + 1];
					nine[1][0] = boom[i + 1][j];
				}
				else if (i != 10 && j == 25) {
					nine[2][2] = boom[i - 1][j - 1];
					nine[1][0] = boom[i + 1][j - 1];
					nine[2][1] = boom[i ][j-1];
					nine[1][2] = boom[i][j - 1];
					nine[0][2] = boom[i ][j+1];
				}
				else if (i == 10 && j != 25) {
					nine[2][2] = boom[i - 1][j - 1];
					nine[1][0] = boom[i - 1][j + 1];
					nine[2][1] = boom[i - 1][j];
					nine[1][2] = boom[i][j + 1];
					nine[0][2] = boom[i + 1][j];
				}
				else {
					nine[0][0] = boom[i - 1][j - 1];
					nine[0][1] = boom[i][j - 1];
					nine[0][2] = boom[i + 1][j - 1];
					nine[1][0] = boom[i - 1][j];
					nine[1][2] = boom[i + 1][j];
					nine[2][0] = boom[i - 1][j + 1];
					nine[2][1] = boom[i][j + 1];
					nine[2][2] = boom[i + 1][j + 1];
				}
			}
			for (k = 0; k < 3; k++) {
				for (l = 0; l < 3; l++) {
					if (nine[k][l] == '*' && boom[i][j] != '*')
						boom[i][j] += 1;
				}
			}
		}
	}
	for (i = 0; i < MAX_X; i++) {
		for (j = 0; j < MAX_Y; j++) {
			cout << boom[i][j] << " ";
		}
		cout << endl;
	}

}