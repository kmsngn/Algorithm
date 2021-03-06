#ifndef __HEAP_H__
#define __HEAP_H__

#define TRUE	1
#define FALSE	0

#define HEAP_LEN	100

typedef struct nodetype {
	char symbol; //노드의 문자
	int frequency; //노드의 빈도수
	struct nodetype* left;
	struct nodetype* right;
}NODE;

typedef NODE* HData;
typedef int PriorityComp(HData d1, HData d2);

typedef struct _heap
{
	PriorityComp * comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap * ph, PriorityComp pc);
int HIsEmpty(Heap * ph);

void HInsert(Heap * ph, HData data);
HData HDelete(Heap * ph);

#endif