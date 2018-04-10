/*
* Author: EpEthan
*
* EpEthan's solution for Exercise 1-21, Chapter1.
*/


#include <stdio.h>

#define MAXLINE 1000	/* maximum length of input line */

int getline(char s[]);
void entab(char from[], char to[]);


main()
{
	char line[MAXLINE];
	char output_line[MAXLINE];

	while (getline(line) > 0) {
		entab(line, output_line);

		printf("\n\n---------------------------------ENTAB RESULT----------------------------------\n");
		for (int i = 0; output_line[i] != '\n'; ++i)
			printf("%c|", output_line[i]);
		printf("\n-------------------------------------------------------------------------------\n");

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

/* entab: replace strings of blanks by minimum number of tabs and blanks to achieve the same spacing */
void entab(char from[], char to[])
{
	int i, new_len;

	for (i = 0, new_len = 0; from[i] != '\0'; ++i, ++new_len) {
		if (from[i] == ' ' && from[i + 1] == ' ' && from[i + 2] == ' ' && from[i + 3] == ' ') {
			to[new_len] = '\t';
			i += 3;	/* 3 and not 4 because in the end of the loop new_len will be incremented by 1 either way */
		}
		else {
			to[new_len] = from[i];
		}
	}
}
