#include <stdlib.h>
#include <string.h>
#include "list.h"

//initialize the list
void list_init(List *list, void (*destroy) (void *data)){
  list->size = 0;
  list->destroy = destroy;
  list->head = NULL;
  list->tail = NULL;
  
  return;
}

//list-destroy
void list_destroy(List *list){
  void *data;
  
  //remove each element
  while(list_size(list) > 0){
    if(list_rem_next(list, NULL, (void**)&data) == 0 && list->destroy != NULL){
      //call a user defined function to free dynamically allocated data
      list->destroy(data);
    }
  }

  //no operations are allowed now, but clear the structure as a precaution.
  memset(list, 0, sizeof(list));
  
  return;
}

int list_ins_next(List *list, ListElmt *element, const void *data){
  ListElmt *new_element;
  
  //allocate storage for the element
  
  if((new_element = (ListElmt *)malloc(sizeof(ListElmt))) == NULL)
    return -1; //memory allocation failed

  //insert the element into the list
  new_element->data = (void*) data;

  if(element == NULL){
    //handle insertion at the head of the list
    if(list_size(list) == 0)
      list->tail = new_element;

    new_element->next = list->head; //why this rotation using tail first?

    list->head = new_element;
  }else{
    //handle insertion somewhere other thatn at the head.
    if(element->next == NULL)
      list->tail = new_element;

    new_element->next = element->next;
    element->next = new_element;
  }

  //adjust size
  list->size++;

  return 0;
}

int list_rem_next(List *list, ListElmt *element, void **data){
  ListElmt *old_element;
  
  //Do not allow removal from an empty list.
  if(list_size(list) == 0)
    return -1;

  //remove the element from the list
  if(element == NULL){
    //remove at the head
    *data = list->head->data;
    old_element = list->head;
    list->head = list->head->next;
    
    if(list_size(list) == 1)
      list->tail = NULL;
  }else{
    //handle removal from somewhere else other than the head
    if(element->next == NULL)
      return -1;

    *data = element->next->data;
    old_element = element->next;
    element->next = element->next->next;

    if(element->next == NULL)
      list->tail = element;
  }

  //free the storage allocated by the abstract datatype 
  free(old_element);

  //adjust size 
  list->size--;
  
  return 0;
}
