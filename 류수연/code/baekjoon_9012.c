#include <stdio.h>
#include <string.h>
#define M 51

int main(void) {
	int n;
	int count; // 괄호 갯수 체크용
	char testStr[M];

	scanf("%d", &n); // 처음 숫자 받아오기

	for (int i = 0; i < n; i++) {
		count = 0;

		scanf("%s", testStr); // 테스트용 문자열 받아오기
		if (strlen(testStr) < 2)
			continue;

		for (int j = 0; j < strlen(testStr); j++) {
			if (testStr[j] == '(')
				count++;
			else if (testStr[j] == ')' && count > 0)
				count--;
			else if (testStr[j] == ')' && count <= 0) {
				count--;
				break;
			}
		}

		if (count == 0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}