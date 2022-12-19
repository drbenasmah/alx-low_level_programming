#include "main.h"
#include <stdio.h>

/**
 *  * _strlen - prints length of string
 *   *
 *    * @s: pointer
 *     * Return: length of tring
 *      */

int _strlen(char *s)
{
		int i = 0;

			for (; *s != '\0'; s++)
					{
								i++;
									}

				return (i);
}
