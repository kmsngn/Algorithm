#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//과정 출력하기
void print_path(const char* s, const char* t, int** E) {
	int i = strlen(s);
	int j = strlen(t);
	printf("%s (을)를 %s (으)로 변경과정\n", s, t);
	while (i>0 || j>0) {
		if (s[i - 1] == t[j - 1]) {
			i--;
			j--;
		}
		else if (E[i][j] == E[i - 1][j-1]+1) {
			printf("%c 를 %c 로 대체\n", s[i - 1], t[j - 1]);
			i--;
			j--;
		}
		else if (E[i][j] == E[i - 1][j] + 1) {
			printf("%c 삭제\n", s[i - 1]);
			i--;
		}
		else if (E[i][j] == E[i][j - 1] + 1) {
			printf("%c 삽입\n", t[j - 1]);
			j--;
		}
	}
}

void print_array(int** arr, int row, int col) {
	printf("\nprint array E result\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
//최소값 구하기
int getMin(int a, int b, int c) {
	if (a <= b && a <= c) return a;
	else if (b <= a && b <= c) return b;
	else return c;
}

int editDistance(const char* s, const char* t) {
	int s_len = strlen(s);
	int t_len = strlen(t);
	int i, j;
	int result;
	
	// 이차원 배열 동적 할당
	int** E = (int**)malloc(sizeof(int*) * (s_len + 1)); //처음 공백 포함하여 +1해줌
	if (E == NULL) {
		printf("동적할당 실패\n");
		return -1;
	}
	for (i = 0; i < s_len + 1; i++) {
		E[i] = (int*)malloc(sizeof(int) * (t_len + 1));
		if (E[i] == NULL) {
			printf("동적할당 실패\n");
			return -1;
		}
	}

	for (i = 0; i <= s_len; i++) //0번 열 초기화
		E[i][0] = i;
	for (j = 0; j <= t_len; j++) //0번 행 초기화
		E[0][j] = j;

	for (i = 1; i <= s_len; i++) {
		for (j = 1; j <= t_len; j++) {
			//대각선 방향 연산 (E[i-1][j-1]+a)  Si=Ti 이면 a=0, 다르면 a=1
			//문자가 같으면 편집 연산 필요없음. 다르면 대체 연산 필요
			if (s[i - 1] == t[j - 1]) {
				E[i][j] = E[i - 1][j - 1];
			}
			else {
				E[i][j] = getMin(E[i][j - 1] + 1, E[i - 1][j] + 1, E[i - 1][j - 1] + 1);
			}

		}
	}
	result = E[s_len][t_len];
	print_array(E, s_len + 1, t_len + 1);
	printf("\n");
	print_path(s, t, E);

	//메모리 해제
	for (i = 0; i < s_len + 1; i++) {
		free(E[i]);
	}
	free(E);
	return result;
}

int main(void) {
	char s1[50];
	char s2[50];
	
	printf("문자열 1 입력: ");
	scanf("%s", s1);
	printf("문자열 2 입력: ");
	scanf("%s", s2);

	printf("\n편집 거리: %d\n",editDistance(s1, s2));

	return 0;
} 