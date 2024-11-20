/*2351131 信04 韦世贸*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>


using namespace std;

const int N = 10;

void output(int grade[], string name[], string degree[])
{
	int i;
	cout << endl;
	cout << "全部名单(学号升序):" << endl;
	for (i = 0; i < N; i++) {
		cout << name[i] << " ";
		cout << degree[i] << " ";
		cout << grade[i] << endl;
	}
}

void sort(int grade[], string name[], string degree[])
{
	int i, j, t;
	string s1;
	for (i = 0; i < N - 1; i++) {
		for (j = 0; j < N - (i + 1); j++) {
			if (degree[j] > degree[j + 1]) {
				t = grade[j];
				grade[j] = grade[j + 1];
				grade[j + 1] = t;
				s1 = name[j];
				name[j] = name[j + 1];
				name[j + 1] = s1;

				s1 = degree[j];
				degree[j] = degree[j + 1];
				degree[j + 1] = s1;

			}
		}
	}
	output(grade, name, degree);
}

void input()
{
	int i;
	int grade[10] = { 0 };
	string name[10];
	string degree[10];

	for (i = 0; i < N; i++) {
		cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
		cin >> degree[i];
		cin >> name[i];
		cin >> grade[i];
	}

	sort(grade, name, degree);
}

int main()
{
	input();
	return 0;
}