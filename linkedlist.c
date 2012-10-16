#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedlist.h"



/*return a node head to a linked list */

linked_list *list_new() {
  linked_list *alist = 
    (linked_list *) malloc(sizeof(linked_list));
  alist->head = NULL;
  alist->tail = NULL;
  alist->size = 0;
  return alist;
}

void list_append(linked_list *list , void *item){
  list_node *new_node = 
             (list_node *) malloc(sizeof(list_node));
  new_node->data = item; /* created the node and 
                          threw the data into it */
  new_node->next = NULL; 
  new_node->head = list;
  if (list_empty(list) == 1) {
    /* list is empty so initialize the 
     * head and tail to the same node*/
    new_node->previous = NULL;
    list->head = new_node;
    list->tail = new_node; 
  } else {
    list_node *tail = list->tail;
    tail->next = new_node;
    new_node->previous =(void *) tail;
    list->tail = new_node;
  }
  int size = list->size;
  size++;
  list->size = size;
  int foo = 5;
  printf("size is %d with data %d\n", list->size, foo );
}

void list_get_data_at_index(linked_list *alist, 
                            int index, void **data , int datasize ) {
   int size = alist->size;
   if (index <= size && index >=1) {
    int i;
    list_node *anode = alist->head;
    for ( i = 1; i < index; i++) {
    //     anode = anode->next; 
    }  
    int *foo = anode->data;
    printf("data in func : %d\n", *foo);
    //*data =(void *) malloc(sizeof(datasize));
    //memcpy(*data, foo, sizeof(datasize));
    //printf("data in data: %d\n", (int) data);
   }
}


int list_size(linked_list *alist) {
  int size = alist->size;
  return size;
}

/* returns 1 if empty, 0 if not empty */
int list_empty(linked_list *list) {
  if (list->size == 0)
    return 1;
  else
    return 1;
}
