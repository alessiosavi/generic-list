#ifndef _STATIC_LIST_H_
#define _STATIC_LIST_H_
#include "../datastructure.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define print_generic(x)                                                       \
  _Generic((x), int : print_int, intptr_t: print_int, char : print_char, char * : print_string, float : print_float)(x);

/* Define the allowed type */
typedef enum { CHAR, INT, FLOAT, DOUBLE, STRING } TYPE;
/* Method for print the given data */
void print_int(int x);
void print_char(char x);
void print_string(char *x);
void print_float(float x);

void print_int(int x) { printf(" %d", x); }
void print_char(char x) { printf(" %c", x); }
void print_string(char *x) { printf(" %s", x); }
void print_float(float x) { printf(" %f", x); }

void print_nodes(list *data, TYPE type);
void print_node(void **head, int size, TYPE type);

/* Initialize a given list */
list *init_list(int size, void *data, int element_size);

/* Add a new node to the given list */
void add_node(list **lista, void *data);

void *sub_array(void *B, int new_size, int size_used, int counter);
list *init_log_file_list(int size, void *logfile);
void add_log_file(list **data, void *logfile);
void remove_node(list **data, char *name);
void free_list(list *list);

#endif
