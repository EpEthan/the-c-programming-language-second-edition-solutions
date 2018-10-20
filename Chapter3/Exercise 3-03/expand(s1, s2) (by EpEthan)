#include <stdio.h>
#include <ctype.h>

void expand(char from[], char to[]);


int main() {
	char s1[] = "a-z0-98-5-a-z4-8c-fm-nn-m1-99-18-5a-zz-cx-yv-u";
	char s2[200];

	expand(s1, s2);

	printf("%s\n", s1);
	printf("=> %s", s2);

	while (getchar() != EOF)
		;
	return 0;
}


/* expand: expand shorthand notations like `a-z` in the string `s1` into the equivalent complete list abc...xyz 
** in `s2` */
void expand(char s1[], char s2[]) {
	int i, j;
	int bef, aft;	// characters before and after `-`
	int len = strlen(s1);

	for (i = j = 0; i < len - 1; ++i) {
		if (isalpha(s1[i])) {
			bef = s1[i++];
			while (!isalpha(s1[i]))	// skip whitespace and `-`
				++i;
			aft = s1[i];

			if (bef < aft)	// ascending or descending order
				while (bef <= aft)
					s2[j++] = bef++;
			else
				while (bef >= aft)
					s2[j++] = bef--;

			s2[j++] = ' ';
		}

		if (isdigit(s1[i])) {
			bef = s1[i++];
			while (!isdigit(s1[i]))	// skip whitespace and `-`
				++i;
			aft = s1[i];

			if (bef < aft)	// ascending or descending order
				while (bef <= aft)
					s2[j++] = bef++;
			else
				while (bef >= aft)
					s2[j++] = bef--;

			s2[j++] = ' ';
		}
	}
	s2[j] = '\0';
}
