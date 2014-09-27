#include <stdio.h>
#include <string.h> 

int main()
{
	int N, i, j, number = 0;
	int count, count2;
	int designer[1001] = {-1}, breaker[1001] = {-1}, designer2[1001] = {-1};

	while(scanf("%d",&N) != EOF && N)
	{
		for(i=0; i<N; i++)
		{
			scanf("%d", &designer[i]);
		}
		printf("Game %d:\n", ++number);

		while(1)
		{
			count = 0;
			count2 = 0;

			for(i=0; i<N; i++)
			{
				scanf("%d", &breaker[i]);
			}
			if(breaker[0] == 0)
				break;

			for(i=0; i<N; i++)
			{
				designer2[i] = designer[i];
			}

			for(i=0; i<N; i++)
			{
				if(designer2[i] == breaker[i])
				{
					count ++;
					breaker[i] = -1;
					designer2[i] = -1;
				}
			}

			for(i=0; i<N; i++)
			{
				for(j=0; j<N; j++)
				{
					if(designer2[i] == breaker[j] && designer2[i] != -1)
					{
						count2 ++;
						designer2[i] = -1;
						breaker[j] = -1;
					}
				}
			}
			
			printf("    (%d,%d)\n", count, count2);
		}
	}

	return 0;
}