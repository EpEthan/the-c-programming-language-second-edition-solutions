#include <stdio.h>

int lower(int c);


int main() {
	char str[] = "THIS STRING IS ALL UPPER CASE LETTERS. OR IS IT?";

	printf("%s\n", str);
	for (int i = 0; i < sizeof(str) / sizeof(str[0]); ++i)
		str[i] = lower(str[i]);
	
	printf(" \t\t%s\n \t\t%s\n", "||", "\\/");
	printf("%s", str);


  return 0;
}

int lower(int c) {
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
