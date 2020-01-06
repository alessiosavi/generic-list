#include "static-list.h"
/* Enable logging */
// #define DEBUG 1
#define MIN_LIST_LENGHT 20
#define DEFAULT_INC MIN_LIST_LENGHT

/* init_list is delegated to allocate a new list and return the given pointer.
 * The list will contains generic data. */
list *init_list(int size, void *data, int element_size) {
  // Create the list
  list *lista = calloc(1, sizeof(list));
  lista->element_size = element_size;
  // Initialize the array of void *
  lista->array = malloc(lista->element_size * MIN_LIST_LENGHT);
  lista->max_size = MIN_LIST_LENGHT;
  lista->size = 0;
  // Set the value and increase the size
  lista->array[lista->size++] = data;

  return lista;
}

/* Use the address of the struct for add a node the list */
void add_node(list **lista, void *data) {
  /* List is not initialized, init the first node */
  if (*lista == NULL) {
    printf("add_node | List is not initialized!\n");
    exit(EXIT_FAILURE);
  } else if /* check if is necessary to allocate a new element */
      ((*lista)->size == (*lista)->max_size) {
    /* List have reached the maximum space! Allocate some new fresh memory */

    /* Increase the size by a constant factor  and set the new max size */
    (*lista)->max_size = (*lista)->max_size + DEFAULT_INC;
    /*Allocate a new space for the data */
    (*lista)->array =
        realloc((*lista)->array, (*lista)->max_size * (*lista)->element_size);
  }
  /* Add the element to the new list and use the post increment to increase
   * the size*/
  (*lista)->array[(*lista)->size++] = data;
}

/* Print node is delegated to print the given list nodes using the type in input
 */
void print_node(void **head, int size, TYPE type) {
  if (head == NULL) {
    printf("\nprint_int_array | ARRAY DATA not initialized");
    return;
  }
  int i;
  for (i = 0; i < size; i++) {
    switch (type) {
    case CHAR:
      print_generic((char)head[i]);
      break;
    case INT:
      print_generic((intptr_t)head[i]);
      break;
    case STRING:
      print_generic((char *)head[i]);
      break;
    }
  }
}

void print_nodes(list *data, TYPE type) {
  if (data == NULL)
    printf("\nprint_nodes | Data null!!");
  else {
    //printf("\n");
    print_node(data->array, data->size, type);
  }
  printf("\n");
}