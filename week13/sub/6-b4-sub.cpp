/* 2351131 信04 韦世贸 */

#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */;
    int length = 0;
    if (str == NULL)
        return 0;

    while (*str)
    {
        str++;
        length++;
    }
    return length;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strcat(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    int length = length1 + length2;
   
    if (s1 == NULL) 
    {
        return NULL;
    }
    s1 += length1;
    if (s2 == NULL) {  //此时不进行复制
        *s1 = '\0';
        s1 -= length1;
    }
    else {
        for (; *s2; s1++, s2++) {
            *s1 = *s2;
        }
        *s1 = '\0';
        s1 -= length;
    }


    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strncat(char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    int length = length1 + len;
    const char* stop;

    stop = s2 + len;
    if (s1 == NULL)
    {
        return NULL;
    }
    s1 += length1;
    if (s2 == NULL) {  //此时不进行复制
        *s1 = '\0';
        s1 -= length1;
    }
    else {
        for (; *s2 && stop - s2; s1++, s2++) {
            *s1 = *s2;
        }
        s1 -= length < length1 + length2 ? length : length1 + length2;   //指针重新指回初始位置
    }


    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strcpy(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length2 = tj_strlen(s2);
    if (s1 == NULL)
    {
        return NULL;
    }
    if (s2 == NULL)   //此时不进行复制
        *s1 = '\0';
    else {
        for (; *s2; s1++, s2++) {
            *s1 = *s2;
        }
        *s1 = '\0';
        s1 -= length2;
    }

    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strncpy(char *s1, const char *s2, const int len)
{
    const char* stop;

    stop = s2 + len;
    int length2 = tj_strlen(s2);
    if (s1 == NULL)
    {
        return NULL;
    }
 
    if (s2 != NULL) {
        for (; *s2 && stop - s2; s1++, s2++) {
            *s1 = *s2;
        }
        s1 -= length2 < len ? length2 : len;
    }
   

    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    
    
    if (s1 != NULL && s2 != NULL) {
        for (; *s1 || *s2; s1++, s2++) {
            if (*s1 != *s2) {
                return (*s1 - *s2);
            }
        }
    }
    else if (s1 == NULL && s2 != NULL)
        return -1;
    else if (s1 != NULL && s2 == NULL)
        return 1;

    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char mid1, mid2;

    if (s1 != NULL && s2 != NULL) {
        for (; *s1 || *s2; s1++, s2++) {
            if (*s1 != *s2) {
                if (*s1 >= 'A' && *s1 <= 'Z')
                    mid1 = 32 + *s1;
                else
                    mid1 = *s1;
                if (*s2 >= 'A' && *s2 <= 'Z')
                    mid2 = 32 + *s2;
                else
                    mid2 = *s2;
                if (mid1 == mid2)
                    continue;
                else
                    return (mid1 - mid2);
            }
        }
    }
    else if (s1 == NULL && s2 != NULL)
        return -1;
    else if (s1 != NULL && s2 == NULL)
        return 1;
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    int shortlen = length1 < length2 ? length1 : length2;
    int final_len = shortlen < len ? shortlen : len;
    
    const char* stop1, * stop2;
    stop1 = s1;
    stop2 = s2;

    stop1 += final_len;
    stop2 += final_len;
    if (s1 != NULL && s2 != NULL) {
        if (shortlen < len) {
            for (; stop1 - s1 >= 0 && stop2 - s2 >= 0; s1++, s2++) {
                if (*s1 != *s2) {
                    return (*s1 - *s2);
                }
            }
        }
        else
            for (; stop1 - s1 && stop2 - s2; s1++, s2++) {
                if (*s1 != *s2) {
                    return (*s1 - *s2);
                }
            }
    }
    else if (s1 == NULL && s2 != NULL)
        return -1;
    else if (s1 != NULL && s2 == NULL)
        return 1;

    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    int shortlen = length1 < length2 ? length1 : length2;
    int final_len = shortlen < len ? shortlen : len;
    char mid1, mid2;
    const char* stop1, * stop2;
    stop1 = s1;
    stop2 = s2;

    stop1 += final_len;
    stop2 += final_len;
    if (s1 != NULL && s2 != NULL) {
        if (shortlen < len) {
            for (; stop1 - s1 >= 0 && stop2 - s2 >= 0; s1++, s2++) {
                if (*s1 != *s2) {
                    if (*s1 >= 'A' && *s1 <= 'Z')
                        mid1 = 32 + *s1;
                    else
                        mid1 = *s1;
                    if (*s2 >= 'A' && *s2 <= 'Z')
                        mid2 = 32 + *s2;
                    else
                        mid2 = *s2;
                    if (mid1 == mid2)
                        continue;
                    else
                        return (mid1 - mid2);
                }
            }
        }
        else
            for (; stop1 - s1 && stop2 - s2; s1++, s2++) {
                if (*s1 != *s2) {
                    if (*s1 >= 'A' && *s1 <= 'Z')
                        mid1 = 32 + *s1;
                    else
                        mid1 = *s1;
                    if (*s2 >= 'A' && *s2 <= 'Z')
                        mid2 = 32 + *s2;
                    else
                        mid2 = *s2;
                    if (mid1 == mid2)
                        continue;
                    else
                        return (mid1 - mid2);
                }
            }
    }
    else if (s1 == NULL && s2 != NULL)
        return -1;
    else if (s1 != NULL && s2 == NULL)
        return 1;
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strupr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length1 = tj_strlen(str);
    if (str == NULL)
        return NULL;
    for (; *str; str++) {
        if (*str >= 'a' && *str <= 'z')
            *str -= 32;
    }
    str -= length1;
    return str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strlwr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length1 = tj_strlen(str);
    if(str == NULL)
        return NULL;
    for (; *str; str++) {
        if (*str >= 'A' && *str <= 'Z')
            *str += 32;
    }
    str -= length1;
    return str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return NULL;
    int i = 0;
    for (; *str; str++) {
        i++;
        if (ch - *str == 0)
            return i;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char *str, const char *substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL || substr == NULL)
        return NULL;
    int length2 = tj_strlen(substr);
    int right = 0, i = 0;
    for (; *str; str++) {
        i++;
        if (*substr == *str) {
            for (; *substr; substr++,str++) {
                if (*str != *substr)
                    break;
                else
                    right++;
            }
            if (right == length2)
                return i;
        }
        substr -= right;
        str -= right;
        right = 0;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return NULL;

    int length1 = tj_strlen(str);
    int i = length1;
    str += length1;
    str--;
    for (; *str;str--,i--) {
        if (ch == *str)
            return i;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char *str, const char *substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL || substr == NULL)
        return NULL;

    int length1 = tj_strlen(str);
    int length2 = tj_strlen(substr);
    int i = length1;

    str += length1;
    str--;
    substr += length2;
    substr--;

    int right = 0;
    for (; *str; str--,i--) {
        if (*substr == *str) {
            for (; *substr; substr--, str--) {
                if (*str != *substr)
                    break;
                else
                    right++;
            }
            if (right == length2)
                return i - length2 + 1;
        }

        substr += right;
        str += right;
        right = 0;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strrev(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return NULL;

    int length1 = tj_strlen(str);
    char mid, * stop, * end;
    stop = str;
    stop += (length1 - 1) / 2;
    end = str;
    end += (length1 - 1);
    for (; stop - str;str++,end--) {
        mid = *end;
        *end = *str;
        *str = mid;
    }
    str -= (length1 - 1) / 2;
    return str;
}
