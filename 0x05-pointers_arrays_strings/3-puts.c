nclude "main.h"
#include <stdio.h>

/**
 *  * _puts - prints a strings
 *   *
 *    * @str: pointer
 *     */

void _puts(char *str)
{
		for (; *str != '\0'; str++)
				{
							_putchar(*str);
								}
			_putchar('\n');
}
