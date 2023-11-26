#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"
#include "board.c"

#define MAX_DIE		6
#define PLAYERSTATUS_LIVE		0
#define PLAYERSTATUS_DIE		1
#define PLAYERSTATUS_END		2
 
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

void checkDie(void){
	int i;
	for(i=0; i<N_PLAYER; i++){
		if (board_status[player_position[i]] == BOARDSTATUS_NOK)
			player_status[i] == PLAYERSTATUS_DIE;
			printf("%s in pos %d has died!! (coin %d)\n", player_name[i], player_position[i], player_coin[i]);
	}
}
int main(int argc, char *argv[]) {
	srand((unsigned)time(NULL));
	//0. 오프닝 
	opening();
	//1. 초기화 2. 플레이어 이름 결정
	board_initBoard();
	
	int i;
	for (i=0; i<N_PLAYER; i++){
		player_position[i]=0;
		player_coin[i]=0;
		player_status[i] = PLAYERSTATUS_LIVE;
		printf("Player %d's name: ", i);
		scanf("%s", player_name[i]);
	} 
	
	//3. 반복문 돌리기(플레이어 턴을 도는)
	
	
	int turn=0;
	int flag_end;
	flag_end=0;
	int coinResult;
	coinResult = 0;
	
	do{
		board_printBoardStatus();
		
		//2-1. 플레이어 상태 출력
		printPlayerStatus();
		
		 //2-2. 주사위 던지기 
		 int dieResult;
		 int dum;
		 //int step= rolldie();
		 printf("%s turn!!", player_name[turn]);
		 printf("Press any key to roll a die!\n");
		 scanf("%d", &dum);
		 fflush(stdin);
		 dieResult = rolldie();
		 
		 //2-3. 이동
		//pos += step;
		player_position[turn] += dieResult;
		if (player_position[turn]>13)
		{
			printf("%s reached to the end!!!", player_name[turn]);
			player_status[turn]= PLAYERSTATUS_END;
		}
				
		printf("Die result : %d, %s moved to %d\n", dieResult, player_name[turn],player_position[turn]);
		
		 //2-4. 동전 줍기
		int pos= player_position[turn];
		board_getBoardCoin(pos);
		coinResult += board_getBoardCoin(pos);
		player_coin[turn]+= coinResult;
		if (board_coin[pos] != 0)
			printf("LUCKY! %s got %d coins!", player_name[turn], board_coin[pos]);
		
		
		//2-5. 다음턴
		int c;
		printf("press any key to continue: ");
		scanf("%d", &c);
		fflush(stdin);
		
		if (player_status[turn] != PLAYERSTATUS_END)
		{
			turn= (turn +1)%N_PLAYER;
			continue;
		}
		
		if (turn ==0)
		{
			board_stepShark();
			int shark_pos = board_stepShark();
			printf("Shark moved to %i\n", shark_pos);
			checkDie();
			
		}
		
		game_end();
		if (flag_end ==1)
		{
			getAlivePlayer();
			getWinner();
		}
	} while (flag_end == 0);
	  
	ending();
	return 0;
	
}
