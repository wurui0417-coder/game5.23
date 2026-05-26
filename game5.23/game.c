#define _CRT_SECURE_NO_WARNINGS

#include"game.h"



//   /   /   
//---/---/---
//   /   /   
//---/---/---
//   /   /





void Iniborad(char borad[ROW][COL], int row, int col)
{
	int i = 0;
	for ( i = 0;i < row;i++)
	{
		int j = 0;
		for ( j = 0;j < col;j++)
		{
			borad[i][j] = 0;
		}
	}
}


void Printborad(char borad[ROW][COL],int row, int col)
{
	int i = 0;
	for (i = 0;i < row;i++)
	{
		int j = 0;
		for (j = 0;j < col;j++)
		{
			printf("  %c  ", borad[i][j]);
			printf("/");
		}
		printf("\n");
		if (i < 2)
		{
			int k = 0;
			for (k = 0;k < col;k++)
			{
				printf("---");
				printf("/");
			}
			printf("\n");
		}
	}
}



void Playertern(char borad[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("please enter your position:");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (borad[x - 1][y - 1] == 0)
			{
				borad[x - 1][y - 1] = 'X';
				Printborad(borad, row, col);
				break;
			}
			else
			{
				printf("the position is occupied,please try again\n");
			}
		}
		else
		{
			printf("illegal position,please try again\n");
		}
	}
}


void Computertern(char borad[ROW][COL], int row, int col)

{
	int x = 0;
	int y = 0;
	printf("Computer's turn:\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (borad[x][y] == 0)
		{
			borad[x][y] = 'O';
			Printborad(borad, row, col);
			break;
		}
	}
}





//int Judegame(char borad[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i, i < 3;i++)
//	{
//		if(borad[i][0] == borad[i][1] && borad[i][1] == borad[i][2] && borad[i][0] != 0)
//		{
//			return 1;
//		}
//	}
//	int j = 0;
//	for (j = 0;j < 3;j++)
//	{
//		if (borad[0][j] == borad[1][j] && borad[1][j] == borad[2][j] && borad[0][j] != 0)
//		{
//			return 1;
//		}
//	}
//	int l = 0;
//	for (l = 0;l < 3;l++)
//	{
//		if (borad[0][l] == borad[1][1] && borad[1][1] == borad[2][2] && borad[0][l] != 0)
//		{
//			return 1;
//		}
//	}
//	int k = 0;
//	for (k = 0;k < 3;k++)
//	{
//		if (borad[0][2] == borad[1][1] && borad[1][1] == borad[2][0] && borad[0][2] != 0)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}


// 判断玩家输赢
// 1:玩家赢了


 int checkgame(char borad[ROW][COL],int i, int j)
{
	if  (borad[i][j] == borad[i][j + 1] && borad[i][j] != 0)
	{
		j++;
		checkgame(borad,i, j);
		if(j==COL-1)
		{
			return 1; 
		}
	}
	else if (borad[i][j] == borad[i + 1][j] && borad[i][j] != 0)
	{
		i++;
		checkgame(borad, i, j);
		if (i == ROW - 1)
		{
			return 1;
		}
	}
	else if (borad[i][j] == borad[i + 1][j + 1] && borad[i][j] != 0)
	{
		i++;
		j++;
		checkgame(borad, i, j);
		if (i == ROW - 1 && j == COL - 1)
		{
			return 1;
		}
	}
	else if (borad[i][j] == borad[i + 1][j - 1] && borad[i][j] != 0)
	{
		i++;
		j--;
		checkgame(borad, i, j);
		if (i == ROW - 1 && j == 0)
		{
			return 1;
		}
	}
	else
	{
		return 0;
	}
}


 int checkcomputergame(char borad[ROW][COL], int i, int j)
 {
	 if (borad[i][j] == borad[i][j + 1] && borad[i][j] != 0 && borad[i][j] == 'O')
	 {
		 j++;
		 checkcomputergame(borad, i, j);
		 if (j == COL - 1)
		 {
			 return 1;
		 }
	 }
	 else if (borad[i][j] == borad[i + 1][j] && borad[i][j] != 0 && borad[i][j] == 'O')
	 {
		 i++;
		 checkcomputergame(borad, i, j);
		 if (i == ROW - 1)
		 {
			 return 1;
		 }
	 }
	 else if (borad[i][j] == borad[i + 1][j + 1] && borad[i][j] != 0 && borad[i][j] == 'O')
	 {
		 i++;
		 j++;
		 checkcomputergame(borad, i, j);
		 if (i == ROW - 1 && j == COL - 1)
		 {
			 return 1;
		 }
	 }
	 else if (borad[i][j] == borad[i + 1][j - 1] && borad[i][j] != 0 && borad[i][j] == 'O')
	 {
		 i++;
		 j--;
		 checkcomputergame(borad, i, j);
		 if (i == ROW - 1 && j == 0)
		 {
			 return 1;
		 }
	 }
	 else
	 {
		 return 0;
	 }
 }


 // 1:棋盘没满
 // 0:棋盘满了

 int is_full(char borad[ROW][COL], int row, int col)
 {
	 int i = 0;
	 for (i = 0;i < row;i++)
	 {
		 int j = 0;
		 for (j = 0;j < col;j++)
		 {
			 if (borad[i][j] == 0)
			 {
				 return 1;
			 }
		 }
	 }
	 return 0;
 }

// 0:平局
// 1:玩家赢了
// 2:没下完
// 3:电脑赢了
int Judegame(char borad[ROW][COL], int row, int col)
{
	int i = 0;
	
	for (i = 0;i < row;i++)
	{
		int j = 0;
		for (j = 0;j < col;j++)
		{
			if (checkgame(borad, i, j))
			{
				return 1;
			}
		}
	}
	for (i = 0;i < row;i++)
	{
		int j = 0;
		for (j = 0;j < col;j++)
		{
			if (checkcomputergame(borad, i, j))
			{
				return 3;
			}
		}
	}
	if (is_full(borad, row, col))
	{
		return 2;
	}
	else if(is_full(borad, row, col) == 0)
	{
		return 0;
	}
}






