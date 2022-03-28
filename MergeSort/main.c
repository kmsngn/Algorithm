#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 60000
int orgArr[MAX_SIZE]; //������ ������ �迭
int arr[MAX_SIZE]; //�� ���Ŀ��� ����� ����� �迭

void SelectionSort(int arr[], int n);
void MergeSort(int arr[], int left, int right);

void CopyArr() //������ ������ �迭�� ���Ŀ� ����� �迭�� ����
{
	int i;
	for (i = 0; i < MAX_SIZE; i++)
		arr[i] = orgArr[i];
}

int main(void)
{
	clock_t start, finish; //�ð� ������ ���� ����
	double duration;
	
	int myArr[8] = { 3,10,22,30,35,13,25,24 };

	printf("***Merge Sort�� �����ϱ�***\n");
	printf("���� ��: ");
	int i;
	for (i = 0; i < 8; i++)
		printf("%d ", myArr[i]);
	printf("\n");

	//arr�� ��ü ������ ����
	MergeSort(myArr,0,sizeof(myArr)/sizeof(int) -1);
	//���ĵ� �迭 ȭ�鿡 ���
	printf("���� ��: ");

	for (i = 0; i < 8; i++)
		printf("%d ", myArr[i]);

	printf("\n\n");

	/**********************************************************/
	//��������
	int j;
	srand((int)time(NULL));
	for (j = 0; j < MAX_SIZE; j++)
		orgArr[j] = (rand() % 100)+1; //1~100 ���� ���� ����

	printf("***SelectionSort �� MergeSort ��***\n\n");
	//Selection Sort
	CopyArr();
	start = clock();
	SelectionSort(arr, sizeof(arr) / sizeof(int));
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Selection Sort �ҿ�ð�: %f ��\n", duration);

	//Merge Sort
	CopyArr();
	start = clock();
	MergeSort(arr, 0, sizeof(arr)/sizeof(int) - 1);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Merge Sort �ҿ�ð�: %f ��\n", duration);

	return 0;
}