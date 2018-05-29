#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream> 
#include <queue> 
using namespace std;

struct QueueSet
{
	int value; //�Է� ��
	int index; //�Էµ� ���� ��
};

struct minOperator //Min���� ���ϱ� ���� ����
{
	bool operator()(QueueSet l, QueueSet r)
	{
		return l.value > r.value;
	}
};

struct maxOperator//Max���� ���ϱ� ���� ����
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
	char input[2]; //�Է� �����̸�
	int value; //�Է� ���갪
	int *sync; //pop���� �� �ΰ��� �켱���� ť�� ����ȭ�ϱ� ���� �迭
	scanf("%d", &T);

	MaxPriorityQueue* maxQueue = new MaxPriorityQueue[T]; //max �켱���� ť ����
	MinPriorityQueue* minQueue = new MinPriorityQueue[T]; //min �켱���� ť ����
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

			if (strcmp(input, "I") == 0) //�Է� ���� �ΰ��� ���� �־��ֱ�
			{
				maxQueue[i].push(qvalue);
				minQueue[i].push(qvalue);
			}
			else
			{
				if (value == -1 && !minQueue[i].empty()) //Min���� �����ϴ� ���
				{
					qvalue = minQueue[i].top(); //1.Min �켱���� ť���� ��Ʈ�� �ҷ�����
					minQueue[i].pop();	        //2.Min �켱���� ť���� ��Ʈ�� �����ϱ�
					sync[qvalue.index] = 1;     //3.�����Ǿ����� ǥ��
				}
				else if (value == 1 && !maxQueue[i].empty())
				{
					qvalue = maxQueue[i].top(); //1.Max �켱���� ť���� ��Ʈ�� �ҷ�����
					maxQueue[i].pop();	        //2.Max �켱���� ť���� ��Ʈ�� �����ϱ�
					sync[qvalue.index] = 1;     //3.�����Ǿ����� ǥ��
				}
			}

		    //����ȭ ���� 
			while (!minQueue[i].empty())
			{
				qvalue = minQueue[i].top();  //1.Min �켱���� ť���� ��Ʈ�� �ҷ�����
				if (sync[qvalue.index] == 1) //2.����ȭ �迭�� ���ؼ�, Max �켱����ť���� ���� �� ��찡 �ִ� ���, Min �켱���� ť������ ���� �ǽ�
					minQueue[i].pop();
				else
					break;
			}
			while (!maxQueue[i].empty())
			{
				qvalue = maxQueue[i].top();  //1.Max �켱���� ť���� ��Ʈ�� �ҷ�����
				if (sync[qvalue.index] == 1) //2.����ȭ �迭�� ���ؼ�, Min �켱����ť���� ���� �� ��찡 �ִ� ���, Max �켱���� ť������ ���� �ǽ�
					maxQueue[i].pop();
				else
					break;
			}
		}
	}

	//��� ���
	for (i = 0; i < T; i++)
	{
		if (maxQueue[i].empty() && minQueue[i].empty())
			printf("EMPTY\n");
		else
			printf("%d %d\n", maxQueue[i].top().value, minQueue[i].top().value);
			
	}
	return 0;
}