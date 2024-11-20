/* 2351131 Τ��ó ��04 */

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "read_stulist.h"
using namespace std;
class stu_list;
#define MAX_FILENAME_LEN		512	//�����ļ�������󳤶�

/* stu_metge ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_merge {
private:
	int  stu_no;				   //ѧ��
	char stu_name[MAX_NAME_LEN];  //����
	char round_1[MAX_NAME_LEN] = { 0 };  //��һ��ѡ��״̬
	char round_2[MAX_NAME_LEN] = { 0 }; //�ڶ���ѡ��״̬
	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */
	void stu_set(int num, char name[MAX_NAME_LEN], int which_list)
	{
		stu_no = num;
		strcpy(stu_name, name);
		if (which_list == 1) {
			strcpy(round_1, "Y");
		}
		else
			strcpy(round_2, "Y");
	}
	void stu_change()
	{
		if (round_1[0] != 'Y' && round_2[0] == 'Y') {
			round_1[0] = '/';
			strcpy(round_2, "��ѡ");
		}
		else if (round_2[0] != 'Y' && round_1[0] == 'Y')
			strcpy(round_2, "�˿�");
	}
	friend stu_list;
public:
	//���಻�������κεĹ������ݳ�Ա����Ա����

};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//��һ��ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_1;						//��һ��ѡ�ε�ѧ������

	student list_round_2[MAX_STU_NUM];	//�ڶ���ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_2;						//�ڶ���ѡ�ε�ѧ������

	stu_merge list_merge[MAX_STU_NUM];	//�ϲ����ѧ��������ȥ�أ����������У�
	int list_merge_num;					//�ϲ����ѧ��������Ŀǰ����ӡ�����������ڲ������������Ҫ��Ҳ��Ҫɾ����

	/* ���������private���ݳ�Ա�ͳ�Ա����
	   ע�⣬���������array / set / map / vector��STL���� */

public:
	stu_list();										//���캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
	int read(const char* filename, const int round);	//���ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
	int print(const char* prompt = NULL);				//��ӡ���յ�ѡ������

	void merge_deduplication()
	{
		int i, j, k = 0;
		int real_list_num_1 = list_num_1;
		int real_list_num_2 = list_num_2;
		int repeat[MAX_STU_NUM] = { 0 };
		stu_merge* p;
		p = list_merge;
		for (i = 0; i < list_num_1; i++) {
			for (j = i + 1; j < list_num_1; j++) {
				if (list_round_1[i].no == list_round_1[j].no && list_round_1[j].no != 0) {
					list_round_1[j].no = 0;
					real_list_num_1--;
				}
			}
		}

		for (i = 0; i < list_num_2; i++) {
			for (j = i + 1; j < list_num_2; j++) {
				if (list_round_2[i].no == list_round_2[j].no && list_round_2[j].no != 0) {
					list_round_2[j].no = 0;
					real_list_num_2--;
				}
			}
		}

		for (i = 0; i < (list_num_1 > list_num_2 ? list_num_1 : list_num_2); i++) {
			for (j = 0; j < (list_num_1 > list_num_2 ? list_num_1 : list_num_2); j++) {
				if (list_round_1[i].no == list_round_2[j].no && list_round_2[j].no > 0) {
					repeat[k++] = list_round_2[j].no;
					list_round_2[j].no = 0;
					real_list_num_2--;
				}
			}
		}

		list_merge_num = real_list_num_1 + real_list_num_2;

		for (i = 0; i < list_num_1; i++) {
			if (list_round_1[i].no > 0) {
				p->stu_set(list_round_1[i].no, list_round_1[i].name, 1);
				p++;
			}
			

		}

		for (i = 0; i < list_num_2; i++) {
			if (list_round_2[i].no > 0) {
				p->stu_set(list_round_2[i].no, list_round_2[i].name, 2);
				p++;
			}
		}

		for (i = 0; i < list_merge_num; i++) {
			for (j = 0; j < (list_num_1 > list_num_2 ? list_num_1 : list_num_2); j++) {
				if (list_merge[i].stu_no > 0 && list_merge[i].stu_no == repeat[j]) {
					strcpy(list_merge[i].round_2, "Y");
				}

			}
		}

		p = list_merge;
		for (i = 0; i < list_merge_num; i++) {
			if (list_merge[i].stu_no > 0) {
				p->stu_change();
				p++;
			}
		}
	}
	
	void sort()
	{
		int i, j;
		int middle = 0;
		char s1[MAX_FILENAME_LEN] = { 0};
		for (i = 0; i < list_merge_num - 1; i++) {
			for (j = 0; j < list_merge_num - (i + 1); j++) {
				if (list_merge[j].stu_no > list_merge[j + 1].stu_no) {    //����˳��
					middle = list_merge[j].stu_no;
					list_merge[j].stu_no = list_merge[j + 1].stu_no;
					list_merge[j + 1].stu_no = middle;

					strcpy(s1, list_merge[j].stu_name);
					strcpy(list_merge[j].stu_name, list_merge[j + 1].stu_name);
					strcpy(list_merge[j + 1].stu_name, s1);

					strcpy(s1, list_merge[j].round_1);
					strcpy(list_merge[j].round_1, list_merge[j + 1].round_1);
					strcpy(list_merge[j + 1].round_1, s1);

					strcpy(s1, list_merge[j].round_2);
					strcpy(list_merge[j].round_2, list_merge[j + 1].round_2);
					strcpy(list_merge[j + 1].round_2, s1);
				}
			}
		}
	}
	/* �������������public��Ա��������ʾ���ϲ���ȥ�ء�����ȣ�
	   �������幫�е����ݳ�Ա
	   �������ڳ�Ա������ʹ��array / set / map / vector��STL���� */

};

