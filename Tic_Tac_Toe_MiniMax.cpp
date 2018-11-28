#include<iostream>
#include<vector>

using namespace std;

const int DIM = 3;
const int SCORE = 10;
const char PLAYER = 'X';
const char OPPONENT = 'O';
const int INFINITE = INT16_MAX;

class TicTacToe{
 	private:
 		char playBoard[DIM][DIM];
 		pair<int, int> chosenPoint;
 		int whoWon;

 	public:
 	/*
	TicTacToe() Constructor - Initialize board
 	*/
 	TicTacToe()
 	{
 		for(int i = 0; i < DIM; i++)
 		{
 			for(int j = 0; j < DIM; j++)
 			{
 				playBoard[i][j] = '_';
 			}
 		}
 		whoWon = 0;
 	}

 	int evaluateCurrentConfiguration();
 	void displayBoard();
 	bool isGameOver();
 	int miniMaxAlgorithm(int, bool);
 	pair<int, int> findBestMove();
 	bool makeAMove(int, int, bool);
 	void startGame();
 	void endGame();
};


/*
void displayBoard() - To display the current status of the
playing board
*/

void TicTacToe::displayBoard()
{
	for(int i = 0; i < DIM; i++)
	{
		for(int j = 0; j < DIM; j++)
		{
			cout << playBoard[i][j];
		}
		cout << endl;
	}
}

/*
bool isGameOver() - To know whether the game is over
*/

bool TicTacToe::isGameOver()
{
	//Row checking
	for(int i = 0; i < DIM; i++)
	{
		int matching = 0;
		for(int j = 1; j < DIM; j++)
		{
			if(playBoard[i][j] == playBoard[i][j - 1] && playBoard[i][j] != '_')
			{
				++matching;
			}
		}
		//Current Row matches
		if(matching == DIM - 1)
		{
			whoWon = (playBoard[i][0] == PLAYER ? -1 : 1);
			return true;
		}
	}

	//Column Checking
	for(int i = 0; i < DIM; i++)
	{
		int matching = 0;
		for(int j = 1; j < DIM; j++)
		{
			if(playBoard[j][i] == playBoard[j - 1][i] && playBoard[i][j] != '_')
			{
				++matching;
			}
		}
		//Current column matches
		if(matching == DIM - 1)
		{
			whoWon = (playBoard[0][i] == PLAYER ? -1 : 1);
			return true;
		}
	}

	//Primary diagonal checking
	int matching = 0;
	for(int i = 1; i < DIM; i++)
	{
		if(playBoard[i][i] == playBoard[i - 1][i - 1] && playBoard[i][i] != '_')
		{
			matching++;
		}
	}
	if(matching == DIM - 1)
	{
		whoWon = (playBoard[0][0] == PLAYER ? -1 : 1);
		return true;
	}

	//Secondary Diagonal Checking
	matching = 0;
	for(int i = 1; i < DIM; i++)
	{
		if(playBoard[i][DIM - i - 1] == playBoard[i - 1][DIM - i] && playBoard[i][DIM - i - 1] != '_')
		{
			matching++;
		}
	}
	if(matching == DIM - 1)
	{
		whoWon = (playBoard[0][DIM - 1] == PLAYER ? -1 : 1);
		return true;
	}

	// Check for empty spaces if any
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(playBoard[i][j] == '_')
			{
				return false;
			}
		}
	}
	return true;
}

/*
int evaluateCurrentConfiguration() - See whether anyone has won, else call
MiniMax Algorithm. 
*/

int TicTacToe::evaluateCurrentConfiguration()
{
	//Row checking
	for(int i = 0; i < DIM; i++)
	{
		int matching = 0;
		for(int j = 1; j < DIM; j++)
		{
			if(playBoard[i][j] == playBoard[i][j - 1])
			{
				++matching;
			}
		}
		//Current Row matches
		if(matching == DIM - 1)
		{
			return playBoard[i][0] == PLAYER ? SCORE : -SCORE;
		}
	}

	//Column Checking
	for(int i = 0; i < DIM; i++)
	{
		int matching = 0;
		for(int j = 1; j < DIM; j++)
		{
			if(playBoard[j][i] == playBoard[j - 1][i])
			{
				++matching;
			}
		}
		//Current column matches
		if(matching == DIM - 1)
		{
			return playBoard[0][i] == PLAYER ? SCORE : -SCORE;
		}
	}

	//Primary diagonal checking
	int matching = 0;
	for(int i = 1; i < DIM; i++)
	{
		if(playBoard[i][i] == playBoard[i - 1][i - 1])
		{
			matching++;
		}
	}
	if(matching == DIM - 1)
	{
		return playBoard[0][0] == PLAYER ? SCORE : -SCORE;
	}

	//Secondary Diagonal Checking
	matching = 0;
	for(int i = 1; i < DIM; i++)
	{
		if(playBoard[i][DIM - i - 1] == playBoard[i - 1][DIM - i])
		{
			matching++;
		}
	}
	if(matching == DIM - 1)
	{
		return playBoard[0][DIM - 1] == PLAYER ? SCORE : -SCORE;
	}

	//No one in winning position
	return 0;
}

