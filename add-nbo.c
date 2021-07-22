#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include <Winsock2.h>

int main(int argc, char** argv) {
    char buffer[10] = { 0 };
    char buffer2[10] = { 0 };

    FILE* fp = fopen(argv[1], "r");
    fread(buffer, sizeof(char), 10, fp);
    int a = atoi(buffer);

    FILE* fp2 = fopen(argv[2], "r");
    fread(buffer2, sizeof(char), 10, fp2);
    int b = atoi(buffer2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", a, a, b, b, a + b, a + b);
    return 0;
}