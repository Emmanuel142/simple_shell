#include "shell.h"
/**
* str_len - returns the length of a string.
* @string: pointer to string.
* Return: length of string.
*/
int str_len(char *string)
{
	int length = 0;

	if (string == NULL)
		return (0);

	while (string[length] != '\0')
	{
		length++;
	}
	return (length);
}

/**
* str_duplicate - duplicates an string
* @string: String to be copied
* Return: pointer to the array
*/
char *str_duplicate(char *string)
{
char *result;
int length, i;

if (string == NULL)
return (NULL);

length = str_len(string) + 1;

result = malloc(sizeof(char) * length);

if (result == NULL)
{
perror("Error");
return (NULL);
}
for (i = 0; i < length ; i++)
{
result[i] = string[i];
}

return (result);
}

/**
* str_compare - Compare two strings
* @string1: String one, or the shorter
* @string2: String two, or the longer
* @number: number of characters to be compared, 0 if infinite
* Return: 1 if the strings are equals,0 if the strings are different
*/
int str_compare(char *string1, char *string2, int number)
{
	int iterator;

	if (string1 == NULL && string2 == NULL)
		return (1);

	if (string1 == NULL || string2 == NULL)
		return (0);

	if (number == 0)
	{
		if (str_len(string1) != str_len(string2))
			return (0);
		for (iterator = 0; string1[iterator]; iterator++)
		{
			if (string1[iterator] != string2[iterator])
				return (0);
		}
		return (1);
	}
	else
	{
		for (iterator = 0; iterator < number ; iterator++)
		{
			if (string1[iterator] != string2[iterator])
				return (0);
		}
		return (1);
	}
}
