/* 2351131 ��04 Τ��ó */

#include <cstdio>   //NULL
//������������κ�ϵͳͷ�ļ�

/* ----- ���������κ���ʽ��ȫ�ֱ���/ȫ������/ֻ��ȫ�ֱ���/�궨��!!!!! ----- */

/* ����ʵ�ֲ��֣�{ }�ڵĶ����������������Ŀǰ��returnֻ��һ��ʾ�����ɸı� */
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strlen(const char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */;
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strcat(char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    int length = length1 + length2;
   
    if (s1 == NULL) 
    {
        return NULL;
    }
    s1 += length1;
    if (s2 == NULL) {  //��ʱ�����и���
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strncat(char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
    if (s2 == NULL) {  //��ʱ�����и���
        *s1 = '\0';
        s1 -= length1;
    }
    else {
        for (; *s2 && stop - s2; s1++, s2++) {
            *s1 = *s2;
        }
        s1 -= length < length1 + length2 ? length : length1 + length2;   //ָ������ָ�س�ʼλ��
    }


    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strcpy(char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int length2 = tj_strlen(s2);
    if (s1 == NULL)
    {
        return NULL;
    }
    if (s2 == NULL)   //��ʱ�����и���
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcmp(const char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    
    
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcasecmp(const char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strncmp(const char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strupr(char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strlwr(char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strchr(const char *str, const char ch)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strstr(const char *str, const char *substr)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strrchr(const char *str, const char ch)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strrstr(const char *str, const char *substr)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strrev(char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
