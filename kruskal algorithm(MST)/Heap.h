#ifndef __HEAP_H__
#define __HEAP_H__

#define TRUE	1
#define FALSE	0

/*** Heap�� ���� ****/
#define HEAP_LEN	100

typedef struct edge {
	int n1; //���1
	int n2;	//���2
	int w;	//�� ��� ���� ����ġ
}EDGE;

//Heap�� ����ϱ� ���� Heap�� ������ ���� EDGE�� ����
//typedef int HData;
typedef EDGE HData;

// d1�� �켱������ ���ٸ� 0���� ū ��
// d2�� �켱������ ���ٸ� 0���� ���� ��
// d1�� d2�� �켱������ ���ٸ� 0�� ��ȯ
typedef int PriorityComp(HData d1, HData d2);

typedef struct _heap
{
	PriorityComp * comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

/*** Heap ���� ����� ****/
void HeapInit(Heap * ph, PriorityComp pc);
int HIsEmpty(Heap * ph);

void HInsert(Heap * ph, HData data);
HData HDelete(Heap * ph);

#endif