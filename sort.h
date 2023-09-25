#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <sys/types.h>


/* Doubly linked list node structure */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* Prototypes for the provided functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size);
void lomuto_sort(int *array, ssize_t low, ssize_t high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);

#endif /* SORT_H */

