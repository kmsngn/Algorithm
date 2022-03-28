void SelectionSort(int arr[], int n)
{
	int i, j, minIdx, tmp;
	
	for (i = 0; i < n - 1; i++) //앞부분이 정렬되면 마지막은 자동으로 정렬되기 때문에 n-1 번 반복
	{	//최소값 찾기
		minIdx = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minIdx])
				minIdx = j;
		}
		//Swap
		tmp = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = tmp;
	}
}