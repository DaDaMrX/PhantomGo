#ifndef	_MAIN_CPP_
#define	_MAIN_CPP_

#include "Define.h"

char undo_board[GRID_NUM][GRID_NUM];
char undo_board_know[GRID_NUM][GRID_NUM];
SPlayer undo_player[3];	

int main()
{
	char	msg[100];
	int		numTi = 0;
	int		x,y;

	InitGame();

	while(1)
	{
		Sleep(50);
		fflush(stdin);
		Sleep(50);
		fflush(stdout);
		scanf("%s",msg);

		if (strcmp(msg,"quit") == 0)
		{
			//结束游戏
			break;
		}else if (strcmp(msg,"new") == 0)
		{
			//开始新棋局
			InitGame();
			scanf("%s",msg);
			if (strcmp(msg,"black") == 0)
			{
				chessColor = BLACK;
				SearchMove(&bestMove);
				printf("move %2d %2d\n",bestMove.x,bestMove.y);
			}else
			{
				chessColor = WHITE;
			}
		}else if (strcmp(msg,"black") == 0)
		{
			//读取黑子信息
			scanf("%s",msg);

			if (chessColor == BLACK)
			{
				//自己是黑子
				if (strcmp(msg,"moved") == 0)
				{
					//自己上次走的为合法招法
					record();
					player[BLACK].total++;
					board[bestMove.x][bestMove.y] = BLACK;
					clean(bestMove, WHITE, board);
					//player[WHITE].total = player[BLACK].total;
					//if (SearchMove(&bestMove))
					//{
					//	//产生招法成功，返回平台
					//	printf("move %d %d\n",bestMove.x,bestMove.y);
					//}

				}else if (strcmp(msg,"illegal") == 0)
				{
					//自己上次走的为非法招法
					player[BLACK].know++;
					board[bestMove.x][bestMove.y] = WHITE;
					board_know[bestMove.x][bestMove.y] ++;
					if (SearchMove(&bestMove))
					{
						//产生招法成功，返回平台
						printf("move %d %d\n",bestMove.x,bestMove.y);
					}else
					{
						//不成功，自己pass
						printf("passed\n");
					}

				}else if (strcmp(msg,"take") == 0)
				{
					SMove moveList[81] ;
					//自己提子,读取提子数目
					scanf("%d",&numTi);
					player[WHITE].total -= numTi;
					for(int i = 0 ; i < numTi ; i++)
					{

						Sleep(50);
						fflush(stdin);
						scanf("%d%d",&x,&y);
						moveList[i].x = x;
						moveList[i].y = y;
					}
					for(int i = 0 ; i < numTi ; i++)
					{
						board[moveList[i].x][moveList[i].y] = NOSTONE;
					}

				}else if (strcmp(msg,"passed") == 0)
				{
					//自己pass
					player[BLACK].know  = player[WHITE].total;
				}

			}else
			{
				//自己是白子
				if (strcmp(msg,"moved") == 0)
				{
					//对方上次走的为合法招法
					player[BLACK].total++;
					if (SearchMove(&bestMove))
					{
						//产生招法成功，返回平台
						printf("move %d %d\n",bestMove.x,bestMove.y);
					}else
					{
						//不成功，自己pass
						printf("passed\n");
					}

				}else if (strcmp(msg,"illegal") == 0)
				{
					//对方上次走的为非法招法
					player[BLACK].know++;

				}else if (strcmp(msg,"take") == 0)
				{
					//对方提子,读取提子数目
					SMove moveList[81] ;
					scanf("%d",&numTi);
					player[WHITE].total -= numTi;
					//读取自己所有被提的子
					for(int i = 0 ; i < numTi ; i++)
					{

						Sleep(50);
						fflush(stdin);

						scanf("%d%d",&x,&y);
						moveList[i].x = x;
						moveList[i].y = y;
						//对所提的子的边界进行探测，如果是空，肯定是对方的子
						if (board[x-1][y] == NOSTONE)
						{
							board[x-1][y] = BLACK;
							player[WHITE].know++;
						}
						if (board[x+1][y] == NOSTONE)
						{
							board[x+1][y] = BLACK;
							player[WHITE].know++;
						}
						if (board[x][y-1] == NOSTONE)
						{
							board[x][y-1] = BLACK;
							player[WHITE].know++;
						}
						if (board[x][y+1] == NOSTONE)
						{
							board[x][y+1] = BLACK;
							player[WHITE].know++;
						}
					}
					for(int i = 0 ; i < numTi ; i++)
					{
						board[moveList[i].x][moveList[i].y] = NOSTONE;
					}

				}else if (strcmp(msg,"passed") == 0)
				{
					//对方pass
					player[BLACK].know  = player[WHITE].total;
				}

			}
		}else if (strcmp(msg,"white") == 0)
		{
			//读取白子信息
			scanf("%s",msg);

			if (chessColor == WHITE)
			{
				//自己是白子
				if (strcmp(msg,"moved") == 0)
				{
					//自己上次走的为合法招法
					record();
					player[WHITE].total++;
					board[bestMove.x][bestMove.y] = WHITE;
					clean(bestMove, BLACK, board);
					//player[WHITE].total = player[BLACK].total - 1;
					//if (SearchMove(&bestMove))
					//{
					//	//产生招法成功，返回平台
					//	printf("move %d %d\n",bestMove.x,bestMove.y);
					//}

				}else if (strcmp(msg,"illegal") == 0)
				{
					//自己上次走的为非法招法
					player[WHITE].know++;
					board[bestMove.x][bestMove.y] = BLACK;
					board_know[bestMove.x][bestMove.y] ++;
					if (SearchMove(&bestMove))
					{
						//产生招法成功，返回平台
						printf("move %d %d\n",bestMove.x,bestMove.y);
					}else
					{
						//不成功，自己pass
						printf("passed\n");
					}

				}else if (strcmp(msg,"take") == 0)
				{
					SMove moveList[81] ;
					//自己提子,读取提子数目
					scanf("%d",&numTi);
					player[BLACK].total -= numTi;
					for(int i = 0 ; i < numTi ; i++)
					{

						Sleep(50);
						fflush(stdin);
						scanf("%d%d",&x,&y);
						moveList[i].x = x;
						moveList[i].y = y;
					}
					for(int i = 0 ; i < numTi ; i++)
					{
						board[moveList[i].x][moveList[i].y] = NOSTONE;
					}
					//自己知道的子也应该修正

				}else if (strcmp(msg,"passed") == 0)
				{
					//自己pass
					player[WHITE].know  = player[BLACK].total;
				}

			}else
			{
				//自己是黑子
				if (strcmp(msg,"moved") == 0)
				{
					//对方上次走的为合法招法
					player[WHITE].total++;
					if (SearchMove(&bestMove))
					{
						//产生招法成功，返回平台
						printf("move %d %d\n",bestMove.x,bestMove.y);
					}else
					{
						//不成功，自己pass
						printf("passed\n");
					}

				}else if (strcmp(msg,"illegal") == 0)
				{
					//对方上次走的为非法招法
					player[WHITE].know++;

				}else if (strcmp(msg,"take") == 0)
				{
					//对方提子,读取提子数目
					SMove moveList[81] ;
					scanf("%d",&numTi);
					player[BLACK].total -= numTi;
					//读取自己所有被提的子
					for(int i = 0 ; i < numTi ; i++)
					{

						Sleep(50);
						fflush(stdin);

						scanf("%d%d",&x,&y);
						moveList[i].x = x;
						moveList[i].y = y;
						//对所提的子的边界进行探测，如果是空，肯定是对方的子
						if (board[x-1][y] == NOSTONE)
						{
							board[x-1][y] = WHITE;
							player[BLACK].know++;
						}
						if (board[x+1][y] == NOSTONE)
						{
							board[x+1][y] = WHITE;
							player[BLACK].know++;
						}
						if (board[x][y-1] == NOSTONE)
						{
							board[x][y-1] = WHITE;
							player[BLACK].know++;
						}
						if (board[x][y+1] == NOSTONE)
						{
							board[x][y+1] = WHITE;
							player[BLACK].know++;
						}
					}
					for(int i = 0 ; i < numTi ; i++)
					{
						board[moveList[i].x][moveList[i].y] = NOSTONE;
					}


				}else if (strcmp(msg,"passed") == 0)
				{
					//对方pass
					player[WHITE].know  = player[BLACK].total;
				}

			}
		}else if (strcmp(msg,"result") == 0)
		{
			scanf("%s",msg);
			if (strcmp(msg,"win") == 0)
			{
				//自己胜
			}else
			{
				//自己负
			}
		}else if (strcmp(msg,"get") == 0)
		{
			printf("board ");
			for(int i = 1; i < 10 ; i++)
			{
				for(int j = 1 ; j < 10 ; j++)
				{
					printf("%d",board[i][j]);
				}
				//printf("\n");
			}
		}else if (strcmp(msg,"undo") == 0){
			Undo();
		}else
		{
			printf("Error Input!!!\n");
			PrintBoard();
		}
	}

	return 0;
}

