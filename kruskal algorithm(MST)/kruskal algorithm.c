#include <stdio.h>
#include "Heap.h"

#define MAX_VTXS 6 //노드 수

int PriComp(EDGE d1, EDGE d2);
void HeapSort(EDGE arr[], int n, PriorityComp pc);

int parent[MAX_VTXS];
static int edges; //입력 그래프의 엣지 수

//mst 출력
void printMst(EDGE mst[])
{
	int i;
	char vData[] = { 'a','b','c','d','e','f' };//0, 1, 2, 3, 4, 5
	for (i = 0; i < MAX_VTXS - 1; i++)
	{
		printf("( %c  %c ) ", vData[mst[i].n1], vData[mst[i].n2]);
	}
}
void init_parent(void)
{
	int i;
	for (i = 0; i < MAX_VTXS; i++)
	{
		//각 노드 자신이 집합의 대표(루트)가 된다.
		parent[i] = i;
	}
}

//find 함수 : 루트노드를 찾는 함수
int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

//union 함수 : 합치기. x가 속한 집합과 y가 속합 집합을 합친다.
void unionFunc(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) return; //x와 y의 루트가 같으면 같은 집합이므로 종료
	parent[y] = x;//아니면 y의 부모를 x로 바꿔준다
}

//heap 사용
EDGE* KruskalMST1(EDGE graph[]) {
	int tree_edges = 0;
	int mst_cost = 0;
	static EDGE mst[MAX_VTXS - 1]; //mst의 간선의 수는 전체 노드의 수 -1

	init_parent();

	//그래프를 힙에 담기
	Heap heap;
	int i;
	HeapInit(&heap, PriComp);

	for (i = 0; i < edges; i++)
		HInsert(&heap, graph[i]);
	//heap sort에서 heap 에Insert하고 하나씩 delete하여 정렬하는 방법 사용

	//힙은 우선순위가 가장 높은 노드가 첫번째로 있음
	//우선순위가 가장 높은(가중치가 가장 작은)노드를 가져오려면
	//힙에서 delete하면 됨
	int k = 0;
	while (tree_edges < (MAX_VTXS - 1))
	{
		EDGE e = HDelete(&heap); //가중치가 가장 작은 간선 가져오기

		if (find(e.n1) != find(e.n2)) //루트노드를 찾고 루트가 다르면(같은 집합이 하니면)
		{
			unionFunc(e.n1, e.n2); //합치기
			mst[k++] = e; //mst에 edge 추가
			mst_cost += e.w;
			tree_edges += 1;
		}
	}
	printf("최소신장트리 : ");
	printMst(mst);
	printf("\n최소신장트리 가중치 : %d\n", mst_cost);

	return mst;
}

//heap sort 사용
EDGE* KruskalMST2(EDGE graph[]) {
	int tree_edges = 0;
	int mst_cost = 0;
	int i = 0;
	int k = 0;
	static EDGE mst[MAX_VTXS - 1]; //mst의 간선의 수는 전체 노드의 수 -1

	init_parent();

	//가중치를 기준으로 오름차순 정렬, heap sort로 정렬
	HeapSort(graph, edges, PriComp);

	while (tree_edges < (MAX_VTXS - 1))
	{
		EDGE e = graph[i]; //가중치가 가장 작은 간선 가져오기

		if (find(e.n1) != find(e.n2)) //루트노드를 찾고 루트가 다르면(같은 집합이 하니면)
		{
			unionFunc(e.n1, e.n2); //합치기
			mst[k++] = e; //mst에 edge 추가
			mst_cost += e.w;
			tree_edges += 1;
		}
		i++;
	}
	printf("최소신장트리 : ");
	printMst(mst);
	printf("\n최소신장트리 가중치 : %d\n", mst_cost);

	return mst;
}

int main(void)
{
	//노드 a=0, b=1, c=2, d=3, e=4, f=5
	//첫번째,두번째 : vertex, 세번째: weight
	EDGE graph[] = { {0,3,2},{0,4,4},{0,1,8},{1,2,1},{1,5,2},{1,3,4},{2,5,1},{3,4,3},{3,5,7},{4,5,9} };
	edges = sizeof(graph) / sizeof(graph[0]);

	//KruskalMST1(graph);
	KruskalMST2(graph);
	return 0;
}