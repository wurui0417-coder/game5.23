#define _CRT_SECURE_NO_WARNINGS

#include"game.h"



void menu()
{
	printf("********************\n");
	printf("**** 1. play  ****\n");
	printf("**** 0. exit  ****\n");
	printf("********************\n");
}


//游戏主体
void game(int row, int col)
{
	printf("welcome to the game!\n");

	char borad[ROW][COL] = { 0 };
	Iniborad(borad, row, col);
	Printborad(borad, row, col);
	for (int times =0;times < ROW * COL; times += 2)
	{
		Playertern(borad, row, col);
		if (Judegame(borad, row, col) == 1)
		{
			printf("Player wins!\n");
			break;
		}
		else if (Judegame(borad, row, col) == 0)
		{
			printf("It's a draw!\n");
			break;
		}
		else if (Judegame(borad, row, col) == 3)
		{
			printf("Computer wins!\n");
			break;
		}
		Computertern(borad, row, col);
		if (Judegame(borad, row, col) == 1)
		{
			printf("Player wins!\n");
			break;
		}
		else if (Judegame(borad, row, col) == 0)
		{
			printf("It's a draw!\n");
			break;
		}
		else if (Judegame(borad, row, col) == 3)
		{
			printf("Computer wins!\n");
			break;
		}
	}
	

}






int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	int row = ROW;
	int col = COL;

	do
	{
		menu();
		printf("Please enter your choice:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("let's play!\n");
			game(row,col);
			break;
		case 0:
			printf("exit game\n");
			break;
		default:
			printf("illegal choice,please try again\n");
			break;

	}

	} while (input);

	return 0;
}
