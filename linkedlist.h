
/* my linked list implememntation */




typedef struct list_node_ {
  struct list_node_ *next;
  struct list_node *previous;
  void *data;
  struct node_head *head;
} list_node;


typedef struct node_head {
  list_node *head;
  list_node *tail;
  int size;
}linked_list;



/* useful functions */
linked_list *list_new();
void list_append(linked_list *list, void *item);
void list_get_data_at_index(linked_list *alist, int index, void **data , int datasize);
int list_empty(linked_list *list);