/*
int miniMaxAlgorithm(int, bool);
Algorithm to give the best move as per the requirement
*/

int TicTacToe::miniMaxAlgorithm(int depth, bool isMax)
{
	int currentScore = evaluateCurrentConfiguration();
	
	// If there is a winning position
	if(abs(currentScore) == SCORE)
	{
		return currentScore;
	}

	// If there is no move left
	if(isGameOver())
	{
		return 0;
	}

	else
	{
		int currentBest = (isMax ? -INFINITE : INFINITE);
		for(int i = 0; i < DIM; i++)
		{
			for(int j = 0; j < DIM; j++)
			{
				if(playBoard[i][j] == '_')
				{
					playBoard[i][j] = (isMax ? PLAYER : OPPONENT);
					currentBest = (isMax ? max(currentBest, miniMaxAlgorithm(depth + 1, !isMax)) : 
						min(currentBest, miniMaxAlgorithm(depth + 1, !isMax)));
					playBoard[i][j] = '_';
				}
			}
		}
		return currentBest;
	}
}


/*
pair<int, int> findBestMove() - A function to find the best move using Minimax
*/

pair<int, int> TicTacToe::findBestMove()
{
	int currentBest = -INFINITE;
	for(int i = 0; i < DIM; i++)
	{
		for(int j = 0; j < DIM; j++)
		{
			if(playBoard[i][j] == '_')
			{
				playBoard[i][j] = PLAYER;
				int currentValue = miniMaxAlgorithm(0, false);
				playBoard[i][j] = '_';
				if(currentValue > currentBest)
				{
					currentBest = currentValue;
					chosenPoint.first = i;
					chosenPoint.second = j;
				}
			}
		}
	}
	return chosenPoint;
}

/*
bool makeAMove(int, int, bool) - A function to make a move for player if possible
*/

bool TicTacToe::makeAMove(int row, int column, bool isPlayer)
{
	// Checking for out of bound or already used space
	if(row >= 0 && row < DIM && column >= 0 && column < DIM && playBoard[row][column] == '_')
	{
		playBoard[row][column] = (isPlayer ? PLAYER : OPPONENT);
		return true;
	}
	cout << "\nIllegal Move!! Move either out of board or the place is already filled! \n";
	return false;	
}

/*
void startGame() - A function to handle all the Game's functionality
*/

void TicTacToe::startGame()
{
	cout << "\n\n\t\t\t TIC - TAC - TOE Using MiniMax Algorithm \n";
	cout << "\n\t\t\t Player Takes " << PLAYER << " and Computer takes " << OPPONENT << " - " << DIM << "x" << DIM << " Game\n";
	while(!isGameOver())
	{
		cout << "\nBoard Status: \n";
		displayBoard();
		int row, column;
		do {
			cout << "\nEnter Row and Column (0 based) to cross: ";
			cin >> row >> column;
		} while(!makeAMove(row, column, true));

		// Opponents Move
		if(!isGameOver())
		{
			pair<int, int> opponentsMove = findBestMove();
			makeAMove(opponentsMove.first, opponentsMove.second, false);	
			cout << "\nComputer chooses Row: " << opponentsMove.first << " Column: " << opponentsMove.second;
			cout << endl;
		}
	}
	cout << endl;
}

/*
void endGame() - To print who won / if the match is drawn
*/

void TicTacToe::endGame()
{
	if(!whoWon)
	{
		cout << "\n\n Match Result: Match is Drawn!!";
	}
	else if(whoWon == -1)
	{
		cout << "\n\n Match Result: Match is WON by PLAYER!!";
	}
	else
	{
		cout << "\n\n Match Result: Match is WON by Computer!!";
	}
	cout << endl;
}

int main()
{
	TicTacToe T;
	T.startGame();
	T.endGame();
	return 0;
}