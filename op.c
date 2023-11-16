#include "monty.h"

/**
 * multiply - multiply two elements of the stack.
 * @stack: pointing to top node of the stack.
 * @line_number: line number of of the opcode.
 * Return: void
 *
 */
void multiply(stack_t **stack, unsigned int line_number)
{
	int multiple;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_mistake(8, line_number, "mul");

	(*stack) = (*stack)->next;
	multiple = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = multiple;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * modules - modules two elements of the stack.
 * @stack: pointing to top node of the stack.
 * @line_number: line number of of the opcode.
 * Return: void
 *
 */
void modules(stack_t **stack, unsigned int line_number)
{
	int model;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_mistake(8, line_number, "mod");


	if ((*stack)->n == 0)
		more_mistake(9, line_number);
	(*stack) = (*stack)->next;
	model = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = model;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
