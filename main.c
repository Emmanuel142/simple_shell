#include "shell.h"
/**
 * main - The starting point of the shell
 * Return: ....
 * Description: ....
 */
int main(void)
{
	pid_t c_pid;
	int status, n, is_terminal, e;
	char *arg[200], *delimiter, buffer[100];

	is_terminal = isatty(STDIN_FILENO);
	status = 0;
	delimiter = " ";
	while (1)
	{
		c_pid = fork();
		if (c_pid == -1)
		{
			perror("Fork failed");
			exit(-1);
		}
		else if (c_pid == 0)
		{
			e = print_prompt(is_terminal);
			if (e == -1)
				exit(-1);
			n = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
			if (n == -1)
			{
				perror("Read failed");
				exit(-1);
			}
			e = tokenize_input(buffer, arg, delimiter, n);
			if (e == 0)
				exit(98);
			arg[e] = NULL;
			execve(arg[0], arg, environ);
			perror(arg[0]);
			exit(-1);
		}
		else
		{
			wait(&status);
			if (!is_terminal || (WIFEXITED(status) && WEXITSTATUS(status) == 98))
			{
				exit(0);
			}
		}
	}
}
