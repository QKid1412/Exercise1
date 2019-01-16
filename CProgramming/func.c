#include <stdbool.h>
#include <stdio.h>


// Check if a number is prime
/*bool is_prime(int n) {
    int divisor;

    if(n <= 1){ return false; }

    for(divisor = 2; divisor*divisor <= n; divisor++){
        if(n % divisor == 0){
           return false;
        }
    }
    return true;
}*/

void check_prime() {
    int n, divisor;

    printf("Enter a number to check if it's prime: ");
    scanf("%d", &n);

    if(n <= 1){
        printf("No need to check\n");
        return;
    }

    for(divisor = 2; divisor*divisor <= n; divisor++){
        if(n % divisor == 0){
           printf("Not Prime\n");
           return;
        }
    }

    printf("Prime\n");
    return;
}
int main(void) {

    // Test for is_prime(n) function
    /*
    int n;

    printf("Enter a number to check if it's prime: ");
    scanf("%d", &n);
    if (is_prime(n)){
        printf("Prime\n");
    } else {
        printf("Not Prime\n");
    }
    */

    check_prime();

    return 0;
}
