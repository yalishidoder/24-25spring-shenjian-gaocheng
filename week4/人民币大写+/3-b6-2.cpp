/* 2351131 ��04 Τ��ó */
#include <iostream>
using namespace std;
int main()
{
    double a;
    int b, c, d, e, f, g, h, i, j, k, l, m;/* ��������Ҹ�λ����ֵ */
    cout << "������[0-100��)֮�������:" << endl;
    cin >> a;

    b = int(a / 1000000000) % 10;
    c = int(a / 100000000) % 10;
    d = int(a / 10000000) % 10;
    e = int(a / 1000000) % 10;
    f = int(a / 100000) % 10;
    g = int(a / 10000) % 10;
    h = int(a / 1000) % 10;
    i = int(a / 100) % 10;
    j = int(a / 10) % 10;
    k = int((a / 10 - int(a / 10)) * 10 + 0.001) % 10;
    l = int((a / 10 - int(a / 10)) * 100 + 0.001) % 10;
    m = int((a / 10 - int(a / 10)) * 1000 + 0.001) % 10;
    cout << "��д�����:" << endl;

    if (b > 0) {
        switch (b) {
            case 9:
                cout << "��";
                break;
            case 8:
                cout << "��";
                break;
            case 7:
                cout << "��";
                break;
            case 6:
                cout << "½";
                break;
            case 5:
                cout << "��";
                break;
            case 4:
                cout << "��";
                break;
            case 3:
                cout << "��";
                break;
            case 2:
                cout << "��";
                break;
            case 1:
                cout << "Ҽ";
                break;

        }
        if (c && b)
            cout << "ʰ";
        else if (int(c && d && e && f  && g && h && i  && j  && k)<0)
            cout << "ʰ��Բ";
        else
            cout << "ʰ��";
    }
    else;

    if (c > 0) {
        switch (c) {
            case 9:
                cout << "��";
                break;
            case 8:
                cout << "��";
                break;
            case 7:
                cout << "��";
                break;
            case 6:
                cout << "½";
                break;
            case 5:
                cout << "��";
                break;
            case 4:
                cout << "��";
                break;
            case 3:
                cout << "��";
                break;
            case 2:
                cout << "��";
                break;
            case 1:
                cout << "Ҽ";
                break;
        }
        if (d || e || f || g || h || i || j || k)
             cout << "��";
        else if (!(d && e && f && g && h && i && j && k))
             cout << "��Բ";
    }
    else;

    if (d > 0) {
        switch (d) {
            case 9:
                cout << "��";
                break;
            case 8:
                cout << "��";
                break;
            case 7:
                cout << "��";
                break;
            case 6:
                cout << "½";
                break;
            case 5:
                cout << "��";
                break;
            case 4:
                cout << "��";
                break;
            case 3:
                cout << "��";
                break;
            case 2:
                cout << "��";
                break;
            case 1:
                cout << "Ҽ";
                break;
        }
        if (e || f || g > 0)
            cout << "Ǫ";
        else if (e < 0 && f || g > 0)
            cout << "Ǫ��";
        else if (e == 0 && f == 0 && g == 0 || h || i || j || k)
            cout << "Ǫ��";
        else if (!( e && f && g && h && i && j && k))
            cout << "Ǫ��Բ";
    }
    else if ((b || c )&& (e || f || g))
        cout << "��";
    else if (!( e && f && g && h && i && j && k))
        cout << "";

    if (e > 0) {
        switch (e) {
            case 9:
                cout << "��";
                break;
            case 8:
                cout << "��";
                break;
            case 7:
                cout << "��";
                break;
            case 6:
                cout << "½";
                break;
            case 5:
                cout << "��";
                break;
            case 4:
                cout << "��";
                break;
            case 3:
                cout << "��";
                break;
            case 2:
                cout << "��";
                break;
            case 1:
                cout << "Ҽ";
                break;

        }
        if (f  || g)
            cout << "��";
        else if ((!f  && !g) && (h || i || j || k))
            cout << "����";
        else if (! f && !g &&! h && !i && !j && !k)
            cout << "����Բ";
    }
    else if ((b || c||d) && ( f || g)&&!((b || c) && (e || f || g))
        )
        cout << "��";
    else if (!(f && g && h && i && j && k))
        cout << "";

    if (f > 0) {
        switch (f) {
            case 9:
                cout << "��";
                break;
            case 8:
                cout << "��";
                break;
            case 7:
                cout << "��";
                break;
            case 6:
                cout << "½";
                break;
            case 5:
                cout << "��";
                break;
            case 4:
                cout << "��";
                break;
            case 3:
                cout << "��";
                break;
            case 2:
                cout << "��";
                break;
            case 1:
                cout << "Ҽ";
                break;

        }
        if (g )
            cout << "ʰ";
        else if ( g==0 && (h || i || j || k))
            cout << "ʰ��";
        else if (!( g && h && i && j && k))
            cout << "ʰ��Բ";
    }
    else if (e&&g)
        cout << "��";
    else if (!(  g && h && i && j && k))
        cout << "";

    if (g > 0) {
        switch (g) {
            case 9:
                cout << "��";
                break;
            case 8:
                cout << "��";
                break;
            case 7:
                cout << "��";
                break;
            case 6:
                cout << "½";
                break;
            case 5:
                cout << "��";
                break;
            case 4:
                cout << "��";
                break;
            case 3:
                cout << "��";
                break;
            case 2:
                cout << "��";
                break;
            case 1:
                cout << "Ҽ";
                break;

        }
        if (g > 0 && i || j || k)
            cout << "��";
        else if (!( h && i && j && k))
            cout << "��Բ";
    }
    else;

    if (h > 0) {
        switch (h) {
            case 9:
                cout << "��";
                break;
            case 8:
                cout << "��";
                break;
            case 7:
                cout << "��";
                break;
            case 6:
                cout << "½";
                break;
            case 5:
                cout << "��";
                break;
            case 4:
                cout << "��";
                break;
            case 3:
                cout << "��";
                break;
            case 2:
                cout << "��";
                break;
            case 1:
                cout << "Ҽ";
                break;

        }
         if (!i && (j || k) )
            cout << "Ǫ��";
        else if (! i && !j && !k)
            cout << "ǪԲ";
        else if (i>0)
             cout << "Ǫ";
    }
    else if ((b || c||d||e || f || g)&&(i||j||k))
        cout << "��";
    else if (int( i && j && k)<0)
        cout << "";

    if (i > 0) {
        switch (i) {
            case 9:
                cout << "��";
                break;
            case 8:
                cout << "��";
                break;
            case 7:
                cout << "��";
                break;
            case 6:
                cout << "½";
                break;
            case 5:
                cout << "��";
                break;
            case 4:
                cout << "��";
                break;
            case 3:
                cout << "��";
                break;
            case 2:
                cout << "��";
                break;
            case 1:
                cout << "Ҽ";
                break;

        }
        if (!j && k)
            cout << "����";
        else if (!j && !k)
            cout << "��Բ";
        else if (j>0 )
            cout << "��";
    }
    else if (! j && !k)
        cout << "";

    if (j > 0) {
        switch (j) {
            case 9:
                cout << "��";
                break;
            case 8:
                cout << "��";
                break;
            case 7:
                cout << "��";
                break;
            case 6:
                cout << "½";
                break;
            case 5:
                cout << "��";
                break;
            case 4:
                cout << "��";
                break;
            case 3:
                cout << "��";
                break;
            case 2:
                cout << "��";
                break;
            case 1:
                cout << "Ҽ";
                break;

        }
        if (j && k)
            cout << "ʰ";
        else if (! k)
            cout << "ʰԲ";
    }
    else if (!(i && j && k))
        cout << "";

    if (k > 0) {
        switch (k) {
            case 9:
                cout << "��";
                break;
            case 8:
                cout << "��";
                break;
            case 7:
                cout << "��";
                break;
            case 6:
                cout << "½";
                break;
            case 5:
                cout << "��";
                break;
            case 4:
                cout << "��";
                break;
            case 3:
                cout << "��";
                break;
            case 2:
                cout << "��";
                break;
            case 1:
                cout << "Ҽ";
                break;

        }
        cout << "Բ";
    }
    else if (!b && !c && !d && !e && !f && !g && !h && !i && !j && !k && !l && !m)
        cout << "��Բ";

    if (l || m) {
        if (l > 0) {
            switch (l) {
                case 9:
                    cout << "��";
                    break;
                case 8:
                    cout << "��";
                    break;
                case 7:
                    cout << "��";
                    break;
                case 6:
                    cout << "½";
                    break;
                case 5:
                    cout << "��";
                    break;
                case 4:
                    cout << "��";
                    break;
                case 3:
                    cout << "��";
                    break;
                case 2:
                    cout << "��";
                    break;
                case 1:
                    cout << "Ҽ";
                    break;

            }
            if (m > 0)
                cout << "��";
            else
                cout << "����" << endl;
        }
        else if ((b || c || d || e || f || g||h||i || j || k))
            cout << "��";
        if (m > 0) {
            switch (m) {
                case 9:
                    cout << "��";
                    break;
                case 8:
                    cout << "��";
                    break;
                case 7:
                    cout << "��";
                    break;
                case 6:
                    cout << "½";
                    break;
                case 5:
                    cout << "��";
                    break;
                case 4:
                    cout << "��";
                    break;
                case 3:
                    cout << "��";
                    break;
                case 2:
                    cout << "��";
                    break;
                case 1:
                    cout << "Ҽ";
                    break;

            }
            cout << "��" << endl;
        }
    }
    else
        cout << "��" << endl;
    return 0;
}
    