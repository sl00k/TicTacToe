#include<string>
using namespace std;

class Board
{
	char boardPosition[16];

public:
	Board();
	void DrawBoard();
	void SetPlayer(string* playerX, string* playerO);
	void MakeMove(Board *gamingBoard, string* playerName, char playerSign);
	int checkFourInARow(Board* gamingBoard);
};

