#include "main.h"

/******** PRINT UNSIGNED NUMBER ********/
/**
 * print_unsigned - Prints an unsigned number
 * @types: List of arguments
 * @width: Width
 * @buffer: Buffer array to handle print
 * @precision: Specification of precision
 * @size: Specifier of size
 * @flags:  Active flags number
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/******** PRINT UNSIGNED NUMBER IN OCTAL  ********/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: List of arguments
 * @flags:  Active flags number
 * @buffer: Buffer array to handle print
 * @width: Width
 * @size: Specifier of size 
 * @precision: Specification of precision
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/******** PRINT UNSIGNED NUMBER IN HEXADECIMAL ********/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: List of arguments
 * @width: width
 * @buffer: Buffer array to handle print
 * @precision: Specification of precision
 * @size: Specifier of size
 * @flags:  Active flag number
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/******** PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL ********/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: List of arguments
 * @flags:  Active flag number
 * @buffer: Buffer array to handle print
 * @precision: Specification of precision
 * @size: Specifier of size
 * @width: width
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/********* PRINT HEXX NUM IN LOWER OR UPPER ********/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @map_to: Array value to map number to
 * @flags:  Active flag number
 * @width: Width
 * @types: List of arguments
 * @precision: Specification of precision
 * @size: Specifier of size
 * @buffer: Buffer array to handle print
 * @size: Specification of size
 * @flag_ch: Active flag number
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}