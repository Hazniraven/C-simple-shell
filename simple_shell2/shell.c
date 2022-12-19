#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>

/**
  *main - simple shell
  *
  *@ac: argument count
  *@av: argument vector
  *
  *Return: integer
  */
int main(int ac, char **av)
{
	char *inputs = NULL;
	size_t nsize = 0, i = 0;
	pid_t pid;
	char *command;
	(void)ac;

	while (1)
	{
		printf("#cisfun$ ");

		if (getline(&inputs, &nsize, stdin) == -1)
			break;

		pid = fork();

		if (pid == 0)
		{
			if (strcmp(inputs, "exit") == 0)
			{
				break;
				_exit(EXIT_SUCCESS);
			}
			command = strtok(inputs, "\t\n");
			while (command != NULL)
			{
				av[i++] = command; 
				command = strtok(NULL, "\t\n");

			}
			av[i] = NULL;
			execve(av[0], av, NULL);
		} else
		{
			int status;
			wait(&status);
		}
		free(inputs);
	}
	return (0);
}
