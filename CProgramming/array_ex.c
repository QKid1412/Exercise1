#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000
/*
// know that function that make private copies, not changing the actual value.
void swap(int x, int y){
    int tmp = x;
    x = y;
    y = tmp;
    printf("In swap function, x is %d after swapped, y is %d after swapped\n", x, y);
}
void swapinfun(int x, int y){
    swap(x,y);
    printf("Using swap function in other function, x is %d after swapped, y is %d after swapped\n", x, y);

}
int main(){

    int x = 12;
    int y = 15;
    swap(x, y);

    printf("In main, x is %d after swapped, y is %d after swapped\n", x, y);

    swapinfun(x,y);

        printf("In main again, x is %d after swapped, y is %d after swapped\n", x, y);

    return 0;
}
*/

// Given an array A[] and a number x, check for pair in A[] with sum as x
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
    return;
}

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low, j;
    for(j = low+1; j <= high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[i]);
    return i;
}

void quicksort(int arr[], int low, int high){
    if(low >= high)
        return;
    int mid;
    mid = partition(arr, low, high);
    quicksort(arr, low, mid-1);
    quicksort(arr, mid+1, high);

}

void printAllPairs(int arr[], int len, int sum){
    // Sort array first;
    quicksort(arr, 0, len-1);

    /*int i;
    printf("In sorted order: ");
    for(i=0; i<len; i++){
        printf("%d ", arr[i]);
    }*/

    int low, high;
    low = 0;
    high = len-1;
    int count = 0;

    while(low < high && arr[low] < sum){
        if(arr[low] + arr[high] == sum){
            count++;
            printf("%d pairs found, %d and %d\n", count, arr[low], arr[high]);
            low++;
            high = len-1;
        }
        else if(arr[low] + arr[high] < sum){
            low++;
        }
        else if(arr[low] + arr[high] > sum){
            high--;
        }
    }
}

// using hashing find pairs

void printPairsHashing(int arr[], int len, int sum){
    int i, tmp, count=0;
    int table[MAX] = {0};

    for(i = 0; i < len; i++){
        tmp = sum-arr[i];
        if(tmp >=0 && table[tmp]==1){
            count++;
            printf("%d pairs found, %d and %d\n", count, tmp, arr[i]);
        }
        table[arr[i]] = 1;
    }

    printf("No such pairs");
}

// using hashing to find triplets add up to given sum

void printTripletsHashing(int arr[], int len, int sum){
    int i, j, tmp, count=0;
    int table[MAX] = {0};

    for(i = 0; i < len-1; i++){
        for(j = i+1; j < len; j++){
            tmp = sum - arr[i] - arr[j];
            if(tmp >= 0 && table[tmp] == 1){
                count++;
                printf("%d triplets found, %d %d %d\n", count, tmp, arr[i], arr[j]);
            }
            table[arr[j]] = 1;
        }
        tanle[arr[i] = 0;
    }
    printf("No such triplets");
}

char *removeSpaces(char *text) {
   int length, c, d;
   char *start;

   c = d = 0;

   length = strlen(text);

   start = (char*)malloc(length+1);

   if (start == NULL)
      exit(EXIT_FAILURE);

   while(*(text + c) == ' ' ){
        c++;
   }

   while (*(text+c) != '\0') {
      if (*(text+c) == ' ') {
         int temp = c + 1;
         if (*(text+temp) != '\0') {
            while (*(text+temp) == ' ' && *(text+temp) != '\0') {
               c++;
               temp++;
            }
         }
      }

      *(start+d) = *(text+c);
      c++;
      d++;
   }
   *(start+d)= '\0';

   return start;
}

void reverseWords(char *s){
    char *word_begin = s;
    char *temp = s;

    while(*temp){
        temp++;
        if(*temp == '\0'){
            reverse(word_begin, temp-1);
        }
        else if(*temp == ' '){
            reverse(word_begin, temp-1);
            word_begin = temp+1;
        }
    }
    reverse(s, temp-1);
}

void reverse(char* begin, char* end){
    char tmp;
    while(begin < end){
        tmp = *begin;
        *begin++ = *end;
        *end-- = tmp;
    }
}

int main()
{
    int A[] = {1, 4, 45, 9, 7, 13, 6, 8, 10, 3};
    int n = 16;
    int arr_size = sizeof(A)/sizeof(A[0]);

    //printPairsHashing(A, arr_size, n);

    char *str = "     hello,   world fyil   895689   4873     356 ";
    str = removeSpaces(str);
    printf("%s\n", str);
    reverseWords(str);
    printf("%s", str);

    return 0;
}

