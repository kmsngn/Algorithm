#include <stdio.h>

// �� ���� ��ȯ �Լ�
void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

//�� ������ �߾Ӱ� ã�� (MedianQuickSort���� ���)
int MedianOfThree(int arr[], int left, int right)
{
	//�� ���ڸ� �����ϰ� �߰����� ��ȯ
	int s[3] = { left, (left)+right / 2, right }; //���� �迭�� �ε����� ������
	if (arr[s[0]] > arr[s[1]])
		Swap(s, 0, 1);
	if (arr[s[1]] > arr[s[2]])
		Swap(s, 1, 2);
	if (arr[s[0]] > arr[s[1]])
		Swap(s, 0, 1);  

	return s[1];
}

//pivot�� �迭�� ���� ���� ������ ������ ������
void QuickSort(int arr[], int left, int right) {
	if (left < right)
	{
		int pivot = arr[left]; // ���� ���� ���� pivot���� ����
		int i = left + 1; // �Ǻ�(���� ���� ��) ���� ��
		int j = right; // ���� ������(������) ��

		//pivot�� �������� ��,�쿡 �۰� ū ���� �����Ѵ�
		//�������� ���� ������ �ݺ�
		while (i <= j)
		{
			//�Ǻ����� ū �� ã��
			while (pivot >= arr[i] && i<=right)
				i++;
			//�Ǻ����� ���� �� ã��
			while (pivot <= arr[j] && j>=(left+1))
				j--;
			//�������� ���� �����̸� �� ���� ��ȯ
			if (i <= j)
				Swap(arr, i, j);
		}
		Swap(arr, left, j);//pivot�� j�� �� ��ȯ
		//j�� �Ű��� pivot�� ��ġ�� ��
		QuickSort(arr, left, j-1); // �Ǻ����� ���� �׷� ����
		QuickSort(arr, j+1, right); //�Ǻ����� ū �׷� ����
	}
}

//Median�� pivot���� ������ ������
void MedianQuickSort(int arr[], int left, int right) {
	if (left < right)
	{
		int mp = MedianOfThree(arr, left, right); //�迭�� 3 ���� �߾Ӱ� ã��
		int pivot = arr[mp]; // 3 ���� �߾Ӱ��� pivot����
		int i = left + 1;
		int j = right;
		
		Swap(arr, left, mp); //������ pivot�� ���� �������� �̵�

		/*****���� ���� �� ���İ� ����*****/

		//pivot�� �������� ��,�쿡 �۰� ū ���� �����Ѵ�
		//�������� ���� ������ �ݺ�
		while (i <= j)
		{
			//�Ǻ����� ū �� ã��
			while (pivot >= arr[i] && i <= right)
				i++;
			//�Ǻ����� ���� �� ã��
			while (pivot <= arr[j] && j >= (left + 1))
				j--;
			//�������� ���� �����̸� �� ���� ��ȯ
			if (i <= j)
				Swap(arr, i, j);
		}
		Swap(arr, left, j);//pivot�� j�� �� ��ȯ
		//j�� �Ű��� pivot�� ��ġ�� ��
		MedianQuickSort(arr, left, j - 1); // �Ǻ����� ���� �׷� ����
		MedianQuickSort(arr, j + 1, right); //�Ǻ����� ū �׷� ����
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

	printf("***���� ���� ���� pivot���� ����***\n");
	printf("���� ��: ");
	printArray(arr1, sizeof(arr1) / sizeof(int));
	//�� ����
	QuickSort(arr1, 0, sizeof(arr1) / sizeof(int) - 1);
	printf("���� ��: ");
	printArray(arr1, sizeof(arr1) / sizeof(int));

	printf("\n***Median Of Three�� pivot ����***\n");
	printf("���� ��: ");
	printArray(arr2, sizeof(arr2) / sizeof(int));
	//�� ����
	MedianQuickSort(arr2, 0, sizeof(arr2) / sizeof(int) - 1);
	printf("���� ��: ");
	printArray(arr2, sizeof(arr2) / sizeof(int));

	return 0;
}