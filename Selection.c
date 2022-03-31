//Selection.c
#include <stdio.h>

// 두 원소 교환 함수
void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
	//quick sort의 pivot 선택 후 교환 과정과 동일
	int pivot = arr[left]; // 가장 왼쪽 값을 pivot으로 선택
	int i = left + 1; // 피봇(가장 왼쪽 값) 다음 값
	int j = right; // 가장 오른쪽(마지막) 값

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
	Swap(arr, left, j);//pivot과 j의 값 교환, j는 옮겨진 pivot의 위치가 됨
	return j;
}

int Selection(int arr[], int left, int right, int k)
{
	if ((1 <= k) && (k <= right - left + 1)) {
		int p = Partition(arr, left, right);
		int S = (p - 1) - left + 1; //Small group의 크기
		if (k <= S) Selection(arr, left, p - 1, k); //Small group에서 찾기
		else if (k == S + 1) return arr[p]; //pivot==k번째 작은 숫자
		else Selection(arr, p + 1, right, k - S - 1); //large group에서 찾기
	}
	else //실패
		return -1;
}

int main(void)
{
	int arr[] = { 6, 3, 11, 9, 12, 2, 8, 15, 18, 10, 7, 14 };
	int k; //k번째로 작은 숫자
	int i;

	printf("입력값 : "); //배열 내용 출력
	for (i = 0; i < sizeof(arr) / sizeof(int); i++)
		printf("%d ", arr[i]);
	printf("\n");

	printf("몇 번째 작은 수: ");
	scanf("%d", &k);
	printf("\n%d 번째로 작은 수: %d\n",k,Selection(arr,0, sizeof(arr)/sizeof(int)-1,k));
	return 0;
}