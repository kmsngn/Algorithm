#include <stdio.h>
#include <stdlib.h>
#include "PriorityQueue.h"

/*
typedef struct nodetype {
	char symbol; //����� ����
	int frequency; //����� �󵵼�
	struct nodetype* left;
	struct nodetype* right;
}NODE; 
*/

//min priority queue, �󵵼��� ���� ���� �켱���� ����
int DataPriorityComp(NODE ch1, NODE ch2)
{
	return ch2.frequency - ch1.frequency;
}

//��� ����
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
//Ʈ�� ����
void delete_tree(NODE* root)
{
	if (root == NULL) return;
	delete_tree(root->left);
	delete_tree(root->right);
	free(root);
}
//�迭 ���� ���
void printArray(int arr[], int t)
{
	int i;
	for (i = 0; i < t; i++)
		printf("%d", arr[i]);
	printf("\n");
}
//������ �����ڵ� ����ϱ�
void printCodes(NODE* root, int code[], int t)
{
	//left�� ���� 0, right�� ���� 1 ���(�迭�� ����)
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
	//�ܸ���� ���� ��� �迭�� ����� �ڵ� ���
	if (root->left == NULL && root->right == NULL)
	{
		printf("%c(%d): ", root->symbol,root->frequency);
		printArray(code, t);
	}
}

NODE* huffmanCode(char ch[], int freq[], int n)
{
	PQueue pq; //�켱���� ť ���� �� �ʱ�ȭ
	PQueueInit(&pq, DataPriorityComp);
	NODE* node;
	NODE* root=NULL;
	int i;

	//���ڵ� ���� �����, ť�� �ֱ�
	for (i = 0; i < n; i++)
	{
		node = make_node(NULL, NULL); //��� ����
		node->symbol = ch[i];
		node->frequency = freq[i];
		PEnqueue(&pq, node); //ť�� ����
	}
	printf("�������\n");
	while (pq.numOfData >= 2)
	{
		//�󵵼��� ���� ���� ��� 2���� ť���� ����
		NODE* node1 = PDequeue(&pq);
		NODE* node2 = PDequeue(&pq);
		//�� ��� ���� ��, ������ ��� 2���� �ڽ� ���� �����
		root = make_node(node1, node2);
		//�� ����� �󵵼� = �� ��� �󵵼� ��
		root->frequency = node1->frequency + node2->frequency;
		printf("%d + %d -> %d\n", node1->frequency, node2->frequency, root->frequency);
		//�� ��带 ť�� ����
		PEnqueue(&pq, root);
	}
	PDequeue(&pq);// ť�� ���� ��� ����

	return root;
}
int main(void)
{
	char chList[] = { 'A', 'T', 'G', 'C' };
	int freq[] = { 450,90,120,270 };
	int arr[3]; // len = sizeof(freq) / sizeof(int) - 1;
	NODE* huffman = huffmanCode(chList, freq, 4);
	printf("\n����: �ڵ�\n");
	printCodes(huffman,arr,0);

	delete_tree(huffman);
	return 0;
}
