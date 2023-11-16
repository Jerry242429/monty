#include "monty.h"

/**
 * dis_str - function print the Ascii value of the stack.
 * @stack: pointing to top node of the stack.
 * @line_number: line number of of the opcode.
 * Return: void
 *
 */

void dis_str(stack_t **stack, unsigned int line_number)
{
	int as;

	if (stack == NULL || *stack == NULL)
		string_mistake(11, line_number);

	as = (*stack)->n;
	if (as < 0 || as > 127)
		string_mistake(10, line_number);
	printf("%c\n", as);
}

/**
 * disc_str1 - function that prints string.
 * @stack: pointing node of the stack.
 * @ln: line number of of the opcode.
 * Return: void
 *
 */

void disc_str1(stack_t **stack, unsigned int ln)
{
	int as;
	stack_t *top;
	(void) ln;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	top = *stack;
	while (top != NULL)
	{
		as = top->n;
		if (as <= 0 || as > 127)
			break;
		printf("%c", as);
		top = top->next;
	}
	printf("\n");
}

/**
 * rl - first node of the stack to rotate the bottom.
 * @stack: pointing to top node of the stack.
 * @ln: line number of of the opcode.
 * Return: void
 *
 */

void rl(stack_t **stack, unsigned int ln)
{
	stack_t *top;
	(void) ln;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	top = *stack;
	while (top->next != NULL)
		top = top->next;

	top->next = *stack;
	(*stack)->prev = top;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - that rotate last node of the stack
 * @stack: pointing to top node of the stack
 * @ln: line number of of the opcode
 */
void rotr(stack_t **stack, unsigned int ln)
{
	stack_t *top;
	(void) ln;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	top = *stack;

	while (top->next != NULL)
		top = top->next;

	top->next = *stack;
	top->prev->next = NULL;
	top->prev = NULL;
	(*stack)->prev = top;
	(*stack) = top;
}
