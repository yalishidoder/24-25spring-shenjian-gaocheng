/*2351131 ��04 Τ��ó*/
#include <iostream>
using namespace std;
int main()
{
	int light[101] = { 0 };//��������
	int j, k;

	for (j = 1; j <= 100; j++)
	{
		for (k = j; k <= 100; k = k + j)//��֤ÿ��ͬѧ���ĵ��������ŵı���
		{
			light[k] = !light[k]; //�ı�Ƶ�״̬
		}
	}
	for (j = 1; j <= 100; j++) 
	{
		if (light[j])
			cout << j << " ";
	}
	cout << endl;
	return 0;
}