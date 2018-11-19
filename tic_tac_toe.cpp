#include <iostream>
#include <vector>

using namespace std;

/*
THIS IS A 3X3 COMPUTER VS HUMAN TIC_TAC_TOE GAME 
*/

int tac_toe[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
int mr,mc;
/*
MINI AND MAX FUCNTIONS MAKE MUTUAL RECURSIVE CALLS UNTILL THEY REACH THE END NODE 
WHICH IS THE STATE IN WHICH EITHER OF THEM WINS OR GAME DRAWS
*/
int mini(int dbvalue);	//dbvalue stands for depth based value -- it's purpose is explained inside the function
int max(int dbvalue);
int root(int dbvalue);

void display();
int win(bool side);		//checks if anyside has won

int evaluate(int dbvalue,bool side,int r,int c);
int nodes=0;
//		false -> mini
//		true -> max

int root(int dbvalue)		// 1 -> o & 2 -> x  // o -> false & x -> true
{
	int a;
	int result = 1;
	if(tac_toe[0][0] == 0)
	{
		a = evaluate(dbvalue,false,0,0);
		if(a <= result)
		{
			result = a;
			mr = 0;
			mc =0;
		}
	}
	if(tac_toe[0][1] == 0)
	{
		a = evaluate(dbvalue,false,0,1);
		if(a <= result)
		{
			result = a;
			mr = 0;
			mc =1;
		}
	}
	if(tac_toe[0][2] == 0)
	{
		a = evaluate(dbvalue,false,0,2);
		if(a <= result)
		{
			result = a;
			mr = 0;
			mc =2;
		}
	}
	if(tac_toe[1][0] == 0)
	{
		a = evaluate(dbvalue,false,1,0);
		if(a <= result)
		{
			result = a;
			mr = 1;
			mc =0;
		}
	}
	if(tac_toe[1][1] == 0)
	{
		a = evaluate(dbvalue,false,1,1);
		if(a <= result)
		{
			result = a;
			mr = 1;
			mc =1;
		}
	}
	if(tac_toe[1][2] == 0)
	{
		a = evaluate(dbvalue,false,1,2);
		if(a <= result)
		{
			result = a;
			mr = 1;
			mc =2;
		}
	}
	if(tac_toe[2][0] == 0)
	{
		a = evaluate(dbvalue,false,2,0);
		if(a <= result)
		{
			result = a;
			mr = 2;
			mc =0;
		}
	}
	if(tac_toe[2][1] == 0)
	{
		a = evaluate(dbvalue,false,2,1);
		if(a <= result)
		{
			result = a;
			mr = 2;
			mc =1;
		}
	}
	if(tac_toe[2][2] == 0)
	{
		a = evaluate(dbvalue,false,2,2);
		if(a <= result)
		{
			result = a;
			mr = 2;
			mc =2;
		}
	}
	return result;
	
}



int mini(int dbvalue)		// 1 -> o & 2 -> x  // o -> false & x -> true
{
	nodes++;
	int a;
	vector<int> result;
	if(tac_toe[0][0] == 0)
	{
		a = evaluate(dbvalue,false,0,0);
		result.push_back(a);
	}
	if(tac_toe[0][1] == 0)
	{
		a = evaluate(dbvalue,false,0,1);
		result.push_back(a);
	}
	if(tac_toe[0][2] == 0)
	{
		a = evaluate(dbvalue,false,0,2);
		result.push_back(a);
	}
	if(tac_toe[1][0] == 0)
	{
		a = evaluate(dbvalue,false,1,0);
		result.push_back(a);
	}
	if(tac_toe[1][1] == 0)
	{
		a = evaluate(dbvalue,false,1,1);
		result.push_back(a);
	}
	if(tac_toe[1][2] == 0)
	{
		a = evaluate(dbvalue,false,1,2);
		result.push_back(a);
	}
	if(tac_toe[2][0] == 0)
	{
		a = evaluate(dbvalue,false,2,0);
		result.push_back(a);
	}
	if(tac_toe[2][1] == 0)
	{
		a = evaluate(dbvalue,false,2,1);
		result.push_back(a);
	}
	if(tac_toe[2][2] == 0)
	{
		a = evaluate(dbvalue,false,2,2);
		result.push_back(a);
	}
		
	
		int i,small=1;
		for(i=0;i<result.size();i++)
		{
			if(result[i] < small)
			{
				small = result[i];
			}
		}
		return small;

	
}


int max(int dbvalue)		// 1 -> o & 2 -> x  // o -> false & x -> true
{
	nodes++;
	int a;
	vector<int> result;
	if(tac_toe[0][0] == 0)
	{
		a = evaluate(dbvalue,true,0,0);
		result.push_back(a);
	}
	if(tac_toe[0][1] == 0)
	{
		a = evaluate(dbvalue,true,0,1);
		result.push_back(a);
	}
	if(tac_toe[0][2] == 0)
	{
		a = evaluate(dbvalue,true,0,2);
		result.push_back(a);
	}
	if(tac_toe[1][0] == 0)
	{
		a = evaluate(dbvalue,true,1,0);
		result.push_back(a);
	}
		
	if(tac_toe[1][1] == 0)
	{
		a = evaluate(dbvalue,true,1,1);
		result.push_back(a);
	}
	if(tac_toe[1][2] == 0)
	{
		a = evaluate(dbvalue,true,1,2);
		result.push_back(a);
	}
	if(tac_toe[2][0] == 0)
	{
		a = evaluate(dbvalue,true,2,0);
		result.push_back(a);
	}
	if(tac_toe[2][1] == 0)
	{
		a = evaluate(dbvalue,true,2,1);
		result.push_back(a);
	}
	if(tac_toe[2][2] == 0)
	{
		a = evaluate(dbvalue,true,2,2);
		result.push_back(a);
	}
		
		
		int i,large=-1;
		for(i=0;i<result.size();i++)
		{
			if(result[i] > large)
			{
				large = result[i];
			}
		}
		return large;
	
}

int evaluate (int dbvalue,bool side,int r,int c)
{
	if (side == false)
	{
		tac_toe[r][c] = 1;
	}
	else
	{
		tac_toe[r][c] = 2;
	}
	
	int res;
	
	if( tac_toe[0][0] == tac_toe[0][1] && tac_toe[0][0] == tac_toe[0][2] && tac_toe[0][0] == 1)
	{
		tac_toe[r][c] = 0;
		return -dbvalue;
	}
	else if ( tac_toe[1][0] == tac_toe[1][1] && tac_toe[1][0] == tac_toe[1][2] && tac_toe[1][0] == 1)
	{
		tac_toe[r][c] = 0;
		return -dbvalue;
	}
	else if ( tac_toe[2][0] == tac_toe[2][1] && tac_toe[2][0] == tac_toe[2][2] && tac_toe[2][0] == 1)
	{
		tac_toe[r][c] = 0;
		return -dbvalue;
	}
	else if ( tac_toe[0][0] == tac_toe[1][0] && tac_toe[0][0] == tac_toe[2][0] && tac_toe[0][0] == 1)
	{
		tac_toe[r][c] = 0;
		return -dbvalue;
	}
	else if ( tac_toe[0][1] == tac_toe[1][1] && tac_toe[0][1] == tac_toe[2][1] && tac_toe[0][1] == 1)
	{
		tac_toe[r][c] = 0;
		return -dbvalue;
	}
	else if ( tac_toe[0][2] == tac_toe[1][2] && tac_toe[0][2] == tac_toe[2][2] && tac_toe[0][2] == 1)
	{
		tac_toe[r][c] = 0;
		return -dbvalue;
	}
	else if ( tac_toe[0][0] == tac_toe[1][1] && tac_toe[0][0] == tac_toe[2][2] && tac_toe[0][0] == 1)
	{
		tac_toe[r][c] = 0;
		return -dbvalue;
	}
	else if ( tac_toe[0][2] == tac_toe[1][1] && tac_toe[0][2] == tac_toe[2][0] && tac_toe[0][2] == 1)
	{
		tac_toe[r][c] = 0;
		return -dbvalue;
	}
	
	
	
	else if( tac_toe[0][0] == tac_toe[0][1] && tac_toe[0][0] == tac_toe[0][2] && tac_toe[0][0] == 2)
	{
		tac_toe[r][c] = 0;
		return dbvalue;
	}
	else if ( tac_toe[1][0] == tac_toe[1][1] && tac_toe[1][0] == tac_toe[1][2] && tac_toe[1][0] == 2)
	{
		tac_toe[r][c] = 0;
		return dbvalue;
	}
	else if ( tac_toe[2][0] == tac_toe[2][1] && tac_toe[2][0] == tac_toe[2][2] && tac_toe[2][0] == 2)
	{
		tac_toe[r][c] = 0;
		return dbvalue;
	}
	else if ( tac_toe[0][0] == tac_toe[1][0] && tac_toe[0][0] == tac_toe[2][0] && tac_toe[0][0] == 2)
	{
		tac_toe[r][c] = 0;
		return dbvalue;
	}
	else if ( tac_toe[0][1] == tac_toe[1][1] && tac_toe[0][1] == tac_toe[2][1] && tac_toe[0][1] == 2)
	{
		tac_toe[r][c] = 0;
		return dbvalue;
	}
	else if ( tac_toe[0][2] == tac_toe[1][2] && tac_toe[0][2] == tac_toe[2][2] && tac_toe[0][2] == 2)
	{
		tac_toe[r][c] = 0;
		return dbvalue;
	}
	else if ( tac_toe[0][0] == tac_toe[1][1] && tac_toe[0][0] == tac_toe[2][2] && tac_toe[0][0] == 2)
	{
		tac_toe[r][c] = 0;
		return dbvalue;
	}
	else if ( tac_toe[0][2] == tac_toe[1][1] && tac_toe[0][2] == tac_toe[2][0] && tac_toe[0][2] == 2)
	{
		tac_toe[r][c] = 0;
		return dbvalue;
	}
	else if ( tac_toe[0][0] != 0 && tac_toe[0][1] != 0 && tac_toe[0][2] != 0 && tac_toe[1][0] != 0 && tac_toe[1][1] != 0 && tac_toe[1][2] != 0 && tac_toe[2][0] != 0 && tac_toe[2][1] != 0 && tac_toe[2][2] != 0 )
	{
		tac_toe[r][c] = 0;
		return 0;
	}
	else
	{
		//return minimax(!side);
		if(side == false)
		{
			res = max(dbvalue-1);
			tac_toe[r][c] = 0;
			return res;
		}
		else
		{
			res = mini(dbvalue-1);
			tac_toe[r][c] = 0;
			return res;
		}
	}	
	
}

void display()
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<tac_toe[i][j]<<" ";
		}
		cout<<endl;
	}
}


