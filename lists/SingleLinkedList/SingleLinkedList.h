#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <stdbool.h>



typedef struct SingleLinkedListNode
{
    void* data;
    struct SingleLinkedListNode *next; 
}SingleLinkedListNode;

typedef struct SingleLinkedList
{
    unsigned int size;
    SingleLinkedListNode *next;
}SingleLinkedList;

void Singlelinkedlist_insert(SingleLinkedList** list,unsigned int index,void* value);
bool Singlelinkedlist_empty(SingleLinkedList** list);

SingleLinkedList* SingleLinkedList_create();
void* SingleLinkedList_get(SingleLinkedList** list,unsigned int index);
void SingleLinkedList_destroy(SingleLinkedList** list);
void SingleLinkedList_set(SingleLinkedList** list, unsigned int index,void* value);
void* SingleLinkedList_pop(SingleLinkedList** list);
void SingleLinkedList_add(SingleLinkedList**list, void* item);
void* Singlelist_remove(SingleLinkedList** list, unsigned int index);
void SingleLinkedList_clear(SingleLinkedList** list);



#endif