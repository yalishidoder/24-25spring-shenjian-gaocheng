/* 2351131 信04 韦世贸 */
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;
int main()
{
	int nian, yue, date,day;
	cout << "请输入年份(2000-2030)和月份(1-12) : ";
	cin >> nian >> yue;
	while (cin.fail())  {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "输入非法，请重新输入" << endl;
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> nian>> yue;
	}
	while ((nian < 2000 || nian >2030) || (yue < 1 || yue >12)) { /*两个while是为了使程序符合demo的逻辑*/
		cin.clear();
		cin.ignore((nian < 2000 || nian >2030) || (yue < 1 || yue >12));
		cout << "输入非法，请重新输入" << endl;
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> nian >> yue;
	}
	cout << "请输入" << nian << "年" << yue << "月1日的星期(0-6表示星期日-星期六) : ";
	cin >> date;
	while (cin.fail() || date < 0 || date > 6) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "输入非法，请重新输入" << endl;
		cout << "请输入" << nian << "年" << yue << "月1日的星期(0-6表示星期日-星期六) : ";
		cin >> date;
		cout << endl;
	}
	cout << endl;
	cout << nian << "年" << yue << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;

	if ((yue % 2 && yue <= 7) || (yue >= 8 && yue % 2 == 0)) {  /*大月*/
		for (day = 1; day <= 31 + date; day++) {
			if(day > date)
				cout << setw(4) << day - date <<"    ";  /*空格判断*/
			else 
				cout <<"        ";
			if (day % 7 == 0)  /*这样的换行思路比较简单，也不需要重新定义变量*/
				cout << endl;
			else;
			
		}
	}

	if (yue==9 || yue == 6 || yue == 4 ||yue==11) { /*小月*/
		for (day = 1; day <= 30 + date; day++) {
			if (day > date)
				cout << setw(4) << day - date << "    ";  
			else
				cout << "        ";
			if (day % 7 == 0)  
				cout << endl;
			else;
		}
	}

	if (yue==2) {
		if ((nian % 4 == 0 && nian % 100 != 0) || (nian % 400 == 0)) { /*闰年*/
			for (day = 1; day <= 29 + date; day++) {
				if (day > date)
					cout << setw(4) << day - date << "    ";
				else
					cout << "        ";
				if (day % 7 == 0)
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
				if (day % 7 == 0)
					cout << endl;
				else;

			}
		}
	}
	cout << endl;
	return 0;
}