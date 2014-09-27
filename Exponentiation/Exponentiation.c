#include <stdio.h>
#include <string.h>

int length;

void multiply(int a[], int n)
{
	int i, j;
	int a2[151] = {0};
	int carry,temp;

	for(i=0; i<151; i++)
	{
		a2[i] = a[i];
		a[i] = 0;
	}

	for(i=0; i<151; i++)
	{
		temp = a2[i] * n;
		a[i] += temp % 10;
		carry = temp/10 + a[i]/10;
		a[i] %= 10;
		for(j=i+1; carry; j++)
		{
			a[j] += carry % 10;
			carry /= 10;
		}
		length = j;
	}
}

int main()
{
	char s[7];
	int n;
	int answer[151]={0};
	int TF;
	int end;

	while(scanf("%s %d", s, &n) != EOF)
	{
		int i = 0, num_decimal = 0, mynum = 0;

		for(i=0; i<151; i++)
		{
			answer[i] = 0;
		}

		for(i=0; i<strlen(s); i++)
		{
			if(s[i] == '.')
			{
				num_decimal = (strlen(s) - i - 1) * n;
			}
			else
			{
				mynum = mynum * 10 + s[i] - 48;
			}
		}
		if(mynum==0 && n!=0){printf("0\n");continue;}
		answer[0] = 1;
		length = 1;
		for(i=0; i<n; i++)
		{
			multiply(answer, mynum);
		}

		for(i=0; i<length-1; i++)
		{
			if(i == num_decimal)
				break;
			if(answer[i]!= 0)
				break;
		}
		end = i;

		TF = 0;
		for(i=length-1; i!=end-1; i--)
		{

			if(i == num_decimal-1)
			{
				printf(".");
				TF = 1;
			}
			if(!TF && !answer[i])
				continue;
			else if(!TF && answer[i])
				TF = 1;
			printf("%d",answer[i]);
		}
		printf("\n");
	}
} 