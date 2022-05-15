#include <stdio.h>

#define INF 9999
#define MAX_SIZE 5

//행렬 곱 연산 순서 출력
void print_bracket(int i, int j, int bracket[][MAX_SIZE]) {
	//하위 표현식으로 나누다가 하나만 남았을 때
	if (i == j) {
		printf("A%d", i);
	}
	else {
		printf("(");
		//하위 표현식으로 나누어 재귀 호출
		//i에서 j까지 중 최적의 break point인 bracket[i][j] 와
		//bracket[i][j] 다음 값부터 j까지로 sub problem을 나누어 문제 해결
		print_bracket(i, bracket[i][j], bracket);
		print_bracket(bracket[i][j] + 1, j, bracket);
		printf(")");
	}
}
//Chained Matrix Multiplications
int matrixChain(int d[]) {
	int i,j,L,k;
	int C[MAX_SIZE][MAX_SIZE]; //곱셈 횟수 저장
	//연산 순서 출력을 위해
	int S[MAX_SIZE][MAX_SIZE]; // i에서 j까지 표현식의 최적의 break point를 저장
	int n = MAX_SIZE -1; //행렬 수

	//배열 초기화, 0번째 행, 렬은 사용 안함
	//행렬 1개(같은 행렬)에 대한 곱 결과는 0
	for (i = 1; i < MAX_SIZE; i++) { 
		C[i][i] = 0;
	}
	//L은 부분문제의 크기
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
	printf("연산 순서 : ");
	print_bracket(1, MAX_SIZE - 1, S);
	printf("\n");
	return C[1][n];
}

int main(void) {
	int dim[] = { 10,20,5,15,30 };
	printf("행렬 곱셈에 필요한 원소의 최소 곱셈 수: %d 번\n",matrixChain(dim));
	
	return 0;
}