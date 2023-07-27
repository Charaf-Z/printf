#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer.
 * @args: A va_list pointing to the unsigned integer argument.
 * @params: A pointer to the parameters struct for formatting.
 * Return: The number of characters printed.
 */
int print_unsigned(va_list args, params_t *params)
{
	unsigned long digit;
	va_list args_copy;

	va_copy(args_copy, args);
	if (params->l_modifier)
		digit = (unsigned long) va_arg(args_copy, long);
	else if (params->h_modifier)
		digit = (unsigned short int) va_arg(args_copy, int);
	else
		digit = (unsigned int) va_arg(args_copy, int);
	params->is_unsign = TRUE;
	return (print_number(convert_to(digit, 10, TO_UNSIGNED), params));
}

/**
 * print_address - Function to print the address of a pointer.
 * @args: The va_list containing the arguments.
 * @params: The pointer to the params_t struct.
 * Return: The number of characters printed.
 */
int print_address(va_list args, params_t *params)
{
	unsigned long int digit;
	int len = 0;
	va_list args_copy;

	va_copy(args_copy, args);
	digit = va_arg(args_copy, unsigned long int);
	if (!digit)
		return (put_string("(nil)"));
	len += put_string("0x"), params->width ? params->width -= 2 : 0;
	return (len += print_number(convert_to(digit, 16,
					TO_LOWER | TO_UNSIGNED), params));
}
