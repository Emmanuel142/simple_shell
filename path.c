#include "shell.h"
#include <string.h>

char *find_path(char *command)
{
	char *path = getenv("PATH");
	char full_path[100];
	char *path_copy = strdup(path);
	int dir_len;
	char *dir = NULL;

	if (path_copy == NULL)
	{
		perror("Error copying path");
		exit(-1);
	}
	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		dir_len = strlen(dir);

		if (dir_len > 0 && dir[dir_len - 1] != '/')
		{
			dir_len++;
		}

		strcpy(full_path, dir);
		if (full_path[dir_len - 1] != '/')
			strcat(full_path, "/");
		strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return strdup(full_path);
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
/**
 **_strcpy - replicates a string
 *@dest: destination the string is replicated to
 *@src: the source string
 *Return: the copy of the string
 */
char *_strcat(char *dest, char *src)
{
	int j, len;
	char *s = dest;

	j = 0;
	len = strlen (dest);
	while (src[j] != '\0')
	{
		dest[len + j] = src[j];
		j++;
	}
	return (s);
}

