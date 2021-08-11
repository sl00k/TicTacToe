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
	cout << "\n";
}

void Board::SetPlayer(string* playerX, string* playerO)
{
	cout << "Insert Name Of Player X\n";
	cin >> *playerX;
	cout << "Insert Name Of Player O\n";
	cin >> *playerO;
	system("CLS");
	cout << "Match: " << *playerX << " vs. " <<*playerO <<"\n\n";
} 

void Board::MakeMove(Board* gamingBoard, string* playerName, char playerSign)
{
	//TODO: Print board and labeld positions
	int playersChoosenPosition = 0;
	int moveSuccessful=0;
	cout << "Make your move " << *playerName << ".\n";
	cout << "Enter position between 0 and 15"<<"\n";
	cin >> playersChoosenPosition;

	//check if input is a valid integer
	while (playersChoosenPosition > 15 and playersChoosenPosition < 0 or !cin)
	{
		cin.clear();
		cout << "This is not a valid board position\n";
		cout << "Enter position between 0 and 15\n";
		cin >> playersChoosenPosition;
	}

	// check if position is not taken yet
	while (moveSuccessful == 0)
	{
		if (gamingBoard->boardPosition[playersChoosenPosition] == '_')
		{
			gamingBoard->boardPosition[playersChoosenPosition] = playerSign;
			cout << "Position " << playersChoosenPosition << " taken by " << *playerName<<"\n";
			moveSuccessful = 1;
		}
		else
		{
			cout << "Position is already taken, please choose another position\n";
			cout << "Enter position between 0 and 15\n";
			cin >> playersChoosenPosition;
		}
	}

}