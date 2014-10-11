#include <stdio.h>

int main()
{
	int i;
	float sum=0, temp;

	for(i=0; i<12; i++)
	{
		scanf("%f", &temp);
		sum += temp;
	}
	printf("$%.2f", sum/12.0);
}