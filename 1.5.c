/*
 * Author: Xin Quan <quanxin1991@163.com>
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *compress(char *str){
    unsigned len;
    char *compressed_str;
    int i;
    char last;
    int count;
    char str_of_count[10];
    int index;
    unsigned len_of_count;
    len = strlen(str);
    compressed_str = (char *)malloc(sizeof(*str) * (len+1));
    memset(compressed_str, '\0', len+1);
    for (i=0, index = 0, last = str[0], count = 0; i<len+1 && index < len; ++i){
        if (str[i] == last){
            count += 1;
        } else {
            compressed_str[index++] = last;
            memset(str_of_count, '\0', 10);
            sprintf(str_of_count, "%d", count);
            len_of_count = strlen(str_of_count);
            if (index + len_of_count >= len){
                free(compressed_str);
                return str;
            }
            strncpy(&(compressed_str[index]), str_of_count, len_of_count);
            index += len_of_count;
            last = str[i];
            count = 0;
            --i;
        }
    }
    return compressed_str;
}

void test(char *(*func4test)(char *), char *str){
    printf("The compressed string of \"%s\" is \"%s\"\n", str, func4test(str));
}

int main(){
    char str1[] = "aabcccccaaa";
    char str2[] = "abc";
    test(compress, str1);
    test(compress, str2);
    return 0;
}
