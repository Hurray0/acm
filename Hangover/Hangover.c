#include <stdio.h>

int main()
{
	double input, temp;
	double i;

	while(1)
	{
		scanf("%lf", &input);
		// printf("%lf\n", input);
		if(input == 0)
			break;
		if(input < 0.5)
		{
			printf("1 card(s)\n");
			continue;
		}
		i = 2;temp = 0;
		while((temp + 1/i) <= input)
		{
			temp += 1/i;
			i++;
		}
		printf("%d card(s)\n", (int)i-1);
	}

	return 0;
}