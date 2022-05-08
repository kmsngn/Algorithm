#include <stdio.h>
#define VTX 5
#define INF 999

void floyd_warshall(int d[VTX][VTX])
{
	int i, j, k;
	//k�� �����ϴ� ��
	for (k = 0; k < VTX; k++){
		//i�� ��� ����
		for (i = 0; i < VTX; i++) {
			if (i == k) continue; //��� ������ ������ ������ ������ �������� ����
			//j�� ���� ����
			for (j = 0; j < VTX; j++) {
				//�����ؼ� ���� �Ÿ��� �� ª���� ����
				if ((j != k) && (j != i) && (d[i][k] + d[k][j] < d[i][j]))
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}
}
//d ���� ���
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