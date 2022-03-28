#include <stdlib.h>

//���ĵ� �� ������ �ϳ��� ���� ���� �Լ�
void Merge(int arr[], int left, int mid, int right) {
	int lidx = left;	//������ ���� ������ ù ��° ��ġ
	int ridx = mid + 1; //������ ���� ������ ù ��° ��ġ
	int i;

	//������ ����� ��� ���� �迭 ���� �Ҵ�
	int* sortArr = (int*)malloc(sizeof(int) * (right + 1));
	int sidx = left;


	while (lidx <= mid && ridx <= right)
	{
		//�� ������ �����͸� ���Ͽ�
		//sortArr�� �ϳ��� ��´�
		if (arr[lidx] <= arr[ridx])
			sortArr[sidx++] = arr[lidx++];
		else
			sortArr[sidx++] = arr[ridx++];
	}
	if (lidx > mid) // �պκ��� ��� �Ű�������
	{
		//�޺κ��� ���� �����͸� ��� sortArr�� �ű��
		for (i = ridx; i <= right; i++, sidx++)
			sortArr[sidx] = arr[i];
	}
	else //�޺κ��� ��� �Ű�������
	{
		//�պκ��� ���� �����͸� ��� sortArr�� �ű��
		for (i = lidx; i <= mid; i++, sidx++) {
			sortArr[sidx] = arr[i];
		}
	}
	//�ӽ� �迭�� arr�� ����
	for (i = left; i <= right; i++)
		arr[i] = sortArr[i];

	free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
	int mid;

	if (left < right) //�迭�� ������ ���� 2�� �̻��̸�
	{
		mid = (left + right) / 2; //�߰�����
		MergeSort(arr, left, mid); //�պκ� ��� ȣ��
		MergeSort(arr, mid + 1, right); //�޺κ� ��� ȣ��

		//���ĵ� �� �κ��� ����
		Merge(arr, left, mid, right);
	}
}