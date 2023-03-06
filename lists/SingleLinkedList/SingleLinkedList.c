#include <stdlib.h>
#include <assert.h>
#include "SingleLinkedList.h"


#define SINGLINKEDLIST_INITAL_CAPACITY 4
#define SINGLINKEDLIST_GROWN_SPEED 0.75

void Singlelinkedlist_insert(SingleLinkedList* list,unsigned int index,void* value){
   
    SingleLinkedList* next = malloc(sizeof(SingleLinkedList));

}
void Singlelinkedlist_clear(SingleLinkedList* list);
bool Singlelinkedlist_empty(SingleLinkedList* list);

SingleLinkedList* SingleLinkedList_create(){
    SingleLinkedList* res = malloc(sizeof(SingleLinkedList));
    res->size = 0;
    res->capacity = SINGLINKEDLIST_INITAL_CAPACITY;
    SingleLinkedList* ptr = res;
    for(int i = 0; i < SINGLINKEDLIST_INITAL_CAPACITY; i++){
        SingleLinkedList* next = malloc(sizeof(SingleLinkedList));
        ptr->next = next;
        ptr = ptr->next;
    }
    return res;
}
void* SingleLinkedList_get(SingleLinkedList* list,unsigned int index);
void SingleLinkedList_destroy(SingleLinkedList* list);
SingleLinkedList* SingleLinkedList_copy(SingleLinkedList* list);
void SingleLinkedList_set(SingleLinkedList* list, unsigned index,void* value);
void* SingleLinkedList_pop(SingleLinkedList* list);
void SingleLinkedList_add(SingleLinkedList*list, void* item);
void* arraylist_remove(SingleLinkedList* list, unsigned int index);
void SingleLinkedList_clear(SingleLinkedList* list);