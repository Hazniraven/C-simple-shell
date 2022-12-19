#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
  *main - stat exercise
  *
  *Return: int
  */
int main(int ac, char **av)
{
	unsigned int j = 1;
	struct stat st;

	if (ac < 2)
	{
		printf("Usage: _which filename...\n");
		return (1);
	}

	while (av[j])
	{
		if (stat(av[i], &st) == 0)
		{
			printf("File is present here\n");
		}
		else
		{
			printf("File is not here...!!!\n");
		}
		j++;
	}

	return (0);
}
