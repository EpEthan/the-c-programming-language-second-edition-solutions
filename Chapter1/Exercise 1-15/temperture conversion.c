#include <stdio.h>


double temp_conversion(int fahr, int cels);

int main(void)
{
	int fahr, cels;
	int lower, upper, step;
	
	printf ("Set the starting temperture of the Fahrenheit-Celsius table: "); /* set lower with user input */
	scanf ("%d",&lower);
	printf ("Set the ending temperture of the table: "); /* set upper with user input */
	scanf ("%d",&upper);
	printf ("Set the step size between each temperture: "); /* set the step size with user input */
	scanf ("%d",&step);
  
	
	printf("Fahrenheit to Celsius Table:\n\n"); /* table heading */
	printf(" Fahr\t ||\t Cels\n"); /* table columns */
	printf("=======================\n"); /* table columns line */
	
	for (fahr = lower; fahr <= upper; fahr += step)
		printf("%3d\t ||\t %6.1f\n", fahr, temp_conversion(fahr, '\0')); /* the character '\0' stands for a null value */
	putchar('\n');


	printf ("Set the starting temperture of the Celsius-Fahrenheit table: "); /* set lower with user input */
	scanf ("%d",&lower);
	printf ("Set the ending temperture of the table: "); /* set upper with user input */
	scanf ("%d",&upper);
	printf ("Set the step size between each temperture: "); /* set the step size with user input */
	scanf ("%d",&step);
    
	printf("Celsius to Fahrenheit Table:\n\n"); /* table heading */
	printf(" Cels\t ||\t Fahr\n"); /* table columns */
	printf("=======================\n"); /* table columns line */

	for (cels = lower; cels <= upper; cels += step)
		printf("%3d\t ||\t %6.1f\n", cels, temp_conversion('\0', cels)); /* the character '\0' stands for a null value */


	return 0;
}

/* temp_conversion: convert Celsius-Fahrenheit / Fahrenheit-Celsius */
double temp_conversion(int fahr, int cels)
{
	if (cels == '\0') {
		cels = (5.0 / 9.0) * (fahr - 32);
		return cels;
	}
	else {
		fahr = cels * (9.0 / 5.0) + 32;
		return fahr;
	}
}
