#include <stdio.h>

//동전 거스름돈 최소 동전 수 구하기
//입력 : 거스름돈 액수
//출력 : 거스름돈 액수에 대한 최소 동전 수
int coinChange(int change)
{
	int n500=0, n100=0, n50=0, n10=0, n1=0;
	while (change >= 500)
	{
		change = change - 500;
		n500++; //500원짜리 동전 수를 1 증가
	}
	while (change >= 100)
	{
		change = change - 100;
		n100++; //100원짜리 동전 수를 1 증가
	}
	while (change >= 50)
	{
		change = change - 50;
		n50++; //50원짜리 동전 수를 1 증가
	}
	while (change >= 10)
	{
		change = change - 10;
		n10++; //10원짜리 동전 수를 1 증가
	}
	while (change >= 1)
	{
		change = change - 1;
		n1++; //1원짜리 동전 수를 1 증가
	}
	
	printf("500원: %d개\n100원: %d개\n50원: %d개\n10원: %d개\n1원: %d개\n", n500, n100, n50, n10, n1);
	return (n500 + n100 + n50 + n10 + n1); //총 동전 수를 리턴
}

int main(void)
{
	int change;
	printf("거스름돈 액수: ");
	scanf("%d", &change);
	printf("\n동전 수: %d 개", coinChange(change));
}