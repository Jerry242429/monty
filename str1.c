#include "monty.h"


/**
 * append_elem - function that append elemnt to thee stack.
 * @new_node: Pointer to the new node.
 * @ln: line number of of the opcode.
 */
void append_elem(stack_t **new_node, unsigned int ln)
{
	stack_t *top;
	(void) ln;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	top = head;
	head = *new_node;
	head->next = top;
	top->prev = head;
}


/**
 * display -to display node to the stack.
 * @stack: pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void display(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	top = *stack;
	while (top != NULL)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}

/**
 * pop_data - pop data from stack.
 * @stack: poimter point to top node.
 * @line_number: line number of the opcode.
 */
void pop_data(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (stack == NULL || *stack == NULL)
		more_mistake(7, line_number);

	top = *stack;
	*stack = top->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(top);
}

/**
 * top - Prints the top node of the stack.
 * @stack: Pointing to top node of the stack.
 * @line_number: line number of of the opcode.
 */
void top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_mistake(6, line_number);
	printf("%d\n", (*stack)->n);
}
