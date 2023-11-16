#include "monty.h"

/**
 * ofile - function that opens a file
 * @file_name: the name of the file
 * Return: void
 */

void ofile(char *file_name)
{
	FILE *file_d = fopen(file_name, "r");

	if (file_name == NULL || file_d == NULL)
		mistake(2, file_name);

	boldVariable(file_d);
	fclose(file_d);
}


/**
 * boldVariable - traverse through file
 * @fd: file iptor
 * Return: void
 *
 */

void boldVariable(FILE *fd)
{
	int linenum, format = 0;
	char *bf = NULL;
	size_t lth = 0;

	for (linenum = 1; getline(&bf, &lth, fd) != -1; linenum++)
	{
		format = pline(bf, linenum, format);
	}
	free(bf);
}


/**
 * pline - function that tokenize the input
 * @buffer: the file stored
 * @line_number: line number
 * @format:  storage format
 * Return:  0 or 1
 */

int pline(char *buffer, int line_number, int format)
{
	char *pde, *v;
	const char *delim = "\n ";

	if (buffer == NULL)
		mistake(4);

	pde = strtok(buffer, delim);
	if (pde == NULL)
		return (format);
	v = strtok(NULL, delim);

	if (strcmp(pde, "stack") == 0)
		return (0);
	if (strcmp(pde, "queue") == 0)
		return (1);

	search_f(pde, v, line_number, format);
	return (format);
}

/**
 * search_f - search for the function
 * @opcode: represnts the opcod
 * @value: an argument for opcode
 * @format:  storage format
 * @ln: the line number
 */
void search_f(char *opcode, char *value, int ln, int format)
{
	int a;
	int f;

	instruction_t func_list[] = {
		{"push", append_elem},
		{"pall", display},
		{"pint", top},
		{"pop", pop_data},
		{"nothing_data", nothing_data},
		{"swap", swapped_data},
		{"add", sumnodes},
		{"sub", snodes},
		{"div", divide},
		{"mul", multiply},
		{"mod", modules},
		{"pchar", dis_str},
		{"pstr", disc_str1},
		{"rl", rl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (f = 1, a = 0; func_list[a].opcode != NULL; a++)
	{
		if (strcmp(opcode, func_list[a].opcode) == 0)
		{
			function_call(func_list[a].f, opcode, value, ln, format);
			f = 0;
		}
	}
	if (f == 1)
		mistake(3, ln, opcode);
}


/**
 * function_call - a function that Calls the required function.
 * @func: Pointer to the function
 * @op: represent the opcode of the function
 * @val: represent numeric value.
 * @ln: line numeber
 * @format: Format specifier
 */
void function_call(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *exist_node;
	int f;
	int a;

	f = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			f = -1;
		}
		if (val == NULL)
			mistake(5, ln);
		for (a = 0; val[a] != '\0'; a++)
		{
			if (isdigit(val[a]) == 0)
				mistake(5, ln);
		}
		exist_node = disc_node(atoi(val) * f);
		if (format == 0)
			func(&exist_node, ln);
		if (format == 1)
			addq_elem(&exist_node, ln);
	}
	else
		func(&head, ln);
}
