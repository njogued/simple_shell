#include "main.h"
/**
 * main - takes in mutliple commands
 * Return: zero on success, 1 on success
 */
int main(void)
{
        char *buffer = NULL;
        size_t bufsize = 0;
        int i = 0, j, len;
        char *str, *token;
        pid_t pid;
        char **av;

        while (1)
        {
                printf("$ ");
                i = getline(&buffer, &bufsize, stdin);
                if (i == -1 || strcmp(buffer, "exit\n") == 0)
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
			printf("our token[%d]: %s\n", i, token);
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
