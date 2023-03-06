#include "arraylist.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(){
    typedef struct User{
        char* name;
        unsigned int id; 
        unsigned int age;
    }user;
    user* kid = malloc(sizeof(user));
    kid->age = 19;
    kid->name = "Ğ¡ÅóÓÑ";
    kid->id = 3112;
    arraylist* list = arraylist_create();
    printf("list cap:%d\n",list->capacity);
    arraylist_insert(list,list->size,kid);
    void* data = arraylist_pop(list);
    user* u = (user*)data;
    printf("age: %d\n",kid->age);
    printf("name: %s\n",kid->name);
    printf("name: %d\n",kid->id);
    
    return 0;
}