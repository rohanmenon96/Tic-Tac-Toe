#include<iostream>
#include<stdlib.h>
using namespace std;
//Change Grid Size
char displayGrid[102][102];
int mainGrid[102][102];
void setMainGrid(int gridSize, int flag)
	{
		if(flag==0)
			{
				for(int i=0; i<gridSize; i++)
					{
						for(int j=0; j<gridSize; j++)
							{
								mainGrid[i][j]=0;
							}
					}		
			}
		
	}
void setGrid(int gridSize)
	{
		for(int i=0; i<gridSize; i++)
			{
				for(int j=0; j<gridSize; j++)
					{
						displayGrid[i][j] = ' ';
					}
			}
	}
void displayGridfn(int gridSize, int flag)
	{
				
			//For Showing the X Co-ordinate Numbers
			for(int i=0; i<gridSize; i++)
				{
					if(i==0)
						{
							cout<<"     "<<i+1<<" ";
						}
					else if(i>=9)
						{
							cout<<"  "<<i+1<<" ";
						}
					else
						{
							cout<<"  "<<i+1<<"  ";
						}
				}
			cout<<"\n";
			//This is for in-between the --- lines.
			for(int i=0; i<gridSize; i++)
				{
					if(i<9)
						{
							cout<<i+1<<"   ";
						}
					else if(i>98)
						{
							cout<<i+1<<" ";
						}
					else
						{
							cout<<i+1<<"  ";
						}
					for(int j=0; j<gridSize; j++)
						{
							if(flag==1)
							{
							cout<<""<<displayGrid[i][j];
							}
							else
							{
							cout<<""<<mainGrid[i][j];
							}
							if(j!=gridSize-1)
								{
									cout<<"  | ";
								}
						}
					cout<<"\n";
					if(i!=(gridSize-1))
					{
						for(int l=0; l<gridSize; l++)
						{
							if(l==0)
								{
									cout<<"    ---+";
								}
							else if(l==(gridSize-1))
								{
									cout<<"---";
								}
							else
								{
									cout<<"----+";
								}

						}
					}
					cout<<"\n";
				}
			
		
	}
/*void checkAll(int id,int x,int y, int winSequence)
	{

	}*/
int main()
	{
		char Players[] = {'X','O','A','B','C','D','E','F','G','H','I','J','K','L','M','N','P','Q','R','S','T','U','V','W','Y','Z'};
		int id[26];
		for(int i=0; i<26;i++)
			{
				id[i]=i; //Setting Unique IDs for every player
			}
		int gridSize = 0;
		int i=1;
		int x,y, winSequence;
		int a,numOfPlayers;
		bool k = false;
		bool gameOver = false;
		cout<<"\t\t\tWelcome to the game of TicTacToe!! ";
        cout<<"\n\t\t   -----------------------------------";
        cout<<"\nChoose an option: ";
     	cout<<"\n1.Start a new game";
     	cout<<"\n2.Load a saved game\nInput : ";
     	cin>>a;
     	while(i>0)
     	{
     	if(a==1)
     		{
     			goto A;
     		}
     	else if (a==2)
     		{
     			goto B;
     			//Write this part of code
     		}
     	else
     		{
     			cout<<"\nWrong Input Please Try Again!";
     		}
     	}
		B:
     	cout<<"\nSorry! This part is still in progress!";
     	A:
     	while(k==false)
     		{
     			cout<<"\nEnter The Number of Players : ";
     			cin>>numOfPlayers;
     			if(numOfPlayers>26)
     				{
     					cout<<"\nSorry! The maximum number of players is 26! Please Enter Again.";
     				}
     			else if(numOfPlayers==1)
     				{
     					cout<<"\nTicTacToe requires minimum 2 players. Please Enter Again.";
     				}
     			else
     				{
     					k=true;
     				}

     		}
     	k=false;
     	while(k==false)
     		{
     			cout<<"\nEnter the size of the Grid: ";
     			cin>>gridSize;
     			if(gridSize<=(numOfPlayers-2))
     				{
     					cout<<"\nThis grid size wouldn't give a winner! Please Enter Again.";
     				}
     			else if(gridSize>999)
                    {
                        cout<<"\nGrid size should be less than 999. Please try again.";
                    }
                else
     				{
     					k=true;
     				}
     		}
     	k=false;
     	while(k==false)
     		{
     			cout<<"\nEnter the Win Sequence: ";
     			cin>>winSequence;
     			if(winSequence>gridSize)
     				{
     					cout<<"\nThis win Sequence wouldn't give a winner! Please Enter Again.";
     				}
                else
     				{
     					k=true;
     				}
     		}
		setGrid(gridSize);
		setMainGrid(gridSize,0);
		while(gameOver == false)
			{
				for(int counter=0 ; counter<numOfPlayers; counter++)
       				{
       					displayGridfn(gridSize,1); //Flag1 for Char Grid, Flag2 for main Grid
       					displayGridfn(gridSize,2);
       					cout<<"\nPlayer "<<Players[counter]<<"'s Chance : ";
       					cin>>x;
       					cin>>y;
       					displayGrid[x-1][y-1] = Players[counter];
       					mainGrid[x-1][y-1]= id[counter];
       					//checkAll(id[counter],);
       					system("cls");
       				}
			}
	}