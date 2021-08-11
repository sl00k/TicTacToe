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

int Board::checkFourInARow(Board* gamingBoard) 
{
	// check horizontal rows
	char firstSymbol;
	char nextSymbol;
	int row = 0;
	int i = 0;
	int column = 0;
	int counter=0;
	

	// check horizontal rows
	for (row =0; row<16;row =row+4)
	{
		firstSymbol = gamingBoard->boardPosition[row];
		if (firstSymbol != '_')
		{
			while (i < 4)
			{
				nextSymbol = gamingBoard->boardPosition[i + row];
				//cout << "First Symbol ist: " << firstSymbol << "   NextSymbol ist: " << nextSymbol << "   board Position ist: " << i+row << "\n\n";
				if (firstSymbol == nextSymbol)
				{
					if (i == 3)
					{
						return 0;
					}
					i += 1;
				}
				else //less than 4 in a row, check next horizontal row
				{
					break;
				}
			}
			i = 0;
		}
	}

	// check vertical
	i = 0;
	for (column = 0; column < 4;column++)
	{
		firstSymbol = gamingBoard->boardPosition[column];
		if (firstSymbol != '_')
		{
			while (i < 16)
			{
				nextSymbol = gamingBoard->boardPosition[i + column];
				//cout << "First Symbol ist: " << firstSymbol << "   NextSymbol ist: " << nextSymbol << "   board Position ist: " << i+column << "\n\n";
				if (firstSymbol == nextSymbol)
				{
					counter += 1;
					if (counter == 4)
					{
						return 0;
					}
					i += 4;
				}
				else //less than 4 in a row, check next column
				{
					break;
				}
			}
			counter = 0;
			i = 0;
		}
	}
	return -1;
}