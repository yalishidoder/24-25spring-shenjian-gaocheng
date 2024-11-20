/* 2351131 ÐÅ04 Î¤ÊÀÃ³ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    double a;
    int b, c, d, e, f, g, h, i, j, k, l, m;/* ¶¨ÒåÈËÃñ±Ò¸÷Î»µÄÊýÖµ */
    printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:\n");
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

    printf("´óÐ´½á¹ûÊÇ:\n");

    if (b > 0) {
        switch (b) {
            case 9:
                printf("¾Á");
                break;
            case 8:
                printf("°Æ");
                break;
            case 7:
                printf("Æâ");
                break;
            case 6:
                printf("Â½");
                break;
            case 5:
                printf("Îé");
                break;
            case 4:
                printf("ËÁ");
                break;
            case 3:
                printf("Èþ");
                break;
            case 2:
                printf("·¡");
                break;
            case 1:
                printf("Ò¼");
                break;

        }
        if (c && b)
            printf("Ê°");
        else if ((int)(c && d && e && f && g && h && i && j && k) < 0)
            printf("Ê°ÒÚÔ²");
        else
            printf("Ê°ÒÚ");
    }
    else;

    if (c > 0) {
        switch (c) {
            case 9:
                printf("¾Á");
                break;
            case 8:
                printf("°Æ");
                break;
            case 7:
                printf("Æâ");
                break;
            case 6:
                printf("Â½");
                break;
            case 5:
                printf("Îé");
                break;
            case 4:
                printf("ËÁ");
                break;
            case 3:
                printf("Èþ");
                break;
            case 2:
                printf("·¡");
                break;
            case 1:
                printf("Ò¼");
                break;
        }
        if (d || e || f || g || h || i || j || k)
            printf("ÒÚ");
        else if (!(d && e && f && g && h && i && j && k))
            printf("ÒÚÔ²");
    }
    else;

    if (d > 0) {
        switch (d) {
            case 9:
                printf("¾Á");
                break;
            case 8:
                printf("°Æ");
                break;
            case 7:
                printf("Æâ");
                break;
            case 6:
                printf("Â½");
                break;
            case 5:
                printf("Îé");
                break;
            case 4:
                printf("ËÁ");
                break;
            case 3:
                printf("Èþ");
                break;
            case 2:
                printf("·¡");
                break;
            case 1:
                printf("Ò¼");
                break;
        }
        if (e || f || g > 0)
            printf("Çª");
        else if (e < 0 && f || g > 0)
            printf("ÇªÁã");
        else if (e == 0 && f == 0 && g == 0 || h || i || j || k)
            printf("ÇªÍò");
        else if (!(e && f && g && h && i && j && k))
            printf("ÇªÍòÔ²");
    }
    else if ((b || c) && (e || f || g))
        printf("Áã");
    else if (!(e && f && g && h && i && j && k))
        printf("");

    if (e > 0) {
        switch (e) {
            case 9:
                printf("¾Á");
                break;
            case 8:
                printf("°Æ");
                break;
            case 7:
                printf("Æâ");
                break;
            case 6:
                printf("Â½");
                break;
            case 5:
                printf("Îé");
                break;
            case 4:
                printf("ËÁ");
                break;
            case 3:
                printf("Èþ");
                break;
            case 2:
                printf("·¡");
                break;
            case 1:
                printf("Ò¼");
                break;

        }
        if (f || g)
            printf("°Û");
        else if ((!f && !g) && (h || i || j || k))
            printf("°ÛÍò");
        else if (!f && !g && !h && !i && !j && !k)
            printf("°ÛÍòÔ²");
    }
    else if ((b || c || d) && (f || g) && !((b || c) && (e || f || g))
        )
        printf("Áã");
    else if (!(f && g && h && i && j && k))
        printf("");

    if (f > 0) {
        switch (f) {
            case 9:
                printf("¾Á");
                break;
            case 8:
                printf("°Æ");
                break;
            case 7:
                printf("Æâ");
                break;
            case 6:
                printf("Â½");
                break;
            case 5:
                printf("Îé");
                break;
            case 4:
                printf("ËÁ");
                break;
            case 3:
                printf("Èþ");
                break;
            case 2:
                printf("·¡");
                break;
            case 1:
                printf("Ò¼");
                break;

        }
        if (g)
            printf("Ê°");
        else if (g == 0 && (h || i || j || k))
            printf("Ê°Íò");
        else if (!(g && h && i && j && k))
            printf("Ê°ÍòÔ²");
    }
    else if (e && g)
        printf("Áã");
    else if (!(g && h && i && j && k))
        printf("");

    if (g > 0) {
        switch (g) {
            case 9:
                printf("¾Á");
                break;
            case 8:
                printf("°Æ");
                break;
            case 7:
                printf("Æâ");
                break;
            case 6:
                printf("Â½");
                break;
            case 5:
                printf("Îé");
                break;
            case 4:
                printf("ËÁ");
                break;
            case 3:
                printf("Èþ");
                break;
            case 2:
                printf("·¡");
                break;
            case 1:
                printf("Ò¼");
                break;

        }
        if (g > 0 && i || j || k)
            printf("Íò");
        else if (!(h && i && j && k))
            printf("ÍòÔ²");
    }
    else;

    if (h > 0) {
        switch (h) {
            case 9:
                printf("¾Á");
                break;
            case 8:
                printf("°Æ");
                break;
            case 7:
                printf("Æâ");
                break;
            case 6:
                printf("Â½");
                break;
            case 5:
                printf("Îé");
                break;
            case 4:
                printf("ËÁ");
                break;
            case 3:
                printf("Èþ");
                break;
            case 2:
                printf("·¡");
                break;
            case 1:
                printf("Ò¼");
                break;

        }
        if (!i && (j || k))
            printf("ÇªÁã");
        else if (!i && !j && !k)
            printf("ÇªÔ²");
        else if (i > 0)
            printf("Çª");
    }
    else if ((b || c || d || e || f || g) && (i || j || k))
        printf("Áã");
    else if ((int)(i && j && k) < 0)
        printf("");

    if (i > 0) {
        switch (i) {
            case 9:
                printf("¾Á");
                break;
            case 8:
                printf("°Æ");
                break;
            case 7:
                printf("Æâ");
                break;
            case 6:
                printf("Â½");
                break;
            case 5:
                printf("Îé");
                break;
            case 4:
                printf("ËÁ");
                break;
            case 3:
                printf("Èþ");
                break;
            case 2:
                printf("·¡");
                break;
            case 1:
                printf("Ò¼");
                break;

        }
        if (!j && k)
            printf("°ÛÁã");
        else if (!j && !k)
            printf("°ÛÔ²");
        else if (j > 0)
            printf("°Û");
    }
    else if (!j && !k)
        printf("");

    if (j > 0) {
        switch (j) {
            case 9:
                printf("¾Á");
                break;
            case 8:
                printf("°Æ");
                break;
            case 7:
                printf("Æâ");
                break;
            case 6:
                printf("Â½");
                break;
            case 5:
                printf("Îé");
                break;
            case 4:
                printf("ËÁ");
                break;
            case 3:
                printf("Èþ");
                break;
            case 2:
                printf("·¡");
                break;
            case 1:
                printf("Ò¼");
                break;

        }
        if (j && k)
            printf("Ê°");
        else if (!k)
            printf("Ê°Ô²");
    }
    else if (!(i && j && k))
        printf("");

    if (k > 0) {
        switch (k) {
            case 9:
                printf("¾Á");
                break;
            case 8:
                printf("°Æ");
                break;
            case 7:
                printf("Æâ");
                break;
            case 6:
                printf("Â½");
                break;
            case 5:
                printf("Îé");
                break;
            case 4:
                printf("ËÁ");
                break;
            case 3:
                printf("Èþ");
                break;
            case 2:
                printf("·¡");
                break;
            case 1:
                printf("Ò¼");
                break;

        }
        printf("Ô²");
    }
    else if (!b && !c && !d && !e && !f && !g && !h && !i && !j && !k && !l && !m)
        printf("ÁãÔ²");

    if (l || m) {
        if (l > 0) {
            switch (l) {
                case 9:
                    printf("¾Á");
                    break;
                case 8:
                    printf("°Æ");
                    break;
                case 7:
                    printf("Æâ");
                    break;
                case 6:
                    printf("Â½");
                    break;
                case 5:
                    printf("Îé");
                    break;
                case 4:
                    printf("ËÁ");
                    break;
                case 3:
                    printf("Èþ");
                    break;
                case 2:
                    printf("·¡");
                    break;
                case 1:
                    printf("Ò¼");
                    break;

            }
            if (m > 0)
                printf("½Ç");
            else
                printf("½ÇÕû\n");
        }
        else if ((b || c || d || e || f || g || h || i || j || k))
            printf("Áã");
        if (m > 0) {
            switch (m) {
                case 9:
                    printf("¾Á");
                    break;
                case 8:
                    printf("°Æ");
                    break;
                case 7:
                    printf("Æâ");
                    break;
                case 6:
                    printf("Â½");
                    break;
                case 5:
                    printf("Îé");
                    break;
                case 4:
                    printf("ËÁ");
                    break;
                case 3:
                    printf("Èþ");
                    break;
                case 2:
                    printf("·¡");
                    break;
                case 1:
                    printf("Ò¼");
                    break;

            }
            printf("·Ö\n");
        }
    }
    else
        printf("Õû\n");
    return 0;
}
