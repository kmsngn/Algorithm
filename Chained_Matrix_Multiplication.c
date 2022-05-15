#include <stdio.h>

#define INF 9999
#define MAX_SIZE 5

//��� �� ���� ���� ���
void print_bracket(int i, int j, int bracket[][MAX_SIZE]) {
	//���� ǥ�������� �����ٰ� �ϳ��� ������ ��
	if (i == j) {
		printf("A%d", i);
	}
	else {
		printf("(");
		//���� ǥ�������� ������ ��� ȣ��
		//i���� j���� �� ������ break point�� bracket[i][j] ��
		//bracket[i][j] ���� ������ j������ sub problem�� ������ ���� �ذ�
		print_bracket(i, bracket[i][j], bracket);
		print_bracket(bracket[i][j] + 1, j, bracket);
		printf(")");
	}
}
//Chained Matrix Multiplications
int matrixChain(int d[]) {
	int i,j,L,k;
	int C[MAX_SIZE][MAX_SIZE]; //���� Ƚ�� ����
	//���� ���� ����� ����
	int S[MAX_SIZE][MAX_SIZE]; // i���� j���� ǥ������ ������ break point�� ����
	int n = MAX_SIZE -1; //��� ��

	//�迭 �ʱ�ȭ, 0��° ��, ���� ��� ����
	//��� 1��(���� ���)�� ���� �� ����� 0
	for (i = 1; i < MAX_SIZE; i++) { 
		C[i][i] = 0;
	}
	//L�� �κй����� ũ��
	for (L = 1; L < n; L++) {
		for (i = 1; i <= n - L; i++) {
			j = i + L;
			C[i][j] = INF;
			for (k = i; k <= j - 1; k++) {
				int temp = C[i][k] + C[k + 1][j] + d[i - 1] * d[k] * d[j];
				if (temp < C[i][j]) {
					C[i][j] = temp;
					S[i][j] = k;
				}
			}
		}
	}
	printf("���� ���� : ");
	print_bracket(1, MAX_SIZE - 1, S);
	printf("\n");
	return C[1][n];
}

int main(void) {
	int dim[] = { 10,20,5,15,30 };
	printf("��� ������ �ʿ��� ������ �ּ� ���� ��: %d ��\n",matrixChain(dim));
	
	return 0;
}