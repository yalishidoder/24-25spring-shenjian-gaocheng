/* 2351131 信04 韦世贸 */
#include <iostream>
using namespace std;
int zeller(int y, int m, int d)
{
    int c, w, year, date;
    if (m < 3) { /*对月份的判断*/
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
        cout << "请输入年[1900-2100]、月、日：" << endl;
        cin >> nian >> yue >> day;

        if (nian % 4 == 0 && nian % 100 != 0 || nian % 400 == 0)
            run = 1;
        else
            run = 0;
        /*对闰年的判断*/

        if (((yue % 2 && yue <= 7) || (yue >= 8 && yue % 2 == 0)) && (day > 31))
            right = 0;
        /*大月*/
        else if ((yue == 9 || yue == 6 || yue == 4 || yue == 11) && (day > 30))
            right = 0;
        /*小月*/
        else if ((yue==2 && run)&&(day>29))
            right = 0;
        else if ((yue == 2 && !run) && (day > 28))
            right = 0;
       /*日是否正确的判断*/

        if (cin.fail() || nian < 1900 || nian > 2100 || yue < 0 || yue > 12 || !right) {
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
            else if (!right) {
                cout << "日不正确，请重新输入" << endl;
                right = 1;
            }
            continue;
        }

        if ((nian >= 1900 && nian <= 2100) && (yue > 0 && yue <= 12) && right) {
            break;
        }
    }

    w = zeller(nian, yue, day);/*调用函数，得到星期值*/
    cout << "星期";
    switch (w)
    {
        case 0:
            cout << "天" << endl;
            break;
        case 1:
            cout << "一" << endl;
            break;
        case 2:
            cout << "二" << endl;
            break;
        case 3:
            cout << "三" << endl;
            break;
        case 4:
            cout << "四" << endl;
            break;
        case 5:
            cout << "五" << endl;
            break;
        case 6:
            cout << "六" << endl;
            break;
    }
    return 0;
}