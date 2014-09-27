#include <stdio.h>
#include <string.h>

void add(int* answer, char* new_num)
{
	int i, j;

	for(i=124, j=0; i; i--)
	{
		if(new_num[i-1] == '\0') continue;
		answer[j] += new_num[i-1] - 48;
		j++;
	}
}

change_to_decimal(int* answer)
{
	int i, carry, j;
	for(i=0; i<124; i++)
	{
		carry = answer[i]/10;
		answer[i] %= 10;
		j = i;
		while(carry)
		{
			answer[++j] += carry%10;
			carry /= 10;
		}
	}
}

int main()
{
	int answer[124]={0};
	char new_num[124]={'\0'};
	int i;
	int TF;

	while(scanf("%s",new_num) != EOF)
	{
		if(new_num[0]=='0' && strlen(new_num)==1)
			break;
		add(answer,new_num);
		for(i=0; i<124; i++)
		{
			new_num[i] = '\0';
		}
	}

	change_to_decimal(answer);

	for(i=124, TF=1; i; i--)
	{
		if(TF) 
		{
			if(answer[i-1]!=0)
			{
				TF = 0;
			}
			else
			{
				continue;
			}
		}
		printf("%d",answer[i-1]);
	}
	printf("\n");
	return 0;
}