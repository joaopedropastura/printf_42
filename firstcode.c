#include <stdarg.h>
#include <stdio.h>

// va_start();

// va_arg();

// va_end();

// va_start does not return anything;
// initialize with 2 paremeters
// this macro must be called before using va_arg and va_end.

// void va_start(va_list ap, last_arg);

void print(const char *num, ...)
{
	va_list args;
	va_start(args, num);
	char value;
	int i;

	i = 0;
	while (i < num)
	{
		value = va_arg(args, char);
		printf("%d : %s\n", i, value);
		i++;
	}
	va_end(args);
}

int main()
{
	// int a = 3;
	// int b = 24;
	// int c = 26;
	// int d = 312;
	char *e = "macarrao";
	// char e = 'm';
	char *f= "com";
	char *g = "carne";
	char *h = "moida";

	// print(e, f, g, h);
	// char *q;
	// int z = 21;
	// printf("eu amo a %s muito %s que por acaso tem %i %x", h, w, z, q);
	// print(a, b, c, d);
	print(4, e, f, g, h);
	printf("%s", f);
	// print(1, 3, 4, 2, 1, 2, 3, 4, 5);
}

// printf()
