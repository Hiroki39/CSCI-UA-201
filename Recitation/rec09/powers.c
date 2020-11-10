# include <stdio.h>

int main()
{
	int i, value, base, exp;
	printf ("Enter the base (integer): ");
	scanf ("%d", &base );
    	printf ("Enter the exponent (positive integer): ") ;
	scanf ("%d", &exp );

    //calculate base^exponent 
	for (i=0; i<exp; i++)
		value = value * base;    

	printf(" %d^%d  is %d\n",base,exp,value);
}
