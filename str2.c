#include "monty.h"

/**
 * nothing_data - a function that Does nothing.
 * @stack: node of the stack.
 * @line_number:  number of of the opcode.
 */
void nothing_data(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * swapped_data - swap element.
 * @stack: Pointer.
 * @line_number: number of of the opcode.
 */
void swapped_data(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_mistake(8, line_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * sumnodes - Adds the the stack.
 * @stack: Pointer to aof the stack.
 * @line_number: number of of the opcode.
 */
void sumnodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_mistake(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * snodes -  of the stack.
 * @stack: node of the stack.
 * @line_number: number of of the opcode.
 */
void snodes(stack_t **stack, unsigned int line_number)
{
	int m;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_mistake(8, line_number, "sub");


	(*stack) = (*stack)->next;
	m = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = m;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * divide - give me the stack.
 * @stack: stack node.
 * @line_number: row of the file.
 */
void divide(stack_t **stack, unsigned int line_number)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_mistake(8, line_number, "div");

	if ((*stack)->n == 0)
		more_mistake(9, line_number);
	(*stack) = (*stack)->next;
	s = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