void record()
{
	int i, j;
	for (i=1; i<10; i++){
		for (j=1; j<10; j++){
			undo_board[i][j] = board[i][j];
			undo_board_know[i][j] = board_know[i][j];
		}
	}
	for (i=0; i<3; i++){
		undo_player[i] = player[i];
	}
}

void Undo()
{
	int i, j;
	for (i=1; i<10; i++){
		for (j=1; j<10; j++){
			board[i][j] = undo_board[i][j];
			board_know[i][j] = undo_board_know[i][j];
		}
	}
	for (i=0; i<3; i++){
		player[i] = undo_player[i];
	}
}


void InitGame()
{
	memset(player, 0, sizeof(player));
	memset(board, 0, sizeof(board));
	memset(board_know, 0, sizeof(board_know));
	memset(&bestMove, 0, sizeof(bestMove));
//	memset(mark, 0, sizeof(mark));

	for (int i = 0 ; i < 11 ; i++)
	{
		board[i][0] = BORDER;
		board[0][i] = BORDER;
		board[i][10] = BORDER;
		board[10][i] = BORDER;
	}
};

void PrintBoard()
{
	printf("  ");
	for(int j = 1 ; j < 10 ; j++)
	{
		printf("%2d",j);
	}
	printf("\n");

	for(int i = 1; i < 10 ; i++)
	{
		printf("%2d",i);
		for(int j = 1 ; j < 10 ; j++)
		{
			switch(board[i][j])
			{
			case 0:
				printf(" -");
				break;
			case 1:
				printf(" *");
				break;
			case 2:
				printf(" O");
				break;
			}
		}
		printf("\n");
	}
	return ;
}

#endif