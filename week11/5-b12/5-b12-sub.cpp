/* 2351131 信04 韦世贸 */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return 0只是一个示例，可改变 */

/* 不允许定义任何形式的外部全局、静态全局、宏定义、只读变量 */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i;
    int length = 0;
    for (i = 0; i < 65472; i++) {
        if (str[i] == '\0') {
            length = i ;
            break;
        }
    }
    return length; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcat(char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    int length = length1 + length2;
    int i,j;
    for (i = length1,j=0; i < length ,j<length2; i++,j++) {
        s1[i] = s2[j];
    }
    s1[i] = '\0';
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncat(char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    int length = length1 + len;
    int i, j;
    if (len <= length2) {
        for (i = length1, j = 0; i < length, j < len; i++, j++) {
            s1[i] = s2[j];
        }
    }
    else
        for (i = length1, j = 0; i < length1 + length2, j < length2; i++, j++) {
            s1[i] = s2[j];
        }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcpy(char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length2 = tj_strlen(s2);
    int i;
    for (i = 0; i < length2; i++) {
        if (s2[i] == '\0')
            break;
        s1[i] = s2[i];
    }
    s1[i] = '\0';
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncpy(char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length2 = tj_strlen(s2);
    int i;
    if (len <= length2) {
        for (i = 0; i < len; i++) {
            s1[i] = s2[i];
        }
    }
    else
        for (i = 0; i < length2; i++) {
            s1[i] = s2[i];
        }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    int length = length1 > length2 ? length1 : length2;
    int i;
    for (i = 0; i < length; i++) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    int length = length1 > length2 ? length1 : length2;
    int i;
    char mid1, mid2;
    for (i = 0; i < length; i++) {
        if (s1[i] != s2[i]) {
            if (s1[i] > 64 && s1[i] < 91)
                mid1 = 32 + s1[i];
            else
                mid1 = s1[i];
            if (s2[i] > 64 && s2[i] < 91)
                mid2 = 32 + s2[i];
            else
                mid2 = s2[i];
            if (mid1 == mid2)
                continue;
            else
                return (mid1 - mid2);
        }
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    int shortlen = length1 < length2 ? length1 : length2;
    int i;

    if (shortlen >= len) {
        for (i = 0; i < len; i++) {
            if (s1[i] != s2[i]) {
                return (s1[i] - s2[i]);
            }
        }
    }
    else {
        for (i = 0; i <= shortlen; i++) {
            if (s1[i] != s2[i]) {
                return (s1[i] - s2[i]);
            }
        }
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    int shortlen = length1 < length2 ? length1 : length2;
    int i;
    char mid1, mid2;
    if (shortlen >= len) {
        for (i = 0; i < len; i++) {
            if (s1[i] != s2[i]) {
                if (s1[i] > 64 && s1[i] < 91)
                    mid1 = 32 + s1[i];
                else
                    mid1 = s1[i];
                if (s2[i] > 64 && s2[i] < 91)
                    mid2 = 32 + s2[i];
                else
                    mid2 = s2[i];
                if (mid1 == mid2)
                    continue;
                else
                    return (mid1 - mid2);
            }
        }
    }
    else {
        for (i = 0; i <= shortlen; i++) {
            if (s1[i] != s2[i]) {
                if (s1[i] > 64 && s1[i] < 91)
                    mid1 = 32 + s1[i];
                else
                    mid1 = s1[i];
                if (s2[i] > 64 && s2[i] < 91)
                    mid2 = 32 + s2[i];
                else
                    mid2 = s2[i];
                if (mid1 == mid2)
                    continue;
                else
                    return (mid1 - mid2);
            }
        }
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strupr(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length1 = tj_strlen(str);
    int i;
    for (i = 0; i < length1; i++) {
        if (str[i] > 96 && str[i] < 123)
            str[i] -= 32;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlwr(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length1 = tj_strlen(str);
    int i;
    for (i = 0; i < length1; i++) {
        if (str[i] > 64 && str[i] < 91)
            str[i] += 32;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char str[], char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length1 = tj_strlen(str);
    int i;
    for (i = 0; i < length1; i++) {
        if (ch - str[i] == 0)
            return i + 1;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char str[], const char substr[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length1 = tj_strlen(str);
    int length2 = tj_strlen(substr);
    int i,j=0;
    int right=0;
    for (i = 0; i < length1; i++) {
        if (substr[0] - str[i] == 0) {
            for (j = 0; j < length2; j++) {
                if (str[i + j] != substr[j])
                    break;
                else
                    right++;
            }
            if (right == length2)
                return i + 1;
        }
        right = 0;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char str[], const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length1 = tj_strlen(str);
    int i;
    for (i = length1; i >= 0 ; i--) {
        if (ch - str[i] == 0)
            return i + 1;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char str[], const char substr[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length1 = tj_strlen(str);
    int length2 = tj_strlen(substr);
    int i, j = 0;
    int right = 0;
    for (i = length1; i >= 0 ; i--) {
        if (substr[length2 - 1] - str[i] == 0) {
            for (j = 0; j < length2; j++) {
                if (str[i - j] != substr[length2 - j - 1])
                    break;
                else
                    right++;
            }
            if (right == length2)
                return i - length2 + 2;
        }
        right = 0;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrev(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length1 = tj_strlen(str);
    int i;
    char mid;
    for (i = 0; i < (length1 - 1) / 2; i++) {
        mid = str[length1 - 1 - i];
        str[length1 - 1 - i] = str[i];
        str[i] = mid;
    }
    return 0; //return值可根据需要修改
}
