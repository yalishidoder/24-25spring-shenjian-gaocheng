/*2351131 ��04 Τ��ó*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int shudu[9][9];//����
	int crosswiseright, verticalright , gongright ;//�����ж�����
	int cross1, vertical1 ,gong1 ;//С���ж�����
	int i, j, k, l, m;//ѭ������
	int gong[9] = { 0 }; //���ÿ��С�Ź����е���

	cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			while (1) {    //���봦��
				cin >> shudu[i][j];
				//ѭ���������
				if (cin.fail()) {
					cin.clear();
					cin.ignore(114514, '\n');
					cout << "�����������" << i + 1 << "��" << j + 1 << "��(���о���1��ʼ����)��ֵ" << endl;
					continue;
				}
				if (!shudu[i][j] || shudu[i][j] > 9) {
					cout << "�����������" << i + 1 << "��" << j + 1 << "��(���о���1��ʼ����)��ֵ" << endl;
					continue;
				}
				else
					break;
			}
		}
	}
	
			
	//�����ж�
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (shudu[i][j] != -1) {
				for (k = j + 1; k < 9; k++) {
					if (shudu[i][j] == shudu[i][k]) {
						cross1 = 0;
						crosswiseright = 0;
					}
					else
						cross1 = 1;
				}
			}
		}
		
	}
	if (cross1)
		crosswiseright = 1;

	for (i = 0; i < 9; i++) {  //��ֱ�ж�
		for (j = 0; j < 9; j++) {
			if (shudu[j][i] != -1) {
				for (k = j + 1; k < 9; k++) {
					if (shudu[j][i] == shudu[k][i]) {
						vertical1 = 0;
						verticalright = 0;
					}
					else
						vertical1 = 1;
				}
			}
		}


	}
	if (vertical1)
		verticalright = 1;

	for (i = 0; i < 9; i++) {
		k = 0;
		for (j = 0; j < 9; j++) {
			gong[k] = shudu[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3]; 
			//���Ź��������ıȶ�ת����һ��һά�����Ԫ�رȶ�
			k++;
		}

		for (l = 0; l < 9; l++) {
			for (m = l + 1; m < 9; m++) {
				if (gong[l] == gong[m])
					gong1 = 0;
				else
					gong1 = 1;
			}
		}
	}

	if (gong1)
		gongright = 1;

	if (crosswiseright && verticalright && gongright)  //ͬʱ���������������������Ľ�
		cout << "�������Ľ�" << endl;
	else
		cout << "���������Ľ�" << endl;
}
