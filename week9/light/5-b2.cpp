/*2351131 信04 韦世贸*/
#include <iostream>
using namespace std;
int main()
{
	int light[101] = { 0 };//定义数组
	int j, k;

	for (j = 1; j <= 100; j++)
	{
		for (k = j; k <= 100; k = k + j)//保证每个同学按的灯是自身编号的倍数
		{
			light[k] = !light[k]; //改变灯的状态
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