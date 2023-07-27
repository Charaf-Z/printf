#include "main.h"

/**
 * put_char - Function to write a character to the standard output.
 * @c: The character to be written.
 * Return: On success, returns 1. Otherwise, returns -1.
 */
int put_char(int c)
{
	static int i;
	static char buf[BUF_SIZE];

	if (c == EOF || i >= BUF_SIZE)
		write(1, buf, i), i = 0;
	if (c != EOF)
		buf[i++] = (char) c;
	return (1);
}

/**
 * put_string - Function to write a null-terminated string
 *              to the standard output.
 * @s: The input string to be written.
 * Return: The number of characters written.
 */
int put_string(const char *s)
{
	const char *_start = s;

	while (*s)
		put_char(*s++);
	return ((int)(s - _start));
}

/**
 * _strstr - Locates a substring in a string.
 * @haystack: The string to search in.
 * @needle: The substring to find.
 * Return: A pointer to the beginning of the found substring,
 *        or NULL if the substring is not found.
 */
const char *_strstr(const char *haystack, const char *needle)
{
	int i, j;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; haystack[i + j] &&
					needle[j] && haystack[i + j] == needle[j]; j++)
			;
		if (!needle[j])
			return (&haystack[i]);
	}
	return (NULL);
}

/**
 * _strlen - Function to calculate the length of a string.
 * @s: The input string.
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
}
