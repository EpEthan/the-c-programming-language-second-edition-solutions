/*
* Author: EpEthan
*
* EpEthan's solution for Exercise 1-20, Chapter1.
*/


#include <stdio.h> /

#define MAXLINE 1000 /* maximum input line size */
#define TABSPACE 40 /* the space for the tabs in the line; tab = 4 spaces */

char line[MAXLINE];	/* current input line */
char notab_line[MAXLINE];	/* line without the tabs saved here */

int getline(void);
void detab(void);



main()
{
	int i;
	extern char notab_line[];

	printf("Input something and then press Ctrl+Z.\n");
	while (getline() > 0) {
		detab();

		printf("\n\n---------------------------------DETAB RESULT----------------------------------\n");
		printf("%s", notab_line);
		printf("\n-------------------------------------------------------------------------------\n");
	}


  return 0;
}



/* getline: read a line, return length */
int getline(void)
{
	int c, i;
	extern char line[];

	for (i = 0; i < MAXLINE - TABSPACE - 1
		&& (c = getchar()) != EOF && c != '\n'; ++i)
		    line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
    
	return i;
}


/* detab: replace tabs with 4 blanks from string */
void detab(void)
{
	int i;
	int new_len;	/* length of the new string */
	extern char line[], notab_line[];

	for (i = 0, new_len = 0; line[i] != '\n'; ++i, ++new_len) {
		if (line[i] == '\t') {
			notab_line[new_len] = ' ';
			notab_line[++new_len] = ' ';
			notab_line[++new_len] = ' ';
			notab_line[++new_len] = ' ';
		}
		else
			notab_line[new_len] = line[i];
	}

	return new_len;
}
