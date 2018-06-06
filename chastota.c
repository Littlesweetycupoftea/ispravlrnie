#include <stdio.h>

    unsigned c[255];

int main(void) {
    FILE * F;
    int i;
    F = fopen("old.txt", "r");

    memset(c, 0, 255);

    while (!feof(F)) {
        c[fgetc(F)]++;
    }

    for (i = 0; i < 256; i++) {
        if (c[i]) {
            printf("simvol %c : %5u raz\n", i, c[i]);
        }
    }
}
