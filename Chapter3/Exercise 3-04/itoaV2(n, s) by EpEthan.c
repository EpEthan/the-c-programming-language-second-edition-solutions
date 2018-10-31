#include <stdio.h>
#include <limits.h>

void itoa(int sourceNumber, char destinationArray[]);
void itoaV2(int sourceNumber, char destinationArray[]);

void reverse(char s[]);

int main() {
	char s[10];
	int i;

	printf("INT_MIN = %d\n -(INT_MIN) = %d\n\n", INT_MIN, -(INT_MIN));
	itoa2(INT_MIN, s);
	printf("%d is converted to %s\n", INT_MIN, s);


	return 0;
}


/* itoa: convert n to characters in s */
void itoa(int n, char s[]) {
	int i, sign;

	if ((sign = n) < 0)	// record sign
		n = -n;	// make n positive

	i = 0;
	do {	// generate digits in reverse order
		s[i++] = n % 10 + '0';	// get next digit
	} while ((n /= 10) > 0);	// delete it
	
	if (sign < 0)
		s[i++] = '-';
	reverse(s);
}

/* Exercise 3-4:
In a two's complement number representation this version of itoa does not handle the largest negative number.
That is, the value of n equal to -(2^(wordsize-1)).
The reason for that is the leftmost bit. In two's complement, this bit determines wheter the number is positive
or not. When translating INT's minimum value to it's opposite form (-n), the machine transfers all the one's to 
zero's, and vice versa. 
Moreover, in two's complement, the representation of a negative number is 2^n, unlike one's complement, where 
it's (2^n - 1). In other words, to find the two's complement representation of a negative number, find the one's 
complement of it, and add one. This also means that two's complement's range of an 8 bit number is -128 to 127, 
and one's complement's is -127 to 127.
Thus, we cannot represent the absolute value of an integer (+128) and itoa() needs reverses the sign of the number
before processing it, which isn't possible in the case of the smallest integer, as passing the largest negative 
number will result it in being translated to itself:
	-128            :		10000000
	One's complement:		01111111
	Subtract 1      :		10000000

Also, in the while part of the do-while, it requires the number to be bigger than zero, so we need to change it 
so it doesn't equal to zero, even if it's a negative number.
*/
void itoaV2(int n, char s[]) {
	int i, sign;

	sign = n;
	i = 0;
	do {
		s[i++] = ( (sign < 0) ? -(n % 10) : n % 10 ) + '0';
	} while (n /= 10);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}


void reverse(char s[])
{
	int i, j;
	int tmp;

	for (j = 0; s[j] != '\0'; ++j)
		;
	--j;

	for (i = 0; i < j; ++i, --j) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}
