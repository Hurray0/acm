#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//设A、B对称，这里只计正确次数，初始都为1
int A = 1;
int B = 1;


void teach();
void test();

int main()
{
	srand((unsigned int)time(NULL));

	while(1)
	{
		int input_num;
		int i;

		printf("请输入序号：\n");
		printf("1.教学\n");
		printf("2.测试\n");

		scanf("%d", &input_num);
		switch (input_num)
		{
			case 1:
			teach();
			printf("A=%d,B=%d\n", A, B);
			break;

			case 2:
			test();
			break;
			
			default:
			printf("输入错误，请重试！ \n");
			break;
		}
	}
}

void test()
{
	while(1)
	{
		int randnum = rand() % (A+B);
		char input_char;
		int judgenum;

		printf("请输入A/B:\n");
		rewind(stdin);
		scanf("%c", &input_char);

		if(input_char == 'A' || input_char == 'a')
			judgenum = A;
		else if (input_char == 'B' || input_char == 'b')
			judgenum = B;
		else
		{
			printf("退出测试！\n");
			return;
		}

		if(randnum < judgenum)
		{
			printf("%c=1\n", input_char);
		}
		else
		{
			printf("%c=0\n", input_char);
		}
	}
}

void teach()
{
	while(1)
	{
		int randnum = rand() % 2;
		int input_num;

		switch(randnum)
		{
			case 0:
			printf("A\n");
			break;

			case 1:
			printf("B\n");
		}

		scanf("%d", &input_num);
		switch(input_num)
		{
			case 0:
			if(randnum == 0)
				B++;
			else			
				A++;			
			break;

			case 1:
			if(randnum == 0)			
				A++;			
			else		
				B++;			
			break;

			default:
			printf("退出教学\n");
			return;
		}
	}
}