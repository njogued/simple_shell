#include "main.h"

char *get_cmd(char *name)
{
	char *path = NULL;
	char *token = NULL;
	struct stat st;
	struct stat pt;
	char *cmd = malloc(1024);

	if (stat(name, &pt) == 0)
	{
		cmd = strdup(name);
		return (cmd);
	}
	
	
	path = strdup(_getenv("PATH"));

	token = strtok(path, ":");

	while (token)
	{
		strcat(cmd, token);
		strcat(cmd, "/");
		strcat(cmd, name);
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

	str = strdup(get_cmd(argv[1]));
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
