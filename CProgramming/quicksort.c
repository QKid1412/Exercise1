/* QuickSort Algorithm */
#include <stdio.h>

#define N 10

void quicksort(int a[], int low, int high);
int split(int a[], int low, int high);


void swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void quicksort(int a[], int low, int high){
    int middle;

    if(low >= high){
        return;
    }

    middle = split(a, low, high);
    quicksort(a, low, middle-1);
    quicksort(a, middle+1, high);

}

int split(int a[], int low, int high){
    //use first element as pivot
    int pivot_element = a[low];

    int i=low, j;

    for(j=low+1; j<=high; j++){
        if(a[j] <= pivot_element){
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[low], &a[i]);

    return i;
}


int main(void){
    int a[N], i;

    printf("Enter %d numbers to be sorted: ", N);
    for(i=0; i<N; i++){
        scanf("%d", &a[i]);
    }

    quicksort(a, 0, N-1);

    printf("In sorted order: ");
    for(i=0; i<N; i++){
        printf("%d ", a[i]);
    }
    return 0;

}
