#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void checkType(void* arg1,void* arg2,int size);
int main(){
    printf("Int size: %d\n",sizeof(int));
    char a = 27,y=2;
    printf("Int size: %d\n",sizeof(a));
    checkType(&a,&y,sizeof(typeof(*&a)));
    printf("%d\n",a);
    printf("%d\n",y);
    return 0;
   
}

void checkType(void* arg1,void* arg2,int size){
    printf("size: %d\n",size);
    char buffer[sizeof(typeof(arg1))];
    memcpy(buffer,arg1,size);
    memcpy(arg1,arg2,size);
    memcpy(arg2,buffer,size);
}