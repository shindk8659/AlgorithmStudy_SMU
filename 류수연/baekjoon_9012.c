#include <stdio.h>
#include <string.h>
#define M 51

int main(void) {
	int n;
	int count; // ��ȣ ���� üũ��
	char testStr[M];

	scanf("%d", &n); // ó�� ���� �޾ƿ���

	for (int i = 0; i < n; i++) {
		count = 0;

		scanf("%s", testStr); // �׽�Ʈ�� ���ڿ� �޾ƿ���
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