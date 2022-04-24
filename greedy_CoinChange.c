#include <stdio.h>

//���� �Ž����� �ּ� ���� �� ���ϱ�
//�Է� : �Ž����� �׼�
//��� : �Ž����� �׼��� ���� �ּ� ���� ��
int coinChange(int change)
{
	int n500=0, n100=0, n50=0, n10=0, n1=0;
	while (change >= 500)
	{
		change = change - 500;
		n500++; //500��¥�� ���� ���� 1 ����
	}
	while (change >= 100)
	{
		change = change - 100;
		n100++; //100��¥�� ���� ���� 1 ����
	}
	while (change >= 50)
	{
		change = change - 50;
		n50++; //50��¥�� ���� ���� 1 ����
	}
	while (change >= 10)
	{
		change = change - 10;
		n10++; //10��¥�� ���� ���� 1 ����
	}
	while (change >= 1)
	{
		change = change - 1;
		n1++; //1��¥�� ���� ���� 1 ����
	}
	
	printf("500��: %d��\n100��: %d��\n50��: %d��\n10��: %d��\n1��: %d��\n", n500, n100, n50, n10, n1);
	return (n500 + n100 + n50 + n10 + n1); //�� ���� ���� ����
}

int main(void)
{
	int change;
	printf("�Ž����� �׼�: ");
	scanf("%d", &change);
	printf("\n���� ��: %d ��", coinChange(change));
}