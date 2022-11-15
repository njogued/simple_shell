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
        char *str = NULL, *tok = NULL; 
        pid_t pid;
	char *return_cmd;
	char *token_cp;
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
		tok = strtok(str, " ");
		printf("value of token is: %s\n", tok);
		return_cmd = malloc(sizeof(tok));
		token_cp = strdup(tok);
		return_cmd = get_cmd(token_cp);
		if (return_cmd == NULL)
		{
			perror("Not a valid path\n");
			break;
		}
		printf("value of return_cmd: %s\n", return_cmd);
		while (tok)
		{
			av[i] = strdup(tok);
			tok = strtok(NULL, " ");
			i++;
		}
		printf("value of i: %d\n", i);
		av[0] = return_cmd;
		av[i] = NULL;
		i = 0;
		while (av[i] != NULL)
		{
			printf("values of av[%d]: %s\n",i, av[i]);
			i++;
		}	

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
	free(return_cmd);
	return (0);
}
