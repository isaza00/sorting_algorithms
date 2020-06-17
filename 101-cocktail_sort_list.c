#include "sort.h"
#include <stdio.h>
/**
 * swap_consec_node - orders linked list with insertion
 * @temp: current pointer to list
 * @list: doble pointer to head
 * Return: swaps two consecutive nodes
 */
void swap_consec_node(listint_t *temp, listint_t **list)
{
	listint_t *uno, *uno_next, *uno_prev = NULL;
	listint_t *dos, *dos_next = NULL, *dos_prev;

	uno = temp;
	dos = temp->next;
	uno_next = uno->next;
	if (uno->prev)
		uno_prev = uno->prev;
	else
		uno_prev = NULL;
	if (dos->next)
		dos_next = dos->next;
	else
		dos_next = NULL;
	dos_prev = dos->prev;
	if (uno_prev)
		uno_prev->next = uno_next;
	else
		*list = dos;
	if (dos_next)
		dos_next->prev = dos_prev;
	uno->next = dos_next;
	uno->prev = dos;
	dos->next = uno;
	dos->prev = uno_prev;
}
/**
 * cocktail_sort_list - orders dlinked list with cocktail sort algo
 * @list: head of double linked list
 * Return: prints list on each swap
 */
void cocktail_sort_list(listint_t **list)
{
	int swap = 1;
	listint_t *temp = *list;

	if (!list)
		return;
	while (swap)
	{
		swap = 0;
		while (temp->next)
		{
			printf("comparing: %i and %i\n", temp->n, temp->next->n);
			if (temp->n > temp->next->n)
			{
				swap_consec_node(temp, list);
				temp = temp->prev;
				swap = 1;
				if (temp->n != temp->next->n)
					print_list(*list);
			}
			temp = temp->next;
		}
		temp = temp->prev;

		while (temp->prev)
		{
			printf("comparing: %i and %i\n", temp->prev->n, temp->n);
			if (temp->prev->n > temp->n)
			{
				swap_consec_node(temp->prev, list);
				temp = temp->next;
				swap = 1;
				if (temp->prev->n != temp->n)
					print_list(*list);
			}
			temp = temp->prev;
		}
		temp = temp->next;
	}
}
