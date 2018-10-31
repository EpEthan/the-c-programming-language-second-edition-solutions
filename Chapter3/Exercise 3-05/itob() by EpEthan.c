#include <stdio.h>
#include <limits.h>

void itob(int sourceNumber, char destinationArray[], int base);
void reverse(char s[]);


int main() {
	char s[15];

	itob(INT_MIN, s, 16);
	printf("%d is converted to %s\n", INT_MIN, s2);
	itob(INT_MAX, s, 30);
	printf("%d is converted to %s\n", INT_MAX, s2);
	itob(5, s, 89);


	return 0;
}


/* itob: convert the integer `n` into a base `base` character representation in the string `s` (1 > b > 37) */
void itob(int n, char s[], int b) {
	if (b >= 2 && b <= 36) {
		char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		int i, sign, remainder;

		sign = n;

		i = 0;
		do {
			s[i++] = ((sign < 0) ? digits[-(n % b)] : digits[n % b]);
		} while (n /= b);
		if (sign < 0)
			s[i++] = '-';
		s[i] = '\0';
		reverse(s);
	}
	else
		printf("\n===============\n unable to convert decimal number to a bigger base than 36 or smaller than 2\n===============\n\n");
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
