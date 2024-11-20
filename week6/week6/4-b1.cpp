/* 2351131 信04 韦世贸 */
#include <iostream>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	/* 按需完成 */
	double qian;
    cout << "请输入[0-100亿)之间的数字:" << endl;
    cin >> qian;

    while (qian < 0 || qian >= 10000000000) {
        cout << "请输入[0-100亿)之间的数字:" << endl;
        cin >> qian;
        if (qian >= 0 && qian < 10000000000)
            break;
    }
	int b, c, d, e, f, g, h, i, j, k, l, m;/* 定义人民币各位的数值 */
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
	cout << "大写结果是:" << endl;

    daxie(b, 0);
    if (b > 0) {
        if (c && b)
            cout << "拾";
        else if (int(c && d && e && f && g && h && i && j && k) < 0)
            cout << "拾亿圆";
        else
            cout << "拾亿";
    }
    else;

    daxie(c, 0);/*亿位就不会多输出0*/
    if (c > 0) {
        if (d || e || f || g || h || i || j || k)
            cout << "亿";
        else if (!(d && e && f && g && h && i && j && k))
            cout << "亿圆";
    }
    else;

    daxie(d, d);
    if (d > 0) {
    
        if (e || f || g > 0)
            cout << "仟";
        else if (e == 0 && f == 0 && g == 0 || h || i || j || k)
            cout << "仟万";
        else if (!(e && f && g && h && i && j && k))
            cout << "仟万圆";
    }
    else if ((b || c) && (e || f || g))
        daxie(d, 1);
    else if (!(e && f && g && h && i && j && k))
        cout << "";

    daxie(e, e);
    if (e > 0) {
        if (f || g)
            cout << "佰";
        else if ((!f && !g) && (h || i || j || k))
            cout << "佰万";
        else if (!f && !g && !h && !i && !j && !k)
            cout << "佰万圆";
    }
    else if ((b || c || d) && (f || g) && !((b || c) && (e || f || g)) )
        daxie(e, 1);
    else if (!(f && g && h && i && j && k))
        cout << "";

    daxie(f, f);
    if (f > 0) {
        if (g)
            cout << "拾";
        else if (g == 0 && (h || i || j || k))
            cout << "拾万";
        else if (!(g && h && i && j && k))
            cout << "拾万圆";
    }
    else if (e && g)
        daxie(f, 1);
    else if (!(g && h && i && j && k))
        cout << "";

    daxie(g, g);
    if (g > 0) {
        if (g > 0 && i || j || k)
            cout << "万";
        else if (!(h && i && j && k))
            cout << "万圆";
    }
    else;

    daxie(h, h);
    if (h > 0) {
        if (!i && (j || k)) { /*由于千位到个位的逻辑与千万位到万位的逻辑不一样*/
            cout << "仟";  /*且千位到个位的逻辑更加复杂QAQ*/
            daxie(0, 1);
        }
        else if (!i && !j && !k)
            cout << "仟圆";
        else if (i > 0)
            cout << "仟";
    }
    else if ((b || c || d || e || f || g) && (i || j || k))
        daxie(h,1);
    else if (int(i && j && k) < 0)
        cout << "";

    daxie(i, i);
    if (i > 0) {
        if (!j && k) {
            cout << "佰";
            daxie(0, 1);
        }
        else if (!j && !k)
            cout << "佰圆";
        else if (j > 0)
            cout << "佰";
    }
    else if (!j && !k)
        cout << "";

    daxie(j, j);
    if (j > 0) {
        if (j && k)
            cout << "拾";
        else if (!k)
            cout << "拾圆";
    }
    else if (!(i && j && k))
        cout << "";
    
    daxie(k, k);
    if(k)
        cout << "圆";
    else if (!b && !c && !d && !e && !f && !g && !h && !i && !j && !k && !l && !m) {
        daxie(k, 1);
        cout << "圆";
    }
    

    if (l || m) {
        daxie(l, l);
        if (l > 0) {
            if (m > 0)
                cout << "角";
            else
                cout << "角整" << endl;
        }
        else if ((b || c || d || e || f || g || h || i || j || k))
            daxie(l, 1);

        daxie(m, m);
        if (m > 0){
            cout << "分" << endl;
        }
    }
    else
        cout << "整" << endl;
	
	return 0;
}
