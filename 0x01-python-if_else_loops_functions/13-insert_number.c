#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
* insert_node - inserts a node to be in order
* @head: so nice. the tip of the long list.
* @number: the number we want tp stick in so deep in the linked list
* Description: inserts a node in order and requires the use of a temp node
* Return: the address of the new node
*/

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *temp = *head;

	new = malloc(sizeof(listint_t));
	if (!new || !head)
		return (NULL);
	new->n = number;
	/* if the value of head is equal to NULL then we place new before it */
	if (!*head)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	/* while head has value do this loop*/
	/* i initially did head->next but had problems with small lists*/
	/* I also tried head->next->n which caused seg faults */
	while (temp)
	{
		/* for when the number is bigger than the head's n value, */
		/* but if it is less than the next head n value- we insert inbetween*/
		if ((temp->n <= number) && (temp->next && (temp->next->n >= number)))
		{
			new->next = temp->next;
			temp->next = new;
			return (new);
		}
		/* if number is greater than the head's n value and */
		/* the next node is a NULL then do this */
		else if (temp->n <= number && !(temp->next))
		{
			new->next = NULL;
			temp->next = new;
			return (new);
		}
		/* when the number is smaller than heads value */
		/* then we insert it before head and do stuff */
		else if (temp->n > number)
		{
			new->next = temp;
			*head = new;
			return (new);
		}
		temp = temp->next;
	}
	return (NULL);
}
