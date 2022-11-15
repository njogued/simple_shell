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
	token = strtok(path, ":");
	
	while (token)
	{
		cmd = malloc(sizeof(char) * (strlen(token) + strlen(name) + 1));
		strcat(cmd, token), strcat(cmd, "/"), strcat(cmd, name);
		if (stat(cmd, &st) == 0)
		{
			return (cmd);
		}
		token = strtok(NULL, ":");
	}
	free(token);
	free(path);
	free(cmd);
	return (NULL);
}
