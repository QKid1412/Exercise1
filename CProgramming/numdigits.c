#include <stdio.h>

int main(){
    int digits=0, n;

    printf("Enter a digit: ");
    scanf("%d", &n);

    do{
        n /=10;
        digits++;
    } while (n > 0);

    printf("The number of digits is %d.\n", digits);
    return 0;

}
