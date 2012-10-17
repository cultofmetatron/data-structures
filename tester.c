#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"


int main(int argc, char *argv[]) {
    printf("testing the linked list file\n");
    int *num = malloc(sizeof(int));
    linked_list *mylist = list_new();
    int i;
    for (i = 0; i <= 10; i++) {
      int foo = 10-i;
      int *goo = &foo;
      
      list_append(mylist, goo);

    }
    
    int *foo;
    list_get_data_at_index(mylist, 8, (void *) &foo, sizeof(size_t));
    //int goo = *foo;
    //printf("number at index 8 %d\n \n", *foo);
    

    return 0;

}
