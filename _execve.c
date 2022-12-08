#include "shell.h"

/**
 * exec - execute command user typed into shell
 * @s: command user typed
 * @env: environmental variable
 * Return: 0 on success
 */
int exec(char **s, char **env)
{
	if (access(s[0], F_OK) == 0)
	{
		if (execve(s[0], s, NULL) == -1)
		{
			perror("Error:");
			__exit(s);
		}
	}

	else
	{
		if (execve(_which(s[0], env), s, NULL) == -1)
		{
			perror("Error:");
			__exit(s);
		}
	}
	return (0);
}