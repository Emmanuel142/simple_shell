#ifndef __SHELL_H__
#define __SHELL_H__

extern char** environ;

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>


int print_prompt(int terminal);
int tokenize_input(char *buffer, char *token_array[], char *delimiter, int read_count);
char *_strchr(const char *str, char c);
void handle_signal(int signum);
char *find_path(char *command);
char *_strcpy(char *dest, char *src);
int builtin_env(void);
int builtin_list(char *prompt);
int str_compare(char *string1, char *string2, int number);
char *str_duplicate(char *string);
int str_len(char *string);
int builtin_exit(void);
#endif
