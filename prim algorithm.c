#include <stdio.h>
#include <stdbool.h>

#define INF 999
#define VTX 6 //vertex 수

typedef struct edge {
	int u;
	int v;
}EDGE;

char vData[] = { 'a','b','c','d','e','f' };

int graph[VTX][VTX] = {
		{0,3,INF,2,4,INF},
		{3,0,1,4,INF,2},
		{INF,1,0,INF,INF,1},
		{2,4,INF,0,5,7},
		{4,INF,INF,5,0,9},
		{INF,2,1,7,9,0}
};

//D[v]에서 최소인 점 찾기
//mst에 포함되지 않은 정점 중 mst와 거리가 최소인 정점 찾기 
int getMinVertex(bool visited[], int dist[])
{
	int minVtx=0;
	int minDist = INF;
	int v;
	for (v = 0; v < VTX; v++)
	{
		if (!visited[v] && dist[v] < minDist)
		{
			minDist = dist[v];
			minVtx = v;
		}
	}
	return minVtx;
}

EDGE* PrimMST(int start)
{
	int mst_cost=0;
	int r = start; //시작점
	int from[VTX]; //추가된 정점이 연결된 이전 정점(간선 정보)
	int D[VTX]; //mst에 있는 점 u와 v를 연결하는 간선의 최소 가중치를 저장
	bool visited[VTX]; //노드가 mst에 있으면 true, 아니면 false
	static EDGE mst[VTX];
	int vtxs = 1;
	int i;

	//배열 D 초기화
	for (i = 0; i < VTX; i++) 
	{
		D[i] = INF;
		from[i] = 0;
		visited[i] = false;
	}
	D[r] = 0;

	while (vtxs < VTX) 
	{
		int v;

		int minV = getMinVertex(visited, D); //mst에 속하지 않은 각 점들 v중 D[v]가 최소인 점 minV
		
		visited[minV] = true;
		mst_cost += D[minV];//가중치 합

		if (minV != r) //D에서 가중치 가장 작은 노드가 첫 시작 노드가 아니면
		{
			mst[vtxs].u = from[minV]; //mst에 간선 넣기
			mst[vtxs].v = minV;			//D배열에서 최소인 정점 mst에 추가
			vtxs++;
		}

		for (v = 0; v < VTX; v++) // D[v]배열 업데이트
		{
			if (graph[minV][v] > 0 && visited[v] == false)
				if (graph[minV][v] < D[v])
				{
					from[v] = minV;
					D[v] = graph[minV][v];
				}
		}
	}
	//mst 간선, 가중치 출력
	for (i = 1; i < VTX; i++)
		printf("(%c - %c)\n", vData[mst[i].u], vData[mst[i].v]);

	printf("mst 가중치: %d\n", mst_cost);

	return mst;
}

int main(void)
{
	printf("Prim MST\n");
	PrimMST(2); //c(2)에서 시작

	return 0;
}
