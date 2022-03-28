#include <stdio.h>

// 두 원소 교환 함수
void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

//세 숫자의 중앙값 찾기 (MedianQuickSort에서 사용)
int MedianOfThree(int arr[], int left, int right)
{
	//세 숫자를 정렬하고 중간값을 반환
	int s[3] = { left, (left)+right / 2, right }; //원래 배열의 인덱스를 값으로
	if (arr[s[0]] > arr[s[1]])
		Swap(s, 0, 1);
	if (arr[s[1]] > arr[s[2]])
		Swap(s, 1, 2);
	if (arr[s[0]] > arr[s[1]])
		Swap(s, 0, 1);  

	return s[1];
}

//pivot을 배열의 가장 왼쪽 값으로 선택한 퀵정렬
void QuickSort(int arr[], int left, int right) {
	if (left < right)
	{
		int pivot = arr[left]; // 가장 왼쪽 값을 pivot으로 선택
		int i = left + 1; // 피봇(가장 왼쪽 값) 다음 값
		int j = right; // 가장 오른쪽(마지막) 값

		//pivot을 기준으로 좌,우에 작고 큰 값을 나열한다
		//교차되지 않을 때가지 반복
		while (i <= j)
		{
			//피봇보다 큰 값 찾기
			while (pivot >= arr[i] && i<=right)
				i++;
			//피봇보다 작은 값 찾기
			while (pivot <= arr[j] && j>=(left+1))
				j--;
			//교차되지 않은 상태이면 두 원소 교환
			if (i <= j)
				Swap(arr, i, j);
		}
		Swap(arr, left, j);//pivot과 j의 값 교환
		//j는 옮겨진 pivot의 위치가 됨
		QuickSort(arr, left, j-1); // 피봇보다 작은 그룹 정렬
		QuickSort(arr, j+1, right); //피봇보다 큰 그룹 정렬
	}
}

//Median을 pivot으로 선택한 퀵정렬
void MedianQuickSort(int arr[], int left, int right) {
	if (left < right)
	{
		int mp = MedianOfThree(arr, left, right); //배열의 3 숫자 중앙값 찾기
		int pivot = arr[mp]; // 3 숫자 중앙값을 pivot으로
		int i = left + 1;
		int j = right;
		
		Swap(arr, left, mp); //선택한 pivot을 가장 왼쪽으로 이동

		/*****이하 위의 퀵 정렬과 동일*****/

		//pivot을 기준으로 좌,우에 작고 큰 값을 나열한다
		//교차되지 않을 때가지 반복
		while (i <= j)
		{
			//피봇보다 큰 값 찾기
			while (pivot >= arr[i] && i <= right)
				i++;
			//피봇보다 작은 값 찾기
			while (pivot <= arr[j] && j >= (left + 1))
				j--;
			//교차되지 않은 상태이면 두 원소 교환
			if (i <= j)
				Swap(arr, i, j);
		}
		Swap(arr, left, j);//pivot과 j의 값 교환
		//j는 옮겨진 pivot의 위치가 됨
		MedianQuickSort(arr, left, j - 1); // 피봇보다 작은 그룹 정렬
		MedianQuickSort(arr, j + 1, right); //피봇보다 큰 그룹 정렬
	}
}

void printArray(int arr[], int count) {
	int i;
	for (i = 0; i < count; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(void)
{
	int arr1[12] = {6, 3, 11, 9, 12, 2, 8, 15, 18, 10, 7, 14 };
	int arr2[9] = {31, 17, 42, 9, 1, 23, 18, 11, 26 };

	printf("***제일 왼쪽 값을 pivot으로 선택***\n");
	printf("정렬 전: ");
	printArray(arr1, sizeof(arr1) / sizeof(int));
	//퀵 정렬
	QuickSort(arr1, 0, sizeof(arr1) / sizeof(int) - 1);
	printf("정렬 후: ");
	printArray(arr1, sizeof(arr1) / sizeof(int));

	printf("\n***Median Of Three로 pivot 선택***\n");
	printf("정렬 전: ");
	printArray(arr2, sizeof(arr2) / sizeof(int));
	//퀵 정렬
	MedianQuickSort(arr2, 0, sizeof(arr2) / sizeof(int) - 1);
	printf("정렬 후: ");
	printArray(arr2, sizeof(arr2) / sizeof(int));

	return 0;
}