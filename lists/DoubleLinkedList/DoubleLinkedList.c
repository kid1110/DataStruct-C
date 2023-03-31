#include "DoubleLinkedList.h"
#include "stdlib.h"
#include "assert.h"



void DoubleLinkedList_insert(DoubleLinkedList** list,unsigned int index,void* value){
    assert(index >=0 && index <= (*list)->size);
    DoubleLinkedListNode* ptr = (*list)->next;
    for(int i = 0; i < index;i++){
        ptr = ptr->next;
    }
    DoubleLinkedListNode* new_data = malloc(sizeof(DoubleLinkedListNode));
    new_data->data = value;
    new_data->next = ptr->next;
    ptr->next = new_data;
    new_data->prev = ptr;
    (*list)->size++;
}
bool DoubleLinkedList_empty(DoubleLinkedList** list){
    return (*list)->size == 0;
}

DoubleLinkedList* DoubleLinkedList_create(){
    DoubleLinkedList* res = malloc(sizeof(DoubleLinkedList));
    res->size = 0;
    DoubleLinkedListNode* dump = malloc(sizeof(DoubleLinkedListNode));
    dump->next = NULL;
    res->next = dump;
    dump->prev = res;
    return res;

}
void* DoubleLinkedList_get(DoubleLinkedList* list,unsigned int index){
    assert(list->size >0);
    assert(index >=0 && index < list->size);
    DoubleLinkedListNode* ptr = list->next;
    for(int i = 0; i < index;i++){
        ptr = ptr->next;
    }
    return ptr->next->data;
}
void DoubleLinkedList_destry(DoubleLinkedList** list){
    DoubleLinkedList_clear(list);
    free((*list)->next);
    (*list)->next = NULL;
    free(*list);
    (*list) = NULL;
}
void DoubleLinkedList_set(DoubleLinkedList* list,unsigned int index,void* value){
    assert(list->size >0);
    assert(index >=0 && index < list->size);
    DoubleLinkedListNode* ptr = list->next;
    for(int i = 0; i <index; i++){
        ptr = ptr->next;
    }
    ptr->next->data = value;
}
void* DoubleLinkedList_pop(DoubleLinkedList* list){
    assert(list->size >0);
    DoubleLinkedListNode* ptr = list->next;
    for(int i = 0; i < list->size; i++){
        ptr = ptr->next;
    }
    void* res = ptr->data;
    ptr->prev->next = NULL;
    free(ptr);
    list->size--;
    return res;
}
void DoubleLinkedList_add(DoubleLinkedList** list,void* item){
    DoubleLinkedListNode* ptr = (*list)->next;
    for(int i = 0; i <(*list)->size;i++){
        ptr = ptr->next;
    }
    DoubleLinkedListNode* new_come = malloc(sizeof(DoubleLinkedListNode));
    new_come->data = item;
    ptr->next = new_come;
    new_come->next = NULL;
    new_come->prev = ptr;
    (*list)->size++;
}
void* DoubleLinkedList_remove(DoubleLinkedList** list,unsigned int index){
    assert((*list)->size >0);
    assert(index >=0 && index <(*list)->size);
    DoubleLinkedListNode* ptr = (*list)->next;
    for(int i = 0; i < index;i++){
        ptr = ptr->next;
    }
    DoubleLinkedListNode* ret = ptr->next;
    ret->next->prev = ptr;
    ptr->next = ret->next;
    void* res = ret->data;
    free(ret);
    (*list)->size;
    return res;
}
void DoubleLinkedList_clear(DoubleLinkedList** list){
    if(DoubleLinkedList_empty(list)){
        return;
    }
    DoubleLinkedListNode* ptr = (*list)->next->next;
    DoubleLinkedListNode* next = ptr;
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