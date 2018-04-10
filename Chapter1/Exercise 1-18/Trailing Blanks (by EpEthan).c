/*
* Author: EpEthan
*
* Solution for Exercise 1-18, Chapter1.
*/


#include <stdio.h>

#define TRUE 0
#define FALSE 1
#define MAXLINE 1000 /* maximum input line size */

int getline(char line[], int maxline);
int delete_trailing(char s[], char output_s[]);


/* print longest input line */
main()
{
	int i;
	char line[MAXLINE];	/* current input line */
	char clean_line[MAXLINE];	/* the line without the trailing blanks */
	int cleanlen; /* length of clean_line */

	while (getline(line, MAXLINE) > 0) {
		int cleanlen = delete_trailing(line, clean_line);
		if (cleanlen == -1)
			printf("The line was made only by whitespaces\n\n");
		else {
			printf("The line without the trailing blanks:\n\t|");
			for (i = 0; i <= cleanlen; ++i)
				printf("%c|", clean_line[i]); /* The character '|' was put at the end of each character in order to 
                                               * seperate all the characters and check if there are no trailing blanks */
			putchar('\n');
		}
	}

	return 0;
}


/* getline: read a line into s */
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

/* delete_trailing: delete all trailing whitespace characters */
int delete_trailing(char s[], char output_s[])
{
	int len;	/* length of s[] including the trailing blanks */
	int dont_del;	/* the index of the end of the line without the trailing blanks */
	int del_line; /* if the line is made only of trailing balnks, this will be set to TRUE */
	int i, continue_loop;


	for (len = 0; s[len] != '\0'; ++len)
		;

	del_line = FALSE;
	continue_loop = TRUE;
	while (continue_loop == TRUE)
		if (s[len] == '.' || s[len] == '!' || s[len] == '?' || s[len] == ':') { /* if it's a punctutaion mark */
			dont_del = len;
			continue_loop = FALSE;
		}
		else if ((s[len] >= 'a' && s[len] <= 'z') || (s[len] >= 'A' && s[len] <= 'Z')) { /* if it's a letter */
			dont_del = len;
			continue_loop = FALSE;
		}
		else
			if (len <= 0) {
				continue_loop = FALSE;
				del_line = TRUE;
			}
			else
				--len;

	
	if (del_line == FALSE) {
		for (i = 0; i <= dont_del; ++i)
			output_s[i] = s[i];
		output_s[++i] = "\n";

		return dont_del;
	}
	else {
		return -1;
	}
}
