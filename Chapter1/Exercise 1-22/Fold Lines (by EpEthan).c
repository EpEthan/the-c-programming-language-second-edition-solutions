/*
* Author: EpEthan
*
* EpEthan's solution for Exercise 1-22, Chapter1.
*/


#include <stdio.h>

#define MAXLINE 1000	/* maximum length of input line */
#define PERLINE 75	/* maximum number of character per line */

int getline(char s[]);
void fold(char from[], char to[]);


main()
{
	char line[MAXLINE];
	char output_lines[MAXLINE];

	while (getline(line) > 0) {
		fold(line, output_lines);

		printf("\n\n---------------------------------FOLD RESULT-----------------------------------\n");
		printf("%s", output_lines);
		printf("\n-------------------------------------------------------------------------------\n\n");

	}

	return 0;
}




/* getline: copies line into s[], returns length */
int getline(char s[])
{
	int i;
	int c;

	for (i = 0; i < MAXLINE - 1
		&& (c = getchar()) != 'EOF' && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}

/* fold: turn long input lines into two or more shorter lines after the last non-blanks */
void fold(char from[], char to[])
{
	int i;
	int chars_in_line;	/* number of characters in the line */
	int last_blank;	/* index of last blank/tab found */


	for (i = 0, chars_in_line = 0; from[i] != '\0'; ++i, ++chars_in_line) {
		to[i] = from[i];

		if (to[i] == ' ' || to[i] == '\t')
			last_blank = i;
		if (chars_in_line == PERLINE - 1) {
			chars_in_line = 0;
			to[last_blank] = '\n';
		}
	}

	to[--i] = '\0';
}
