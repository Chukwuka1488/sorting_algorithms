#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 *                       using the Insertion sort algorithm
 * @list: double pointer to the head of the linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev_node;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		prev_node = current->prev;
		while (prev_node && prev_node->n > current->n)
		{
			prev_node->next = current->next;
			if (current->next)
				current->next->prev = prev_node;
			current->prev = prev_node->prev;
			current->next = prev_node;
			if (prev_node->prev)
				prev_node->prev->next = current;
			else
				*list = current;
			prev_node->prev = current;

			print_list((const listint_t *)*list);
			prev_node = current->prev;
		}
		current = current->next;
	}
}
