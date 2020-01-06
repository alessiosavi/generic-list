/*
 * Static list C implementation
 *
 * This datastructure contains an array that store the value that we want to
 * save; The array have a fixed size, once the array is full and the user try to
 * insert a new node, the size will grow of DEFAULT_INC
 *
 * Structure
 * - void *array:
 *   the array contains the value that we want to store
 * - int size:
 *   number of value that the array contains
 * - int max_size:
 *   max number of value that the array can contains before allocate a new array
 *
 * */
typedef struct {
  /* This array will be a static array of size == max_size */
  void **array;
  /* element size is the size of the struct that will be stored as a void
   * pointer */
  int element_size;
  int size;
  int max_size;
} list;