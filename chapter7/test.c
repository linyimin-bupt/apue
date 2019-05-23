#include <stdio.h>

FILE *open_data(char *filename) {
    FILE *fp;
    char data_buf[1024];

    if ((fp = fopen(filename, "r")) == NULL) {
        return NULL;
    }

    if (setvbuf(fp, data_buf, _IOLBF, 1024) != 0) {
        return (NULL);
    }
    return(fp);
}

int main(void) {
    for (int i = 0; i < 10000; i++) {
        open_data(i + "");
    }
    return 0;
}