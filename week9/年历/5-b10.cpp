/*2351131 信04 韦世贸*/
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
    int tianshu[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; //包含每个月的天数
    int yuefen[3] = { 1,2,3 };  //第一季度
    int date[3] = { 0 };  //一个季度中每个月的第一天的星期数
    int enddate[3] = { 0 }; //一个季度中每个月的最后一天的星期数
    int i, j1,j2,j3, k,  day;  //循环变量
    int day1[1] = { 1 };
    int day2[1] = { 1 };
    int day3[1] = { 1 }; //记录每一行打印到这个月的第几天
    cout << year << "年的日历:" << endl;
    cout << endl;
    /* 头部分隔线，不算打表 */
    /* 按需添加代码 */

    tianshu[1] += ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));//闰年特判
    j2 = 0;

    while (1) {
        if (yuefen[0] == 1) {
            j2 = 0;  //与天数数组挂钩
        }
        else if (yuefen[0] == 4)
            j2 = 3;
        else if (yuefen[0] == 7)
            j2 = 6;
        else if (yuefen[0] == 10)
            j2 = 9;

        for (i = 0,j3 = j2; i < 3; i++,j3++) {
            date[i] = zeller(year, yuefen[i], 1);  //求每个季度月份中第一天是星期几
            enddate[i] = zeller(year, yuefen[i],tianshu[j3]);
        }

        day1[0] = { 1 };
        day2[0] = { 1 };
        day3[0] = { 1 };//每个季度过后都需要对记录天数的数组初始化

        cout << "            " << yuefen[0] << "月                             " << yuefen[1] << "月                             " << yuefen[2] << "月" << endl;
        cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
        //格式

        for (i = 0; i < 6; i++) {  //每个月最多六行
            j1 = 0;
            if (yuefen[0] == 1) {
                j2 = 0;  //与天数数组挂钩
            }
            else if (yuefen[0] == 4)
                j2 = 3;
            else if (yuefen[0] == 7)
                j2 = 6;
            else if (yuefen[0] == 10)
                j2 = 9;

            for (day = day1[0]; day <= tianshu[j2] + date[j1]; day++) {
                if (day > date[j1])
                    cout << setiosflags(ios::left) << setw(4) << day - date[j1];  /*空格判断*/
                else
                    cout << "    ";

                if (day == tianshu[j2] + date[j1]) {  //输出完一个月后补空格
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
                    cout << setiosflags(ios::left) << setw(4) << day - date[j1];  /*空格判断*/
                else
                    cout << "    ";

                if (day == tianshu[j2] + date[j1]) {  //输出完一个月后补空格
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
                    cout << setiosflags(ios::left) << setw(4) << day - date[j1];  /*空格判断*/
                else
                    cout << "    ";

                if (day == tianshu[j2] + date[j1]) {  //输出完一个月后补空格
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
                day3[0] - date[j1] == tianshu[j2] + 1)    //一个季度的天数全部打印完毕，退出循环
                break;
        }
        cout << endl;
        for (k = 0; k < 3; k++) {
            yuefen[k] += 3;   //进入到下一个季度
        }

        if (yuefen[1] > 13) //打印完一整年的年历后退出循环
            break;

    }
}

int main()
{
    int nian;
    while (1) {
        cout << "请输入年份[1900-2100]" << endl;
        cin >> nian ;

        if (cin.fail() || nian < 1900 || nian > 2100) {
            /*按老师讲解修改后的错误处理，更加简单*/
            if (cin.fail()) {
                cout << "输入错误，请重新输入" << endl;
                cin.clear();
                cin.ignore(1024, '\n');
            }
            else if (nian < 1900 || nian > 2100)
                cout << "年份不正确，请重新输入" << endl;
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
