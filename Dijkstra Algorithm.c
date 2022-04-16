#include <stdio.h>

#define VERTEX 10
#define INF 999
#define TRUE 1
#define FALSE 0

int distance[VERTEX]; //���� �������κ��� �ִܰ���� �Ÿ�
int visited[VERTEX]; //�湮�� ����

void printStatus(void) //������� ���
{
	static int cnt = 1;
	int i;
	printf("%2d) ", cnt++);
	//visited ���� ���
	printf(" visited: ");
	for (i = 0; i < VERTEX; i++)
		printf(" %3d ", visited[i]);
	printf("\n");
	//distance ���� ���
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
//���� distance �迭���� ���� ���� ���� ������ ��带 ��ȯ
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
	
	//distance, visited �ʱ�ȭ
	for (i = 0; i < VERTEX; i++)
	{
		distance[i] = INF; //��� �Ÿ��� INF
		visited[i] = FALSE; //��� �� �湮����
	}
	distance[start] = 0; //�������� �Ÿ��� 0

	while (n < VERTEX)
	{
		u = getMinVertex(distance, visited); // distance���� ���� ���� ���� �����´�.
		visited[u] = TRUE; //�Ÿ��� ���� ª�� ������ �湮 
		
		for (w = 0; w < VERTEX; w++)
			if (!visited[w])//���� ����(�湮)���� ���� ���� ��
				//������ ���������� w������ �Ÿ�����   u������ �ִ� �Ÿ��� u���� w�� �Ÿ��� ��ģ �Ÿ��� �� ª����
				if (distance[u] + graph[u][w] < distance[w]) 
					distance[w] = distance[u] + graph[u][w]; //�� ������ ��������
		n++;
		printStatus(); //���� ���� ���
	}
}
int main(void)
{
	//����, õ��, ����, ����, ���, ����, ����, �뱸, ����, �λ�
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
	printf("      VERTEX:  ���� õ�� ���� ���� ��� ���� ���� �뱸 ���� �λ�\n");
	dijkstra(graph, 0);

	return 0;
}