int draw()
{
	if ( tac_toe[0][0] != 0 && tac_toe[0][1] != 0 && tac_toe[0][2] != 0 && tac_toe[1][0] != 0 && tac_toe[1][1] != 0 && tac_toe[1][2] != 0 && tac_toe[2][0] != 0 && tac_toe[2][1] != 0 && tac_toe[2][2] != 0 )
	{
		return 1;
	}
	return 0;
}

int win(bool side)
{
	if(side == false)
	{
	if( tac_toe[0][0] == tac_toe[0][1] && tac_toe[0][0] == tac_toe[0][2] && tac_toe[0][0] == 1)
	{
		return 1;
	}
	else if ( tac_toe[1][0] == tac_toe[1][1] && tac_toe[1][0] == tac_toe[1][2] && tac_toe[1][0] == 1)
	{
		return 1;
	}
	else if ( tac_toe[2][0] == tac_toe[2][1] && tac_toe[2][0] == tac_toe[2][2] && tac_toe[2][0] == 1)
	{
		return 1;
	}
	else if ( tac_toe[0][0] == tac_toe[1][0] && tac_toe[0][0] == tac_toe[2][0] && tac_toe[0][0] == 1)
	{
		return 1;
	}
	else if ( tac_toe[0][1] == tac_toe[1][1] && tac_toe[0][1] == tac_toe[2][1] && tac_toe[0][1] == 1)
	{
		return 1;
	}
	else if ( tac_toe[0][2] == tac_toe[1][2] && tac_toe[0][2] == tac_toe[2][2] && tac_toe[0][2] == 1)
	{
		return 1;
	}
	else if ( tac_toe[0][0] == tac_toe[1][1] && tac_toe[0][0] == tac_toe[2][2] && tac_toe[0][0] == 1)
	{
		return 1;
	}
	else if ( tac_toe[0][2] == tac_toe[1][1] && tac_toe[0][2] == tac_toe[2][0] && tac_toe[0][2] == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	}
	
	
	else if(side == true)
	{
	if( (tac_toe[0][0] == tac_toe[0][1] ) && (tac_toe[0][0] == tac_toe[0][2] ) && (tac_toe[0][0] == 2) ) 
	{
		return 1;
	}
	else if ( tac_toe[1][0] == tac_toe[1][1] && tac_toe[1][0] == tac_toe[1][2] && tac_toe[1][0] == 2)
	{
		return 1;
	}
	else if ( tac_toe[2][0] == tac_toe[2][1] && tac_toe[2][0] == tac_toe[2][2] && tac_toe[2][0] == 2)
	{
		return 1;
	}
	else if ( tac_toe[0][0] == tac_toe[1][0] && tac_toe[0][0] == tac_toe[2][0] && tac_toe[0][0] == 2)
	{
		return 1;
	}
	else if ( tac_toe[0][1] == tac_toe[1][1] && tac_toe[0][1] == tac_toe[2][1] && tac_toe[0][1] == 2)
	{
		return 1;
	}
	else if ( tac_toe[0][2] == tac_toe[1][2] && tac_toe[0][2] == tac_toe[2][2] && tac_toe[0][2] == 2)
	{
		return 1;
	}
	else if ( tac_toe[0][0] == tac_toe[1][1] && tac_toe[0][0] == tac_toe[2][2] && tac_toe[0][0] == 2)
	{
		return 1;
	}
	else if ( tac_toe[0][2] == tac_toe[1][1] && tac_toe[0][2] == tac_toe[2][0] && tac_toe[0][2] == 2)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
	}
}

int main()
{
	int rw,cl;
	while(1)
	{
		
	display();
	cout<<"Nodes reached: "<<nodes<<endl;
	nodes=0;
	cout<<"YOUR TURN --"<<endl;
	cout<<"ROW: ";
	cin>>rw;
	cout<<"COLUMN: ";
	cin>>cl;
	tac_toe[rw][cl] = 2;
	display();
	if(win(true))
	{
		cout<<"YOU WIN"<<endl;
		break;
	}
	if(draw())
	{
		cout<<"GAME DRAW"<<endl;
		break;
	}
	root(10);
	cout<<nodes<<endl;
	tac_toe[mr][mc] = 1;
	if(win(false))
	{
		display();
		cout<<"COMPUTER WIN"<<endl;
		break;
	}
	if(draw())
	{
		display();
		cout<<"GAME DRAW"<<endl;
		break;
	}
	cout<<"COMPUTER --"<<endl;
	
	
	}
	
	return 0;
}



