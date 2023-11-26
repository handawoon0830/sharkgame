#include <stdio.h>
#include <stdlib.h>

#define N_BOARD				15
#define BOARDSTATUS_OK		1
#define BOARDSTATUS_NOK		0

#define N_COINPOS 			12
#define MAX_COIN			4

#define N_PLAYER 			3

#define PLAYERSTATUS_LIVE	0
#define PLAYERSTATUS_DIE	1
#define PLAYERSTATUS_END	2

#define MAX_CHARNAME 		200

#define MAX_SHARKSTEP		6
#define SHARK_INITPOS		-4

static int player_position[N_PLAYER]; // 위치 
static char player_name[N_PLAYER][MAX_CHARNAME]; //이름 
static int player_coin[N_PLAYER]; //누적 코인 
static int player_status[N_PLAYER]; //현재 상태 
static char player_statusString[3][MAX_CHARNAME] = {"LIVE","DIE","END"}; //상태설명 문자열 

static int board_status[N_BOARD];
static int board_coin[N_BOARD];

static int board_shark_position;

static int game_end(void);
static int getAlivePlayer(void);
static int getWinner(void);

void board_initBoard(void){
	int i;
	for (i=0; i<N_BOARD; i++)
	{
		board_status[i]=0;
		board_coin[i]=0;
	}
	
	srand((unsigned)time(NULL));
	
	for (i=0; i<N_COINPOS; i++)
	{
		int j;	
		do{
			
			j= 1+ rand()%N_BOARD;
			if (board_coin[j] != 0 ){
				board_coin[j] = 1+ rand()%N_COINPOS;
				break;
			}
		}
		while (board_coin[j] == 0);
	}
	
}
int board_printBoardStatus(void){
	int i;
	printf("----------------------------------- BOARD STATUS-------------------------------------\n");
	for (i=0; i<N_BOARD; i++)
	{
		printf("|");
		if (board_status[i] == BOARDSTATUS_NOK)
			printf("X");
		else
			printf("0");
			
	}
	printf("|\n");
	printf("--------------------------------------------------------------------------------------\n");
}
int board_getBoardCoin(int pos){
	int coin;
	coin = 0;
	
	if (board_coin[pos] != 0);
		coin += board_coin[pos];
		board_coin[pos] = 0;
	return coin;
}
int board_getSharkPosition(void);
int board_stepShark(void){
	int pos;
	pos = 1+ rand()%MAX_SHARKSTEP;
	int i;
	for (i=0; i<pos+1; i++)
	{
		board_status[i]= BOARDSTATUS_NOK;
	}
	shark_position += pos;
}
int board_getBoardStatus(int pos){
	/*
	if (board_coin[pos] != 0);
		coin += board_coin[pos];
		board_coin[pos] = 0;
	 } 
	 */
}

 void printPlayerPosition(int player)
 {
	int i;
	 	
	for(i=0; i<N_BOARD; i++)
	{
	 	printf("|");
	 		
	 	if (player_position[player] == i)
	 		printf("%c", player_name[player][i]);
	 	else
	 	{
	 		if (board_getBoardStatus(i) == BOARDSTATUS_NOK)
	 			printf("X");
	 		else
	 			printf(" ");
		}
		 printf("|\n");
	}
}

void printPlayerStatus(void)
{
	int i;
	printf("player status ---\n");
	for (i=0; i<N_PLAYER; i++)
	{
		printf("%s : pos %d, coin %d, status %s\n",player_name[i], player_position[i], player_coin[i], player_statusString[player_status[i]]);
		printPlayerPosition(i);
	}
}


int game_end(void)
{
	int i;
	int flag_end=1;
	
	for (i=0; i<N_PLAYER; i++)
	{
		if (player_status[i]== PLAYERSTATUS_LIVE)
		{
			flag_end=0;
			break;
		}
	}
	return flag_end;
}

int getAlivePlayer(void)
{
	int i;
	int cnt=0;
	for (i=0; i<N_PLAYER; i++)
	{
		if (player_status[i]== PLAYERSTATUS_END)
			cnt++;
	}
	return cnt;
}

int getWinner(void)
{
	int i;
	int winner=0;
	int max_coin =-1;
	for (i=0; i<N_PLAYER; i++){
		if (player_coin[i]> max_coin)
		{
			max_coin = player_coin[i];
			winner=i;
		}
	}
	return winner;
}
