#include "main.h"
/**
 * main - takes in mutliple commands
 * Return: zero on success, 1 on success
 */
int main(void)
{
        char *buffer = NULL;
        size_t bufsize = 0;
        int i = 0, j = 0, len = 0;
        char *str = NULL, *token = NULL; 
        pid_t pid;
        char **av = NULL;

        while (1)
        {
                printf("$ ");
                i = getline(&buffer, &bufsize, stdin);
		if (strcmp(buffer, "exit\n") == 0)
		{
			break;
		}
                if (i == -1)
                {
			printf("\n");
                        break;
                }
		while (buffer[j] != '\0') 
		{
			if (buffer[j] == ' ')
			{
				len++;
			}
			j++;
		}	
                av = malloc(sizeof(char *) * (len + 2));
                str = strndup(buffer, (i - 1));
		i = 0;
		token = strtok(str, " ");
		while (token)
		{
			av[i] = strdup(token);
			token = strtok(NULL, " ");
			i++;
		}
		av[i] = NULL;

		pid = fork();
		if (pid == 0)
		{
			if (execve(av[0], av, NULL) == -1)
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
	free(av);
	free(buffer);
	return (0);
}
