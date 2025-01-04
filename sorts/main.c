#include "sorts.h"


int int_cmp(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int main(){
    int arr[] = {3, 2, 1, 4, 5};
    swap(&arr[0], &arr[1], sizeof(int));
    printf("%d\n", arr[0]);
    printf("%d\n", arr[1]);
    bubble_sort(arr, 5, sizeof(int), int_cmp);
    for(int i = 0; i < 5; i++){
        printf("%d\n", arr[i]);
    }
    return 0;
}