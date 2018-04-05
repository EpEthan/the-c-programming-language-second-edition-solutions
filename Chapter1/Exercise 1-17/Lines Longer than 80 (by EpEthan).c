/*
* Author: EpEthan
* Created using Jeremy Yu's (ccpalettes) solution
*
* EpEthan's solution for Exercise 1-14, Chapter1.
*/

#include <stdio.h>

#define MAXLINE 1000	/* maximum input line size */
#define MIN_LEN 80	/* minimum length for a line to be printed */

int getline(char line[], int maxline);

/* print all input lines longer than 80 */
main()
{
	int len;	/* current line length */
	char line[MAXLINE];	/* current input line */

	while ((len = getline(line, MAXLINE)) > 0)
		if (len > MIN_LEN) {
			printf("\n\n--------------------THIS LINE WAS LONGER THAN 80 CHARACTERS!--------------------\n");
			printf("%s\n", line);
			printf("--------------------------------------------------------------------------------\n\n");
		}


	while (getchar() != EOF)
		;

	return 0;
}


/* getline: read a line into s, return length */
int getline(char s[], int limit)
{
	int c, i, l;

	for (i = 0, l = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (i < limit - 1)
			s[l++] = c;
	}
	if (c == '\n') {
		if (l < limit - 1)
			s[l++] = c;
		++i;
	}
	s[l] = '\0';

	return i;
}
