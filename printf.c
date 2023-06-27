#include "main.h"

/**
 * _putchar - writes one byte to stdout
 * @c: The character to print
 * Return: Nothing
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string
 * @str: A pointer to the string to be printed
 * Return: Nothing
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 *print_int - prints an int
 *@n: The int to be printed
 *Return: Nothing
 */

void print_int(int n)
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	if (n / 10 > 0)
	{
		print_int(n / 10);
	}
	putchar(n % 10 + '0');
}

/**
 *count_digits - counts the digits
 *@n: The number to count its digits
 *Return: The amount of digits counted
 */

int count_digits(int n)
{
	int count = 0;
	if (n < 0)
		n = -n;
	if (n == 0)
		return 1;
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return count;
}

/**
 *_printf - prints characters according to a format
 *@format: The format of the character to be printed
 *Return: The number of characters printed
 */

int _printf(const char *format, ...)
{
	int i = 0, d, counter = 0;
	char *str, c;
	va_list args;

	va_start(args, format);
	while ((long unsigned int)i < strlen(format))
	{
		switch (format[i])
		{
		case '%':
			if (format[i + 1] == 'c')
			{
				c = va_arg(args, int);
				putchar(c);
				counter++;
				i++;
				break;
			}
			if (format[i + 1] == 's')
			{
				str = va_arg(args, char *);
				if (!str)
				{
					_puts("(null)");
					i++;
					break;
				}
				_puts(str);
				counter += strlen(str);
				i++;
				break;
			}
			if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				d = va_arg(args, int);
				print_int(d);
				counter += count_digits(d);
				break;
			}
			break;
		default:
			putchar(format[i]);
			counter++;
			break;
		}
		i++;
	}

	va_end(args);
	return (counter);
}
