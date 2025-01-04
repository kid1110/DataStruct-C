#ifndef __ARRAYLIST__
#define __ARRAYLIST__

#include <stdbool.h>

typedef struct arraylist
{
    unsigned int size;
    unsigned int capacity;
    void** data;   
}arraylist;

/**
 * @brief 
 * 
 * @param list 
 * @param index insert the value at the index
 * @param value insert value 
 */
void arraylist_insert(arraylist* list, unsigned int index, void* value);


/**
 * @brief 
 * 
 * @param list 
 * @param index 
 * @return void* 
 */
void arraylist_clear(arraylist* list);
bool arraylist_empty(arraylist* list);
// inline unsigned int arraylist_size(arraylist* list);
arraylist* arraylist_create();
void arraylist_allocate(arraylist *list,unsigned int size);
void* arraylist_get(arraylist *list,unsigned int index);
void arraylist_destroy(arraylist* list);
arraylist *arraylist_copy(arraylist* list);
void arraylist_set(arraylist *list,unsigned int index,void* value);
void* arraylist_pop(arraylist *list);
void arraylist_add(arraylist *list,void* item);
void* arraylist_remove(arraylist* list, unsigned int index);
void arraylist_clear(arraylist* list);

#endif