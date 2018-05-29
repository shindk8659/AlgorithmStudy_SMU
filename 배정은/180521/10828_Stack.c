#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
	int stackArr[10000];
	int topind;
}Stack;

void init(Stack* stack)
{
	stack->topind = -1;
}

void push(Stack* stack, int n)
{
	stack->topind++;
	stack->stackArr[stack->topind] = n;
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

int size(Stack* stack)
{
	return stack->topind + 1;
}

int empty(Stack*stack)
{
	if (stack->topind == -1)
		return 1;
	else
		return 0;
}

int top(Stack* stack)
{
	if (stack->topind == -1)
		return -1;
	else
		return stack->stackArr[stack->topind];
}

void excuteStack(Stack* stack)
{
	char instruct[6];
	int input;
	scanf("%s", instruct);

	fgetc(stdin);
	if (strcmp(instruct, "push") == 0)
	{
		scanf("%d", &input);
		fgetc(stdin);
		push(stack, input);
	}
	else if (strcmp(instruct, "pop") == 0)
	{
		printf("%d\n", pop(stack));
	}
	else if (strcmp(instruct, "size") == 0)
	{
		printf("%d\n", size(stack));
	}
	else if (strcmp(instruct, "empty") == 0)
	{
		printf("%d\n", empty(stack));
	}
	else if (strcmp(instruct, "top") == 0)
	{
		printf("%d\n", top(stack));
	}
	else
	{
		printf("error\n");
	}

}

int main()
{
	Stack stack;
	init(&stack);

	int n, i;
	scanf("%d", &n);
	fgetc(stdin);
	for (i = 0; i < n; i++)
	{
		excuteStack(&stack);
	}
	return 0;
}