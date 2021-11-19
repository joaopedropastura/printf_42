#include <stdarg.h>
#include <stdio.h>

// va_start();

// va_arg();

// va_end();

//va_start does not return anything;
//initialize with 2 paremeters
//this macro must be called before using va_arg and va_end.

//void va_start(va_list ap, last_arg);

void printCharacters(int num, ...)
{
	va_list args;
	va_start(args, num);
	int i;
	for (i = 0; i < num; i++)
	{
		int value = va_arg(args, int);
		printf("eu amo a %s muito %s ", h, w);
	}
	i = 0;

	va_end(args);
}

int main()
{
	// char *a = 3;
	// char *b = 24;
	// char *c = 26;
	// char *d = 312;

	// printCharacters(a, b, c, d);
	char *h = "maria clara";
	char *w = "muitaomuitao";
	printf("eu amo a %s muito %s ", h, w);
	// printCharacters(3, 24, 26, 312);
	// printCharacters(1, 4, 3343, 2);
	// printCharacters(1, 3, 4, 2, 1, 2, 3, 4, 5);
}
