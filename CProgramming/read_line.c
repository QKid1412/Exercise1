
#include <stdio.h>

int read_line(char str[], int n){
    int ch, i=0;

    while ((ch = getchar()) != '\n'){
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';

    printf("%s", str); //inside function str print till str[19];
    // because passing in the pointer and the array can be changed within the function.
    return i;
}
/*
    If read_line returns a str2, when print it within the function, it prints till str[n-1]
    but when call it in main function e.g. char* str2 = read_line(str,20);
    it prints in main function till str[9], same as str.

    Since the length of str[10] is fixed when declared, pointer char* str2 points to the
    same string without changable length. However, inside the function read_line,
    it prints till str[19](depends on n) since it's garbage/automatic memory storage,
    and will be discarded when the function returns.
*/



int main() {
    int count;

    char str[10] = "Hello";
    //char str[] = "Hello";

    //char *str; /* Wrong since it's a point, and we dont even know where it is pointing */
    //char *str = "HI"; /* Wrong since it's pointer, cannot modify content */
    count = read_line(str, 20);

    printf("\n%s", str); //print till str[9] if declared as str[10] = "Hello"

    //print till str[5] if declared as str[]= "Hello" --> length fixed to 6 which is {H', 'E', 'L', 'L', 'O', '\0'}

    return 0;
}
