#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int count;
	char b[10];
	struct node * next;
}node;

void transform(char * a, char * b)
{
	int i,j = 0;
	while(1)
	{
		if(a[i]=='\0')
			break;

		if(a[i] == '-')
		{
			i++;
			continue;
		}
		else if(a[i]>='0' && a[i]<='9')
		{
			b[j] = a[i];
		}
		else if(a[i] == 'A' || a[i] == 'B' || a[i] == 'C')
		{
			b[j] = '2';
		}
		else if(a[i] == 'D' || a[i] == 'E' || a[i] == 'F')
		{
			b[j] = '3';
		}
		else if(a[i] == 'G' || a[i] == 'H' || a[i] == 'I')
		{
			b[j] = '4';
		}
		else if(a[i] == 'J' || a[i] == 'K' || a[i] == 'L')
		{
			b[j] = '5';
		}
		else if(a[i] == 'M' || a[i] == 'N' || a[i] == 'O')
		{
			b[j] = '6';
		}
		else if(a[i] == 'P' || a[i] == 'R' || a[i] == 'S')
		{
			b[j] = '7';
		}
		else if(a[i] == 'T' || a[i] == 'U' || a[i] == 'V')
		{
			b[j] = '8';
		}
		else if(a[i] == 'W' || a[i] == 'X' || a[i] == 'Y')
		{
			b[j] = '9';
		}
		else
		{
			b[j] = '0';
		}

		i++;
		j++;
	}
}

void addToList(char * b, node * head)
{
	int i,j;
	node * temp, * newnode, *temp2;

	temp = head;
	while(1)
	{	
		temp2 = temp;
		if(temp -> next == NULL)
			break;
		temp = temp -> next;

		for(i=0; i<7; i++)
		{
			if(temp ->b[i] == b[i])
				continue;
			else
				break;
		}
		if(i == 7)
		{
			temp->count++;
			return;
		}
		else if(temp->b[i] > b[i])
		{
			break;
		}
	}

	newnode = (node*)malloc(sizeof(node));
	if(temp2 != temp)
	{
		temp2 ->next = newnode;
		newnode ->next = temp;
	}
	else
	{
		temp ->next = newnode;
		newnode -> next = NULL;
	}
	for(i=0; i<7; i++)
	{
		newnode ->b[i] = b[i];
	}
	newnode -> count = 1;
	return;
}

void printList(node * head)
{
	int i, j;
	node * temp = head;
	while(1)
	{
		if(temp->next == NULL)
			break;
		temp = temp->next;
		if(temp -> count == 1)
			continue;
		for(i=0; i<7; i++)
		{
			printf("%c", temp->b[i]);
			if(i == 2)
				printf("-");
		}
		printf(" %d\n", temp->count);
	}

}

int main()
{
	int i, j, number;
	char a[30]={'\0'};
	char b[10]={'\0'};
	node head;

	head.next = NULL;

	scanf("%d", &number);
	for(i=0; i<number; i++)
	{
		scanf("%s", a);

		transform(a,b);
		addToList(b, &head);

		for(j=0; j<30; j++)
		{
			a[j] = '\0';
			if(j<10)
				b[j] = '\0';
		}
	}

	printList(&head);
}