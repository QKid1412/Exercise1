#include<stdlib.h>
#include<stdio.h>
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

void SelectionSort(int a[], int len){
    int i,j;
    for( i=0; i<len-1; ++i){
        int pos = i;
        for( j=i; j<len; ++j){
            if( a[j]< a[pos] ){
                pos = j;
            }
        }
        swap(&a[i], &a[pos]);
        /*int tmp = a[i];
        a[i] = a[pos];
        a[pos] = tmp;*/
        printArr(a, len);
    }
}

void InsertionSort(int a[], int len){
    int i,j;

    /*for( i=1; i<len; ++i){
        int j = i;
        while( j>0 & a[j]<a[j-1]){
            swap(&a[j], &a[j-1]);
            j--;
        }
        printArr(a,len);
    }*/

    for( i=1; i<len; ++i){
        int tmp = a[i];
        int j = i;
        while( j>0 && tmp<a[j-1]){
            a[j] = a[j-1];
            j--;
        }
        a[j] = tmp;
        printArr(a,len);
    }
}

void BubbleSort(int a[], int len){
    int i,j;

    for( i=0; i<len-1; ++i){
        for( j=0; j<len-i-1; ++j){
            if( a[j]>a[j+1]){
                swap(&a[j], &a[j+1]);
            }
        }
        printArr(a,len);
    }
}

void Merge(int a[], int start, int mid, int end){

    int len1 = mid-start+1;
    int len2 = end-mid;
    int subArr1[len1], subArr2[len2];
    int i,j,k;

    for( i=0; i<len1; ++i){
        subArr1[i] = a[start+i];
    }
    for( j=0; j<len2; ++j){
        subArr2[j] = a[mid+1+j];
    }

    i = 0;
    j = 0;
    k = start;
    while( i<len1 && j <len2){

        if( subArr1[i] <= subArr2[j]){
            a[k] = subArr1[i];
            i++;
        }
        else{
            a[k] = subArr2[j];
            j++;
        }
        k++;
    }

    while( i<len1 ){
        a[k] = subArr1[i];
        i++;
        k++;
    }
    while( j<len2 ){
        a[k] = subArr2[j];
        j++;
        k++;
    }

}

void MergeSort(int a[], int start, int end){
    if( start >= end ){ return; }
    int mid = start + (end - start)/2;
    MergeSort(a, start, mid);
    MergeSort(a, mid+1, end);

    Merge(a, start, mid, end);
    printArr(a, end-start+1);
}


int partition(int a[], int start, int end){
    //printf("Before Partition\n");
    //printArr(a,end-start+1);

    // last ele as pivot, partition--> <pivot;pivot;>pivot
    int pivot = a[end];
    int i = start-1;
    int j;

    for( j=start; j<end; j++){
        if( a[j] <= pivot){
            i++;
            swap(&a[i], &a[j]);
        }

        printf("Processing...");
        printArr(a,end-start+1);
    }
    swap(&a[i+1], &a[end]);

    //printf("After Partition\n");
    //printArr(a,end-start+1);
    return (i+1);
}

void QuickSort(int a[], int start, int end){
    if( start >= end){ return; }
    int pivot;
    pivot = partition(a, start, end);

    QuickSort(a, start, pivot-1);
    QuickSort(a, pivot+1, end);
    //printArr(a,end-start+1);
}


int main() {
   //printf("Hello, World! \n");
   int arr[8] = {4,3,2,10,12,1,5,6};
   //SelectionSort(arr,9);
   //InsertionSort(arr,8);
   //MergeSort(arr,0,7);
   QuickSort(arr,0,7);
   printArr(arr,8);
   int arr2[5] = {5,1,4,2,8};
   BubbleSort(arr2,5);
   return 0;
}
