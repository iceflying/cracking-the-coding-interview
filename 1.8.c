/*
 * Author: Xin Quan <quanxin1991@163.com>
 */

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int BOOLEAN;

BOOLEAN isSubstring(char *str, char *substr){
    if (strstr(str, substr)){
        return TRUE;
    }
    return FALSE;
}

BOOLEAN is_rotation(char *str1, char *str2){
/*
 * Assume that str2 is the rotation of str1.
 * str1 can be split into x and y which let str1 = x + y;
 * and str2 can also be split into x and y which let str2 = y + x.
 * What is clear is that str2 (y + x) is the substring of str1 + str1 (x + y + x + y)
 */

    int len1, len2;
    char *str1_str1;
    len1 = strlen(str1);
    len2 = strlen(str2);
    if (len1 != len2){
        return FALSE;
    }
    str1_str1 = (char *)malloc(sizeof(*str1_str1) * (len1 * 2 + 1));
    memset(str1_str1, '\0', len1 * 2 + 1);
    strcpy(str1_str1, str1);
    strcat(str1_str1, str1);
    if (isSubstring(str1_str1, str2)){
        return TRUE;
    }
    return FALSE;
}

void test(BOOLEAN (*func4test)(char *, char *), char *str1, char *str2){
    if (func4test(str1, str2)){
        printf("\"%s\" is the rotation of \"%s\"\n", str2, str1);
    } else {
        printf("\"%s\" is not the rotation of \"%s\"\n", str2, str1);
    }
}

int main(){
    char str1[] = "waterbottle";
    char str2[] = "erbottlewat";
    char str3[] = "waterbollte";
    test(is_rotation, str1, str2);
    test(is_rotation, str1, str3);
    return 0;
}
