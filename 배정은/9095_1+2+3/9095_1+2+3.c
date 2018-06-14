#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cnt[12] = { 0 }; // 0<=n<11, �޸� ���� �迭

int plus(int n)
{
	int i;
	int temp = 0;

	if (n == 1)
	{
		cnt[n] = 1;
		return cnt[n];
	}
	if (n == 2)
	{
		cnt[n] = 2;
		return cnt[n];
	}
	if (n == 3)
	{
		cnt[n] = 4;
		return cnt[n];
	}
	
	for (i = 1; i <= 3; i++)
	{

		if (n - i <= 0) break;

		if (cnt[n - i] == 0) // �������� ������ ���
			cnt[n - i] = plus(n - i);

		cnt[n] += cnt[n - i]; //c[n] = c[n-1]+c[n-2]+c[n-3]
	}
	return cnt[n];
}

int main()
{
	int i;
	int T, n;
	scanf("%d", &T);
	plus(11); // n�� 11���� �۴ٰ� ������ �̸� �ѹ��� ���س���
	for (i = 0; i < T; i++)
	{
		scanf("%d", &n);
		printf("%d\n", cnt[n]);
	}
	return 0;
}