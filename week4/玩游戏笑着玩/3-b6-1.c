/* 2351131 ��04 Τ��ó */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    double a;
    int b, c, d, e, f, g, h, i, j, k, l, m;/* ��������Ҹ�λ����ֵ */
    printf("������[0-100��)֮�������:\n");
    scanf("%lf", &a);

    b = (int)(a / 1000000000) % 10;
    c = (int)(a / 100000000) % 10;
    d = (int)(a / 10000000) % 10;
    e = (int)(a / 1000000) % 10;
    f = (int)(a / 100000) % 10;
    g = (int)(a / 10000) % 10;
    h = (int)(a / 1000) % 10;
    i = (int)(a / 100) % 10;
    j = (int)(a / 10) % 10;
    k = (int)((a / 10 - (int)(a / 10)) * 10 + 0.001) % 10;
    l = (int)((a / 10 - (int)(a / 10)) * 100 + 0.001) % 10;
    m = (int)((a / 10 - (int)(a / 10)) * 1000 + 0.001) % 10;

    printf("��д�����:\n");

    if (b > 0) {
        switch (b) {
            case 9:
                printf("��");
                break;
            case 8:
                printf("��");
                break;
            case 7:
                printf("��");
                break;
            case 6:
                printf("½");
                break;
            case 5:
                printf("��");
                break;
            case 4:
                printf("��");
                break;
            case 3:
                printf("��");
                break;
            case 2:
                printf("��");
                break;
            case 1:
                printf("Ҽ");
                break;

        }
        if (c && b)
            printf("ʰ");
        else if ((int)(c && d && e && f && g && h && i && j && k) < 0)
            printf("ʰ��Բ");
        else
            printf("ʰ��");
    }
    else;

    if (c > 0) {
        switch (c) {
            case 9:
                printf("��");
                break;
            case 8:
                printf("��");
                break;
            case 7:
                printf("��");
                break;
            case 6:
                printf("½");
                break;
            case 5:
                printf("��");
                break;
            case 4:
                printf("��");
                break;
            case 3:
                printf("��");
                break;
            case 2:
                printf("��");
                break;
            case 1:
                printf("Ҽ");
                break;
        }
        if (d || e || f || g || h || i || j || k)
            printf("��");
        else if (!(d && e && f && g && h && i && j && k))
            printf("��Բ");
    }
    else;

    if (d > 0) {
        switch (d) {
            case 9:
                printf("��");
                break;
            case 8:
                printf("��");
                break;
            case 7:
                printf("��");
                break;
            case 6:
                printf("½");
                break;
            case 5:
                printf("��");
                break;
            case 4:
                printf("��");
                break;
            case 3:
                printf("��");
                break;
            case 2:
                printf("��");
                break;
            case 1:
                printf("Ҽ");
                break;
        }
        if (e || f || g > 0)
            printf("Ǫ");
        else if (e < 0 && f || g > 0)
            printf("Ǫ��");
        else if (e == 0 && f == 0 && g == 0 || h || i || j || k)
            printf("Ǫ��");
        else if (!(e && f && g && h && i && j && k))
            printf("Ǫ��Բ");
    }
    else if ((b || c) && (e || f || g))
        printf("��");
    else if (!(e && f && g && h && i && j && k))
        printf("");

    if (e > 0) {
        switch (e) {
            case 9:
                printf("��");
                break;
            case 8:
                printf("��");
                break;
            case 7:
                printf("��");
                break;
            case 6:
                printf("½");
                break;
            case 5:
                printf("��");
                break;
            case 4:
                printf("��");
                break;
            case 3:
                printf("��");
                break;
            case 2:
                printf("��");
                break;
            case 1:
                printf("Ҽ");
                break;

        }
        if (f || g)
            printf("��");
        else if ((!f && !g) && (h || i || j || k))
            printf("����");
        else if (!f && !g && !h && !i && !j && !k)
            printf("����Բ");
    }
    else if ((b || c || d) && (f || g) && !((b || c) && (e || f || g))
        )
        printf("��");
    else if (!(f && g && h && i && j && k))
        printf("");

    if (f > 0) {
        switch (f) {
            case 9:
                printf("��");
                break;
            case 8:
                printf("��");
                break;
            case 7:
                printf("��");
                break;
            case 6:
                printf("½");
                break;
            case 5:
                printf("��");
                break;
            case 4:
                printf("��");
                break;
            case 3:
                printf("��");
                break;
            case 2:
                printf("��");
                break;
            case 1:
                printf("Ҽ");
                break;

        }
        if (g)
            printf("ʰ");
        else if (g == 0 && (h || i || j || k))
            printf("ʰ��");
        else if (!(g && h && i && j && k))
            printf("ʰ��Բ");
    }
    else if (e && g)
        printf("��");
    else if (!(g && h && i && j && k))
        printf("");

    if (g > 0) {
        switch (g) {
            case 9:
                printf("��");
                break;
            case 8:
                printf("��");
                break;
            case 7:
                printf("��");
                break;
            case 6:
                printf("½");
                break;
            case 5:
                printf("��");
                break;
            case 4:
                printf("��");
                break;
            case 3:
                printf("��");
                break;
            case 2:
                printf("��");
                break;
            case 1:
                printf("Ҽ");
                break;

        }
        if (g > 0 && i || j || k)
            printf("��");
        else if (!(h && i && j && k))
            printf("��Բ");
    }
    else;

    if (h > 0) {
        switch (h) {
            case 9:
                printf("��");
                break;
            case 8:
                printf("��");
                break;
            case 7:
                printf("��");
                break;
            case 6:
                printf("½");
                break;
            case 5:
                printf("��");
                break;
            case 4:
                printf("��");
                break;
            case 3:
                printf("��");
                break;
            case 2:
                printf("��");
                break;
            case 1:
                printf("Ҽ");
                break;

        }
        if (!i && (j || k))
            printf("Ǫ��");
        else if (!i && !j && !k)
            printf("ǪԲ");
        else if (i > 0)
            printf("Ǫ");
    }
    else if ((b || c || d || e || f || g) && (i || j || k))
        printf("��");
    else if ((int)(i && j && k) < 0)
        printf("");

    if (i > 0) {
        switch (i) {
            case 9:
                printf("��");
                break;
            case 8:
                printf("��");
                break;
            case 7:
                printf("��");
                break;
            case 6:
                printf("½");
                break;
            case 5:
                printf("��");
                break;
            case 4:
                printf("��");
                break;
            case 3:
                printf("��");
                break;
            case 2:
                printf("��");
                break;
            case 1:
                printf("Ҽ");
                break;

        }
        if (!j && k)
            printf("����");
        else if (!j && !k)
            printf("��Բ");
        else if (j > 0)
            printf("��");
    }
    else if (!j && !k)
        printf("");

    if (j > 0) {
        switch (j) {
            case 9:
                printf("��");
                break;
            case 8:
                printf("��");
                break;
            case 7:
                printf("��");
                break;
            case 6:
                printf("½");
                break;
            case 5:
                printf("��");
                break;
            case 4:
                printf("��");
                break;
            case 3:
                printf("��");
                break;
            case 2:
                printf("��");
                break;
            case 1:
                printf("Ҽ");
                break;

        }
        if (j && k)
            printf("ʰ");
        else if (!k)
            printf("ʰԲ");
    }
    else if (!(i && j && k))
        printf("");

    if (k > 0) {
        switch (k) {
            case 9:
                printf("��");
                break;
            case 8:
                printf("��");
                break;
            case 7:
                printf("��");
                break;
            case 6:
                printf("½");
                break;
            case 5:
                printf("��");
                break;
            case 4:
                printf("��");
                break;
            case 3:
                printf("��");
                break;
            case 2:
                printf("��");
                break;
            case 1:
                printf("Ҽ");
                break;

        }
        printf("Բ");
    }
    else if (!b && !c && !d && !e && !f && !g && !h && !i && !j && !k && !l && !m)
        printf("��Բ");

    if (l || m) {
        if (l > 0) {
            switch (l) {
                case 9:
                    printf("��");
                    break;
                case 8:
                    printf("��");
                    break;
                case 7:
                    printf("��");
                    break;
                case 6:
                    printf("½");
                    break;
                case 5:
                    printf("��");
                    break;
                case 4:
                    printf("��");
                    break;
                case 3:
                    printf("��");
                    break;
                case 2:
                    printf("��");
                    break;
                case 1:
                    printf("Ҽ");
                    break;

            }
            if (m > 0)
                printf("��");
            else
                printf("����\n");
        }
        else if ((b || c || d || e || f || g || h || i || j || k))
            printf("��");
        if (m > 0) {
            switch (m) {
                case 9:
                    printf("��");
                    break;
                case 8:
                    printf("��");
                    break;
                case 7:
                    printf("��");
                    break;
                case 6:
                    printf("½");
                    break;
                case 5:
                    printf("��");
                    break;
                case 4:
                    printf("��");
                    break;
                case 3:
                    printf("��");
                    break;
                case 2:
                    printf("��");
                    break;
                case 1:
                    printf("Ҽ");
                    break;

            }
            printf("��\n");
        }
    }
    else
        printf("��\n");
    return 0;
}
