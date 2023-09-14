#include <iostream>
using namespace std;

bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);

int main()
{
	//
	//	PLEASE DO NOT CHANGE function main
	//
	char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
	displayBoard(board);

	while (true)
	{

		// The first player makes a move
		makeAMove(board, 'X');
		displayBoard(board);

		if (isWon('X', board))
		{
			cout << "X player won" << endl;
			exit(0);
		}
		else if (isDraw(board))
		{
			cout << "No winner" << endl;
			exit(0);
		}

		// The second player makes a move
		makeAMove(board, 'O');
		displayBoard(board);

		if (isWon('O', board))
		{
			cout << "O player won" << endl;
			exit(0);
		}
		else if (isDraw(board))
		{
			cout << "No winner" << endl;
			exit(0);
		}
	}

	return 0;
}

bool isWon(char a, char board[][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == a && board[i][1] == a && board[i][2] == a)
		{
			return true;
		}
		if (board[0][i] == a && board[1][i] == a && board[2][i] == a)
		{
			return true;
		}
	}
	if (board[0][0] == a && board[1][1] == a && board[2][2] == a)
	{
		return true;
	}
	if (board[0][2] == a && board[1][2] == a && board[2][2] == a)
	{
		return true;
	}
	return false;
}

bool isDraw(char board[][3])
{

	int isCount = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 'X' || board[i][j] == 'O')
			{
				isCount++;
			}
		}
	}
	if (isCount != 9)
	{
		return false;
	}
	if (!isWon('X', board) && !isWon('O', board))
	{
		return true;
	}
	
	return false;
}

void makeAMove(char board[][3], char apm)
{
	while (true)
	{
		int userInputRow;
		int userInputColumn;
		cout << "Enter a row(0,1,2) for player " << apm << ": ";
		cin >> userInputRow;
		;
		cout << "Enter a column(0,1,2) for player " << apm << ": ";
		cin >> userInputColumn;

		if (userInputRow < 0 || userInputRow > 2 || userInputColumn < 0 || userInputColumn > 2)
		{
			cout << "This is an invalid move\n";
		}
		else
		{
			if (board[userInputRow][userInputColumn] != 'X' && board[userInputRow][userInputColumn] != 'O')
			{
				board[userInputRow][userInputColumn] = apm;
				break;
			}
			else
			{
				cout << "This cell is already occupied. Try a different cell\n";
			}
		}
	}
}

void displayBoard(char board[][3])
{
	
	cout << "-------------\n";
	for (int i = 0; i < 3; i++)
	{
		cout << "|";
		for (int j = 0; j < 3; j++)
		{
			cout << board[i][j] << "|";
		}

		cout << endl;
		cout << "-------------\n";
	}
}