/*
* Author: EpEthan
*
* EpEthan's solution for Exercise 1-23, Chapter1.
*/


#include <stdio.h>

#define MAXLINE 3000	/* maximum length of input line */

int summary[7];	/* array of number of missing syntax */

int getline(char s[]);
void check_code(char program[]);



main()
{
	char program[MAXLINE];	/* input program */
	extern int summary[];

	while (getline(program) > 0) {
		check_code(program);

		printf("\n\n---------------------------------FOLD RESULT-----------------------------------\n");
		printf("braces missing: %14d\n", summary[0]);
		printf("brackets missing: %12d\n", summary[1]);
		printf("parentheses missing: %9d\n", summary[2]);
		printf("double quotes missing: %7d\n", summary[3]);
		printf("single quotes missing: %7d\n", summary[4]);
		printf("escape sequences missing: %4d\n", summary[5]);
		printf("comments missing: %12d", summary[6]);
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
		&& (c = getchar()) != EOF; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}

/* check_code: check a C program for rudimentary syntax errors suck as unbalanced braces, quotes, comments, escape sequence etc. */
void check_code(char prog[])
{
	int i, j;
	int line;	/* current line */
	int braces, brackets, parentheses;	/* number of missing braces, brackets, parentheses, angle brackets */
	int double_qu, single_qu;	/* number of missing single, double quotes */
	int escape;	/* number of missing escape sequences */
	int comment;	/* number of missing comment ends */
	extern int summary[];


	line = 1;
	braces = brackets = parentheses = double_qu = single_qu = escape = comment = 0;
	for (i = 0; prog[i] != '\0'; ++i) {
		if (prog[i] == '\n')
			++line;
		else {
			/* single quotes */
			if (prog[i] == '\'' && prog[i - 1] != '\\' && single_qu % 2 != 0)
				--single_qu;
			else if (prog[i] == '\'' && prog[i - 1] != '\\')
				++single_qu;

			/* brackets */
			else if (prog[i] == '[')
				++brackets;
			else if (prog[i] == ']')
				--brackets;

			/* parenthesis */
			else if (prog[i] == '(')
				++parentheses;
			else if (prog[i] == ')')
				--parentheses;

			/* comments */
			else if (prog[i] == '/' && prog[i + 1] == '*')
				++comment;
			else if (prog[i] == '*' && prog[i + 1] == '/')
				--comment;

			/* escape sequence */
			else if (prog[i] == '\\'
				&& (prog[i + 1] != 'n' || prog[i + 1] != 't' || prog[i + 1] != '\\' || prog[i + 1] != 'r'
					|| prog[i + 1] != '\'' || prog[i + 1] != '\"' || prog[i + 1] != 'v' || prog[i + 1] != 'f'
					|| prog[i + 1] != 'a' || prog[i + 1] != 'b'))
				++escape;

			/* double quotes */
			else if (prog[i] == '\"' && prog[i - 1] != '\\' && single_qu % 2 != 0)
				--single_qu;
			else if (prog[i] == '\"' && prog[i - 1] != '\\')
				++single_qu;
			
			/* braces */
			else if (prog[i] == '{')
				++braces;
			else if (prog[i] == '}')
				--braces;
		}
	}


	summary[0] = braces;
	summary[1] = brackets;
	summary[2] = parentheses;
	summary[3] = double_qu;
	summary[4] = single_qu;
	summary[5] = escape;
	summary[6] = comment;
}
