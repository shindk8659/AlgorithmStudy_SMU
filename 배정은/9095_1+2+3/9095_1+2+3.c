#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cnt[12] = { 0 }; // 0<=n<11, 메모를 위한 배열

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

		if (cnt[n - i] == 0) // 구한적이 없으면 계산
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
	plus(11); // n은 11보다 작다고 했으니 미리 한번에 구해놓기
	for (i = 0; i < T; i++)
	{
		scanf("%d", &n);
		printf("%d\n", cnt[n]);
	}
	return 0;
}