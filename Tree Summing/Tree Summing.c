#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int value;
	struct Node * leftNode;
	struct Node * rightNode;
}Node;

int creatTree(char * str_tree, int position, Node ** head)
{
	int i, curser=0, j, number, END=1;
	Node * left, * right;
	for(i=position; str_tree[i]!='\0'; i++)
	{
		if(str_tree[i] == '(' && !curser)
		{
			curser++;
		}
		else if(str_tree[i] == ')')
		{
			if(END)
			{
				*head = NULL;
			}

			return i;
		}
		else if(str_tree[i] == '(')
		{

			if(curser == 1)
			{
				i = creatTree(str_tree, i, &left);

				(*head) -> leftNode = left;
				curser++;
			}
			else if(curser == 2)
			{
				i = creatTree(str_tree, i, &right);
				(*head) -> rightNode = right;
			}
		}
		else
		{
			END = 0;
			for(number=0; str_tree[i]!=')'&&str_tree[i]!='('; i++)
			{
				number *= 10;
				number += str_tree[i]-48;
			}
			i--;
			(*head) = (Node*)malloc(sizeof(Node));
			(*head) -> value = number;
			(*head) -> leftNode = NULL;
			(*head) -> rightNode = NULL;
		}
	}
	return -1;
}

void printTree(Node * head, int num_turn)
{
	int i;
	if(head)
	{
		if(head->rightNode)
		{
			printTree(head->rightNode, num_turn+1);
		}

		for(i=0;i<num_turn;i++)
			printf("\t");
		printf("%d\n", head->value);

		if(head->leftNode)
		printTree(head->leftNode, num_turn+1);
	}
	else
	{
		printf("head为空啊！！！\n");
	}
}

int isSum(Node * head, int sum)
{
	int mysum, left, right;
	if(head)
	{
		if(!head->leftNode && !head->rightNode)
		{
			if(head->value==sum)
				return 1;
			else
				return 0;
		}
		if(head->leftNode)
			left = isSum(head->leftNode, sum - head->value);
		else
			left = 0;
		if(head->rightNode)
			right = isSum(head->rightNode, sum - head->value);
		else 
			right = 0;
		return left+right;
	}
	return 0;
}

int main()
{
	int based_sum;
	char str_tree[501] = {'\0'};
	char temp;
	Node * head;

	while(scanf("%d", &based_sum)!=EOF)
	{
		int i=0, left=0, right=0;
		while(scanf("%c",&temp))
		{
			if(temp == '\n' || temp == '\t' || temp == ' '|| c==9 || c==10)
				continue;
			else
			{
				str_tree[i++] = temp;
				if(temp == '(') 
					left++;
				else if(temp == ')') 
					right++;
				if(left == right) 
					break;
			}
		}
		if(str_tree[1] == ')')
		{
			printf("no\n");
			continue;
		}
		creatTree(str_tree, 0, &head);
		// printTree(head, 0);
		if(isSum(head, based_sum))
			printf("yes\n");
		else
			printf("no\n");

		for(i=0; i<501 && str_tree[i]!='\0'; i++)
		{
			str_tree[i] = '\0';
		}
	}

	return 0;
}