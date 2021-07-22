#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

int main(int argc, char** argv) {
    FILE       *f1,  *f2;
    uint32_t   n1,   n2;

    if (argc <= 2) {
        printf("syntax : add-nbo <file1> <file2> \n");
        printf("sample : add-nbo a.bin c.bin \n");
        return -1;
    }

    f1 = fopen(argv[1], "rb");
    f2 = fopen(argv[2], "rb");

    if (f1 == NULL || f2 == NULL) {
        printf("file open error \n");
        return -1;
    }

    fread(&n1, 1, sizeof(uint32_t), f1);
    fread(&n2, 1, sizeof(uint32_t), f2);

    n1 = ntohl(n1);
    n2 = ntohl(n2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, (n1 + n2), (n1 + n2));

    fclose(f1);
    fclose(f2);

    return 0;
}
