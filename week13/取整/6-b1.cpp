/* 2351131 ��04 Τ��ó */
#include <iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], *p;
	int  a[N] = { 0 }, *pnum, *pa;
	bool is_num;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */

	cout << "�����������������������ֵ��ַ���" << endl;
	gets_s(str);
	p = str;
	pa = a;
	pnum = pa;

	
	for (; *p != '\0' && pa-a<10; p++) {
		if (*p >= '0' && *p <= '9') {
			is_num = true;
		}
		else
			is_num = false;
		
		if (is_num) {
			*pnum = *pnum * 10 + *p - '0';
		}
		if ((*(p - 1) >= '0' && *(p - 1) <= '9') && !is_num) {   //�жϺ�һ��Ԫ���ǲ�������
			pnum++; //ָ��ָ����һ��Ԫ��λ��
			pa++;
		}
		if (is_num && *(p + 1) == '\0')  //�ж����ֺ��Ԫ���Ƿ�Ϊβ0
			pa++;
		
	}

	if (pa - a == 10)
		pnum--;

	cout << "����" << pa - a << "������" << endl;
	

	pa = a;

	while (pnum-pa>=0) {
		cout << *pa << " ";
		pa++;
	}

	cout << endl;
	return 0;
}
