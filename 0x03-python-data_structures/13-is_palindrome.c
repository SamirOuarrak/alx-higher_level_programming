#include "lists.h"

/**
 * is_palindrome - chacks wether a singly linked list is a palindrome
 * @head: a pointr to a pointer to the first element of the list
 * Return: 0 if it is not palindrome, or 1 if it is
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head;
	listint_t *fast = *head;
	listint_t *prev = NULL;
	listint_t *next = NULL;
	listint_t *first;
	listint_t *second;

	if (!*head || !(*head)->next)
		return (1);

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		next = slow->next;
		slow->next = prev;
		prev = slow;
		slow = next;
	}
	first = prev;
	second = slow;
	if (fast != NULL)
		second = second->next;
	while (first != NULL && second != NULL)
	{
		if (first->n != second->n)
			return (0);
		first = first->next;
		second = second->next;
	}

	return (1);
}
