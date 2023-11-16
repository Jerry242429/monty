#include "monty.h"
stack_t *head = NULL;

/**
 * main -function theat serve as entry point
 * @argc: count the number of argumnet
 * @argv: list of arguments
 * Return: 0
 *
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	ofile(argv[1]);
	free_nodes();
	return (0);
}


/**
 * disc_node - function to create node to stack
 * @n: Number that contain data
 * Return: pointer to the node
 *
 */
stack_t *disc_node(int n)
{
	stack_t *exist_node;

	exist_node = malloc(sizeof(stack_t));
	if (exist_node == NULL)
		mistake(4);
	exist_node->next = NULL;
	exist_node->prev = NULL;
	exist_node->n = n;
	return (exist_node);
}

/**
 * addq_elem - append node element to the queue
 * @new_node: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void addq_elem(stack_t **new_node, unsigned int ln)
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
	while (top->next != NULL)
		top = top->next;

	top->next = *new_node;
	(*new_node)->prev = top;

}

/**
 * free_nodes - release the memory allocated for nodes
 */
void free_nodes(void)
{
	stack_t *top;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		top = head;
		head = head->next;
		free(top);
	}
}
