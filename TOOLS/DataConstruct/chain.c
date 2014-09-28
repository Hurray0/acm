#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node * next;
}node;

int main()
{
	node *p, *pre;
	node head;
	int input;
	pre = &head;
	while((scanf("%d", &input))!=EOF && input)
	{
		p = (node*)malloc(sizeof(node));
		p -> value = input;
		pre -> next = p;
		pre = p;
	}

	pre = &head;
	while(pre)
	{
		printf("%d->", pre -> value);
		pre = pre -> next;
	}

	return 0;
}