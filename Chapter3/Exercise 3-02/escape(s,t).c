#include <stdio.h>

#define MAX_LEN 500	// max of 500 characters for a paragraph

void escape(char s[], char t[]);


int main() {
	char t[MAX_LEN], s[MAX_LEN];
	int c, i;

	for (i = 0; (c = getchar()) != EOF; ++i)
		t[i] = c;

	escape(s, t);
	for (i = 0; s[i] != '\0'; ++i)
		printf("%c", s[i]);


	return 0;
}


/* Convert characters like 'tab' and 'newline' to visible escape sequences like '\t' and '\n' and 
copy them from t[] to s[] */
void escape(char s[], char t[]) {
	int i, j;

	for (i = j = 0; t[i] != '\0'; ++i, ++j) {
		switch (t[i]) {
		case '\n':
			s[j++] = '\\';
			s[j] = 't';
			break;
		case '\t':
			s[j++] = '\\';
			s[j] = 't';
			break;
		case '\v':
			s[j++] = '\\';
			s[j] = 'v';
			break;
		case '\a':
			s[j++] = '\\';
			s[j] = 'a';
			break;
		case '\b':
			s[j++] = '\\';
			s[j] = 'b';
			break;
		default:
			s[j] = t[i];
			break;
		}
	}
}
