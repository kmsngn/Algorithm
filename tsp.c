#include <stdio.h>
#define MAX_VTXS 6

/* <weighted graph>>
int g[VERTEX][VERTEX] = {
        {0, 3, INF, 2, 4, INF},
        {3, 0, 1, 4, INF, 2},
        {INF, 1, 0, INF, INF, 1},
        {2, 4, INF, 0, 5, 7},
        {4, INF, INF, 5, 0, 9},
        {INF, 2, 1, 7, 9, 0}
    };
*/

/*<MST>
mst = [[0, 3, 2],  # �ּ� ���� Ʈ���� �� ������ �� ���� ����ġ
       [0, 1, 3],  # (0,1)�� ����ġ 3
       [1, 2, 1],
       [2, 5, 1],
       [0, 4, 4]]
*/

//---mst �������----
int mst[MAX_VTXS][MAX_VTXS];

//�ʱ�ȭ
void init() {
    int i, j;
    for (i = 0; i < MAX_VTXS; i++)
        for (j = 0; j < MAX_VTXS; j++)
            mst[i][j] = 0;
}
// ���� �߰�
void insert_edge(int u, int v, int value) {
    mst[u][v] = value;
    mst[v][u] = value;
}

/*---- - DFS----*/
int visited[MAX_VTXS] ={0};
int path[MAX_VTXS + 1] = {0}; //��� ����. �� �湮 ��� �� + �������� ��� ��� �߰�
int p = 0;

void dfs(int v) {
    int w;
    visited[v] = 1;
    path[p++] = v; //�湮�� ��带 ���(path)�� �߰�
    for (w = 0; w < MAX_VTXS; w++) {
        if ((mst[v][w] != 0) && visited[w] == 0)
            dfs(w);
    }
}

int main(void) {
    /*MST���� ������ ���(0)���� ����Ͽ�
    * Ʈ���� ������ ���� ��� ��带 �湮
    * => DFS
    * dfs�� ������ ������ �湮 �� �������� ù ������ �ѹ� �� �߰�
    */
    int i;
    init(); //mst ������� �ʱ�ȭ
    // mst ���� �߰�
    insert_edge(0, 3, 2);
    insert_edge(0, 1, 3);
    insert_edge(1, 2, 1);
    insert_edge(2, 5, 1);
    insert_edge(0, 4, 4);

    // ��� 0 ���� ����
    dfs(0);//dfs�� ��� ��� �湮
    path[p] = 0; //���� �켱 Ž�� �Ϸ� �� �������� ù ����(0)�� �ѹ� �� �߰�

    //��� ���
    printf("Approximation Algorithm, Traveling Salesman Problem\n");
    printf("\n��� : ");
    for (i = 0; i < MAX_VTXS+1; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
	return 0;
}