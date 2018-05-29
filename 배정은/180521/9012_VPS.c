#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
	char stackArr[50];
	int topind;
}Stack;

void init(Stack* stack)
{
	stack->topind = -1;
}

void push(Stack* stack, char input)
{
	stack->topind++;
	stack->stackArr[stack->topind] = input;
}

int pop(Stack* stack)
{
	if (stack->topind == -1)
		return -1;
	else
	{
		int value = stack->stackArr[stack->topind];
		stack->topind--;
		return value;
	}
}

int main()
{
	Stack stack;
	init(&stack);

	char input[50];
	int n, i, j;
	int cnt = 0;
	int flag = 0;

	scanf("%d", &n);
	fgetc(stdin);

	for (i = 0; i < n; i++)
	{
		flag = 0;
		cnt = 0;
		init(&stack);

		scanf("%s", input);
		fgetc(stdin);

		while (input[cnt] != '\0')
			cnt++;

		for (j = 0; j < cnt; j++)
		{
			if (input[j] == '(')
			{
				push(&stack, input);
			}
			else if (input[j] == ')')
			{
				if (stack.topind == -1)
				{
					flag = 1;
					break;
				}
				else
					pop(&stack);
			}
			else
			{
				printf("error\n");
			}
		}
		if (stack.topind == -1 && flag == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}