/* --- ������Ը���stu_merge/stu_list������ĳ�Ա����������ʵ�� --- */


/***************************************************************************
  �������ƣ�
  ��    �ܣ����ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
  ���������
  �� �� ֵ��
  ˵    �������캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
***************************************************************************/
stu_list::stu_list()
{

}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��̬���ӿ��ʹ�ã��������е��þ�̬���ӿ��е�Ԥ�ú���
  ���������
  �� �� ֵ��
  ˵    ��������������Ҫ�޸� 
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* ��ȡ��1/2�ֵ�ѡ����������ӡ */
	switch (round) {
		case 1:
			this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
			if (this->list_num_1 > 0)
				print_stulist("��һ��ѡ��������", this->list_round_1, this->list_num_1);
			else
				ret = -1;
			break;
		case 2:
			this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
			if (this->list_num_2 > 0)
				print_stulist("�ڶ���ѡ��������", this->list_round_2, this->list_num_2);
			else
				ret = -1;
			break;
		default:
			ret = -1;
			break;
	}

	return ret;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ������ӡ���յ�ѡ������
***************************************************************************/
int stu_list::print(const char* prompt)
{
	int i, j, num = 0;
	
	cout << *prompt << endl;
	cout << "============================================================" << endl;
	cout << "��� ѧ��     ����                            ��һ�� �ڶ���" << endl;
	cout << "============================================================" << endl;
	for (i = 0; i < list_merge_num; i++) {
		if (list_merge[i].stu_no > 0) {
			cout << setiosflags(ios::left) << setw(5) << ++num << setw(7) << list_merge[i].stu_no << " " << setw(33) << list_merge[i].stu_name << setw(7);
			for (j = 0; j < MAX_NAME_LEN; j++) {
				if (list_merge[i].round_1[j])
					cout << list_merge[i].round_1[j];
			}
			if (list_merge[i].round_2[0] == 'Y')
				cout << list_merge[i].round_2[0];
			else {
				for (j = 0; j < MAX_NAME_LEN; j++) {
					if (list_merge[i].round_2[j])
						cout << list_merge[i].round_2[j];
				}
			}
		}
		cout << endl;
	}
	cout << "============================================================" << endl;
	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	gets_s(file1); //cin���ܶ��пո���ļ�

	cout << "�������һ��ѡ�ε������ļ� : ";
	gets_s(file2);

	stu_list list;

	/* �������� */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* �������� */
	list.merge_deduplication();
	list.sort();

	/* ��ӡ */
	list.print("����ѡ������");

	return 0;
}

