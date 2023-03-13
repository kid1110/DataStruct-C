#include <stdlib.h>
#include <assert.h>
#include "SingleLinkedList.h"



/**
 * @brief 
 * insert value in singleLinkedlist
 * @param list singleLinkedlist
 * @param index from 0 to size-1;
 * @param value 
 * @return ** void 
 */
void Singlelinkedlist_insert(SingleLinkedList** list,unsigned int index,void* value){
    assert(index >=0 && index <= (*list)->size);
    SingleLinkedListNode* ptr = (*list)->next;
    for(int i = 0; i <index;i++){
            ptr = ptr->next;
    }
    SingleLinkedListNode* new_data = malloc(sizeof(SingleLinkedListNode));
    new_data->data = value;
    new_data->next = ptr->next;
    ptr->next = new_data;
    (*list)->size++;
}

/**
 * @brief 
 * clear a singlelinkedlist
 * 
 * @param list 
 * @return ** void 
 */
void SingleLinkedList_clear(SingleLinkedList** list){
    if((*list)->size == 0){
        return;
    }
    SingleLinkedListNode* ptr = (*list)->next->next;
    SingleLinkedListNode* next = ptr;
    while(ptr != NULL && ptr->next != NULL){
        next = ptr->next;
        free(ptr);
        ptr = next;
    }
    free(ptr);
    (*list)->next->next = NULL;
    ptr = NULL;
    (*list)->size = 0;
}


bool Singlelinkedlist_empty(SingleLinkedList** list){
    return (*list)->size == 0;
}
/**
 * @brief 
 * create a singleLinkedList
 * @return ** SingleLinkedList* 
 */
SingleLinkedList* SingleLinkedList_create(){
    //malloc a singlinkedlist
    SingleLinkedList* res = malloc(sizeof(SingleLinkedList));
    res->size = 0;
    SingleLinkedListNode* dump = malloc(sizeof(SingleLinkedListNode));
    dump->next = NULL;
    res->next = dump;
    return res;
}
/**
 * @brief 
 * return a list->data;
 * @param list 
 * @param index 
 * @return ** void* 
 */
void* SingleLinkedList_get(SingleLinkedList** list,unsigned int index){
    assert(index >=0);
    SingleLinkedListNode* ptr = (*list)->next;
    for(int i = 0; i <index;i++){
        ptr = ptr->next;
    }
    return ptr->next->data;
}

void SingleLinkedList_destroy(SingleLinkedList** list){
    SingleLinkedList_clear(list);
    free((*list)->next);
    (*list)->next = NULL;
    free(*list);
    (*list) = NULL;
}



void SingleLinkedList_set(SingleLinkedList** list, unsigned int index,void* value){
    assert((*list)->size >0);
    assert(index >=0 && index < (*list)->size);
    SingleLinkedListNode* ptr = (*list)->next;
    for(int i = 0;i <index;i++){
        ptr =ptr->next;
    }
    ptr->next->data = value;
}


void* SingleLinkedList_pop(SingleLinkedList** list){
    assert((*list)->size >0);
    SingleLinkedListNode* ptr = (*list)->next;
    for(int i = 0; i<(*list)->size-1;i++){
        ptr = ptr->next;
    }
    SingleLinkedListNode * ptr2 = ptr->next;
    void* res = ptr2->data;
    ptr->next = NULL;
    free(ptr2);
    (*list)->size--;
    return res; 
}


void SingleLinkedList_add(SingleLinkedList**list, void* item){
    SingleLinkedListNode* ptr = (*list)->next;
    for(int i = 0; i< (*list)->size;i++){
        ptr = ptr->next;
    }
    SingleLinkedListNode* new_come = malloc(sizeof(SingleLinkedListNode));
    new_come->data = item;
    ptr->next = new_come;
    new_come->next = NULL;
    (*list)->size++;
}

void* Singlelist_remove(SingleLinkedList** list, unsigned int index){
    assert((*list)->size >0);
    assert(index >=0 && index <(*list)->size);
    SingleLinkedListNode* ptr = (*list)->next;
    for(int i = 0; i <index;i++){
        ptr = ptr->next;
    }
    SingleLinkedListNode* ret = ptr->next;
    ptr->next = ret->next;
    void* res = ret->data;
    free(ret);
    (*list)->size--;
    return res;
}
