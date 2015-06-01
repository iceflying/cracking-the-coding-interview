/*
 * Author: Xin Quan <quanxin1991@163.com>
 */

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <string.h>

typedef int BOOLEAN;

BOOLEAN permutation(char *str1, char *str2){
    unsigned len1, len2;
    unsigned char_set[256] = {0};
    unsigned ascii;
    unsigned i;
    len1 = strlen(str1);
    len2 = strlen(str2);
    if (len1 != len2){
        return FALSE;
    }
    for (i=0; i<len1; ++i){
        ascii = (unsigned)str1[i];
        char_set[ascii] += 1;
    }
    for (i=0; i<len2; ++i){
        ascii = (unsigned)str2[i];
        char_set[ascii] -= 1;
    }
    for (i=0; i<256; ++i){
        if (char_set[i] != 0){
            return FALSE;
        }
    }
    return TRUE;
}

void test(BOOLEAN (*func4test)(char *, char *), char *str1, char *str2){
    if (func4test(str1, str2)){
        printf("\"%s\" is the anagram of \"%s\"\n", str1, str2);;
    } else {
        printf("\"%s\" is not the anagram of \"%s\"\n", str1, str2);;
    }
}

int main(){
    char str1[] = "dog";
    char str2[] = "god";
    char str3[] = "tiny";
    test(permutation, str1, str2);
    test(permutation, str1, str3);
    return 0;
}
