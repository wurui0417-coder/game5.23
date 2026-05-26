#pragma once


#include<stdio.h>

//定义棋盘的行和列
#define ROW 3
#define COL 3


 

//初始化棋盘
void Iniborad(char borad[ROW][COL], int row, int col);


//打印棋盘
void Printborad(char borad[ROW][COL], int row, int col);

//玩家下棋
void Playertern(char borad[ROW][COL], int row, int col);

//电脑下棋
void Computertern(char borad[ROW][COL], int row, int col);


//判断玩家输赢
// 0:平局
// 1:玩家赢了
// 2:没下完
// 3:电脑赢了
int Judegame(char borad[ROW][COL], int row, int col);