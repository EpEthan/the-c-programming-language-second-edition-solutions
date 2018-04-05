/* Author: EpEthan
*
* EpEthan's solution for Exercise 1-19, Chapter1.
*/


#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int getline(char line[], int maxline);
void reverse(char s[]);

/* print longest input line */
main()
{
	int len;	/* current line's length */
	char line[MAXLINE];	/* current input line */


	while ((len = getline(line, MAXLINE)) > 0) {
		reverse(line);
		printf("%s\n", line);
	}

	while (getchar() != EOF)
		;

	return 0;
}


/* getline: read a line into s, return length */
int getline(char s[], int limit)
{
	int c, i, l;

	for (i = 0, l = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		if (i < limit - 1)
			s[l++] = c;
	if (c == '\n' && l < limit - 1)
		s[l++] = c;
	s[l] = '\0';

	return l;
}

/* reverse: reverse input string */
void reverse(char s[])
{
	int i, j;	/* index markers */
	int len;	/* length of the line */
	char temporary[MAXLINE];	/* temporary string for storaging the original */

	for (len = 0; s[len] != '\0'; ++len)	/* find the length of the line */
		;
	i = len -1;

	for (j = 0; i != -1; --i, ++j)
		temporary[j] = s[i];	/* copy the line in reverse to temporary */
	
	for (i = 0; i <= len - 1; ++i)
		s[i] = temporary[i];	/* copy the reverse line to the original string */
}
