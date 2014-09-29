#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node * next;
}node;

void addNode(node ** newnode)
{
	*newnode = (node*)malloc(sizeof(node));
}

int main()
{
	node *p, *p2;
	node head;
	int input;
	p2 = &head;
	while((scanf("%d", &input))!=EOF && input)
	{
		//p = (node*)mallc(sizeof(node));
		addNode(&p);
		p -> value = input;
		p2 -> next = p;
		p2 = p;
	}

	p2 = &head;
	while(p2)
	{
		printf("%d->", p2 -> value);
		p2 = p2 -> next;
	}

	return 0;
}