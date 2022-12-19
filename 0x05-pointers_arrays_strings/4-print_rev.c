#include "main.h"
#include <stdio.h>

/**
 *  * print_rev - prints string in reverse
 *   *
 *    * @s: pointer
 *     */

void print_rev(char *s)
{
		int i = 0;

			while (s[i])
						i++;
				while (i--)
							_putchar(s[i]);
					_putchar('\n');
}
