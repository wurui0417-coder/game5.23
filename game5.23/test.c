#define _CRT_SECURE_NO_WARNINGS

#include"game.h"



void menu()
{
	printf("********************\n");
	printf("**** 1. play  ****\n");
	printf("**** 0. exit  ****\n");
	printf("********************\n");
}


void game(int row, int col)
{
	printf("welcome to the game!\n");
	char borad[ROW][COL] = { 0 };
	Iniborad(borad, row, col);
	Printborad(borad, row, col);

}






int main()
{
	
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
