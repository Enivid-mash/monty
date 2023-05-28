#include "monty.h"

instruction_t instructions[] = {
	{"push", PUSH},
	{"pop", POP},
	{"add", ADD},
	{"sub", SUB},
	{"pall", PALL},
	{"nop", NOP},
	{"swap", SWAP},
	{"pint", PINT},
};

/**
 * main - interpreter main entry
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: zero on success
 */
int main(int argc, char *argv[])
{
	FILE *file = NULL;
	stack_t *stack = NULL;
	char line[100], *arg = NULL, *opcode = NULL;
	int line_number = 1, found = 0;
	unsigned long i;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line[strcspn(line, "\n")] = '\0';
		opcode = strtok(line, " ");
		arg = strtok(NULL, " ");
		for (i = 0; i < sizeof(instructions) / sizeof(instruction_t); i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, arg, line_number);
				found = 1;
				break;
			}
		}
		if (!found)
		{
			fprintf(stderr, "L%d: Unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	fclose(file);
	return (0);
}
