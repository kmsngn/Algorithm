#include <stdio.h>
#define VTX 5
#define INF 999

void floyd_warshall(int d[VTX][VTX])
{
	int i, j, k;
	//k는 경유하는 점
	for (k = 0; k < VTX; k++){
		//i는 출발 지점
		for (i = 0; i < VTX; i++) {
			if (i == k) continue; //출발 지점과 경유할 지점이 같으면 수행하지 않음
			//j는 도착 지점
			for (j = 0; j < VTX; j++) {
				//경유해서 가는 거리가 더 짧으면 갱신
				if ((j != k) && (j != i) && (d[i][k] + d[k][j] < d[i][j]))
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}
}
//d 내용 출력
void print_distance(int d[VTX][VTX]) {
	int i,j;
	for (i = 0; i < VTX; i++) {
		for (j = 0; j < VTX; j++)
			printf("%d\t", d[i][j]);
		printf("\n");

	}
}
int main(void) {
	int D[VTX][VTX] = {
		{0,4,2,5,INF},
		{INF,0,1,INF,4},
		{1,3,0,1,2},
		{-2,INF,INF,0,2},
		{INF,-3,3,1,0}
	};
	floyd_warshall(D);
	print_distance(D);
	return 0;
}