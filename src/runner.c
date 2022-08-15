#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#define SIZEARG 512
#define SIZEarr 1024
#define SIZECOMMAND 512

char arr[SIZEarr];
size_t pos = 0;
int arrumulator;

int compare(char *str, char *str2){
    int out = 0;
    for(; *str == *str2; str++, str2++)
        out = 1;
    if(*str != '\0' && *str2 != '\0' && *str != *str2)
        out = 0;
    return out;
}

void run(char *bytes){
    char command[SIZECOMMAND];
    char arg[SIZEARG];
    size_t len = 0;
    size_t lencommand = 0;
    int start = 1;
    for(; *bytes != '\0'; bytes++){
        if(*bytes == ' ' && start){
            start = 0;
            continue;
        } else if(*bytes == '\n' || *bytes == ';'){
            int num = atoi(arg);
            if(compare(command, "printstr")){
                printf("%s", arg);
            } else if(compare(command, "addstr")){
                strcat(arr, arg);
                pos += strlen(arg);
            } else if(compare(command, "printarr")){
                for(char *ptr = arr; *ptr != 0; ptr++)
                    printf("%c", *ptr);
            } else if(compare(command, "printascii")){
                printf("%c", num);
            } else if(compare(command, "printchar")){
                printf("%c", arr[pos]);
            } else if(compare(command, "setpos")){
                pos = num;
            } else if(compare(command, "setchar")){
                if(num)
                    arr[pos] = num;
                else
                    arr[pos] = arg[0];
            }

            start = 1;
            lencommand = 0;
            len = 0;
            memset(arg, 0, sizeof(arg));
            memset(command, 0, sizeof(command));
            continue;
        }
        if(start && *bytes != ' ')
            command[lencommand++] = *bytes;
        else
            arg[len++] = *bytes;
    }
}