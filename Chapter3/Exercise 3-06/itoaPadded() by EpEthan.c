#include <stdio.h>

void itoaPadded(int sourceNumber, char destinationArray[], int minimumFieldWidth);
void reverse(char s[]);


int main() {
	char s[10];

	itoaPadded(340, s, 10);
	printf("%d is converted to %s\n", 340, s);
	itoaPadded(340, s, 3);
	printf("%d is converted to %s\n", 340, s);
	itoaPadded(340, s, 1);
	printf("%d is converted to %s\n", 340, s);


	return 0;
}


/* itoaPdded: The third argument is a minimum field width; the converted number is padded with blanks on the left 
if necessary to make it wide enough */
void itoaPadded(int n, char s[], int fieldWidth) {
	int i, sign;

	sign = n;
	i = 0;
	do {
		s[i++] = ((sign < 0) ? -(n % 10) : n % 10) + '0';
	} while (n /= 10);
	if (sign < 0)
		s[i++] = '-';
	
	while (i < fieldWidth)  // only addition to the function
		s[i++] = ' ';

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
