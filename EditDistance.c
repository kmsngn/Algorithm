#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//���� ����ϱ�
void print_path(const char* s, const char* t, int** E) {
	int i = strlen(s);
	int j = strlen(t);
	printf("%s (��)�� %s (��)�� �������\n", s, t);
	while (i>0 || j>0) {
		if (s[i - 1] == t[j - 1]) {
			i--;
			j--;
		}
		else if (E[i][j] == E[i - 1][j-1]+1) {
			printf("%c �� %c �� ��ü\n", s[i - 1], t[j - 1]);
			i--;
			j--;
		}
		else if (E[i][j] == E[i - 1][j] + 1) {
			printf("%c ����\n", s[i - 1]);
			i--;
		}
		else if (E[i][j] == E[i][j - 1] + 1) {
			printf("%c ����\n", t[j - 1]);
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
//�ּҰ� ���ϱ�
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
	
	// ������ �迭 ���� �Ҵ�
	int** E = (int**)malloc(sizeof(int*) * (s_len + 1)); //ó�� ���� �����Ͽ� +1����
	if (E == NULL) {
		printf("�����Ҵ� ����\n");
		return -1;
	}
	for (i = 0; i < s_len + 1; i++) {
		E[i] = (int*)malloc(sizeof(int) * (t_len + 1));
		if (E[i] == NULL) {
			printf("�����Ҵ� ����\n");
			return -1;
		}
	}

	for (i = 0; i <= s_len; i++) //0�� �� �ʱ�ȭ
		E[i][0] = i;
	for (j = 0; j <= t_len; j++) //0�� �� �ʱ�ȭ
		E[0][j] = j;

	for (i = 1; i <= s_len; i++) {
		for (j = 1; j <= t_len; j++) {
			//�밢�� ���� ���� (E[i-1][j-1]+a)  Si=Ti �̸� a=0, �ٸ��� a=1
			//���ڰ� ������ ���� ���� �ʿ����. �ٸ��� ��ü ���� �ʿ�
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

	//�޸� ����
	for (i = 0; i < s_len + 1; i++) {
		free(E[i]);
	}
	free(E);
	return result;
}

int main(void) {
	char s1[50];
	char s2[50];
	
	printf("���ڿ� 1 �Է�: ");
	scanf("%s", s1);
	printf("���ڿ� 2 �Է�: ");
	scanf("%s", s2);

	printf("\n���� �Ÿ�: %d\n",editDistance(s1, s2));

	return 0;
} 