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
  /* set initial node properties */
  new_node->next = NULL;
  new_node->head = list;


  if (list_empty(list) == 1) {
    /* list is empty so initialize the 
     * head and tail to the same node*/
    new_node->previous = NULL;
    new_node->next = NULL;
    printf("address of empty_list new_node: %d\n", new_node);
    list->head = new_node;
    list->tail = new_node; 
  } else {
    list_node *tail = list->tail;
    tail->next = new_node;
    printf("address of list->head %d, tail: %d  new_node: %d\n",list->head ,tail, new_node);
    new_node->previous =(void *)  tail;
    list->tail = new_node;
  }
  int size = list->size;
  size++;
  list->size = size;
  int *foo = (new_node->data);
  printf("size is %d with data %d\n", list->size, *foo );
}

void list_get_data_at_index(linked_list *alist, 
                            int index, void **data , size_t datasize ) {
   int size = alist->size;
   if (index <= size && index >=1) {
    int i;
    list_node *anode = alist->head;
    for ( i = 1; i < index; i++) {
      int *honey =  anode->data;
      printf("in list(),anode: %d, anode->next: %d  i = %d\n data: %d, location: %d\n",anode,  anode->next, i, *honey, honey); 
      list_node *next = anode->next;
      anode = next;
      printf("anode now: %d\n" , anode);
    }  
    int *foo = anode->data;
    printf("data in func : %d\n", *foo);
    //segfault starts here!!
    //*data =(void *) malloc(datasize);
    //memcpy(*data, foo, datasize);
    //**data = *foo;
    //printf("data in data: %d\n", gomba);
   }
}


int list_size(linked_list *alist) {
  int size = alist->size;
  return size;
}

/* returns 1 if empty, 0 if not empty */
int list_empty(linked_list *list) {
  if (list->size == 0){
    return 1;
  }
  else {
    return 0;
  }
}

