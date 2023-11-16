#include "monty.h"

/**
 * mistake - a function Prints appropiate mistakeor messages
 * determined by their mistakeor code.
 * @mistakeor_code: The mistakeor code
 */
void mistake(int mistakeor_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, mistakeor_code);
	switch (mistakeor_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l_num = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_mistake - hdunction that handles mistakeors.
 * @mistakeor_code: The mistakeor code
 * Return: void
 *
 */
void more_mistake(int mistakeor_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, mistakeor_code);
	switch (mistakeor_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			l_num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_mistake - function that handles mistakeors.
 * @mistakeor_code: The mistakeor code
 * return: void
 *
 */
void string_mistake(int mistakeor_code, ...)
{
	va_list ag;
	int l_num;

	va_start(ag, mistakeor_code);
	l_num = va_arg(ag, int);
	switch (mistakeor_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
