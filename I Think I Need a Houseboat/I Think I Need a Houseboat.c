#include <stdio.h>
#include <math.h>

#define PI 3.1415926;

int main()
{
	int number, i;

	scanf("%d", &number);
	for(i=0; i<number; i++)
	{
		double x, y, square;
		int year;

		scanf("%lf %lf", &x, &y);
		square = (x*x + y*y)*PI;
		year = (int)(square/100);
		printf("Property %d: This property will begin eroding in year %d.\n", i+1, year+1);
	}
	printf("END OF OUTPUT.");
}