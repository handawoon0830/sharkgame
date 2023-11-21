#include <stdio.h>
#include <stdlib.h>

#define N_BOARD				15
#define BOARDSTATUS_OK		1
#define BOARDSTATUS_NOK		0

static int board_status[N_BOARD];
static int board_coin[N_BOARD];

static int board_shark_position;

int board_initBoard(void);
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
int board_getBoardCoin(int pos);
int board_getSharkPosition(void);
int board_stepShark(void);
int board_getBoardStatus(int pos);

