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
    user* data = (user*)arraylist_pop(list);
    printf("age: %d\n",kid->age);
    printf("name: %s\n",kid->name);
    printf("name: %d\n",kid->id);

    printf("data age: %d\n",data->age);
    printf("data name: %s\n",data->name);
    printf("data name: %d\n",data->id);
    
    return 0;
}