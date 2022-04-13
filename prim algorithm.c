#include <stdio.h>
#include <stdbool.h>

#define INF 999
#define VTX 6 //vertex ��

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

//D[v]���� �ּ��� �� ã��
//mst�� ���Ե��� ���� ���� �� mst�� �Ÿ��� �ּ��� ���� ã�� 
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
	int r = start; //������
	int from[VTX]; //�߰��� ������ ����� ���� ����(���� ����)
	int D[VTX]; //mst�� �ִ� �� u�� v�� �����ϴ� ������ �ּ� ����ġ�� ����
	bool visited[VTX]; //��尡 mst�� ������ true, �ƴϸ� false
	static EDGE mst[VTX];
	int vtxs = 1;
	int i;

	//�迭 D �ʱ�ȭ
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

		int minV = getMinVertex(visited, D); //mst�� ������ ���� �� ���� v�� D[v]�� �ּ��� �� minV
		
		visited[minV] = true;
		mst_cost += D[minV];//����ġ ��

		if (minV != r) //D���� ����ġ ���� ���� ��尡 ù ���� ��尡 �ƴϸ�
		{
			mst[vtxs].u = from[minV]; //mst�� ���� �ֱ�
			mst[vtxs].v = minV;			//D�迭���� �ּ��� ���� mst�� �߰�
			vtxs++;
		}

		for (v = 0; v < VTX; v++) // D[v]�迭 ������Ʈ
		{
			if (graph[minV][v] > 0 && visited[v] == false)
				if (graph[minV][v] < D[v])
				{
					from[v] = minV;
					D[v] = graph[minV][v];
				}
		}
	}
	//mst ����, ����ġ ���
	for (i = 1; i < VTX; i++)
		printf("(%c - %c)\n", vData[mst[i].u], vData[mst[i].v]);

	printf("mst ����ġ: %d\n", mst_cost);

	return mst;
}

int main(void)
{
	printf("Prim MST\n");
	PrimMST(2); //c(2)���� ����

	return 0;
}
