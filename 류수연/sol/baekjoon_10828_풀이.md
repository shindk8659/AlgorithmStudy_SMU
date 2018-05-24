# baekjoon_10828_풀이

[문제설명](https://www.acmicpc.net/problem/10828)

최신: 180522

```c
#include <stdio.h>
#include <string.h>

#define M 10000

int main(void) {
	int N; // 전체 명령어의 개수
	int n; // 스택에 있는 값
	int idx = 0; // 스택 인덱스. 넣을 자리를 가리키고 있음.
	char command[15]; // 명령어 받아올 문자열
	int stack[M]; // 스택

	scanf("%d", &N); // 명령어 개수 받아오기

	for (int i = 0; i < N; i++) { // 명령어는 N개
		scanf("%s", command); // 명령어 받아오기

        // push인 경우
		if (strcmp(command, "push") == 0) {
			if (idx > M) { // 인덱스 값이 스택의 범위를 넘으면
				printf("%d\n", -1); // push 불가능
			}
			scanf("%d", &n); // 스택에 넣을 값 받아옴
			stack[idx] = n; // idx자리에 push 하고
			idx++;		// 다음 인덱스를 가리킴
		}
        // pop인 경우
		else if (strcmp(command, "pop") == 0) {
			if (idx - 1 < 0) // idx가 가리키는 것이 스택의 처음이라면 스택은 비어 있다.
				printf("%d\n", -1); // pop 불가능
			else {
				n = stack[idx - 1]; // pop 수행. 이 때 idx는 top의 다음을 가리키고 있으므로 스택의 idx-1번째 값을 가져온다.
				idx--; // 스택의 원소가 줄었으므로 idx 감소
				printf("%d\n", n);
			}
		}
        // size인 경우
		else if (strcmp(command, "size") == 0) {
            // size는 스택에 들어있는 값의 개수
			printf("%d\n", idx); // 0 ~ idx -1 개가 있다
		}
        // empty인 경우
		else if (strcmp(command, "empty") == 0) {
			if (idx - 1 < 0) { // idx가 가리키는 것이 스택의 처음이라면 스택은 비어 있다. => 1 출력
				printf("%d\n", 1);
			}
			else printf("%d\n", 0);
		}
        // top인 경우
		else if (strcmp(command, "top") == 0) {
			if (idx - 1 < 0) // idx가 가리키는 것이 스택의 처음이라면 스택은 비어 있다.
				printf("%d\n", -1);
			else {
				n = stack[idx - 1];
				printf("%d\n", n);
                // pop과 동일하지만 단순히 top의 값을 보여주는 것이므로 idx를 감소시키지 않는다.
			}
		}
		else { // 그 외 명령어는 error처리한다.
			printf("Error\n");
		}
	}
	
	return 0;
}
```

