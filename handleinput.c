#include "shell.h"

volatile sig_atomic_t interrupted = 0;

int print_prompt(int terminal)
{
	int n;

	if (terminal)
	{
		n = write(STDOUT_FILENO, "#cisfun$ ", 9);
		if (n == -1)
		{
			perror("Write failed");
			return (-1);
		}
	}
	return (0);
}

int tokenize_input(char *buffer, char *token_array[], char *delimiter, int read_count)
{
	int n = read_count;
	char *token, *endquote;
	int token_count = 0;

	n = (n > 0 && buffer[n - 1] == '\n') ? n - 1 : n;
	if (n == 0)
		return (0);
	buffer[n] = '\0';
	token = strtok(buffer, delimiter);
	while (token != NULL)
	{
		if (token[0] == '"')
		{
			endquote = _strchr(token + 1, '"');
			printf("OKayyy");
			if (endquote != NULL)
			{
				token_array[token_count] = token;
				token = endquote + 1;
			}
		}
		else
		{
			token_array[token_count] = token;
			token = strtok(NULL, delimiter);
		}
		token_count++;
	}
	return (token_count);
}
char *_strchr(const char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
