/*
* Author: EpEthan
*
* EpEthan's solution for Exercise 1-23, Chapter1.
*/


#include <stdio.h>

#define MAXLINE 1500	/* maximum length of input line */

int getline(char s[]);
void rem_com(char from[], char to[]);



main()
{
	char program[MAXLINE];	/* input program */
	char output_prog[MAXLINE];	/* ouput program (without comments) */

	while (getline(program) > 0) {
		rem_com(program, output_prog);
	}

	printf("\n\n-----------------------YOUR PROGRAM WITHOUT COMMENTS---------------------------\n");
	printf("%s", output_prog);
	printf("\n-------------------------------------------------------------------------------\n\n");



	while (getchar() != EOF)
		;

	return 0;
}




/* getline: copies line into s[], returns length */
int getline(char s[])
{
	int i;
	int c;

	for (i = 0; i < MAXLINE - 1
		&& (c = getchar()) != EOF; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}

/* rem_com: remove comments from a C program; C comments do not nest */
void rem_com(char from[], char to[])
{
	int i, j;
	int comment_start;	/* index of the last found comment's start */
	int comment_end;	/* index of the last found comment's end */


	for (i = j = 0; from[j] != '\0'; ++i, ++j) {
		if (from[j] == '/' && from[j + 1] == '*') {
			j += 2;
			while (from[j] != '*' && from[j + 1] != '/')
				++j;
			j += 2;
		}

		to[i] = from[j];
	}
	
	to[i] == '\0';
}
