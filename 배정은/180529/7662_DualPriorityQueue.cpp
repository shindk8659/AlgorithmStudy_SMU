#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream> 
#include <queue> 
using namespace std;

struct QueueSet
{
	int value; //입력 값
	int index; //입력된 순서 값
};

struct minOperator //Min값을 구하기 위한 연산
{
	bool operator()(QueueSet l, QueueSet r)
	{
		return l.value > r.value;
	}
};

struct maxOperator//Max값을 구하기 위한 연산
{
	bool operator()(QueueSet l, QueueSet r)
	{
		return l.value < r.value;
	}
};

typedef priority_queue<QueueSet, vector<QueueSet>, maxOperator> MaxPriorityQueue;
typedef priority_queue<QueueSet, vector<QueueSet>, minOperator> MinPriorityQueue;

int main()
{
	int T, k;
	int i,j;
	char input[2]; //입력 연산이름
	int value; //입력 연산값
	int *sync; //pop연산 후 두개의 우선순위 큐를 동기화하기 위한 배열
	scanf("%d", &T);

	MaxPriorityQueue* maxQueue = new MaxPriorityQueue[T]; //max 우선순위 큐 생성
	MinPriorityQueue* minQueue = new MinPriorityQueue[T]; //min 우선순위 큐 생성
	QueueSet qvalue;

	for (i = 0; i < T; i++)
	{
		scanf("%d", &k);
		
		sync = (int*)malloc(sizeof(int)*k);
		memset(sync, 0, sizeof(int)*k);

		for (j = 0; j < k; j++)
		{

			scanf("%s", input);
			fgetc(stdin);
			scanf("%d", &value);
			fgetc(stdin);

			qvalue.index = j;
			qvalue.value = value;

			if (strcmp(input, "I") == 0) //입력 값을 두개의 힙에 넣어주기
			{
				maxQueue[i].push(qvalue);
				minQueue[i].push(qvalue);
			}
			else
			{
				if (value == -1 && !minQueue[i].empty()) //Min값을 삭제하는 경우
				{
					qvalue = minQueue[i].top(); //1.Min 우선순위 큐에서 루트값 불러오기
					minQueue[i].pop();	        //2.Min 우선순위 큐에서 루트값 삭제하기
					sync[qvalue.index] = 1;     //3.삭제되었음을 표시
				}
				else if (value == 1 && !maxQueue[i].empty())
				{
					qvalue = maxQueue[i].top(); //1.Max 우선순위 큐에서 루트값 불러오기
					maxQueue[i].pop();	        //2.Max 우선순위 큐에서 루트값 삭제하기
					sync[qvalue.index] = 1;     //3.삭제되었음을 표시
				}
			}

		    //동기화 과정 
			while (!minQueue[i].empty())
			{
				qvalue = minQueue[i].top();  //1.Min 우선순위 큐에서 루트값 불러오기
				if (sync[qvalue.index] == 1) //2.동기화 배열을 통해서, Max 우선순위큐에서 삭제 된 경우가 있는 경우, Min 우선순위 큐에서도 삭제 실시
					minQueue[i].pop();
				else
					break;
			}
			while (!maxQueue[i].empty())
			{
				qvalue = maxQueue[i].top();  //1.Max 우선순위 큐에서 루트값 불러오기
				if (sync[qvalue.index] == 1) //2.동기화 배열을 통해서, Min 우선순위큐에서 삭제 된 경우가 있는 경우, Max 우선순위 큐에서도 삭제 실시
					maxQueue[i].pop();
				else
					break;
			}
		}
	}

	//결과 출력
	for (i = 0; i < T; i++)
	{
		if (maxQueue[i].empty() && minQueue[i].empty())
			printf("EMPTY\n");
		else
			printf("%d %d\n", maxQueue[i].top().value, minQueue[i].top().value);
			
	}
	return 0;
}