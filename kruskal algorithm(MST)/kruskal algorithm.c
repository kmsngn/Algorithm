#include <stdio.h>
#include "Heap.h"

#define MAX_VTXS 6 //��� ��

int PriComp(EDGE d1, EDGE d2);
void HeapSort(EDGE arr[], int n, PriorityComp pc);

int parent[MAX_VTXS];
static int edges; //�Է� �׷����� ���� ��

//mst ���
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
		//�� ��� �ڽ��� ������ ��ǥ(��Ʈ)�� �ȴ�.
		parent[i] = i;
	}
}

//find �Լ� : ��Ʈ��带 ã�� �Լ�
int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

//union �Լ� : ��ġ��. x�� ���� ���հ� y�� ���� ������ ��ģ��.
void unionFunc(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) return; //x�� y�� ��Ʈ�� ������ ���� �����̹Ƿ� ����
	parent[y] = x;//�ƴϸ� y�� �θ� x�� �ٲ��ش�
}

//heap ���
EDGE* KruskalMST1(EDGE graph[]) {
	int tree_edges = 0;
	int mst_cost = 0;
	static EDGE mst[MAX_VTXS - 1]; //mst�� ������ ���� ��ü ����� �� -1

	init_parent();

	//�׷����� ���� ���
	Heap heap;
	int i;
	HeapInit(&heap, PriComp);

	for (i = 0; i < edges; i++)
		HInsert(&heap, graph[i]);
	//heap sort���� heap ��Insert�ϰ� �ϳ��� delete�Ͽ� �����ϴ� ��� ���

	//���� �켱������ ���� ���� ��尡 ù��°�� ����
	//�켱������ ���� ����(����ġ�� ���� ����)��带 ����������
	//������ delete�ϸ� ��
	int k = 0;
	while (tree_edges < (MAX_VTXS - 1))
	{
		EDGE e = HDelete(&heap); //����ġ�� ���� ���� ���� ��������

		if (find(e.n1) != find(e.n2)) //��Ʈ��带 ã�� ��Ʈ�� �ٸ���(���� ������ �ϴϸ�)
		{
			unionFunc(e.n1, e.n2); //��ġ��
			mst[k++] = e; //mst�� edge �߰�
			mst_cost += e.w;
			tree_edges += 1;
		}
	}
	printf("�ּҽ���Ʈ�� : ");
	printMst(mst);
	printf("\n�ּҽ���Ʈ�� ����ġ : %d\n", mst_cost);

	return mst;
}

//heap sort ���
EDGE* KruskalMST2(EDGE graph[]) {
	int tree_edges = 0;
	int mst_cost = 0;
	int i = 0;
	int k = 0;
	static EDGE mst[MAX_VTXS - 1]; //mst�� ������ ���� ��ü ����� �� -1

	init_parent();

	//����ġ�� �������� �������� ����, heap sort�� ����
	HeapSort(graph, edges, PriComp);

	while (tree_edges < (MAX_VTXS - 1))
	{
		EDGE e = graph[i]; //����ġ�� ���� ���� ���� ��������

		if (find(e.n1) != find(e.n2)) //��Ʈ��带 ã�� ��Ʈ�� �ٸ���(���� ������ �ϴϸ�)
		{
			unionFunc(e.n1, e.n2); //��ġ��
			mst[k++] = e; //mst�� edge �߰�
			mst_cost += e.w;
			tree_edges += 1;
		}
		i++;
	}
	printf("�ּҽ���Ʈ�� : ");
	printMst(mst);
	printf("\n�ּҽ���Ʈ�� ����ġ : %d\n", mst_cost);

	return mst;
}

int main(void)
{
	//��� a=0, b=1, c=2, d=3, e=4, f=5
	//ù��°,�ι�° : vertex, ����°: weight
	EDGE graph[] = { {0,3,2},{0,4,4},{0,1,8},{1,2,1},{1,5,2},{1,3,4},{2,5,1},{3,4,3},{3,5,7},{4,5,9} };
	edges = sizeof(graph) / sizeof(graph[0]);

	//KruskalMST1(graph);
	KruskalMST2(graph);
	return 0;
}