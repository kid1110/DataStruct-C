#ifndef ARRAYLIST_H
#define ARRAYLIST_H

 /**************************************************************
 *    Struct Define Section
 **************************************************************/
typedef  struct ArrayList
{   //数据类型大小 
    int trsize;
    //arraylist大小
    int size;
    //数据
    void** data;
    //数据长度
    int len;
}ArrayList,*ArrayListP;

ArrayListP CreateArrayList(int size,int trsize);

void ArrayJudgeCapacity(ArrayListP arr);

void ArrayListput(ArrayListP A,void* data,int trsize);

void ArrayAddValueAtIndex(ArrayListP arr,int index,void *const data);

void ArrayCheckIndex(ArrayListP arr,int index);

void ArrayAddValue(ArrayListP arr,void *const data);



#endif