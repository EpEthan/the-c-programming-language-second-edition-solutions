/**
 * Author: EpEthan
 * 
 * Solution for Exercise 2-01, Chapter2.
 */

#include <stdio.h>
#include <limits.h>

int main(void)
{
	printf("Range of signed char: %11d - %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("Range of unsigned char: %7u - %u\n", 0, UCHAR_MAX);
	printf("Range of char: %18d - %d\n\n", CHAR_MIN, CHAR_MAX);

	printf("Range of signed short int: %8hd - %hd\n", SHRT_MIN, SHRT_MAX);
	printf("Range of unsigned short int: %2hu - %hu\n\n", 0, USHRT_MAX);

	printf("Range of signed int: %19d - %d\n", INT_MIN, INT_MAX);
	printf("Range of unsigned int: %8u - %u\n\n", 0, UINT_MAX);

	printf("Range of signed long: %18ld - %ld\n", LONG_MIN, LONG_MAX);
	printf("Range of unsigned long int: %3lu - %lu\n\n", 0, ULONG_MAX);

	printf("----------------------------------CONCLUSION-----------------------------------\n");
	printf("Range of signed char = char   ---> %6d - %d\n", CHAR_MIN, CHAR_MAX);
	printf("Range of signed int  = signed long   ---> %14d - %d\n", INT_MIN, INT_MAX);
	printf("In addition, signed and unsigned have the same range, however, signed may be both a positive or a negative number, while unsigned must be a positive number or 0.\n");


	return 0;
}
