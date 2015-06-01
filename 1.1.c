/*
 * Author: Xin Quan <quanxin1991@163.com>
 */

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <string.h>

typedef int BOOLEAN;

BOOLEAN is_unique_chars(char *str){
    /* check with a boolean hash map of char set */
    unsigned len = strlen(str);
    BOOLEAN char_set[256] = {0};
    unsigned ascii;
    unsigned i;
    if (len > 256){
        return TRUE;
    }
    for (i=0; i<len; ++i){
        ascii = (unsigned)str[i];
        if (char_set[ascii] == TRUE){
            return TRUE;
        }
        char_set[ascii] = TRUE;
    }
    return FALSE;
}

BOOLEAN is_unique_chars2(char *str){
    /* check with a bit vector */
    unsigned len = strlen(str);
    unsigned checker_vector = 0;
    unsigned char_flag;
    unsigned i;
    if (len > 256){
        return TRUE;
    }
    for (i=0; i<len; ++i){
        char_flag = 1 << (unsigned)str[i];
        if (checker_vector & 1 << char_flag){
            return TRUE;
        }
        checker_vector |= char_flag;
    }
    return FALSE;
}

void test(BOOLEAN (*func4test)(char *), char *str){
    if (func4test(str)){
        printf("\"%s\" is a string with unique chars.\n", str);
    } else {
        printf("\"%s\" is a string without unique chars.\n", str);
    }
}

int main(){
    char str_with_unique_chars[] = "abca";
    char str_without_unique_chars[] = "abcd";
    test(is_unique_chars, str_with_unique_chars);
    test(is_unique_chars, str_without_unique_chars);
    test(is_unique_chars2, str_with_unique_chars);
    test(is_unique_chars2, str_without_unique_chars);
    return 0;
}
