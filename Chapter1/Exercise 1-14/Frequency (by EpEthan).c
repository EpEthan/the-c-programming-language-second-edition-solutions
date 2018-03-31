/*
 Author: EpEthan
 Created using Jeremy Yu's (ccpalettes) solution
 
 EpEthan's solution for Exercise 1-14, Chapter1.
 */

#include <stdio.h>


#define NUM_CHARS 128 /* Number of characters */
#define IN 1 /* Inside a word */
#define OUT 0 /* Outside a word */

/* A histogram of the frequencies of words in input */
int hist_of_word_freq(void)
{
	int c; /* for the getchar() function */
	int i, j; /* i and j are simply index counters */
	int char_frequencies[NUM_CHARS]; /* the array of number of characters */
	long characters = 0; /* number of characters */

	for (i = 0; i < NUM_CHARS; ++i)
		char_frequencies[i] = 0; /* create the array */

	printf("Enter some characters and press Ctrl+Z when finished.\n");
	while ((c = getchar()) != EOF) {
		++char_frequencies[c]; /* as c is an int, this will increment every character correctly */
		++characters;
	}

	printf("\n Char | Count\n");
	for (i = 0; i <= NUM_CHARS; ++i)
		if (char_frequencies[i] > 0) {
			if ((char)(i) == '\n') /* the syntax '(char)(x)' (where x is an integer) will produce the corresponding character for x (for the table of all of them, reffer to https://www.asciitable.com/ */
				printf(" '%s%s' | ", "\\", "n"); /* if you write '/n' as one string, it will just put a new line, hence the separation */
			else if ((char)(i) == '\t')
				printf(" '%s%s' | ", "\\", "t"); /* if you write '/t' as one string, it will just put a tab, hence the separation */
			else
				printf(" '%c'  | ", i);
			for (j = 0; j < char_frequencies[i]; ++j)
				printf("=");


			/* If you want to view the amount of times each of the character was used (I misread the instructions, made this and kept it...)
			if ((char)(i) == '\n')
				printf(" '%s%s' : %5.4f", "\\", "n", (double)(char_frequencies[i]) / (double)(characters));
			else if ((char)(i) == '\t')
				printf(" '%s%s' : %5.4f", "\\", "t", (double)(char_frequencies[i]) / (double)(characters));
			else
				printf(" '%c'  : %5.4f", i, (double)(char_frequencies[i]) / (double)(characters));
			printf("\t %s %d%s%d%s \n", "(OR", char_frequencies[i], "/", characters, ")");
			*/
		}
}
