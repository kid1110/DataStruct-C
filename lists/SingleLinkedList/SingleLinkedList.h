#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <stdbool.h>

typedef struct SingleLinkedList
{
    unsigned int size;
    unsigned int capacity;
    void* data;
    struct SingleLinkedList *next;
}SingleLinkedList;

void Singlelinkedlist_insert(SingleLinkedList* list,unsigned int index,void* value);
void Singlelinkedlist_clear(SingleLinkedList* list);
bool Singlelinkedlist_empty(SingleLinkedList* list);

SingleLinkedList* SingleLinkedList_create();
void* SingleLinkedList_get(SingleLinkedList* list,unsigned int index);
void SingleLinkedList_destroy(SingleLinkedList* list);
SingleLinkedList* SingleLinkedList_copy(SingleLinkedList* list);
void SingleLinkedList_set(SingleLinkedList* list, unsigned index,void* value);
void* SingleLinkedList_pop(SingleLinkedList* list);
void SingleLinkedList_add(SingleLinkedList*list, void* item);
void* arraylist_remove(SingleLinkedList* list, unsigned int index);
void SingleLinkedList_clear(SingleLinkedList* list);



#endif