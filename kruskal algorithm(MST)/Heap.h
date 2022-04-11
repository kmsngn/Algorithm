#ifndef __HEAP_H__
#define __HEAP_H__

#define TRUE	1
#define FALSE	0

/*** Heap의 정의 ****/
#define HEAP_LEN	100

typedef struct edge {
	int n1; //노드1
	int n2;	//노드2
	int w;	//두 노드 사이 가중치
}EDGE;

//Heap을 사용하기 위해 Heap의 데이터 형을 EDGE로 변경
//typedef int HData;
typedef EDGE HData;

// d1의 우선순위가 높다면 0보다 큰 값
// d2의 우선순위가 높다면 0보다 작은 값
// d1과 d2의 우선순위가 같다면 0을 반환
typedef int PriorityComp(HData d1, HData d2);

typedef struct _heap
{
	PriorityComp * comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

/*** Heap 관련 연산들 ****/
void HeapInit(Heap * ph, PriorityComp pc);
int HIsEmpty(Heap * ph);

void HInsert(Heap * ph, HData data);
HData HDelete(Heap * ph);

#endif