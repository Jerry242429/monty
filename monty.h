#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void mistake(int mistakeor_code, ...);
void more_mistake(int mistakeor_code, ...);
void string_mistake(int mistakeor_code, ...);
void ofile(char *file_name);
void boldVariable(FILE *fd);
int pline(char *buffer, int line_number, int format);
void search_f(char *opcode, char *value, int ln, int format);
void function_call(op_func func, char *op, char *val, int ln, int format);
int main(int argc, char *argv[]);
stack_t *disc_node(int n);
void addq_elem(stack_t **new_node, unsigned int ln);
void free_nodes(void);
void multiply(stack_t **stack, unsigned int line_number);
void modules(stack_t **stack, unsigned int line_number);
void rl(stack_t **stack, unsigned int ln);
void rotr(stack_t **stack, unsigned int ln);
void append_elem(stack_t **new_node, unsigned int ln);
void display(stack_t **stack, unsigned int line_number);
void pop_data(stack_t **stack, unsigned int line_number);
void top(stack_t **stack, unsigned int line_number);
void nothing_data(stack_t **stack, unsigned int line_number);
void swapped_data(stack_t **stack, unsigned int line_number);
void sumnodes(stack_t **stack, unsigned int line_number);
void snodes(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void dis_str(stack_t **stack, unsigned int line_number);
void disc_str1(stack_t **stack, unsigned int ln);

#endif
