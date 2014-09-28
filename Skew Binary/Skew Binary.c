#include <stdio.h>
#include <string.h>

int main()
{
	int i, length, sum;
	char input[32];
	int skewbinary[32];

	for(i=1, skewbinary[0]=1; i<32; i++)
	{
		skewbinary[i] = skewbinary[i-1] * 2 + 1;
	}

	while((scanf("%s",input))!=EOF && input[0]!='0')
	{
		length = strlen(input);
		sum = 0;
		for(i=0; i<length; i++)
		{
			sum += skewbinary[length-i-1] * (input[i]-48);
		}
		printf("%d\n", sum);
	}
}