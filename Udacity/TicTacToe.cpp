#include "TicTacToe.h"
#include<iostream>
using namespace std;

Board::Board() 
{
	for (int i = 0; i < sizeof(boardPosition); i++)
	{
		boardPosition[i] = '_';
	}
}

void Board::DrawBoard()
{
	for (int i = 0; i < sizeof(boardPosition); i++)
	{
		cout << '|'<< boardPosition[i];
		if (i % 4 == 3)
		{
			cout << "| \n";
		}
	}
}