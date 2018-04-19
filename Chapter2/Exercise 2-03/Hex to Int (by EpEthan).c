/**
 * Author: EpEthan
 * 
 * Solution for Exercise 2-03, Chapter2.
 */
 

#include <stdio.h>
#include <string.h>


enum boolean { FALSE, TRUE }; 
#define HEX_BASE 16	/* base of hexadecimal numbers */
enum hex_equiv { A = 10, B, C, D, E, F };	/* equivalent decimal numbers to hexadecimal letters */

double pow(double base, double n);
double htoi(char hexa_num[]);




int main(void)
{
	int stop = FALSE;	/* stop a loop */
	char hex[10];

	while (stop == FALSE) {
		printf("input a hexadicmal number: ");	/* getting hex number from use input */
		gets(hex);

		if (hex[0] != 'q')
			printf("The equivalent integer of \'%s\' is %.f\n", hex, htoi(hex));
		else
			stop = TRUE;
	}


	return 0;
}




/* pow: raise base to n-th power; n >= 0 */
double pow(double base, double n)
{
	int i, p;

	p = 1;
	for (i = 1; i <= n; ++i)
		p = p * base;

	return p;
}

/* htoi: convert a hexadecimal number to its decimal/integer equivalent */
double htoi(char s[])
{
	int len;	/* length of s[] */
	int power = 0;	/* (16) power of digit location */
	int stop;	/* when to stop the conversion ('0x' OR '0X' OR end of string) */
	long double int_val = 0.0;	/* integer value of the hexadecimal number given */

	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		stop = 1;
	else
		stop = -1;

	for (len = strlen(s) - 1; len > stop; --len, ++power) {
		if (s[len] >= '0' && s[len] <= '9') { /* digit between 0 - 9 */
			int_val += (s[len] - '0') * pow(HEX_BASE, power);
		}
		else if ((s[len] >= 'A' && s[len] <= 'F') || (s[len] >= 'a' && s[len] <= 'f')) /* letter between A - F or a - f */
			if (s[len] == 'A' || s[len] == 'a')
				int_val += A * pow(HEX_BASE, power);
			else if (s[len] == 'B' || s[len] == 'b')
				int_val += B * pow(HEX_BASE, power);
			else if (s[len] == 'C' || s[len] == 'c')
				int_val += C * pow(HEX_BASE, power);
			else if (s[len] == 'D' || s[len] == 'd')
				int_val += D * pow(HEX_BASE, power);
			else if (s[len] == 'E' || s[len] == 'e')
				int_val += E * pow(HEX_BASE, power);
			else if (s[len] == 'F' || s[len] == 'f')
				int_val += F * pow(HEX_BASE, power);
	}

	return int_val;
}
