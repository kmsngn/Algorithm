void SelectionSort(int arr[], int n)
{
	int i, j, minIdx, tmp;
	
	for (i = 0; i < n - 1; i++) //�պκ��� ���ĵǸ� �������� �ڵ����� ���ĵǱ� ������ n-1 �� �ݺ�
	{	//�ּҰ� ã��
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