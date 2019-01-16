
#include <stdio.h>
#include <stdlib.h>

unsigned char average(const char *filename){
    FILE *fp = fopen(filename, "rb");

    if(fp == NULL){
        return -1;
    }

    unsigned long long n = 0;
    unsigned long long sum = 0;
    unsigned char tmp[512];
    size_t read_count, i;

    while((read_count = fread(tmp, 1, sizeof(tmp), fp)) > 0){
        printf("read_count is: %d\n", read_count);
        n += read_count;
        for(i = 0; i < read_count; i++){
            sum += tmp[i];
        }
    }

    fclose(fp);

    int avg = 0;
    if(n) {
        avg = (int) (sum/n);
        printf("the total number of chars is: %d\n", n);
        printf("the total number of bytes is: %d\n", sum);
    }

    return (unsigned char) avg;
}

int main(){
    unsigned char result = average("echo");
    printf("%c", result);
    /*FILE *f_ptr;
    f_ptr = fopen("output.txt", "w");
    if(f_ptr == NULL) {
        printf("Could not write to file");
        return 0;
    }
    fprintf(f_ptr, "hello world\n");
    fflush(f_ptr);
    fclose(f_ptr);

    return 0;*/
}
