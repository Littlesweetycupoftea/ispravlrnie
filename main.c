#include <stdio.h>

    int main(void) {
        int ch;
        FILE * pf_r, * pf_w;
        int presence[255] = {0};

        pf_r = fopen("old.txt", "r");
        pf_w = fopen("new.txt", "w");
        fprintf(stderr, "new.txt");

        for (int i = 0; i < 255; ++i) {
            while (feof(pf_r) == 0) {
                ch = getc(pf_r);
                if (presence[ch] != 1 && ch == i) {
                    presence[ch] = 1;
                    putc(ch, pf_w);
                }
            }
            fseek(pf_r, 0L, SEEK_SET);
        }
        fclose(pf_r);
        fclose(pf_w);
        return 0;
    }
