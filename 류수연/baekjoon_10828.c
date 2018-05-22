#include <stdio.h>
#include <string.h>

#define M 10000

void push(int* stack, int n, int* top) {
	int idx = *top;
	if (idx == M - 1) {
		printf("stack is full\n");
	}
	else {
		stack[idx] = n;
		*top = idx + 1;
	}
}

int pop(int* stack, int* top) {
	int idx = *top;
	if (idx - 1 <= 0) {
		return 0;
	}
	else {
		return stack[idx - 1];
		*top = idx - 1;
	}
}

int empty(int* top) {
	if (*top < 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int stackTop(int* stack, int* top) {
	int idx = *top;
	if (idx <= 0) {
		return 0;
	}
	else {
		return stack[idx - 1];
	}
}
/*
int main(void) {
	int N;
	int n;
	int idx = 0;
	char command[15];
	int stack[M];

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", command);

		if (strcmp(command, "push") == 0) {
			if (idx > M) {
				printf("%d\n", -1);
			}
			scanf("%d", &n);
			stack[idx] = n;
			idx++;
		}
		else if (strcmp(command, "pop") == 0) {
			if (idx - 1 < 0)
				printf("%d\n", -1);
			else {
				n = stack[idx - 1];
				idx--;
				printf("%d\n", n);
			}
		}
		else if (strcmp(command, "size") == 0) {
			printf("%d\n", idx);
		}
		else if (strcmp(command, "empty") == 0) {
			if (idx - 1 < 0) {
				printf("%d\n", 1);
			}
			else printf("%d\n", 0);
		}
		else if (strcmp(command, "top") == 0) {
			if (idx - 1 < 0)
				printf("%d\n", -1);
			else {
				n = stack[idx - 1];
				printf("%d\n", n);
			}
		}
		else {
			printf("Error\n");
		}
	}
	
	return 0;
}

*/
/*
if (strcmp(command, "push") == 0) {
scanf("%d", &n);
push(stack, n, &idx);
printf("%d\n", stack[idx - 1]);
}
else if (strcmp(command, "pop") == 0) {
printf("%d\n", pop(stack, &idx));
}
else if (strcmp(command, "size") == 0) {
printf("%d\n", idx);
}
else if (strcmp(command, "empty") == 0) {
printf("%d\n", empty(&idx));
}
else if (strcmp(command, "top") == 0) {
printf("%d\n", stackTop(stack, &idx));
}
else {
printf("Error\n");
}
*/