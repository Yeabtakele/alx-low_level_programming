#include <stdio.h>

void __attribute__((constructor)) hare(void);

/**
 * hare - Prints a string before the
 *        main function is executed.
 */
void hare(void)
{
	printf("You're best!work hard ,\n"
	       "you well buy  house upon you dearm!\n");
}
