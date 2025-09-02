#include <stdio.h>

int main(void)
{
	double 	a = 5.999999;
	double 	b = 5.9999999;
	int	c;

	c = (int)a;
	printf("num: %d | (%e)\n", c, a); //  gives "num: 5 | (5.999999)"
	c = (int)b;
	printf("num: %d | (%e)\n", c, b); // gives "num: 6 | (6.000000)"
}