#include <stdio.h>
#include <string.h>
#include "runner.h"
#define MAXBYTES 1000000

int main(int argc, char **argv){
    FILE *file = fopen(argv[1], "r");
    char bytes[MAXBYTES];
    size_t len = 0;
    char ch;
    while((ch = getc(file)) != EOF)
        bytes[len++] = ch;
    bytes[len++] = '\n';
    run(bytes);
}