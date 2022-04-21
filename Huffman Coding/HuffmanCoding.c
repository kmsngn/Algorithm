#include <stdio.h>
#include <stdlib.h>
#include "PriorityQueue.h"

/*
typedef struct nodetype {
	char symbol; //노드의 문자
	int frequency; //노드의 빈도수
	struct nodetype* left;
	struct nodetype* right;
}NODE; 
*/

//min priority queue, 빈도수가 작은 것이 우선순위 높음
int DataPriorityComp(NODE ch1, NODE ch2)
{
	return ch2.frequency - ch1.frequency;
}

//노드 생성
NODE* make_node(NODE* left, NODE* right)
{
	NODE* node = (NODE*)malloc(sizeof(NODE));
	if (node == NULL)
	{
		printf("Memory Allocation Error\n");
		exit(1);
	}
	node->left = left;
	node->right = right;
	return node;
}
//트리 삭제
void delete_tree(NODE* root)
{
	if (root == NULL) return;
	delete_tree(root->left);
	delete_tree(root->right);
	free(root);
}
//배열 내용 출력
void printArray(int arr[], int t)
{
	int i;
	for (i = 0; i < t; i++)
		printf("%d", arr[i]);
	printf("\n");
}
//문자의 이진코드 출력하기
void printCodes(NODE* root, int code[], int t)
{
	//left로 가면 0, right로 가면 1 출력(배열에 저장)
	if (root->left != NULL)
	{
		code[t] = 0;
		printCodes(root->left, code, t + 1);
	}
	if (root->right != NULL)
	{
		code[t] = 1;
		printCodes(root->right, code, t + 1);
	}
	//단말노드 만난 경우 배열에 저장된 코드 출력
	if (root->left == NULL && root->right == NULL)
	{
		printf("%c(%d): ", root->symbol,root->frequency);
		printArray(code, t);
	}
}

NODE* huffmanCode(char ch[], int freq[], int n)
{
	PQueue pq; //우선순위 큐 생성 및 초기화
	PQueueInit(&pq, DataPriorityComp);
	NODE* node;
	NODE* root=NULL;
	int i;

	//문자들 노드로 만들고, 큐에 넣기
	for (i = 0; i < n; i++)
	{
		node = make_node(NULL, NULL); //노드 생성
		node->symbol = ch[i];
		node->frequency = freq[i];
		PEnqueue(&pq, node); //큐에 저장
	}
	printf("수행과정\n");
	while (pq.numOfData >= 2)
	{
		//빈도수가 가장 작은 노드 2개를 큐에서 제거
		NODE* node1 = PDequeue(&pq);
		NODE* node2 = PDequeue(&pq);
		//새 노드 생성 후, 꺼내온 노드 2개를 자식 노드로 만들기
		root = make_node(node1, node2);
		//새 노드의 빈도수 = 두 노드 빈도수 합
		root->frequency = node1->frequency + node2->frequency;
		printf("%d + %d -> %d\n", node1->frequency, node2->frequency, root->frequency);
		//새 노드를 큐에 삽입
		PEnqueue(&pq, root);
	}
	PDequeue(&pq);// 큐에 남은 노드 제거

	return root;
}
int main(void)
{
	char chList[] = { 'A', 'T', 'G', 'C' };
	int freq[] = { 450,90,120,270 };
	int arr[3]; // len = sizeof(freq) / sizeof(int) - 1;
	NODE* huffman = huffmanCode(chList, freq, 4);
	printf("\n문자: 코드\n");
	printCodes(huffman,arr,0);

	delete_tree(huffman);
	return 0;
}
