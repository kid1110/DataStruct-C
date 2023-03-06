#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "arraylist.h"

//inital capacity of arraylist
#define ARRAYLIST_INITIAL_CAPACITY 4
#define ARRAYLIST_GROWN_SPEED 2

//macro shift a section memory
#define arraylist_memshift(set,offset,length) memmove((set)+(offset),(set),(length)*sizeof(set))
arraylist* arraylist_create(){
    arraylist* res = malloc(sizeof(arraylist));
    res->size = 0;
    //allocate data
    res->data = malloc(sizeof(void*) *ARRAYLIST_INITIAL_CAPACITY);
    res->capacity = ARRAYLIST_INITIAL_CAPACITY;
    return res;
}

void arraylist_allocate(arraylist *list,unsigned int size){
    assert(size >0);
    if(size >list->capacity){
        unsigned int new_capacity = list->capacity;
        while(new_capacity <size){
            new_capacity *= ARRAYLIST_GROWN_SPEED;
        }
        list->data = realloc(list->data,sizeof(void*) *new_capacity);
        assert(list->data);
        list->capacity = new_capacity;
    }
}

// inline unsigned int arraylist_size(arraylist* list){
//     return list->size;
// }

void* arraylist_pop(arraylist *list){
    assert(list->size >0);
    unsigned int size = list->size;
    return list->data[--size];
}

void* arraylist_get(arraylist* list, unsigned int index){
    assert(index <list->size);
    return list->data;
}

void arraylist_set(arraylist *list,unsigned int index,void* value){
    assert(index <list->size);
    list->data[index] = value;
}

void arraylist_insert(arraylist* list, unsigned int index, void* value){

    arraylist_allocate(list,list->size+1);
    arraylist_memshift(list->data+index,1,list->size-index);
    list->data[index] = value;
    list->size++;
}

void* arraylist_remove(arraylist* list, unsigned int index){
    void* value = list->data[index];
    arraylist_memshift(list->data+index+1,-1,list->size-index);
    list->size--;
    return value;
}
void arraylist_clear(arraylist* list){
    list->size = 0;
    list->data = realloc(list->data,sizeof(void*)*ARRAYLIST_INITIAL_CAPACITY);
}


