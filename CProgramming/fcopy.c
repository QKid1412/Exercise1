/* copies a file */
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
    FILE *source_fp, *dest_fp;
    int ch;

    if(argc != 3){
        exit(EXIT_FAILURE);
    }

    if((source_fp = fopen(argv[1], "rb")) == NULL){
        exit(EXIT_FAILURE);
    }

    if((dest_fp = fopen(argv[2], "wb")) == NULL){
        fclose(source_fp);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(source_fp)) != EOF){
        putc(ch, dest_fp);
    }

    fclose(source_fp);
    fclose(dest_fp);
    return 0;
}
