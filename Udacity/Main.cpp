// TicTacToe
// Create Board
#include<string>
#include "TicTacToe.h"
#include<iostream>

using namespace std;

int main() {
	Board playBoard;
	string playerX;
	string playerO;
	int maxPossibleRounds = 8;
	int playedRounds = 0;

	playBoard.SetPlayer(&playerX, &playerO);	// Ask for player names
	playBoard.DrawBoard();						// Draw the empty gameboard

	while (playedRounds < maxPossibleRounds)
	{
		/*
		Ask for player X input, check if 4 in a row
		Ask for player O input, check if 4 in a row
		*/
		playBoard.MakeMove(&playBoard, &playerX, 'X');
		playBoard.DrawBoard();
		playBoard.MakeMove(&playBoard, &playerO, 'O');
		playBoard.DrawBoard();
	}
}