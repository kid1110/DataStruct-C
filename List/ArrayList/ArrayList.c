#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>
#include"../../headers/List/ArrayList.h"



ArrayListP CreateArrayList(int size,int trsize){
    ArrayListP A = calloc(1,sizeof(ArrayList));
    printf("%d\n",trsize*size);
    A->data = calloc(size*trsize, sizeof(void*));
    A->size = size;
    A->trsize = trsize;
    A->len = 0;
    return A;
}
void ArrayCheckIndex(ArrayListP arr,int index){
    if(index <0 || index >arr->len-1){
        if(arr->len == 0){
            printf("空数组越界: index:%d",index);
        }else{
        printf("数组越界 index:%d range:[0 %d]",index,arr->len-1);
    }
    assert(false);
    }
}

void ArrayJudgeCapacity(ArrayListP arr){
    if(arr->len ==arr->size){
        arr->size == arr->size *2;
        arr->data = realloc(arr->data,arr->size);
    }
}
void ArrayAddValue(ArrayListP arr,void *const data){
    ArrayAddValueAtIndex(arr,arr->len,data);
}
void ArrayAddValueAtIndex(ArrayListP arr,int index,void *const data){
    ArrayJudgeCapacity(arr);
    if(index != arr->len){
        ArrayCheckIndex(arr,index);
    }
    arr->len = arr->len + 1;
    for(int i = arr->len-1;i>index;i--){
        arr->data[i] = arr->data[i-1];
    }
    arr->data[index] = data;

}
void* ArrayGetValueOfIndex(ArrayListP arr,int index){
    ArrayCheckIndex(arr,index);
    return arr->data[index];
}
// int main(){
//     struct User{
//         char* value;
//     }user;
//     ArrayListP A = CreateArrayList(10,sizeof(char*));

//     for(int i = 0; i <2;i++){
//         struct User *data = malloc(sizeof(struct User));
//         data->value = "test";
//         ArrayAddValue(A,data);    
//     }

//     for(int i = 0; i <A->len;i++){
//         struct User *data = ArrayGetValueOfIndex(A,i);
//         printf("data:%s \n",data->value);
//     }
//     return 0;
// }
