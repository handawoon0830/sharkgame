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
	//0. 오프닝 
	opening();
	//1. 초기화 2. 플레이어 이름 결정
	board_initboard();
	
	//3. 반복문 돌리기(플레이어 턴을 도는)
	
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
	 //2-1. 플레이어 상태 출력
	 
	 //2-2. 주사위 던지기 
	 
	 //2-3. 이동
	 
	 //2-4. 동전 줍기
	 
	 //2-5. 다음턴
	 
	 //2-6. if이용 상어의 동작 설정 (조건: 모든 플레이어가 한번씩 턴을 돈다)
	 	//상어 동작
	
	//3. 정리(승자 계상, 출력 등) 
	ending();
	return 0;
	
}
