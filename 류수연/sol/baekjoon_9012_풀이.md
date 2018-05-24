# baekjoon 9012 풀이

[문제설명](https://www.acmicpc.net/problem/9012)

최신: 180522

```c
#include <stdio.h>
#include <string.h>
#define M 51

int main(void) {
	int n; // 테스트 할 문장의 개수
	int count; // 괄호 체크용
	char testStr[M]; // 테스트 할 문장

	scanf("%d", &n); // 몇 개의 문장을 테스트 할건지 받아오기

	for (int i = 0; i < n; i++) {
		count = 0;

		scanf("%s", testStr); // 테스트 할 문장 받아오기
		if (strlen(testStr) < 2) // 테스트문장이 2글자 이상이어야 함
			continue;

		for (int j = 0; j < strlen(testStr); j++) {
			if (testStr[j] == '(') // 여는 괄호일땐 count 증가
				count++;
			else if (testStr[j] == ')' && count > 0) // 닫는 괄호일땐 count 감소
				count--;
			else if (testStr[j] == ')' && count <= 0) { // 닫는 괄호일땐 count 감소. 단, 여는 괄호 없이 시작하는 경우 조건에 부합하지 않으므로 바로 중단.
				count--;
				break; // count가 -1이 됨
			}
		}

		if (count == 0) { // 여는 괄호와 닫는 괄호의 갯수가 같은 경우 count는 0 -> VPS이므로 YES 출력
			printf("YES\n");
		}
		else { // 차이가 있는 경우 VPS가 아니므로 NO 출력
			printf("NO\n");
		}
	}
	return 0;
}
```

