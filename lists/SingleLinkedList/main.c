#include<stdio.h>
#include "SingleLinkedList.h"
#include<stdlib.h>

typedef struct User{
        char* name;
        unsigned int id; 
        unsigned int age;
}user;
void toString(user* data){
    printf("data:{age: %d name: %s id:%d}\n",data->age,data->name,data->id);
}
void list_to_string(SingleLinkedList* list){
    if(list == NULL){
        printf("NULL");
        return;
    }
    SingleLinkedListNode* ptr =  list->next;
    for(int i = 0; i < list->size;i++){
        ptr = ptr->next;
        toString((user*) ptr->data);
    }
    printf("finish print!\n");
}
int main(){
    user* kid = malloc(sizeof(user));
    kid->age = 18;
    kid->id = 2;
    kid->name = "小朋友";
    user* kid2 = malloc(sizeof(user));
    kid2->age = 18;
    kid2->id = 2;
    kid2->name = "kid";
    SingleLinkedList* data =  SingleLinkedList_create();
    SingleLinkedList_add(&data,kid2);
    SingleLinkedList_add(&data,kid);
    SingleLinkedList_add(&data,kid2);
    list_to_string(data);
    SingleLinkedList_clear(&data);
    list_to_string(data);
    SingleLinkedList_destroy(&data);
    list_to_string(data);
    data = SingleLinkedList_create();
    SingleLinkedList_add(&data,kid2);
    Singlelist_remove(&data,0);

    return 0;
}
