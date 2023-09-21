#include "monty.h"
/**
 * print_dlistint - function that prints all the elements of a stack_t list.
 *
 * @h: head of list.
 *
 * Return: the number of nodes.
 */

size_t print_dlistint(const stack_t *h)
{
	int node_num = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		node_num++;
	}
	return (node_num);
}


/**
 * add_dnodeint - add new node at the beginning of a stack_t list.
 * @head: pointer to head pointer
 * @n: integer value
 * Return: node address or null in fail
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new = (stack_t *)malloc(sizeof(stack_t));

	if (!new)
		return (NULL);
	new->n = n;
	new->next = *head;
	if (*head != NULL)
	{
		(*head)->prev = new;
	}
	*head = new;

	return (*head);
}

/**
 * add_dnodeint_end - add new node at the end of a dlistint_t list.
 * @head: pointer to head pointer
 * @n: integer value
 * Return: node address or null in fail
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new, *current;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	new->prev = NULL;
	/*add new node in the beginning of the list*/
	if (*head == NULL)
		*head = new;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;

		new->prev = current;
		current->next = new;
	}


	return (new);
}


/**
 * delete_top_node - free all the elements of a stack_t list.
 * @stack: pointer to stack_t
 */
void delete_top_node(stack_t **stack)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		printf("Error: Stack is empty.\n");
		return;
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	temp->next = NULL;
	free(temp);
}

/**
 * free_dlistint - free all the elements of a stack_t list.
 * @head: pointer to stack_t
 */
void free_dlistint(stack_t *head)
{
	stack_t *current;

	current = head;
	while (head)
	{
		current = head;
		head = head->next;
		if (current)
			free(current);
	}
}
