/* 2351131 Τ��ó ��04 */
#include <iostream>
#include <cmath>
using namespace std;

class point {
private:
	int x;
	int y;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա
public:
	int getx() const //�����������const����ʾ�������ڱ��������޸����ݳ�Ա��ֵ 
	{
		return x;
	}
	int gety() const //�����������const����ʾ�������ڱ��������޸����ݳ�Ա��ֵ
	{
		return y;
	}
	/* ���Զ�����Ҫ�ĳ�Ա�������������ޣ��������ڷ�ʽʵ�֣�������������ݳ�Ա */
	void set(int a,int b)
	{
		x = a;
		y = b;
	}
};

class triangle {
private:
	point p1;
	point p2;
	point p3;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա
public:
	/* ������Ҫ������Ӧ���������area����(�β�Ϊ�գ���׼��)��Ҫ����������ܹ��������Σ��򷵻���������򷵻� -1 */
	double area()
	{
		double s1, s2, s3;   //�����߶εĳ���

		s1 = Length(p1, p2);
		s2 = Length(p2, p3);
		s3 = Length(p3, p1);

		if (s1 + s2 <= s3 || s2 + s3 <= s1 || s3 + s1 <= s2)
			return -1;

		else {
			double s;
			
			s = 0.5 * fabs((p2.getx() - p1.getx()) * (p3.gety() - p1.gety()) - (p3.getx() - p1.getx()) * (p2.gety() - p1.gety()));

			return s;
		}
	}
	/* ���캯�� */

	triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y)
	{
		/* ��p1/p2/p3������ֱ�x,y����ֵ */
		p1.set(p1_x, p1_y);
		p2.set(p2_x, p2_y);
		p3.set(p3_x, p3_y);
	}
	/* ���Զ�����Ҫ�ĳ�Ա�������������ޣ��������ڷ�ʽʵ�֣�������������ݳ�Ա */
	double Length(point pp, point ppp)
	{
		double delta_x, delta_y, length;

		delta_x = (ppp.getx() - pp.getx()) * (ppp.getx() - pp.getx());
		delta_y = (ppp.gety() - pp.gety()) * (ppp.gety() - pp.gety());
		length = sqrt(delta_x + delta_y);

		return length;
	}
};

/* -- �滻����� -- ���в�Ҫ���κθĶ� -- ���в�Ҫɾ�� -- �ڱ��е����治Ҫ�����κ��Լ�����䣬��ҵ�ύ��ӱ��п�ʼ�ᱻ�滻 -- �滻����� -- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	if (1) {
		triangle tr(0, 0, 0, 1, 1, 0);  //������Ϊ(0,0) (0,1) (1,0)�������
		cout << "���������Ӧ���ǣ�0.5��ʵ���ǣ�" << tr.area() << endl;
		}

	if (1) {
		triangle tr(0, 2, -1, -1, 1, -1);  //������Ϊ(0,2) (-1,-1) (1,-1)�������
		cout << "���������Ӧ���ǣ�3��  ʵ���ǣ�" << tr.area() << endl;
		}

	if (1) {
		triangle tr(5, 5, -3, 1, 9, -2);  //������Ϊ(5,5) (-3,1) (9,-2)�������
		cout << "���������Ӧ���ǣ�36�� ʵ���ǣ�" << tr.area() << endl;
		}

	if (1) {
		triangle tr(0, 0, 1, 1, 2, 2);  //���㹲��
		cout << "���������Ӧ���ǣ�-1�� ʵ���ǣ�" << tr.area() << endl;
	}

	return 0;
}

