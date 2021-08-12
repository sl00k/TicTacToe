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
	playBoard.DrawPossibleBoardPositions();					// Draw the empty gameboard with numbered positions

	while (playedRounds < maxPossibleRounds)
	{
		/*
		Ask for player X input, check if 4 in a row
		Ask for player O input, check if 4 in a row
		*/
		playBoard.MakeMove(&playBoard, &playerX, 'X');
		playBoard.DrawBoard();
		cout << "\n";
		playBoard.DrawPossibleBoardPositions();

		if (playBoard.checkFourInARow(&playBoard) == 0)
		{
			cout << playerX << " has won the game!!!\n";
			playedRounds = maxPossibleRounds + 2;
			continue;
		}

		playBoard.MakeMove(&playBoard, &playerO, 'O');
		playBoard.DrawBoard();
		cout << "\n";
		playBoard.DrawPossibleBoardPositions();
		if (playBoard.checkFourInARow(&playBoard) == 0)
		{
			cout << playerO << " has won the game!!!\n";
			playedRounds = maxPossibleRounds + 2;
			continue;
		}
		playedRounds += 1;
	}
	if (playedRounds == 8)
	{
		cout << "\n\nNo Winner!\n\n";
	}
	
}