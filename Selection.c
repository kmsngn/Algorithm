//Selection.c
#include <stdio.h>

// �� ���� ��ȯ �Լ�
void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
	//quick sort�� pivot ���� �� ��ȯ ������ ����
	int pivot = arr[left]; // ���� ���� ���� pivot���� ����
	int i = left + 1; // �Ǻ�(���� ���� ��) ���� ��
	int j = right; // ���� ������(������) ��

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
	Swap(arr, left, j);//pivot�� j�� �� ��ȯ, j�� �Ű��� pivot�� ��ġ�� ��
	return j;
}

int Selection(int arr[], int left, int right, int k)
{
	if ((1 <= k) && (k <= right - left + 1)) {
		int p = Partition(arr, left, right);
		int S = (p - 1) - left + 1; //Small group�� ũ��
		if (k <= S) Selection(arr, left, p - 1, k); //Small group���� ã��
		else if (k == S + 1) return arr[p]; //pivot==k��° ���� ����
		else Selection(arr, p + 1, right, k - S - 1); //large group���� ã��
	}
	else //����
		return -1;
}

int main(void)
{
	int arr[] = { 6, 3, 11, 9, 12, 2, 8, 15, 18, 10, 7, 14 };
	int k; //k��°�� ���� ����
	int i;

	printf("�Է°� : "); //�迭 ���� ���
	for (i = 0; i < sizeof(arr) / sizeof(int); i++)
		printf("%d ", arr[i]);
	printf("\n");

	printf("�� ��° ���� ��: ");
	scanf("%d", &k);
	printf("\n%d ��°�� ���� ��: %d\n",k,Selection(arr,0, sizeof(arr)/sizeof(int)-1,k));
	return 0;
}