#include "main.h"

char *get_cmd(char *name)
{
	char *path = NULL;
	char *token = malloc(1024);
	struct stat st;
	char *cmd;

	if (stat(name, &st) == 0)
	{
		cmd = strdup(name);
		return (cmd);
	}
	
	
	path = _getenv("PATH");
	printf("path is : %s\n", path);

	token = strtok(path, ":");
	printf("%s\n", token);
	
	while (token)
	{
		cmd = malloc(sizeof(char) * (strlen(token) + strlen(name) + 1));
		strcat(cmd, token), strcat(cmd, "/"), strcat(cmd, name);
		printf("cmd: %s\n token: %s\n", cmd, token);
		if (stat(cmd, &st) == 0)
		{
			return (cmd);
		}
		token = strtok(NULL, ":");
	}
	free(token);
	free(path);
	return (NULL);

}
int main(int ac, char **argv)
{
	char *str = malloc(1024);
	if (ac < 2)
	{
		printf("usage\n");
	}

	str = get_cmd(argv[1]);
	if (str != NULL)
	{

		printf("success: %s\n", str);
	}
	else
	{
		perror("not found\n");
	}
	free(str);
	return (0);


}
