#include "sorts.h"

void swap(void* a, void* b,size_t size){ 
    void* temp = malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}


void bubble_sort(void* arr, size_t n, size_t size, Comparator cmp){
    int flag = 0;
    for(int i = n-1;i>=0;i--){
        for(int j  = 0; j <i;j++){
            void* first = (char*)arr + j*size;
            void* second = (char*)arr + (j+1)*size;
            if(cmp(first,second)>0){
                flag = 1;
                swap(first,second, size);
            }
        }
        if(flag == 0){
            break;
        }
    }
}

void insert_sort(void* arr, size_t n, size_t size, Comparator cmp){
    //TODO: add things here
}

void select_sort(void* arr, size_t n, size_t size, Comparator cmp){
    //TODO: add things here
}


void quick_sort(void* arr, size_t n, size_t size, Comparator cmp){
    //TODO: add content 
}





