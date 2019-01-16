#include <stdio.h>
#include <float.h>

void swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void printArr(int a[], int len){
    int k;
    for( k=0; k<len; ++k){
            printf("%d ", a[k]);
        }
        printf("\n");
}

int LinearSearch(int a[], int len, int target){
    int i;
    for( i=0; i<len; ++i){
        if( a[i] == target){
            return i;
        }
    }
    return -1;
}

int BinarySearch(int a[], int len, int target){

   int i,j;
   if( len <=0 ){
    return -1;
   }

   int start = 0;
   int end = len-1;

   while( start<end ){
    int mid = start + (end-start)/2;
    if( a[mid] == target ){
        return mid;
    }
    if( a[mid]<target ){
        start = mid+1;
    }
    else if( a[mid] > target ){
        end = mid-1;
    }
   }
   return -1;
}

int BinarySearchRecursion(int a[], int start, int end, int target){

    // base case
    if( start>end ){ return -1; }
    int mid = start + (end-start)/2;
    if( a[mid] == target){
        return mid;
    }
    if( a[mid]>target ){
        return BinarySearchRecursion(a, start, mid-1, target);
    }
    if( a[mid]<target ){
        return BinarySearchRecursion(a, mid+1, end, target);
    }
}

int main() {
   //printf("Hello, World! \n");
   int arr[8] = {1,2,3,4,5,6,7,8};
   //int res = BinarySearchRecursion(arr,0,7,7);
   int res = BinarySearch(arr,8,7);
   printf("result: %d  ", res);
}
