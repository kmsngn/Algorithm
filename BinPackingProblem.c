#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int firstFit(int item[], int capacity, int n) {
	int result = 0; //�ʿ��� ���� ��
	int i;
	//���� ���� ���� ����
	int* remain = (int*)malloc(sizeof(int) * n);
	//�� �뿡 ����� item �� ����
	int* itemCount = (int*)malloc(sizeof(int) * n);
	memset(itemCount, 0, sizeof(int) * n); //0���� �ʱ�ȭ

	printf("***First Fit***\n");
	for (i = 0; i < n; i++) {
		//������ �� �߿� �������� ���� �� �ִ� ù���� �� ã��
		int j;
		for (j = 0; j < result; j++) {
			if (remain[j] >= item[i]) {//���� ���� ������ item���� ���ų� ũ��
				remain[j] = remain[j] - item[i]; //���� �������� item ũ�⸸ŭ ����(item ���)
				itemCount[j]++;
				printf("bin '%d'�� item '%d' �ֱ�\n", j,item[i]);
				break;
			} 
				
		}
		//�������� ���� �� �ִ� ���� ������
		//�� �뿡 item �ִ´�.
		if (j == result) {
			remain[result] = capacity - item[i];
			printf("bin '%d'�� item '%d' �ֱ�\n", result, item[i]);
			itemCount[result]++;
			result++;
		}
	}
	printf("\n");
	//�� ���� ������ �� ���
	for (i = 0; i < result; i++) {
		printf("bin '%d' : %d ��\n", i, itemCount[i]);
	}
	printf("\n");
	free(remain);
	free(itemCount);
	return result;
}

int bestFit(int item[], int capacity, int n) {
	int result = 0; //�ʿ��� ���� ��
	int i;
	//���� ���� ���� ����
	int* remain = (int*)malloc(sizeof(int) * n);
	//�� �뿡 ����� item �� ����
	int* itemCount = (int*)malloc(sizeof(int) * n);
	memset(itemCount, 0, sizeof(int) * n); //0���� �ʱ�ȭ

	printf("\n***Best Fit***\n");
	for (i = 0; i < n; i++) {
		//������ �� �߿� �������� ���� �� �ִ� best �� ã��
		int j;
		//���� �ּ� ���� min
		int min = capacity + 1;
		//best ���� idex
		int bIdx = 0;
		for (j = 0; j < result; j++) {
			if (remain[j] >= item[i] && (remain[j] - item[i] < min)) {
				bIdx = j;
				min = remain[j] - item[i];
			}
		}
		//�������� ���� �� �ִ� ���� ������
		//�� �뿡 item �ִ´�.
		if (min == capacity + 1) {
			remain[result] = capacity - item[i];
			itemCount[result]++;
			printf("bin '%d'�� item '%d' �ֱ�\n", result, item[i]);
			result++;
		}
		else {
			remain[bIdx] -= item[i];
			itemCount[bIdx]++;
			printf("bin '%d'�� item '%d' �ֱ�\n", bIdx, item[i]);
		}
	}
	printf("\n");
	//�� ���� ������ �� ���
	for (i = 0; i < result; i++) {
		printf("bin '%d' : %d ��\n", i, itemCount[i]);
	}
	printf("\n");
	free(remain);
	free(itemCount);
	return result;
}

int main(void) {

	int item[] = { 7, 5, 6, 4, 2, 3, 7, 5 };
	int capacity = 10;
	int n = sizeof(item) / sizeof(capacity);
	printf("First Fit���� �ʿ��� ���� ��: %d\n", firstFit(item, capacity, n));
	printf("Best Fit���� �ʿ��� ���� ��: %d\n", bestFit(item, capacity, n));
	return 0;
}