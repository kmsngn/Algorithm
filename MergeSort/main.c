#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 60000
int orgArr[MAX_SIZE]; //난수를 저장할 배열
int arr[MAX_SIZE]; //각 정렬에서 사용할 복사된 배열

void SelectionSort(int arr[], int n);
void MergeSort(int arr[], int left, int right);

void CopyArr() //난수를 저장한 배열을 정렬에 사용할 배열에 복사
{
	int i;
	for (i = 0; i < MAX_SIZE; i++)
		arr[i] = orgArr[i];
}

int main(void)
{
	clock_t start, finish; //시간 측정을 위한 변수
	double duration;
	
	int myArr[8] = { 3,10,22,30,35,13,25,24 };

	printf("***Merge Sort로 정렬하기***\n");
	printf("정렬 전: ");
	int i;
	for (i = 0; i < 8; i++)
		printf("%d ", myArr[i]);
	printf("\n");

	//arr의 전체 영역을 정렬
	MergeSort(myArr,0,sizeof(myArr)/sizeof(int) -1);
	//정렬된 배열 화면에 출력
	printf("정렬 후: ");

	for (i = 0; i < 8; i++)
		printf("%d ", myArr[i]);

	printf("\n\n");

	/**********************************************************/
	//난수생성
	int j;
	srand((int)time(NULL));
	for (j = 0; j < MAX_SIZE; j++)
		orgArr[j] = (rand() % 100)+1; //1~100 사이 난수 생성

	printf("***SelectionSort 와 MergeSort 비교***\n\n");
	//Selection Sort
	CopyArr();
	start = clock();
	SelectionSort(arr, sizeof(arr) / sizeof(int));
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Selection Sort 소요시간: %f 초\n", duration);

	//Merge Sort
	CopyArr();
	start = clock();
	MergeSort(arr, 0, sizeof(arr)/sizeof(int) - 1);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Merge Sort 소요시간: %f 초\n", duration);

	return 0;
}