#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int rolldie(void)
{
	return rand()%MAX_DIE +1;
}
void opening(void){
	printf("====================================\n");
	printf("             shark game             \n");
	printf("====================================\n");
}
void ending(void){
	printf("====================================\n");
	printf("          CONGRATULATION!!           \n");
	printf("====================================\n");
}

int main(int argc, char *argv[]) {
	srand((unsigned)time(NULL));
	//0. ������ 
	opening();
	//1. �ʱ�ȭ 2. �÷��̾� �̸� ����
	board_initboard();
	
	//3. �ݺ��� ������(�÷��̾� ���� ����)
	
	do{
		int step= rolldie();
		int coinResult;
		pos += step;
		print();
		coinResult = board_getBoardCoin(pos);
		
		printf("press any key to continue: ");
		scanf("%d", &c);
		fflush(stdin);
	}
	 //2-1. �÷��̾� ���� ���
	 
	 //2-2. �ֻ��� ������ 
	 
	 //2-3. �̵�
	 
	 //2-4. ���� �ݱ�
	 
	 //2-5. ������
	 
	 //2-6. if�̿� ����� ���� ���� (����: ��� �÷��̾ �ѹ��� ���� ����)
	 	//��� ����
	
	//3. ����(���� ���, ��� ��) 
	ending();
	return 0;
	
}
