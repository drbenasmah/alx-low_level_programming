#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point
 *
 * Description: This program will assign a random number to the variable n
 *              each time it is executed, and prints whether the number is
 *              positive or negative.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
        int n;

        /* initialize random seed */
        srand(time(0));

        /* generate random number between -10 and 10 */
        n = rand() % 21 - 10;

        printf("%d is ", n);
        if (n > 0)
                printf("positive\n");
        else if (n == 0)
                printf("zero\n");
        else
                printf("negative\n");

        return (0);
}

