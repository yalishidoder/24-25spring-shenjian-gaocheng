/* 2351131 ��04 Τ��ó */
#include <iostream>
using namespace std;
int zeller(int y, int m, int d)
{
    int c, w, year, date;
    if (m < 3) { /*���·ݵ��ж�*/
        m += 12;
        y--;
    }
    else;
    c = y / 100  ;
    year = y - 100 * c;

    w = year + year / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1;
    while (w < 0)
        w += 7;

    date = w % 7;
    
    return date;
}
int main()
{
    int nian, yue, day, right = 1,run,w;
    while (1) {
        cout << "��������[1900-2100]���¡��գ�" << endl;
        cin >> nian >> yue >> day;

        if (nian % 4 == 0 && nian % 100 != 0 || nian % 400 == 0)
            run = 1;
        else
            run = 0;
        /*��������ж�*/

        if (((yue % 2 && yue <= 7) || (yue >= 8 && yue % 2 == 0)) && (day > 31))
            right = 0;
        /*����*/
        else if ((yue == 9 || yue == 6 || yue == 4 || yue == 11) && (day > 30))
            right = 0;
        /*С��*/
        else if ((yue==2 && run)&&(day>29))
            right = 0;
        else if ((yue == 2 && !run) && (day > 28))
            right = 0;
       /*���Ƿ���ȷ���ж�*/

        if (cin.fail() || nian < 1900 || nian > 2100 || yue < 0 || yue > 12 || !right) {
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
            else if (!right) {
                cout << "�ղ���ȷ������������" << endl;
                right = 1;
            }
            continue;
        }

        if ((nian >= 1900 && nian <= 2100) && (yue > 0 && yue <= 12) && right) {
            break;
        }
    }

    w = zeller(nian, yue, day);/*���ú������õ�����ֵ*/
    cout << "����";
    switch (w)
    {
        case 0:
            cout << "��" << endl;
            break;
        case 1:
            cout << "һ" << endl;
            break;
        case 2:
            cout << "��" << endl;
            break;
        case 3:
            cout << "��" << endl;
            break;
        case 4:
            cout << "��" << endl;
            break;
        case 5:
            cout << "��" << endl;
            break;
        case 6:
            cout << "��" << endl;
            break;
    }
    return 0;
}