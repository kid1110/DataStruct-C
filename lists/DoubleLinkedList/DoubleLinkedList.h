#ifndef __DOUBLELINKEDLIST__H
#define __DOUBLELINKEDLIST__H

#include <stdbool.h>


typedef struct DoubleLinkedListNode
{
    void* data;
    struct DoubleLinkedListNode *next;
    struct DoubleLinkedListNode *prev;

}DoubleLinkedListNode;

typedef struct DoubleLinkedList
{
    unsigned int size;
    DoubleLinkedListNode *next;
}DoubleLinkedList;
void DoubleLinkedList_insert(DoubleLinkedList** list,unsigned int index,void* value);
bool DoubleLinkedList_empty(DoubleLinkedList** list);

DoubleLinkedList* DoubleLinkedList_create();
void* DoubleLinkedList_get(DoubleLinkedList* list,unsigned int index);
void DoubleLinkedList_destry(DoubleLinkedList** list);
void DoubleLinkedList_set(DoubleLinkedList* list,unsigned int index,void* value);
void* DoubleLinkedList_pop(DoubleLinkedList* list);
void DoubleLinkedList_add(DoubleLinkedList** list,void* item);
void* DoubleLinkedList_remove(DoubleLinkedList** list,unsigned int index);
void DoubleLinkedList_clear(DoubleLinkedList** list);





#endif