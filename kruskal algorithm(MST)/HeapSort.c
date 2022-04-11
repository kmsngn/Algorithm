#include <stdio.h>
#include "Heap.h"

//Heap�� �켱���� ��
int PriComp(EDGE d1, EDGE d2)
{
	//�� ������ ����ġ�� ��
	return d2.w - d1.w; //�������� ����
}

void HeapSort(EDGE arr[], int n, PriorityComp pc)
{
	Heap heap;
	int i;

	HeapInit(&heap, pc);

	// ���� ����� ������ ���� ����
	for(i=0; i<n; i++)
		HInsert(&heap, arr[i]);

	// ������� �ϳ��� ������ ����
	for(i=0; i<n; i++)
		arr[i] = HDelete(&heap);
}