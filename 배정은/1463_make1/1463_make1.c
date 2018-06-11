#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cnt[1000001] = { 0 };
//n일때 최소 연산 횟수, 0으로 초기화, 입력 범위가 1 ~ 10^6이니깐, 10^6+1만큼 할당


int makeone(int n)
{
	int temp;

	if (n == 1) return 0;
	if (cnt[n] > 0) return cnt[n]; //이미 구한 적이 있는지 체크

	//1 빼기
	cnt[n] = makeone(n - 1) + 1;

	//3 나누기
	if (n % 3 == 0)
	{
		temp = makeone(n / 3) + 1;
		if (cnt[n] > temp) cnt[n] = temp;
	}

	//2 나누기
	if (n % 2 == 0)
	{
		temp = makeone(n / 2) + 1;
		if (cnt[n] > temp) cnt[n] = temp;
	}

	//가장 작은 cnt[n]을 리턴시키기
	return cnt[n];
}


int main()
{
	int N; //입력받을 자연수 
	scanf("%d", &N);

	printf("%d\n", makeone(N));
	return 0;
}
