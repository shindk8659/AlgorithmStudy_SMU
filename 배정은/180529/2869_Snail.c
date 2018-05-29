#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int A, B, V; //A:낮 B:밤 V:높이
	int value=0;
	int step;
	int day;
	int i;

	scanf("%d %d %d", &A, &B, &V);
	step = A - B; //하루에 올라가는 계단의 수
	day = V / step - A; //빠른 계산을 위한 day값 세팅

	for (i = day; i <= 10000000000; i++)
	{
		if (value >= V)
			break;
		value = step*i + A; //현재 위치
	}
	printf("%d\n", i);
	return 0;
}