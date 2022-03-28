#include <stdlib.h>

//정렬된 두 영역을 하나로 묶기 위한 함수
void Merge(int arr[], int left, int mid, int right) {
	int lidx = left;	//병합할 앞쪽 영역의 첫 번째 위치
	int ridx = mid + 1; //병합할 뒤쪽 영역의 첫 번째 위치
	int i;

	//병합한 결과를 담기 위한 배열 동적 할당
	int* sortArr = (int*)malloc(sizeof(int) * (right + 1));
	int sidx = left;


	while (lidx <= mid && ridx <= right)
	{
		//두 영역의 데이터를 비교하여
		//sortArr에 하나씩 담는다
		if (arr[lidx] <= arr[ridx])
			sortArr[sidx++] = arr[lidx++];
		else
			sortArr[sidx++] = arr[ridx++];
	}
	if (lidx > mid) // 앞부분이 모두 옮겨졌으면
	{
		//뒷부분의 남은 데이터를 모두 sortArr에 옮긴다
		for (i = ridx; i <= right; i++, sidx++)
			sortArr[sidx] = arr[i];
	}
	else //뒷부분이 모두 옮겨졌으면
	{
		//앞부분의 남은 데이터를 모두 sortArr에 옮긴다
		for (i = lidx; i <= mid; i++, sidx++) {
			sortArr[sidx] = arr[i];
		}
	}
	//임시 배열을 arr로 복사
	for (i = left; i <= right; i++)
		arr[i] = sortArr[i];

	free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
	int mid;

	if (left < right) //배열의 원소의 수가 2개 이상이면
	{
		mid = (left + right) / 2; //중간지점
		MergeSort(arr, left, mid); //앞부분 재귀 호출
		MergeSort(arr, mid + 1, right); //뒷부분 재귀 호출

		//정렬된 두 부분을 병합
		Merge(arr, left, mid, right);
	}
}