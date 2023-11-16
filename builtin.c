#include "shell.h"

int builtin_list(char *prompt)
{
	int i, code;
	struct
	{
		const char *command;
		int (*function)();
	}

	list[] = {
		{"exit", builtin_exit},
		{"env", builtin_env},
		{NULL, NULL}
	};

	for (i = 0; list[i].command != NULL; i++)
	{
		if (str_compare((char *)list[i].command, prompt, 0))
		{
			code = list[i].function();
			return (code);
		}
	}

	return -1;
}
int builtin_env(void)
{
	int i = 0;
	char **envp = environ;

	while (envp[i] != NULL)
	{
		printf("%s\n",envp[i]);
		i++;            
	}
	return (0);
}
int builtin_exit(void)
{
	return (98);
}
