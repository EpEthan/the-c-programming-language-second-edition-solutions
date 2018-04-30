/**
 * Author: EpEthan
 * 
 * Solution for Exercise 2-05, Chapter2.
 */
 
 
#include <stdio.h>

int any(char s1[], char s2[]);


int main()
{
	int i;
	int loc;	/* location of first occurance of a character from s2 in s1 */
	char s1[] = "My name is EpEthan. What is you name?";
	char s2[] = "Hello, World!";

	loc = any(s1, s2);

	if (loc > -1) {
		printf("The location of first occurance of a character from s2 in s1 is %d (the character \'%c\'):\n", loc, s1[loc]);
		for (i = 0; s1[i] != '\0'; ++i)
			if (i == loc)
				printf("|%c|", s1[i]);
			else
				putchar(s1[i]);
	}
	else
		printf("There were no occurances between s1 and s2.\n");



	while (getchar() != EOF)
		;

	return 0;
}


/* any: return the location of first occurance of a character from s2 in s1 */
int any(char s1[], char s2[])
{
	int i, j;
	int location = -1;	/* location of first occurance of a character from s2 in s1; it is set to -1 in case there is no occurance */

	for (i = 0; s1[i] != '\0'; ++i) {
		for (j = 0; s2[j] != '\0'; ++j)
			if (s1[i] == s2[j] && s1[i] != ' ') {
				if (location == -1)
					location = i;
			}
	}

	return location;
}
