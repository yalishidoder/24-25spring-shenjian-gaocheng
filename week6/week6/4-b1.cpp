/* 2351131 ��04 Τ��ó */
#include <iostream>
using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */

/***************************************************************************
  �������ƣ�
  ��    �ܣ������д��0~9
  ���������
  �� �� ֵ��
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		default:
			cout << "error";
			break;
	}
}

/* �ɸ�����Ҫ�Զ�����������(Ҳ���Բ�����) */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	/* ������� */
	double qian;
    cout << "������[0-100��)֮�������:" << endl;
    cin >> qian;

    while (qian < 0 || qian >= 10000000000) {
        cout << "������[0-100��)֮�������:" << endl;
        cin >> qian;
        if (qian >= 0 && qian < 10000000000)
            break;
    }
	int b, c, d, e, f, g, h, i, j, k, l, m;/* ��������Ҹ�λ����ֵ */
	b = int(qian / 1000000000) % 10;
	c = int(qian / 100000000) % 10;
	d = int(qian / 10000000) % 10;
	e = int(qian / 1000000) % 10;
	f = int(qian / 100000) % 10;
	g = int(qian / 10000) % 10;
	h = int(qian / 1000) % 10;
	i = int(qian / 100) % 10;
	j = int(qian / 10) % 10;
	k = int((qian / 10 - int(qian / 10)) * 10 + 0.001) % 10;
	l = int((qian / 10 - int(qian / 10)) * 100 + 0.001) % 10;
	m = int((qian / 10 - int(qian / 10)) * 1000 + 0.001) % 10;
	cout << "��д�����:" << endl;

    daxie(b, 0);
    if (b > 0) {
        if (c && b)
            cout << "ʰ";
        else if (int(c && d && e && f && g && h && i && j && k) < 0)
            cout << "ʰ��Բ";
        else
            cout << "ʰ��";
    }
    else;

    daxie(c, 0);/*��λ�Ͳ�������0*/
    if (c > 0) {
        if (d || e || f || g || h || i || j || k)
            cout << "��";
        else if (!(d && e && f && g && h && i && j && k))
            cout << "��Բ";
    }
    else;

    daxie(d, d);
    if (d > 0) {
    
        if (e || f || g > 0)
            cout << "Ǫ";
        else if (e == 0 && f == 0 && g == 0 || h || i || j || k)
            cout << "Ǫ��";
        else if (!(e && f && g && h && i && j && k))
            cout << "Ǫ��Բ";
    }
    else if ((b || c) && (e || f || g))
        daxie(d, 1);
    else if (!(e && f && g && h && i && j && k))
        cout << "";

    daxie(e, e);
    if (e > 0) {
        if (f || g)
            cout << "��";
        else if ((!f && !g) && (h || i || j || k))
            cout << "����";
        else if (!f && !g && !h && !i && !j && !k)
            cout << "����Բ";
    }
    else if ((b || c || d) && (f || g) && !((b || c) && (e || f || g)) )
        daxie(e, 1);
    else if (!(f && g && h && i && j && k))
        cout << "";

    daxie(f, f);
    if (f > 0) {
        if (g)
            cout << "ʰ";
        else if (g == 0 && (h || i || j || k))
            cout << "ʰ��";
        else if (!(g && h && i && j && k))
            cout << "ʰ��Բ";
    }
    else if (e && g)
        daxie(f, 1);
    else if (!(g && h && i && j && k))
        cout << "";

    daxie(g, g);
    if (g > 0) {
        if (g > 0 && i || j || k)
            cout << "��";
        else if (!(h && i && j && k))
            cout << "��Բ";
    }
    else;

    daxie(h, h);
    if (h > 0) {
        if (!i && (j || k)) { /*����ǧλ����λ���߼���ǧ��λ����λ���߼���һ��*/
            cout << "Ǫ";  /*��ǧλ����λ���߼����Ӹ���QAQ*/
            daxie(0, 1);
        }
        else if (!i && !j && !k)
            cout << "ǪԲ";
        else if (i > 0)
            cout << "Ǫ";
    }
    else if ((b || c || d || e || f || g) && (i || j || k))
        daxie(h,1);
    else if (int(i && j && k) < 0)
        cout << "";

    daxie(i, i);
    if (i > 0) {
        if (!j && k) {
            cout << "��";
            daxie(0, 1);
        }
        else if (!j && !k)
            cout << "��Բ";
        else if (j > 0)
            cout << "��";
    }
    else if (!j && !k)
        cout << "";

    daxie(j, j);
    if (j > 0) {
        if (j && k)
            cout << "ʰ";
        else if (!k)
            cout << "ʰԲ";
    }
    else if (!(i && j && k))
        cout << "";
    
    daxie(k, k);
    if(k)
        cout << "Բ";
    else if (!b && !c && !d && !e && !f && !g && !h && !i && !j && !k && !l && !m) {
        daxie(k, 1);
        cout << "Բ";
    }
    

    if (l || m) {
        daxie(l, l);
        if (l > 0) {
            if (m > 0)
                cout << "��";
            else
                cout << "����" << endl;
        }
        else if ((b || c || d || e || f || g || h || i || j || k))
            daxie(l, 1);

        daxie(m, m);
        if (m > 0){
            cout << "��" << endl;
        }
    }
    else
        cout << "��" << endl;
	
	return 0;
}
