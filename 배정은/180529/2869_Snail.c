#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int A, B, V; //A:�� B:�� V:����
	int value=0;
	int step;
	int day;
	int i;

	scanf("%d %d %d", &A, &B, &V);
	step = A - B; //�Ϸ翡 �ö󰡴� ����� ��
	day = V / step - A; //���� ����� ���� day�� ����

	for (i = day; i <= 10000000000; i++)
	{
		if (value >= V)
			break;
		value = step*i + A; //���� ��ġ
	}
	printf("%d\n", i);
	return 0;
}