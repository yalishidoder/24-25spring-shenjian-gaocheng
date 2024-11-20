/* 2351131 信04 韦世贸 */
#include <iostream>
using namespace std;
int main()
{
    cout << "请输入年，月，日" << endl;
    int a, b, c, d;
    cin >> a >> b >> c;
    if (b <= 12){
        if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)) {
            switch (b) {
                case 1:
                    if (c > 31) {
                        cout << "输入错误-日与月的关系非法" << endl;
                    }
                    else
                        cout << a << "-" << b << "-" << c << "是" << a << "年的第" << c << "天" << endl;
                    break;
                case 2:
                    if (c > 29) {
                        cout << "输入错误-日与月的关系非法" << endl;
                    }
                    else {
                        d = c + 31;
                        cout << a << "-" << b << "-" << c << "是" << a << "年的第" << d << "天" << endl;
                    }
                    break;
                case 3:
                    if (c > 31) {
                        cout << "输入错误-日与月的关系非法" << endl;
                    }
                    else {
                        d = c + 31 + 29;
                        cout << a << "-" << b << "-" << c << "是" << a << "年的第" << d << "天" << endl;
                    }
                    break;
                case 4:
                    if (c > 30) {
                        cout << "输入错误-日与月的关系非法" << endl;
                    }
                    else {
                        d = c + 31 + 29 + 31;
                        cout << a << "-" << b << "-" << c << "是" << a << "年的第" << d << "天" << endl;
                    }
                    break;
                case 5:
                    if (c > 31) {
                        cout << "输入错误-日与月的关系非法" << endl;
                    }
                    else {
                        d = c + 31 + 29 + 31 + 30;
                        cout << a << "-" << b << "-" << c << "是" << a << "年的第" << d << "天" << endl;
                    }
                    break;
                case 6:
                    if (c > 30) {
                        cout << "输入错误-日与月的关系非法" << endl;
                    }
                    else {
                        d = c + 31 + 29 + 31 + 30 + 31;
                        cout << a << "-" << b << "-" << c << "是" << a << "年的第" << d << "天" << endl;
                    }
                    break;
                case 7:
                    if (c > 31) {
                        cout << "输入错误-日与月的关系非法" << endl;
                    }
                    else {
                        d = c + 31 + 29 + 31 + 30 + 31 + 30;
                        cout << a << "-" << b << "-" << c << "是" << a << "年的第" << d << "天" << endl;
                    }
                    break;
                case 8:
                    if (c > 31) {
                        cout << "输入错误-日与月的关系非法" << endl;
                    }
                    else {
                        d = c + 31 + 29 + 31 + 30 + 31 + 30 + 31;
                        cout << a << "-" << b << "-" << c << "是" << a << "年的第" << d << "天" << endl;
                    }
                    break;
                case 9:
                    if (c > 30) {
                        cout << "输入错误-日与月的关系非法" << endl;
                    }
                    else {
                        d = c + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31;
                        cout << a << "-" << b << "-" << c << "是" << a << "年的第" << d << "天" << endl;
                    }
                    break;
                case 10:
                    if (c > 31) {
                        cout << "输入错误-日与月的关系非法" << endl;
                    }
                    else {
                        d = c + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
                        cout << a << "-" << b << "-" << c << "是" << a << "年的第" << d << "天" << endl;
                    }
                    break;
                case 11:
                    if (c > 30) {
                        cout << "输入错误-日与月的关系非法" << endl;
                    }
                    else {
                        d = c + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
                        cout << a << "-" << b << "-" << c << "是" << a << "年的第" << d << "天" << endl;
                    }
                    break;
                case 12:
                    if (c > 31) {
                        cout << "输入错误-日与月的关系非法" << endl;
                    }
                    else {
                        d = c + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
                        cout << a << "-" << b << "-" << c << "是" << a << "年的第" << d << "天" << endl;
                    }
                    break;
            }
        }
        else {
            switch (b) {
                case 1:
                    if (c > 31) {
                        cout << "输入错误-日与月的关系非法" << endl;
                    }
                    else
                        cout << a << "-" << b << "-" << c << "是" << a << "年的第" << c << "天" << endl;
                    break;
                case 2:
                    if (c > 28) {
                        cout << "输入错误-日与月的关系非法" << endl;
                    }
                    else {
                        d = c + 31;
                        cout << a << "-" << b << "-" << c << "是" << a << "年的第" << d << "天" << endl;
                    }
                    break;
                case 3:
                    if (c > 31) {
                        cout << "输入错误-日与月的关系非法" << endl;
                    }
                    else {
                        d = c + 31 + 28;
                        cout << a << "-" << b << "-" << c << "是" << a << "年的第" << d << "天" << endl;
                    }
                    break;
                case 4:
                    if (c > 30) {
                        cout << "输入错误-日与月的关系非法" << endl;
                    }
                    else {
                        d = c + 31 + 28 + 31;
                        cout << a << "-" << b << "-" << c << "是" << a << "年的第" << d << "天" << endl;
                    }
                    break;
                case 5:
                    if (c > 31) {
                        cout << "输入错误-日与月的关系非法" << endl;
                    }
                    else {
                        d = c + 31 + 28 + 31 + 30;
                        cout << a << "-" << b << "-" << c << "是" << a << "年的第" << d << "天" << endl;
                    }
                    break;
                case 6:
                    if (c > 30) {
                        cout << "输入错误-日与月的关系非法" << endl;
                    }
                    else {
                        d = c + 31 + 28 + 31 + 30 + 31;
                        cout << a << "-" << b << "-" << c << "是" << a << "年的第" << d << "天" << endl;
                    }
                    break;
                case 7:
                    if (c > 31) {
                        cout << "输入错误-日与月的关系非法" << endl;
                    }
                    else {
                        d = c + 31 + 28 + 31 + 30 + 31 + 30;
                        cout << a << "-" << b << "-" << c << "是" << a << "年的第" << d << "天" << endl;
                    }
                    break;
                case 8:
                    if (c > 31) {
                        cout << "输入错误-日与月的关系非法" << endl;
                    }
                    else {
                        d = c + 31 + 28 + 31 + 30 + 31 + 30 + 31;
                        cout << a << "-" << b << "-" << c << "是" << a << "年的第" << d << "天" << endl;
                    }
                    break;
                case 9:
                    if (c > 30) {
                        cout << "输入错误-日与月的关系非法" << endl;
                    }
                    else {
                        d = c + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
                        cout << a << "-" << b << "-" << c << "是" << a << "年的第" << d << "天" << endl;
                    }
                    break;
                case 10:
                    if (c > 31) {
                        cout << "输入错误-日与月的关系非法" << endl;
                    }
                    else {
                        d = c + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
                        cout << a << "-" << b << "-" << c << "是" << a << "年的第" << d << "天" << endl;
                    }
                    break;
                case 11:
                    if (c > 30) {
                        cout << "输入错误-日与月的关系非法" << endl;
                    }
                    else {
                        d = c + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
                        cout << a << "-" << b << "-" << c << "是" << a << "年的第" << d << "天" << endl;
                    }
                    break;
                case 12:
                    if (c > 31) {
                        cout << "输入错误-日与月的关系非法" << endl;
                    }
                    else {
                        d = c + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
                        cout << a << "-" << b << "-" << c << "是" << a << "年的第" << d << "天" << endl;
                    }
                    break;
            }
        }
    }
    else
        cout << "输入错误-月份不正确" << endl;
    return 0;
}
