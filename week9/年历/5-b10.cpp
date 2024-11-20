/*2351131 ��04 Τ��ó*/
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
    int tianshu[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; //����ÿ���µ�����
    int yuefen[3] = { 1,2,3 };  //��һ����
    int date[3] = { 0 };  //һ��������ÿ���µĵ�һ���������
    int enddate[3] = { 0 }; //һ��������ÿ���µ����һ���������
    int i, j1,j2,j3, k,  day;  //ѭ������
    int day1[1] = { 1 };
    int day2[1] = { 1 };
    int day3[1] = { 1 }; //��¼ÿһ�д�ӡ������µĵڼ���
    cout << year << "�������:" << endl;
    cout << endl;
    /* ͷ���ָ��ߣ������� */
    /* ������Ӵ��� */

    tianshu[1] += ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));//��������
    j2 = 0;

    while (1) {
        if (yuefen[0] == 1) {
            j2 = 0;  //����������ҹ�
        }
        else if (yuefen[0] == 4)
            j2 = 3;
        else if (yuefen[0] == 7)
            j2 = 6;
        else if (yuefen[0] == 10)
            j2 = 9;

        for (i = 0,j3 = j2; i < 3; i++,j3++) {
            date[i] = zeller(year, yuefen[i], 1);  //��ÿ�������·��е�һ�������ڼ�
            enddate[i] = zeller(year, yuefen[i],tianshu[j3]);
        }

        day1[0] = { 1 };
        day2[0] = { 1 };
        day3[0] = { 1 };//ÿ�����ȹ�����Ҫ�Լ�¼�����������ʼ��

        cout << "            " << yuefen[0] << "��                             " << yuefen[1] << "��                             " << yuefen[2] << "��" << endl;
        cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
        //��ʽ

        for (i = 0; i < 6; i++) {  //ÿ�����������
            j1 = 0;
            if (yuefen[0] == 1) {
                j2 = 0;  //����������ҹ�
            }
            else if (yuefen[0] == 4)
                j2 = 3;
            else if (yuefen[0] == 7)
                j2 = 6;
            else if (yuefen[0] == 10)
                j2 = 9;

            for (day = day1[0]; day <= tianshu[j2] + date[j1]; day++) {
                if (day > date[j1])
                    cout << setiosflags(ios::left) << setw(4) << day - date[j1];  /*�ո��ж�*/
                else
                    cout << "    ";

                if (day == tianshu[j2] + date[j1]) {  //�����һ���º󲹿ո�
                    day1[0] = day + 1;
                    for (k = enddate[j1]; k < 6; k++) {
                        cout << "    ";
                    }

                }
                if (day % 7 == 0) {
                    day1[0] = day + 1;
                    break;
                }
            }
            cout << "    ";
            j1++;
            j2++;

            for (day = day2[0]; day <= tianshu[j2] + date[j1]; day++) {
                if (day > date[j1])
                    cout << setiosflags(ios::left) << setw(4) << day - date[j1];  /*�ո��ж�*/
                else
                    cout << "    ";

                if (day == tianshu[j2] + date[j1]) {  //�����һ���º󲹿ո�
                    day2[0] = day + 1;
                    for (k = enddate[j1]; k < 6; k++) {
                        cout << "    ";
                    }

                }
                if (day % 7 == 0) {
                    day2[0] = day + 1;
                    break;
                }
            }
            cout << "    ";
            j1++;
            j2++;

            for (day = day3[0]; day <= tianshu[j2] + date[j1]; day++) {
                if (day > date[j1])
                    cout << setiosflags(ios::left) << setw(4) << day - date[j1];  /*�ո��ж�*/
                else
                    cout << "    ";

                if (day == tianshu[j2] + date[j1]) {  //�����һ���º󲹿ո�
                    day3[0] = day + 1;
                    for (k = enddate[j1]; k < 6; k++) {
                        cout << "    ";
                    }

                }

                if (day % 7 == 0) {
                    day3[0] = day + 1;
                    break;
                }
            }
            cout << endl;

            if (day2[0] - date[j1 - 1] == tianshu[j2 - 1] + 1 && day1[0] - date[j1 - 2] == tianshu[j2 - 2] + 1 &&
                day3[0] - date[j1] == tianshu[j2] + 1)    //һ�����ȵ�����ȫ����ӡ��ϣ��˳�ѭ��
                break;
        }
        cout << endl;
        for (k = 0; k < 3; k++) {
            yuefen[k] += 3;   //���뵽��һ������
        }

        if (yuefen[1] > 13) //��ӡ��һ������������˳�ѭ��
            break;

    }
}

int main()
{
    int nian;
    while (1) {
        cout << "���������[1900-2100]" << endl;
        cin >> nian ;

        if (cin.fail() || nian < 1900 || nian > 2100) {
            /*����ʦ�����޸ĺ�Ĵ��������Ӽ�*/
            if (cin.fail()) {
                cout << "�����������������" << endl;
                cin.clear();
                cin.ignore(1024, '\n');
            }
            else if (nian < 1900 || nian > 2100)
                cout << "��ݲ���ȷ������������" << endl;
            continue;

        }

        if (nian >= 1900 && nian <= 2100)  {
            break;
        }
    }

    zeller(nian, 1, 1);
    calender(nian, 1);
    cout << endl;
    return 0;
}
