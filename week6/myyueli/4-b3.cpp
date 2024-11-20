/* 2351131 ��04 Τ��ó */
#include <iostream>
#include <iomanip>
using namespace std;
int zeller(int y, int m, int d)
{
    int c, w, year, date;
    if (m < 3) {
        m += 12;
        y--;
    }
    else;
    c = y / 100;
    year = y - 100 * c;

    w = year + year / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1;
    while (w < 0)
        w += 7;

    date = w % 7;
    return date;
}

void calender(int year, int month)
{
    /* ������Ӵ��� */ 
    int date, day;
    date = zeller(year, month, 1);
    cout << year << "��" << month << "��" << endl;
    /* ͷ���ָ��ߣ������� */
    cout << "======================================================" << endl;
    cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
    cout << "======================================================" << endl;

    /* ������Ӵ��� */
    if ((month % 2 && month <= 7) || (month >= 8 && month % 2 == 0)) {  /*����*/
        for (day = 1; day <= 31 + date; day++) {
            if (day > date)
                cout << setw(4) << day - date << "    ";  /*�ո��ж�*/
            else
                cout << "        ";
            if (day % 7 == 0 && day - date < 31)  
                /*�����Ļ���˼·�Ƚϼ򵥣�Ҳ����Ҫ���¶������*/
                cout << endl;
            else;

        }
    }

    if (month == 9 || month == 6 || month == 4 || month == 11) { /*С��*/
        for (day = 1; day <= 30 + date; day++) {
            if (day > date)
                cout << setw(4) << day - date << "    ";
            else
                cout << "        ";
            if (day % 7 == 0 && day - date < 30)  /*��ֹ�����*/
                cout << endl;
            else;
        }
    }

    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) { /*����*/
            for (day = 1; day <= 29 + date; day++) {
                if (day > date)
                    cout << setw(4) << day - date << "    ";
                else
                    cout << "        ";
                if (day % 7 == 0 && day - date < 29)
                    cout << endl;
                else;

            }
        }
        else {
            for (day = 1; day <= 28 + date; day++) {
                if (day > date)
                    cout << setw(4) << day - date << "    ";
                else
                    cout << "        ";
                if (day % 7 == 0 && day - date < 28)
                    cout << endl;
                else;

            }
        }
    }
    cout << endl;
    /* β���ָ��ߣ������� */
    cout << "======================================================" << endl;
}

int main()
{
    int nian, yue;
    while (1) {
        cout << "��������[1900-2100]����" << endl;
        cin >> nian >> yue ;

        if (cin.fail() || nian < 1900 || nian > 2100 || yue < 0 || yue > 12 ) {
            /*����ʦ�����޸ĺ�Ĵ��������Ӽ�*/
            if (cin.fail()) {
                cout << "�����������������" << endl;
                cin.clear();
                cin.ignore(1024, '\n');
            }
            else if (nian < 1900 || nian > 2100)
                cout << "��ݲ���ȷ������������" << endl;
            else if (yue < 0 || yue > 12)
                cout << "�·ݲ���ȷ������������" << endl;
            continue;

        }

        if ((nian >= 1900 && nian <= 2100) && (yue > 0 && yue <= 12) ) {
            break;
        }
    }

    zeller(nian, yue, 1);
    cout << endl;
    calender(nian, yue);
    return 0;
}