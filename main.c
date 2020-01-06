#include "structures/static-list/static-list.c"

void test_char() {
  list *lista;
  lista = init_list(10, (void *)'1', sizeof(char));
  add_node(&lista, (void *)'2');
  add_node(&lista, (void *)'3');
  add_node(&lista, (void *)'4');
  print_nodes(lista, CHAR);
}

void test_int() {
  list *lista;
  lista = init_list(10, (void *)0, sizeof(int));
  add_node(&lista, (void *)1);
  add_node(&lista, (void *)2);
  add_node(&lista, (void *)3);
  print_nodes(lista, INT);
  free(lista->array);
  free(lista);
}

void test_string() {
  list *lista;
  lista = init_list(10, (void *)"0", sizeof(char *));
  add_node(&lista, (void *)"1");
  add_node(&lista, (void *)"2");
  add_node(&lista, (void *)"3");
  print_nodes(lista, STRING);
  free(lista->array);
  free(lista);
}

int main() {
  // test_char();
  test_int();
  test_string();
}
