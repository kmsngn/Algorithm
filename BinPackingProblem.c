#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int firstFit(int item[], int capacity, int n) {
	int result = 0; //필요한 통의 수
	int i;
	//통의 남은 공간 저장
	int* remain = (int*)malloc(sizeof(int) * n);
	//각 통에 저장된 item 수 저장
	int* itemCount = (int*)malloc(sizeof(int) * n);
	memset(itemCount, 0, sizeof(int) * n); //0으로 초기화

	printf("***First Fit***\n");
	for (i = 0; i < n; i++) {
		//기존의 통 중에 아이템을 담을 수 있는 첫번재 통 찾기
		int j;
		for (j = 0; j < result; j++) {
			if (remain[j] >= item[i]) {//통의 남은 공간이 item보다 같거나 크면
				remain[j] = remain[j] - item[i]; //남은 공간에서 item 크기만큼 빼기(item 담기)
				itemCount[j]++;
				printf("bin '%d'에 item '%d' 넣기\n", j,item[i]);
				break;
			} 
				
		}
		//아이템을 넣을 수 있는 통이 없으면
		//새 통에 item 넣는다.
		if (j == result) {
			remain[result] = capacity - item[i];
			printf("bin '%d'에 item '%d' 넣기\n", result, item[i]);
			itemCount[result]++;
			result++;
		}
	}
	printf("\n");
	//각 통의 아이템 수 출력
	for (i = 0; i < result; i++) {
		printf("bin '%d' : %d 개\n", i, itemCount[i]);
	}
	printf("\n");
	free(remain);
	free(itemCount);
	return result;
}

int bestFit(int item[], int capacity, int n) {
	int result = 0; //필요한 통의 수
	int i;
	//통의 남은 공간 저장
	int* remain = (int*)malloc(sizeof(int) * n);
	//각 통에 저장된 item 수 저장
	int* itemCount = (int*)malloc(sizeof(int) * n);
	memset(itemCount, 0, sizeof(int) * n); //0으로 초기화

	printf("\n***Best Fit***\n");
	for (i = 0; i < n; i++) {
		//기존의 통 중에 아이템을 담을 수 있는 best 통 찾기
		int j;
		//남은 최소 공간 min
		int min = capacity + 1;
		//best 통의 idex
		int bIdx = 0;
		for (j = 0; j < result; j++) {
			if (remain[j] >= item[i] && (remain[j] - item[i] < min)) {
				bIdx = j;
				min = remain[j] - item[i];
			}
		}
		//아이템을 넣을 수 있는 통이 없으면
		//새 통에 item 넣는다.
		if (min == capacity + 1) {
			remain[result] = capacity - item[i];
			itemCount[result]++;
			printf("bin '%d'에 item '%d' 넣기\n", result, item[i]);
			result++;
		}
		else {
			remain[bIdx] -= item[i];
			itemCount[bIdx]++;
			printf("bin '%d'에 item '%d' 넣기\n", bIdx, item[i]);
		}
	}
	printf("\n");
	//각 통의 아이템 수 출력
	for (i = 0; i < result; i++) {
		printf("bin '%d' : %d 개\n", i, itemCount[i]);
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
	printf("First Fit에서 필요한 통의 수: %d\n", firstFit(item, capacity, n));
	printf("Best Fit에서 필요한 통의 수: %d\n", bestFit(item, capacity, n));
	return 0;
}