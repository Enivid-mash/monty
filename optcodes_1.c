#include "main.h"

/**
 * PUSH - push optcode instruction
 * @stack: A pointer to data structure
 * @arg: argument to optcode instruction
 * @line_number: optcode instruction line number
 **/
void PUSH(stack_t **stack, char *arg, unsigned int line_number)
{
	if (arg != NULL)
	{
		char *endptr;
		stack_t *new_node = NULL;

		int value = strtol(arg, &endptr, 10);

		if (*endptr != '\0')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}

		new_node = malloc(sizeof(stack_t));
		new_node->n = value;
		new_node->prev = *stack;
		new_node->next = NULL;

		if (*stack != NULL)
		{
			(*stack)->next = new_node;
		}

		*stack = new_node;
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}


/**
 * POP - pop optcode instruction
 * @stack: A pointer to data structure
 * @arg: argument to optcode instruction
 * @line_number: optcode instruction line number
 **/
void POP(stack_t **stack, char *arg, unsigned int line_number)
{
	(void)arg;
	if (*stack != NULL)
	{
		stack_t *top = *stack;
		*stack = top->prev;

		if (*stack != NULL)
		{
			(*stack)->next = NULL;
		}

		free(top);
	}
	else
	{
		fprintf(stderr, "L%d: cant't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}


/**
 * ADD - add optcode instruction
 * @stack: A pointer to data structure
 * @arg: argument to optcode instruction
 * @line_number: optcode instruction line number
 **/
void ADD(stack_t **stack, char *arg, unsigned int line_number)
{
	(void)arg;
	if (*stack != NULL && (*stack)->prev != NULL)
	{
		stack_t *top = *stack;
		*stack = top->prev;
		(*stack)->n += top->n;
		(*stack)->next = NULL;

		free(top);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}


/**
 * SUB - sub optcode instruction
 * @stack: A pointer to data structure
 * @arg: argument to optcode instruction
 * @line_number: optcode instruction line number
 **/
void SUB(stack_t **stack, char *arg, unsigned int line_number)
{
	(void)arg;
	if (*stack != NULL && (*stack)->prev != NULL)
	{
		stack_t *top = *stack;
		*stack = top->prev;
		(*stack)->n -= top->n;
		(*stack)->next = NULL;

		free(top);
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
