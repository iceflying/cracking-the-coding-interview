/*
 * Author: Xin Quan <quanxin1991@163.com>
 */

#include <stdio.h>

void swap(char *a, char *b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse(char *str){
    char *end;
    /* find the end of the string */
    for (end = str; *end; ++end);
    /* back to the real end of the character */
    --end;
    while (str < end){
        swap(str, end);
        ++str;
        --end;
    }
}

void test(void (*func4test)(char *), char *str){
    func4test(str);
    printf("The reversed string is \"%s\"\n", str);
}

int main(){
    char odd_str[] = "abc";
    char even_str[] = "abcd";
    test(reverse, odd_str);
    test(reverse, even_str);
    return 0;
}
