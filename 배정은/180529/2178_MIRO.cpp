#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <iostream> 
#include <queue> 
using namespace std;

struct DataSet
{
	int x; //x��ǥ
	int y; //y��ǥ
	int length; //���������� ���� �̵��� �Ÿ�
};

typedef queue<DataSet> MiroQueue;

int main()
{
	int i, j;
	int N, M;
	int location;
	int input;

	scanf("%d %d", &N, &M);
	int *miro = (int*)malloc(sizeof(int)*N*M); //�̷ο����� ��(1)�� ��(0)�� �����ϴ� �迭
	int *visited = (int*)malloc(sizeof(int)*N*M); //�̷ο��� �湮���θ� üũ�ϴ� �迭
	memset(visited, 0, sizeof(int)*N*M);


	for (i = 0; i < N; i++) //�־��� �̷� �Է� ����
	{
		//scanf("%d", &input); //M=100���� �̹Ƿ� 10^10�� �Է� �޴� ��� int������ �Է� ���� �� ����(���� Ʋ�ȴ� �κ�)
		for (j = 0; j < M; j++)
		{
			location = i*M + j;
			scanf("%1d", &input); //���ڸ� �ϳ��� �Է¹޾ƾ���
			miro[location] = input;
			//miro[index] = input / (int)(pow((double)10,(double)(M-j-1)));
			//input %= (int)(pow((double)10, (double)(M - j - 1)));
		}
	}

	MiroQueue Queue; //ť ����
	DataSet past, cur; //���� ��ġ�� ���� ��ġ ������ ���� ����ü

	//x=0, y=0���� �ʱ�ȭ
	cur.x = 0;
	cur.y = 0;
	cur.length = 1;
	location = cur.y*M + cur.x;
	visited[location] = 1;

	Queue.push(cur);
	int cnt = 0;
	while (!Queue.empty()) //������ġ�� ������ ������ ����
	{
		past = Queue.front(); //���� �տ� �ִ� ������ ��������
		Queue.pop();

		if (past.x == M - 1 && past.y == N - 1) //���� ������ �����Ͽ��� �� Ž�� ����
			break;

		//�� Ž��
		cur.x = past.x;
		cur.y = past.y - 1;
		if (cur.y >= 0 && cur.x >= 0 && cur.y < N && cur.x < M) //������ ������� üũ
		{
			location = cur.y*M + cur.x;
			if (miro[location] == 1 && visited[location] == 0) //�̷ι迭�� �湮���ι迭 üũ
			{
				cur.length = past.length + 1;
				Queue.push(cur);
				visited[location] = 1;
			}
		}

		//�Ʒ� Ž��
		cur.x = past.x;
		cur.y = past.y + 1;
		if (cur.y >= 0 && cur.x >= 0 && cur.y < N && cur.x < M)
		{
			location = cur.y*M + cur.x;
			if (miro[location] == 1 && visited[location] == 0)
			{
				cur.length = past.length + 1;
				Queue.push(cur);
				visited[location] = 1;
			}
			
		}

		//������ Ž��
		cur.x = past.x + 1;
		cur.y = past.y;
		if (cur.y >= 0 && cur.x >= 0 && cur.y < N && cur.x < M)
		{
			location = cur.y*M + cur.x;
			if (miro[location] == 1 && visited[location] == 0)
			{
				cur.length = past.length + 1;
				Queue.push(cur);
				visited[location] = 1;
			}
		}

		//���� Ž��
		cur.x = past.x - 1;
		cur.y = past.y;
		if (cur.y >= 0 && cur.x >= 0 && cur.y < N && cur.x < M)
		{
			location = cur.y*M + cur.x;
			if (miro[location] == 1 && visited[location] == 0)
			{
				cur.length = past.length + 1;
				Queue.push(cur);
				visited[location] = 1;
			}
		}	
	}

	printf("%d\n", past.length);

	free(miro);
	free(visited);
	return 0;
}