#include "monty.h"

/**
 * PALL - pall optcode instruction
 * @stack: A pointer to data structure
 * @arg: argument to optcode instruction
 * @line_number: optcode instruction line number
 **/
void PALL(stack_t **stack, char *arg, unsigned int line_number)
{
	stack_t *current = NULL;

	(void)arg;
	(void)line_number;

	current = *stack;
	if (current != NULL)
	{
		while (current != NULL)
		{
			fprintf(stdout, "%d\n", current->n);
			current = current->prev;
		}
	}
}


/**
 * NOP - nop optcode instruction
 * @stack: A pointer to data structure
 * @arg: argument to optcode instruction
 * @line_number: optcode instruction line number
 **/
void NOP(stack_t **stack, char *arg, unsigned int line_number)
{
	(void)arg;
	(void)line_number;
	(void)stack;
}


/**
 * SWAP - swap optcode instruction
 * @stack: A pointer to data structure
 * @arg: argument to optcode instruction
 * @line_number: optcode instruction line number
 **/
void SWAP(stack_t **stack, char *arg, unsigned int line_number)
{
	(void)arg;
	if (*stack != NULL && (*stack)->prev != NULL)
	{
		stack_t *top1 = *stack;
		stack_t *top2 = top1->prev;
		stack_t *prev = top2->prev;

		/* Adjust pointers */
		top2->prev = top1;
		top1->prev = prev;
		if (prev != NULL)
			prev->next = top1;
		top1->next = top2;
		top2->next = NULL;

		/* Update stack pointer */
		*stack = top2;
	}
	else
	{
		fprintf(stderr, "L%d: cant't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}


/**
 * PINT - pint optcode instruction
 * @stack: A pointer to data structure
 * @arg: argument to optcode instruction
 * @line_number: optcode instruction line number
 **/
void PINT(stack_t **stack, char *arg, unsigned int line_number)
{
	(void)arg;
	if (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%d: cant't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
