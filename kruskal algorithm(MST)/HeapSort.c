#include <stdio.h>
#include "Heap.h"

//Heap의 우선순위 비교
int PriComp(EDGE d1, EDGE d2)
{
	//각 엣지의 가중치로 비교
	return d2.w - d1.w; //오름차순 정렬
}

void HeapSort(EDGE arr[], int n, PriorityComp pc)
{
	Heap heap;
	int i;

	HeapInit(&heap, pc);

	// 정렬 대상을 가지고 힙을 구성
	for(i=0; i<n; i++)
		HInsert(&heap, arr[i]);

	// 순서대로 하나씩 꺼내서 정렬
	for(i=0; i<n; i++)
		arr[i] = HDelete(&heap);
}