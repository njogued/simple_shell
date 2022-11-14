#include "main.h"
/**
 * main - runs a simple shell
 * Return: returns 0 on success, -1 on failure
*/
int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	int i = 0;
	char *str;
	pid_t pid;
	char *av[2];

	while (1)
	{
		printf("$ ");
		i = getline(&buffer, &bufsize, stdin);
		if (i == -1 || strcmp(buffer, "exit\n") == 0)
		{
			printf("\n");
			break;
		}
		str = strndup(buffer, (i - 1));
		av[0] = str;
		av[1] = NULL;
		pid = fork();
		if (pid == 0)
		{
			if (execve(av[0], av, environ) == -1)
			{
				perror("./shell");
				exit(-1);
			}
		}
		else
		{
			wait(NULL);
		}
	}
	free(str);
	free(buffer);
	return (0);
}
