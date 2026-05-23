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
			printf(" %c ", borad[i][j]);
			printf("/");
		}
		printf("\n");
	}
}
