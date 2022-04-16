#include <stdio.h>

#define VERTEX 10
#define INF 999
#define TRUE 1
#define FALSE 0

int distance[VERTEX]; //시작 정점으로부터 최단경로의 거리
int visited[VERTEX]; //방문한 정점

void printStatus(void) //진행상태 출력
{
	static int cnt = 1;
	int i;
	printf("%2d) ", cnt++);
	//visited 내용 출력
	printf(" visited: ");
	for (i = 0; i < VERTEX; i++)
		printf(" %3d ", visited[i]);
	printf("\n");
	//distance 내용 출력
	printf("    distance: ");
	for (i = 0; i < VERTEX; i++)
	{
		if (distance[i] == INF)
			printf("   - ");
		else
			printf(" %3d ", distance[i]);
	}
	printf("\n\n");
}
//현재 distance 배열에서 가장 작은 값을 가지는 노드를 반환
int getMinVertex(int dist[], int visited[])
{
	int minDist = INF;
	int minVtx = 0;
	int i;
	for (i = 0; i < VERTEX; i++)
	{
		if (dist[i] < minDist && !visited[i])
		{
			minDist = dist[i];
			minVtx = i;
		}
	}
	return minVtx;
}
void dijkstra(int graph[][VERTEX], int start)
{
	int i,u,w;
	int n = 0;
	
	//distance, visited 초기화
	for (i = 0; i < VERTEX; i++)
	{
		distance[i] = INF; //모든 거리를 INF
		visited[i] = FALSE; //모든 점 방문안함
	}
	distance[start] = 0; //시작점은 거리가 0

	while (n < VERTEX)
	{
		u = getMinVertex(distance, visited); // distance에서 가장 작은 값을 가져온다.
		visited[u] = TRUE; //거리가 가장 짧은 정점을 방문 
		
		for (w = 0; w < VERTEX; w++)
			if (!visited[w])//아직 선택(방문)되지 않은 점들 중
				//기존의 기준점에서 w까지의 거리보다   u까지의 최단 거리와 u에서 w의 거리를 합친 거리가 더 짧으면
				if (distance[u] + graph[u][w] < distance[w]) 
					distance[w] = distance[u] + graph[u][w]; //그 값으로 수정해줌
		n++;
		printStatus(); //현재 상태 출력
	}
}
int main(void)
{
	//서울, 천안, 원주, 강릉, 논산, 대전, 광주, 대구, 포항, 부산
	int graph[VERTEX][VERTEX] = {
		{0,12,15,INF,INF,INF,INF,INF,INF,INF},
		{12,0,INF,INF,4,10,INF,INF,INF,INF},
		{15,INF,0,21,INF,INF,INF,7,INF,INF},
		{INF,INF,21,0,INF,INF,INF,INF,25,INF},
		{INF,4,INF,INF,0,3,13,INF,INF,INF},
		{INF,10,INF,INF,3,0,INF,10,INF,INF},
		{INF,INF,INF,INF,13,INF,0,INF,INF,15},
		{INF,INF,7,INF,INF,10,INF,0,19,9},
		{INF,INF,INF,25,INF,INF,INF,19,0,5},
		{INF,INF,INF,INF,INF,INF,15,9,5,0}
	};
	printf("      VERTEX:  서울 천안 원주 강릉 논산 대전 광주 대구 포항 부산\n");
	dijkstra(graph, 0);

	return 0;
}