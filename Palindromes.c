#include <stdio.h>
#include <string.h>

int isSame(char a, char b)
{
	if(a == '0' && b == 'O' || a == 'O' && b == '0')
		return 1;
	return a==b ? 1:0;
}

int isMirror(char a, char b)
{
	if(a == b)
	{
		if(a == 'A' ||
			a == 'H' ||
			a == 'I' ||
			a == 'O' ||
			a == 'T' ||
			a == 'U' ||
			a == 'V' ||
			a == 'W' ||
			a == 'M' ||
			a == 'X' ||
			a == 'Y' ||
			a == '1' ||
			a == '8')
			return 1;
		else return 0;
	}
	else
	{
		if(a == 'E' && b == '3' || a == '3' && b == 'E' ||
			a == 'J' && b == 'L' || a == 'L' && b == 'J' ||
			a == 'S' && b == '2' || a == '2' && b == 'S' ||
			a == '5' && b == 'Z' || a == 'Z' && b == '5')
			return 1;
		else return 0;
	}
}


int main()
{
	char s[101];

	while(scanf("%s",s) != EOF)
	{
		int Mirror = 1, Palindrome = 1;
		int i;
		int n = strlen(s);

		//Palindrome
		for(i=0; i<(n/2); i++)
		{
			if(!isSame(s[i], s[n-i-1]))
			{
				Palindrome = 0;
				break;
			}
		}

		//Mirror
		for(i=0; i<(n/2 +1); i++)
		{
			if(!isMirror(s[i], s[n-i-1]))
			{
				Mirror = 0;
				break;
			}
		}

		// printf("%s",s );

		if(Mirror && Palindrome)
			printf("%s -- is a mirrored palindrome.\n", s);
		else if(Mirror)
			printf("%s -- is a mirrored string.\n", s);
		else if(Palindrome)
			printf("%s -- is a regular palindrome.\n", s);
		else
			printf("%s -- is not a palindrome.\n", s);

		printf("\n");

	}

	return 0;
}