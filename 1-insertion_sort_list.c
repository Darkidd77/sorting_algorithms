#include "sort.h"

/**
 * swp - swaps two double-linked list
 * @x: 1st node
 * @y: 2nd node
 *
 * Return: void
 */
void swp(listint_t *x, listint_t *y)
{
	if (x->prev)
		x->prev->next = y;
	if (y->next)
		y->next->prev = x;
	x->next = y->next;
	y->prev = x->prev;
	x->prev = y;
	y->next = x;
}


/**
 * insertion_sort_list - insertion list a doubly-linked list
 *
 * @l: address to head node
 *
 * Return: void
 */
void insertion_sort_list(listint_t **l)
{
	listint_t *x, *y;

	if (!l || !*l || !(*l)->next)
		return;
	x = (*l)->next;
	while (x)
	{
		y = x;
		x = x->next;
		while (y && y->prev)
		{
			if (y->prev->n > y->n)
			{
				swp(y->prev, y);
				if (!y->prev)
					*l = y;
				print_list((const listint_t *)*l);
			}
			else
				y = y->prev;
		}
	}
}
