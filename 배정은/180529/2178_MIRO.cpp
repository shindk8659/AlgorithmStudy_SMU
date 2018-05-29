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
	int x; //x좌표
	int y; //y좌표
	int length; //시작점으로 부터 이동한 거리
};

typedef queue<DataSet> MiroQueue;

int main()
{
	int i, j;
	int N, M;
	int location;
	int input;

	scanf("%d %d", &N, &M);
	int *miro = (int*)malloc(sizeof(int)*N*M); //미로에서의 길(1)과 벽(0)을 저장하는 배열
	int *visited = (int*)malloc(sizeof(int)*N*M); //미로에서 방문여부를 체크하는 배열
	memset(visited, 0, sizeof(int)*N*M);


	for (i = 0; i < N; i++) //주어진 미로 입력 받음
	{
		//scanf("%d", &input); //M=100까지 이므로 10^10을 입력 받는 경우 int형으로 입력 받을 수 없음(내가 틀렸던 부분)
		for (j = 0; j < M; j++)
		{
			location = i*M + j;
			scanf("%1d", &input); //숫자를 하나씩 입력받아야함
			miro[location] = input;
			//miro[index] = input / (int)(pow((double)10,(double)(M-j-1)));
			//input %= (int)(pow((double)10, (double)(M - j - 1)));
		}
	}

	MiroQueue Queue; //큐 생성
	DataSet past, cur; //이전 위치와 현재 위치 정보를 위한 구조체

	//x=0, y=0에서 초기화
	cur.x = 0;
	cur.y = 0;
	cur.length = 1;
	location = cur.y*M + cur.x;
	visited[location] = 1;

	Queue.push(cur);
	int cnt = 0;
	while (!Queue.empty()) //도착위치에 도달할 때까지 실행
	{
		past = Queue.front(); //가장 앞에 있는 데이터 가져오기
		Queue.pop();

		if (past.x == M - 1 && past.y == N - 1) //도착 지점에 도달하였을 때 탐색 중지
			break;

		//위 탐색
		cur.x = past.x;
		cur.y = past.y - 1;
		if (cur.y >= 0 && cur.x >= 0 && cur.y < N && cur.x < M) //범위를 벗어나는지 체크
		{
			location = cur.y*M + cur.x;
			if (miro[location] == 1 && visited[location] == 0) //미로배열과 방문여부배열 체크
			{
				cur.length = past.length + 1;
				Queue.push(cur);
				visited[location] = 1;
			}
		}

		//아래 탐색
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

		//오른쪽 탐색
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

		//왼쪽 탐색
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