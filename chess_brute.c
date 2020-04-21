#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void InitializeBoard(int **board, int xSize, int ySize);
void DisplayBoard(int **board, int xSize, int ySize);
bool KnightsTour(int **board, int xCoor, int yCoor, int xSize, int ySize, int moveNum);
bool MoveIsValid(int **board, int xCoor, int yCoor, int xSize, int ySize);

int main()
{
	int xSize=8, ySize=8, xCoor, yCoor;
	int **board;

	
 	printf("Enter starting COLUMN : \n");
 	scanf("%d",&yCoor);



 	printf("Enter starting ROW : \n");
 	scanf("%d",&xCoor);
	


	
	board = (int**)malloc(xSize*sizeof(int*));

	int **temp = board;

	for (int a = 0; a < xSize; a++)
	{
		temp[a] = (int*)malloc(ySize*sizeof(int));
	}

		InitializeBoard(board, xSize, ySize);
		//DisplayBoard(board, xSize, ySize);
	 
		
	  if (!KnightsTour(board, xCoor, yCoor, xSize, ySize, 1))
	   {
		   printf("Solution found \n");
		   DisplayBoard(board, xSize, ySize);
	  }
	  else
	  {
			printf("Solution not found \n");
			DisplayBoard(board,xSize,ySize);
	  }
	  return 0;
  }

  void InitializeBoard(int **board, int xSize, int ySize)
  {
	  int x, y;
  
	 for (x = 0; x < xSize; x++)
	 {
		 for (y = 0; y < ySize; y++)
	   {
			 board[x][y] = 0;
		  }
	  }
}

 void DisplayBoard(int **board, int xSize, int ySize)
  {
	  int x, y;
  
	  for (x = 0; x < xSize; x++)
	{
		  for (y = 0; y < ySize; y++)
		{
			  printf("%d \t", board[x][y]);
		}
		printf("\n"); 
	}
  }
  
 
 bool MoveIsValid(int **board, int xCoor, int yCoor, int xSize, int ySize)
 {
	 if ((xCoor < 0) || (xCoor >= xSize))
	{
		 return false;
	}
  
	  if ((yCoor < 0) || (yCoor >= ySize))
	  {
		  return false;
	  }

	 if (board[xCoor][yCoor] != 0)
	 {
		  return false;
	 }
   
	  return true;
 }
  
  bool KnightsTour(int **board, int xCoor, int yCoor, int xSize, int ySize, int moveNum)
  {
	  if (!MoveIsValid(board, xCoor, yCoor, xSize, ySize))
	  {
		  return false;
	  }
  
	  board[xCoor][yCoor] = moveNum;
   
	 if ((xSize * ySize) == moveNum)
	 {
		 return true;
	 } 

	 //printf("KT: %d, %d, %d\n", yCoor,xCoor,moveNum);
	
   
	   if (!KnightsTour(board, (xCoor - 1), (yCoor - 2), xSize, ySize, (moveNum + 1)))
		 if (!KnightsTour(board, (xCoor - 2), (yCoor - 1), xSize, ySize, (moveNum + 1)))
			 if (!KnightsTour(board, (xCoor - 2), (yCoor + 1), xSize, ySize, (moveNum + 1)))
				 if (!KnightsTour(board, (xCoor - 1), (yCoor + 2), xSize, ySize, (moveNum + 1)))
					 if (!KnightsTour(board, (xCoor + 1), (yCoor + 2), xSize, ySize, (moveNum + 1)))
						if (!KnightsTour(board, (xCoor + 2), (yCoor + 1), xSize, ySize, (moveNum + 1)))
						   if (!KnightsTour(board, (xCoor + 2), (yCoor - 1), xSize, ySize, (moveNum + 1)))
							   if (!KnightsTour(board, (xCoor + 1), (yCoor - 2), xSize, ySize, (moveNum + 1)))
									return false;
  }
