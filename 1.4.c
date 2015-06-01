/*
 * Author: Xin Quan <quanxin1991@163.com>
 */

#include <stdio.h>
#include <string.h>

void replace_spaces(char *str, unsigned length){
    unsigned num_of_spaces = 0;
    unsigned end;
    int i;
    for (i=0; i<length; ++i){
        if (str[i] == ' '){
            num_of_spaces += 1;
        }
    }
    end = length + num_of_spaces * 2;
    str[end--] = '\0';
    for (i = length - 1; i>=0; --i){
        if (str[i] == ' '){
            str[end--] = '0';
            str[end--] = '2';
            str[end--] = '%';
        } else {
            str[end--] = str[i];
        }
    }
}

void test(void (*func4test)(char *, unsigned), char *str, unsigned length){
    func4test(str, length);
    printf("The replaced string is \"%s\"\n", str);
}

int main(){
    char str[20] = "Mr John Smith";
    test(replace_spaces, str, strlen(str));
    return 0;
}
