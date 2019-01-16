#include <stdio.h>

// sequential search

int linear_search(int a[], int target, int low, int high){
    int i;
    for (i = low; i < high; i++){
        if(a[i] == target){
            return i;
        }
    }
    return -1;
}

int binary_search(int a[], int target, int low, int high){
    int mid;

    while(low <= high){
        mid = (low + high) / 2;
        if(target == a[mid]){
            return mid;
        }
        if(target < a[mid]){
            high = mid - 1;
        }else if(target > a[mid]){
            low = mid + 1;
        }
    }
    return -1;
}

int binary_search_rec(int a[], int target, int low, int high){

    int mid;

    if(low > high){
        return -1;
    }
    mid =  = (low + high) / 2;

    if(target == a[mid])
        return mid;

    if(target < a[mid])
        return binary_search_rec(a, target, low, mid-1);
    else
        return binary_search_rec(a, target, mid+1, high);

}
