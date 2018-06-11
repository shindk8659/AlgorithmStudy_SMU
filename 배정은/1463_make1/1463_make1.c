#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cnt[1000001] = { 0 };
//n�϶� �ּ� ���� Ƚ��, 0���� �ʱ�ȭ, �Է� ������ 1 ~ 10^6�̴ϱ�, 10^6+1��ŭ �Ҵ�


int makeone(int n)
{
	int temp;

	if (n == 1) return 0;
	if (cnt[n] > 0) return cnt[n]; //�̹� ���� ���� �ִ��� üũ

	//1 ����
	cnt[n] = makeone(n - 1) + 1;

	//3 ������
	if (n % 3 == 0)
	{
		temp = makeone(n / 3) + 1;
		if (cnt[n] > temp) cnt[n] = temp;
	}

	//2 ������
	if (n % 2 == 0)
	{
		temp = makeone(n / 2) + 1;
		if (cnt[n] > temp) cnt[n] = temp;
	}

	//���� ���� cnt[n]�� ���Ͻ�Ű��
	return cnt[n];
}


int main()
{
	int N; //�Է¹��� �ڿ��� 
	scanf("%d", &N);

	printf("%d\n", makeone(N));
	return 0;
}
