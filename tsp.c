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
mst = [[0, 3, 2],  # 최소 신장 트리의 각 간선의 끝 점과 가중치
       [0, 1, 3],  # (0,1)의 가중치 3
       [1, 2, 1],
       [2, 5, 1],
       [0, 4, 4]]
*/

//---mst 인접행렬----
int mst[MAX_VTXS][MAX_VTXS];

//초기화
void init() {
    int i, j;
    for (i = 0; i < MAX_VTXS; i++)
        for (j = 0; j < MAX_VTXS; j++)
            mst[i][j] = 0;
}
// 간선 추가
void insert_edge(int u, int v, int value) {
    mst[u][v] = value;
    mst[v][u] = value;
}

/*---- - DFS----*/
int visited[MAX_VTXS] ={0};
int path[MAX_VTXS + 1] = {0}; //경로 저장. 총 방문 노드 수 + 마지막에 출발 노드 추가
int p = 0;

void dfs(int v) {
    int w;
    visited[v] = 1;
    path[p++] = v; //방문한 노드를 경로(path)에 추가
    for (w = 0; w < MAX_VTXS; w++) {
        if ((mst[v][w] != 0) && visited[w] == 0)
            dfs(w);
    }
}

int main(void) {
    /*MST에서 임의의 노드(0)에서 출발하여
    * 트리의 간선을 따라서 모든 노드를 방문
    * => DFS
    * dfs로 마지막 노드까지 방문 후 마지막에 첫 정점을 한번 더 추가
    */
    int i;
    init(); //mst 인접행렬 초기화
    // mst 간선 추가
    insert_edge(0, 3, 2);
    insert_edge(0, 1, 3);
    insert_edge(1, 2, 1);
    insert_edge(2, 5, 1);
    insert_edge(0, 4, 4);

    // 노드 0 에서 시작
    dfs(0);//dfs로 모든 노드 방문
    path[p] = 0; //깊이 우선 탐색 완료 후 마지막에 첫 정점(0)을 한번 더 추가

    //경로 출력
    printf("Approximation Algorithm, Traveling Salesman Problem\n");
    printf("\n경로 : ");
    for (i = 0; i < MAX_VTXS+1; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
	return 0;
}