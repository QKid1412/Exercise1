#include <stdio.h>
#include <float.h>


int gcd(int a, int b){
    while(b!=0){
        int tmp = b;
        b = a%b;
        a = tmp;
        printf("newa = %d\n", a);
        printf("newb = %d\n", b);
    }
    printf("gcd = %d\n", a);

    return a;
}

int dub_chk(int a[], int len){
    int i = len;
    while(i>0){
        i--;
        int j = i-1;
        while(j>=0){
            if(a[j] == a[i]){
                return 1;
            }
        }
    }
    return 0;
}

int main() {
   /* my first program in C */
   printf("Hello, World! \n");

   /*printf("Storage size for float : %d \n", sizeof(float));
   printf("Minimum float positive value: %E\n", FLT_MIN );
   printf("Maximum float positive value: %E\n", FLT_MAX );
   printf("Precision value: %d\n", FLT_DIG );*/

   gcd(18,12);

   return 0;
   return 0;
}
