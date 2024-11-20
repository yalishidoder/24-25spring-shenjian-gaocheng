/* 2351131 信04 韦世贸 */
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
    /* 按需添加代码 */ 
    int date, day;
    date = zeller(year, month, 1);
    cout << year << "年" << month << "月" << endl;
    /* 头部分隔线，不算打表 */
    cout << "======================================================" << endl;
    cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
    cout << "======================================================" << endl;

    /* 按需添加代码 */
    if ((month % 2 && month <= 7) || (month >= 8 && month % 2 == 0)) {  /*大月*/
        for (day = 1; day <= 31 + date; day++) {
            if (day > date)
                cout << setw(4) << day - date << "    ";  /*空格判断*/
            else
                cout << "        ";
            if (day % 7 == 0 && day - date < 31)  
                /*这样的换行思路比较简单，也不需要重新定义变量*/
                cout << endl;
            else;

        }
    }

    if (month == 9 || month == 6 || month == 4 || month == 11) { /*小月*/
        for (day = 1; day <= 30 + date; day++) {
            if (day > date)
                cout << setw(4) << day - date << "    ";
            else
                cout << "        ";
            if (day % 7 == 0 && day - date < 30)  /*防止多空行*/
                cout << endl;
            else;
        }
    }

    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) { /*闰年*/
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
    /* 尾部分隔线，不算打表 */
    cout << "======================================================" << endl;
}

int main()
{
    int nian, yue;
    while (1) {
        cout << "请输入年[1900-2100]、月" << endl;
        cin >> nian >> yue ;

        if (cin.fail() || nian < 1900 || nian > 2100 || yue < 0 || yue > 12 ) {
            /*按老师讲解修改后的错误处理，更加简单*/
            if (cin.fail()) {
                cout << "输入错误，请重新输入" << endl;
                cin.clear();
                cin.ignore(1024, '\n');
            }
            else if (nian < 1900 || nian > 2100)
                cout << "年份不正确，请重新输入" << endl;
            else if (yue < 0 || yue > 12)
                cout << "月份不正确，请重新输入" << endl;
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